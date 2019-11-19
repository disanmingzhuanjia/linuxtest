#include"my.h"
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		perror("failed fork!\n");
		return -1;
	}
	else if(pid==0)
	{
		printf("child %d is running\n",getpid());
		printf("child will exit\n");
		exit(120);
	}
	else
	{
		sleep(120);
		printf("parent is exit \n");
		return 0;
	}
}
