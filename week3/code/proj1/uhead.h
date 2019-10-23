#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
struct reg{
    long sum;
    float average;
};


void show(int *,int); 
void uround(int *,int);
struct reg uoprater(int *,int);
int comp(const void *a,const void *b);
void syssort(int *,int);
void usort(int *,int);
double working_time();
void uwrite(const char *,int *,int);
void uread(const char *,int *,int);
