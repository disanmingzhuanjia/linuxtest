#include"my.h"
int main()
{
	int fd[2];
	pid_t pid;
	if(pipe(fd)==-1)
	{
		fprintf(stderr,"create child error.reason:[%s]",strerror(errno));
	}
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr,"create child error.reason:[%s]",strerror(errno));
	}
	else if(pid==0)
	{
		printf("[child]:pid=%d,ppid=%d\n",getpid(),getppid());
		sleep(50);
		exit(0);
	}
	else{
	wait(NULL);
	return 0;
	}

}
