#include <stdio.h>

void amaze1()//for loop way
{ 	
	int i;
 	printf("amaze1:\t"); 	
	for (i = 0; i <= 10; i++) {
 		if (i % 2 == 1) {
 			printf("%d ", i); 
		} 
	} 
	printf("\n"); 
}

void amaze2()//goto way
{ 	
	int i=0;
 	printf("amaze2:\t"); 	
        top:
	if(i <= 10) {
 		if (i % 2 == 1) {
 			printf("%d ", i); 
		}
        i++;
	goto top; 
	} 
	printf("\n"); 
}

void amaze3()//while way
{ 	
	int i=0;
 	printf("amaze3:\t"); 	
	while(i <= 10) {
 		if (i % 2 == 1) {
 			printf("%d ", i); 
		}
	i++; 
	} 
	printf("\n"); 
}

void amaze4()//while way
{ 	
	int i=0;
 	printf("amaze4:\t"); 	
	do {
 		if (i % 2 == 1) {
 			printf("%d ", i); 
		}
	i++; 
	}
	while(i<=10); 
	printf("\n"); 
}

void amaze5()//forever way
{ 	
	int i=0;
 	printf("amaze5:\t");
	for(;;){ 	
		if (i % 2 == 1) {
 			printf("%d ", i); 
		}
		if(i<10){
			i++;
		} else{
			break;
		}
	}	
	printf("\n"); 
}

void amaze6()//while true way
{ 	
	int i=0;
 	printf("amaze6:\t");
	while(1){ 	
		if (i % 2 == 1) {
 			printf("%d ", i); 
		}
		if(i<10){
			i++;
		} else{
			break;
		}
	}	
	printf("\n"); 
}

void amaze7()//one third for way
{ 	
	int i=0;
 	printf("amaze7:\t");
	for(;i<=10;){ 	
		if (i % 2 == 1) {
 			printf("%d ", i); 
		}
	i++; 
	} 
	printf("\n"); 
}




///////////////////////
int main(int argc, char** argv){
	amaze1();
	amaze2();
	amaze3();
	amaze4();
	amaze5();
	amaze6();
	amaze7();
}


