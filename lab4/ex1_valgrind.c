#include <stdlib.h> 
#include <stdio.h> 
  
void fn()
{ 
	int* x = (int *)malloc(11 * sizeof(int)); 
	 
	x[10] = 0;
	printf("%d",*(x+10));
	free(x);
}  

int main()
{ 
	fn(); 
	return 0;
}
