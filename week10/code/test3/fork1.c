#include"my.h"
int main()
{
	int fd;
	int id;
	char *a="parent:123456789";
	char *b="child:123456789";
	char *filename="test.txt";
	if((fd=open(filename,w+))==-1){
		perror("fopen");
		return ;
	}
	if((id=fork())==-1){//创建进程，失败返回-1
		perror("fork");
		return;
		}
	if(id==0){//子进程
		if(write(fd,a,strlen(a))<1)//write返回成功写入文件的字节数
				printf("write a error!\n");	
	}	
	else{//父进程		
	sleep(1);		
	if(write(fd,b,strlen(b))<1)//write返回成功写入文件的字节数
		printf("write b error!\n");
	}
	close(fd);
	return 0;
}

