#include"my.h"
int main()
{
	int fd[2];
	pid_t pid;
	if(signal(SIGPIPE,sighandler)==SIG_ERR)
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
		close(fd[1]);
		exit(0);
	}
	else{
	close(fd[0]);
	wait(NULL);
	int ret;
	ret=write(fd[1],"hello",5);
	if(ret==-1)
	{
		printf("[parent]:write failed error reason.[%s]\n",strerror(errno));
	}
	return 0;
	}

}
void sighandler(int signo)
{
	printf("[parent]:parent catch a SIGPIPE signal and signumber = %d\n",signo);
}
