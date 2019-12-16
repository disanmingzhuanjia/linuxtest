#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<limits.h>
#define NUM 4
struct sendval{
	int sum;
	double time;
};
