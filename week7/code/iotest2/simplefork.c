#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
int globa=4;
int main()
{
	pid_t pid;
	int vari=5;
	printf("globa=%d vari=%d\n",globa,vari);
	printf("before fork\n");
	if((pid=fork())<0){
		printf("fork error");
		exit(0);
	}
	else if(pid==0){
		globa++;
		vari--;
		printf("child change");
	}
	else
		printf("Parent did not changed\n");
	printf("globa=%d vari=%d\n",globa,vari);
	exit(0);
}
