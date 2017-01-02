
#include <stdio.h>

int main(int argc, char ** argv)
{     
      int i=1;
      top:
	if(i < argc)
	{
        	printf("%s\n", argv[i++]);
		goto top;
	}
     	return 0;
 }

