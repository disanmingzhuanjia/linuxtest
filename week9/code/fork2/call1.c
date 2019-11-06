#include"my.h"
int main()
{
	char *vector[]={"123","456","789",NULL};
	printf("call1:pid=%d,ppid=%d\n",getpid(),getppid());
	execvp("test4",vector);
	printf("-------after calling--------\n");
	return 0;
}
