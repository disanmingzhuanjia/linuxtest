#include"my.h"
static void __attribute__((constructor)) before_main()
{
	printf("-------before mian------\n");
}
static void __attribute__((destructor)) after_main()
{
	printf("-------after mian------\n");
}
int main()
{
	printf("main\n");
	return 0;
}
