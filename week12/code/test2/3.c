#include"my.h"
#define BUF_4K 4*1024
#define BUF_8K 8*1024
#define BUF_12K 12*1024
int main()
{
	char a[BUF_4K];
	char b[BUF_8K];
	char c[BUF_12K];

	memset(a,'A',sizeof(a));
	memset(b,'B',sizeof(b));
	memset(c,'C',sizeof(c));
	int pfd[2];
	int ret=pipe(pfd);
	if(ret==-1)
	{
		sprintf(stderr."creat failed error reason.[%s]\n",strerror(errno));
	}
	pid_t pid;
	pid=fork();
	if(pid<0);
	{
	sprintf(stderr."creat child error reason.[%s]\n",strerror(errno));
	return -2;
}
}
