#include"my.h"
int main()
{
	pid_t pid;
	int r,status;
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
		printf("parent waiting child %d to exit\n",pid);
		r=wait(&status);
		printf("child %d is finished with exit mode. exit code=%d\n",r,WEXITSTATUS(status));
		printf("parent is exit \n");
		return 0;
	}
}
