#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void print_arr(int **arr){
	for(int row=1; row<ROWS+1; row++){
		for (int col=1; col<COLS+1;col++){
			printf("%d ",arr[row][col]);
		}
		printf("\n");
	}
	printf("\n");
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

int main(){
	int *earth[ROWS+2];
	for(int row=0; row<ROWS+2; row++){
		earth[row] = calloc(COLS+2, sizeof(int));//appended boundary
	}
	print_arr(earth);
	//randomly seeding the life
	for(int i=0; i<(ROWS*COLS)/2;i++){
		earth[1+rand()%ROWS][1+rand()%COLS]=1;
	}
	print_arr(earth);
	progress_time(earth);
	print_arr(earth);
	//free the pointers	
	for(int row=0; row<ROWS+2; row++){
		free(earth[row]);
	}
}
