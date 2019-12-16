#include"mhead.h"
void creatfile_1(char *fname)
{
	
	umask(0000);
	 if( creat(fname,0777) < 0 ) {
        printf("文件创建失败！\n");
    } else {
        printf("文件创建成功！\n");
    }
}
void writefile_1(char *fname)
{
	int i = 0;
	FILE *fp = NULL;
	char a[100];
	gets(a);
	fp = fopen(fname,"r+");
	if (NULL == fp)
	{
		printf("func fopen() err:%s\n",fname);
		return;
	}
    fputs(a,fp);
	if (fp != NULL)
	{
		fclose(fp);
	}
	sleep(2);	
}
void readfile_1(char *fname)
{
	int i = 0;
	FILE *fp = NULL;
	char buf[100];
	char *p = NULL;
	fp = fopen(fname,"r");
	if (NULL == fp)
	{
		printf("func fopen() err:\n");
	}	while(!feof(fp))
	{
		p = fgets(buf,100,fp);
		printf("%s\n",p);
	}
	if (fp != NULL)
	{
		fclose(fp);
	}
	sleep(2);

}
