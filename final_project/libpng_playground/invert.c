#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define PNG_SETJMP_NOT_SUPPORTED
#include <png.h>

void _abort(const char *s,...){
	va_list args;
        va_start(args, s);
        vfprintf(stderr, s, args);
        fprintf(stderr, "\n");
        va_end(args);
        abort();
}

void read_png(char *f){
	FILE *fp = fopen(f,"rb");
	if()

}

int main(int argc, char **argv){
	if(argc!=3){
		printf("Not sufficient args! Program will exit.\n");
		return 1;
	}
	printf("Opening file %s\n",argv[1]);
	read_png(argv[1]);
}
