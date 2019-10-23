#include<stdio.h>
int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	printf("hello");
	while(1);
}
