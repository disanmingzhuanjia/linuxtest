#include"my.h"
void *foo(void * arg)
{
	printf("thread is running!\n");
	return (void*)0;
}
int main()
{
	pthread_t tid;
	int ret;
	ret=pthread_create(&tid,NULL,foo,NULL);
	if(ret)
	{
		perror("creat faailed\n");
		exit(1);
	}
	pthread_detach(tid);
	return 0;
}
