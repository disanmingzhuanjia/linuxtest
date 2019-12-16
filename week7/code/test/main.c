#include"mhead.h"
int main()
{
	while(1){
	meunshow_1();
	int a;
	char c;
	scanf("%d%c",&a,&c);
	char str[20];
	switch(a)
	{
		case 0:exit(0);
		case 1:
		{
			printf("please input filename:");
			gets(str);
			creatfile_1(str);
			break;
		}
		case 2:
		{
			writefile_1(str);
		}
		case 3:
		{
			readfile_1(str);
		}
	}
	}

}
