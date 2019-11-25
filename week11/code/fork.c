#include"my.h"
#include"fun.c"
int main()
{	
	FILE *fp;
	fp = openFile();
	pid_t pid;
	pid = fork();
	if(pid<0){
		perror("fork failed!\n");
		exit(-1);
	}else if(pid==0){
		printf("child:pid=%d.begin write in file.dat.\n",getpid());
		writeFile(fp);
		//return 0;
		exit(0);
		//_exit(0);
	}else{
		printf("parent:pid=%d.begin write in file.dat.\n",getpid());
		writeFile(fp);
		return 0;
	}
}
