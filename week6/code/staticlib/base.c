#include"stasticlib.h"
void initarray(int * a,int n)
{
	int i,k;
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
	}

}
void showarray(int * a,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%4d  :  %4d",i,a[i]);
}
