#include"my.h"
int main()
{
	pid_t p;
	int fd[2],rn,wn,psize;
	char rbuf[30],wbuf[30];
	memset(rbuf,0,sizeof(rbuf));
	memset(wbuf,0,sizeof(wbuf));
	pipe(fd);
	//psize=fcntl(fd[0].?F_GETPIPE_SZ)
	//printf("pipe size =%d",psize);
	p=fork();
	if(p<0)
	{
		perror("fork failed \n");
		return -1;
	}
	else if(p==0)
	{
		close(fd[0]);
		sprintf(wbuf,"[chile %d] is running.\n",getpid());
		for(int i=0;i<65537;i++)
		{
			wn=write(fd[1],wbuf,1);
			printf("[child]%d write to pipe %d byte.\n",i,wn);
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
		close(fd[1]);
		while(1)
		{
			rn=read(fd[0],rbuf,sizeof(rbuf));
			printf("[parent] read from pipe %d byte.conten of pipe is %s\n",wn,rbuf);
			if(rn==0)
			{
				printf("[child] read error.\n");
				break;
			}
		}
		close(fd[0]);
		return 0;
	}
}

