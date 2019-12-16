#include"my.h"
int arg=0;
void * foo(void *v)
{
	struct senval va1;
	struct timeval tv1,tv2;
	struct timezone tz;
	int n=(int )v,*sum,i;
	arg++;
	va1=(va1 *)malloc(sizeof(va1));
	printf("%d :global arg= %d\n",n,arg);
	int arg;
	arg=(n+1)*100000;
	gettimeofday(&tv1,&tz);
	for(int i=0;i<=arg;i++)
		*sum+=i;
	gettimeofday(&tv2,&tz);
	printf("%d :local arg= %d\n",n,arg);
	va1->time=tv2.tv_usec-tv1.tv_usec;
	va1->sum=sum;
	pthread_exit((void*)val);
}
int main()
{
	pthread_t tid[NUM];
	int rev[NUM],**pt;
	for(int i=0;i<NUM;i++)
	{
		rev[i]=pthread_create(&tid[i],NULL,(void *(*)())foo,(void*)i);
		if(rev[i]!=0)
		{
			perror("thread failed!\n");
			exit -1;
		}
		pthread_join(tid[i],(void **)&pt);
		printf("master %d:arg=%d,sum=%d\n",i,arg,*pt);
		
	}
}
