#include"my.h"
int mian()
{
	FILE *fp;
	time_t t;
	init_deamon();
	while(1)
	{
		sleep(5);
		if((fp=fopen("work.log","a+"))>=0)
		{
			t=time(0);
			fprintf(fp,"daemon is running,append time is :%S,pid=%d\n",astime(localtime(&t)),getpid());
			fclose(fp);
		}
	}
}
