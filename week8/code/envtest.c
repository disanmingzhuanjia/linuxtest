#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[],char *env[])
{
	int i=0;
	for(;env[i];i++)
	{
		printf("%s\n",env[i]);
	}
	printf("\n");
	extern char **environ;
	i=0;
	for(;environ[i];i++)
	{
		printf("%s\n",environ[i]);
	}
	printf("\n");
	printf("%s\n",getenv("PATH"));
	return 0;
}
