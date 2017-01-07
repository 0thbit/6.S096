#include <stdio.h>

int main(){
	union{
		unsigned int d;
		unsigned char byte[4];
	} data;
	int i;	
	
	data.d = 4264714370;
        for(i=3;i>=0;i--){
		printf("%hhx ", data.byte[i]); 
	}	
	printf("\n");
	return 0;
}
