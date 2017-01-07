#include<stdio.h>

int main(){

	struct X {
 		short s; //2B 
		int i; //4B
  		char c; //1B
	 }; 
	//  -- -- s1 s0  
	//  i3 i2 i1 i0
	//  -- -- -- c0
	// = 12B

	struct Y {
 		int i;
 		char c;
 		short s;
	 }; 
	//  i3 i2 i1 i0
	//  -- c0 s1 s0
	// = 8B

	struct Z { 	
		int   i;
 		short s; 	
		char  c;
	 };
	//  i3 i2 i1 i0
	//  -- s1 s0 c0	
	// = 8B
	
	struct X x;
	struct Y y;
	struct Z z;
 	printf("%zdB\n",sizeof(x));
	printf("%zdB\n",sizeof(y));
	printf("%zdB\n",sizeof(z));






	return 0;
}
