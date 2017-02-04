#include <stdio.h>
#include <stdlib.h>

#define B_H 2
#define B_W 4

void initialize(int **arr, int w, int h){
	for(int row=0; row<h; row++){
		for(int col=0; col<w;col++){
			arr[row][col]=rand()%10;//rand var from 0 to 9
		}
	}
}

void print_2d(int **arr, int w, int h){
	for(int row=0; row<h; row++){
		for(int col=0; col<w;col++){
			printf("%d ",arr[row][col]);
		}
		printf("\n");
	}
}

void zoom(int **b_arr, int **z_arr, int w, int h, int z){
	for(int row=0; row<z*h; row+=z){
		for(int col=0; col<z*w; col+=z){
			//printf("-D- %d %d \n",row,col);
			for(int i=row;i<row+z;i++){
				//printf("-D2- %d %d \n",row,col);
				for(int j=col;j<col+z;j++){
				//	printf("-D- %d %d \n",row,col);
					z_arr[i][j]=b_arr[row/z][col/z];
				}
			}
		}
	}
}

int main(){
	int ratio=2;
	int *_orig_arr[B_H];
	int *_mod_arr[ratio*B_H];

	for(int i=0; i<B_H; i++){
		_orig_arr[i] = (int *)malloc(B_W*sizeof(int));
	}
	for(int i=0; i<ratio*B_H; i++){
		_mod_arr[i] = (int *)malloc(ratio*B_W*sizeof(int));
	}

	initialize(_orig_arr, B_W, B_H);
	print_2d(_orig_arr, B_W, B_H);
	zoom(_orig_arr,_mod_arr,B_W,B_H,ratio);
	print_2d(_mod_arr,ratio*B_W,ratio*B_H);

	for(int i=0; i<B_H; i++){
		free(_orig_arr[i]);
	}
	for(int i=0; i<ratio*B_H; i++){
		free(_mod_arr[i]);
	}

	
}
