#include"my.h"
int main()
{
	int ret;
	printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
	ret=system("./test 123 456");
	printf("After calling\n");
	sleep(100);
	return 0;
}
