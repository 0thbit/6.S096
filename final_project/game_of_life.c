#include <stdio.h>
#include <stdlib.h>
#include <png.h>

#define ROWS 70
#define COLS 70

#define PNG_SETJMP_NOT_SUPPORTED

#define WIDTH 700
#define HEIGHT 700
#define COLOR_DEPTH 8

void print_arr(int **arr,int h, int w){
	for(int row=1; row<h; row++){
		for (int col=1; col<w;col++){
			printf("%d ",arr[row][col]);
		}
		printf("\n");
	}
	printf("\n");
}

void zoom(int **b_arr, int **z_arr, int w, int h, int z){
	printf("-D- %d %d %d\n",w,h,z);
	for(int row=0; row<z*h; row+=z){
		for(int col=0; col<z*w; col+=z){
			for(int i=row;i<row+z;i++){
				for(int j=col;j<col+z;j++){
					//base array is appended with 1 unit wide boundaries, hence the shift
					z_arr[i][j]=b_arr[(row/z)+1][(col/z)+1]; 
				}
			}
		}
	}
}


void progress_time(int **arr){
	int *tmp[ROWS+2];
	for(int row=0; row<ROWS+2; row++){
		tmp[row] = calloc(COLS+2, sizeof(int));
	}
	for(int row=1; row<ROWS+1; row++){
		for(int col=1; col<COLS+1; col++){
			//count the neighbours
			int count=0;
			count=	arr[row-1][col-1] + arr[row][col-1] + arr[row+1][col-1] +
			 	arr[row-1][col] + arr[row+1][col] +
				arr[row-1][col+1] + arr[row][col+1] + arr[row+1][col+1];
			if(count==3){
				tmp[row][col]=1;
			} else if(count==2 && arr[row][col]==1) {
				tmp[row][col]=1;	
			} else{
				tmp[row][col]=0;
			}	
		}
	}
	for(int row=1; row<ROWS+1; row++){
		for(int col=1; col<COLS+1; col++){
			arr[row][col]=tmp[row][col];
		}
	}
	for(int row=0; row<ROWS+2; row++){
		free(tmp[row]);
	}

}


struct Pixel {
	png_byte r, g, b, a;
};

int write_png(char* f_name, int **arr) {

	/* open PNG file for writing */
	FILE *f = fopen(f_name, "wb");
	if (!f) {
		fprintf(stderr, "could not open out.png\n");
		return 1;
	}

	/* initialize png data structures */
	png_structp png_ptr;
	png_infop info_ptr;

	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) {
		fprintf(stderr, "could not initialize png struct\n");
		return 1;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr) {
		png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
		fclose(f);
		return 1;
	}

	/* begin writing PNG File */
	png_init_io(png_ptr, f);
	png_set_IHDR(png_ptr, info_ptr, WIDTH, HEIGHT, COLOR_DEPTH,
	             PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE,
	             PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
	png_write_info(png_ptr, info_ptr);

	/* allocate image data */
	struct Pixel *row_pointers[HEIGHT];
	for (int row = 0; row < HEIGHT; row++) {
		row_pointers[row] = calloc(WIDTH, sizeof(struct Pixel));
	}

	/* copy zoomed array to row pointers */
	for (int row = 0; row < HEIGHT; row++) {
		for (int col = 0; col < WIDTH; col++) {
			row_pointers[row][col].r = 255*arr[row][col]; // red
			row_pointers[row][col].g = 0; // green
			row_pointers[row][col].b = 0; // blue
			row_pointers[row][col].a = 255; // alpha (opacity)
		}
	}


	/* write image data to disk */
	png_write_image(png_ptr, (png_byte **)row_pointers);

	/* finish writing PNG file */
	png_write_end(png_ptr, NULL);

	/* clean up PNG-related data structures */
	png_destroy_write_struct(&png_ptr, &info_ptr);

	/*free row pointers*/
	for(int row=0; row<HEIGHT; row++){
		free(row_pointers[row]);
	}

	/* close the file */
	fclose(f);
	f = NULL;
	return 0;	
}


int main(){
	int *earth[ROWS+2];
	int *z_earth[HEIGHT];
	int st=0;
	int cnt=0;
	int r,c;
	int period=20;
	char outf[20]="tmp.png";

	FILE *ifp;
	ifp = fopen("in.list","r");
	if (ifp == NULL) {
  		fprintf(stderr, "Can't open input file in.list!\n");
  		exit(1);
	}
		
	for(int row=0; row<ROWS+2; row++){
		earth[row] = calloc(COLS+2, sizeof(int));//appended boundary
	}
	for(int row=0; row<HEIGHT; row++){
		z_earth[row] = calloc(WIDTH, sizeof(int));
	}

	//setting row and col :: initializing life
	while (fscanf(ifp, "%d %d", &r, &c) == 2){
		earth[r%ROWS][c%COLS]=1;
	}
	fclose(ifp);

	zoom(earth,z_earth,ROWS,COLS,WIDTH/COLS);
	sprintf(outf,"out/%0d.png",cnt++);
	st=write_png(outf,z_earth);

	for(int i=0; i<period;i++){
		progress_time(earth);

		zoom(earth,z_earth,ROWS,COLS,WIDTH/COLS);
		sprintf(outf,"out/%0d.png",cnt++);
		st=write_png(outf,z_earth);
	}

	//free the pointers	
	for(int row=0; row<ROWS+2; row++){
		free(earth[row]);
	}
	for(int row=0; row<HEIGHT; row++){
		free(z_earth[row]);
	}
	return st;
}
