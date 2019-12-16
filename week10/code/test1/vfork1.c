#include"my.h"
int g=10;
int main()
{
	int t=20;
	static int s=30;
	pid_t pid;
	pid=vfork();
	if(pid<0)
	{
		perror("vfork failed!\n");
		exit(-1);
	}
	else if(pid==1)
	{
		printf("child:pid=%d:&g=%d,&t=%p,&s=%p\n",getpid(),&g,&t,&s,);
		g=100;
		t=200;
		s=300;
		printf("child:g=%d,t=%p,%s=%p\n",g,t,s,getpid());
		_exit(0);
	}
}
