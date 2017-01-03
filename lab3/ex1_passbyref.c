#include <stdio.h>  
void square(int *num)//declaration of num ptr
{ 
	*num = *num * *num;
}  

int main()
{
 	int x = 4; 
	square(&x); 
	printf("%d\n", x); 
	return 0;
}
