#include <stdio.h>

void print_tri(int n){
	int out;
	out=(n*(n+1))/2;
	printf("%d ",out);
}

int main(){
	int i;
	for(i=0; i<100; i++){
		print_tri(i);
	}
	printf("\n");
	return 0;
}
