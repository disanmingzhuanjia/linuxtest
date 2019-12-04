#include"my.h"
int main()
{
	pid_t pid1,pid2,pid3;
	int fd[2],rn,wn;
	char rbuf[30],wbuf[30];
	wbuf[0]='1';
	memset(rbuf,0,sizeof(rbuf));
	memset(wbuf,0,sizeof(wbuf));
	pipe(fd);
	pid1=fork();
	if(pid1<0)
	{
		perror("fork failed \n");
		return -1;
	}
	else if(pid1==0)
	{
		printf("fork pid1\n");
		close(fd[0]);
		printf("fork1 %d is writting.\n",getpid());
		for(int i=0;i<65536;i++)
		{
			wn=write(fd[1],wbuf,1);
			if(wn==-1)
			{
				printf("[child] write error.\n");
				break;
			}
		}
		close(fd[1]);
		exit(0);
	}
	else{
		wait(NULL);
		pid2=fork();
		if(pid2<0)
		{
			perror("fork failed \n");
			return -1;
		}
		else if(pid2==0)
		{
			printf("fork pid2\n");
			close(fd[1]);
			printf("fork2 %d is reading.\n",getpid());
			for(int i=0;i<65536;i++)
			{
				rn=read(fd[0],rbuf,1);
				if(rn==0)
				{
					printf("fork2 read error.\n");
					break;
				}
			}
			close(fd[0]);
			printf("%c",rbuf[0]);
			exit(0);
		}
		else{
			wait(NULL);
			pid3=fork();
			if(pid2<0)
			{
				perror("fork failed \n");
				return -1;
			}
			else if(pid3==0)
			{
				printf("fork pid3\n");
				exit(0);
			}
			else{
				wait(NULL);
				printf("parent fork end\n");
				return 0;
			}
		}
	}
}
