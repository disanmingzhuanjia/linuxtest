#include"my.h"
int main()
{
	char c;
	FILE* fd;
	fd=fopen("out.dat","w+");
	int pid1,pid2,pid3,status,rv;
	pid1=fork();
	if(pid1<0)
	{
		perror("fork1 failed!\n");
	}
	else if(pid1==0)
	{
		printf("child1 pid=%d\n",getpid());
		fprintf(fd,"pid=%d 0123456789\n",getpid());
		sleep(3);
		exit(18);
	}
	else
	{
		pid2=fork();
		if(pid2==0){
				printf("child2 pid=%d\n",getpid());
				fprintf(fd,"pid=%d 0123456789\n",getpid());
				sleep(5);
				exit(99);
		}
		else{
				pid3=fork();
				if(pid3==0)
				{
					printf("child3 pid=%d\n",getpid());
					fprintf(fd,"pid=%d 0123456789\n",getpid());
					fclose(fd);
					sleep(2);
					exit(108);
				}
				else{
					printf("parent waitting child end!\n" );
					rv=wait(&status);
					printf("1:child %d end.exit code is %d\n",rv,WEXITSTATUS(status));
					rv=waitpid(pid1,&status,0);
					printf("2:child %d end.exit code is %d\n",rv,WEXITSTATUS(status));
					rv=waitpid(pid2,&status,0);
					printf("2:child %d end.exit code is %d\n",rv,WEXITSTATUS(status));
					fd=fopen("out.dat","r+");
					while(fscanf(fd,"%c",&c)!=EOF)
					printf("%c",c);		
					}
		}
	}
	
	return 0;
}
