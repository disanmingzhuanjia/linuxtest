#include"uhead.h"

int main(){
    struct reg ret;
    int a[100],b[100],c[100];
    double t1,t2;
    char str1[]="./randow.dat";//随机数
    char str2[]="./syssort.dat";//系统排序 
    char str3[]="./usort.dat";//冒泡排序 
    uround(a,100);
    printf("生成随机数\n");
    ret=uoprater(a,100);
    show(a,100);
    printf("\n平均数为:%f,所有随机数的和为:%ld\n",ret.average,ret.sum);
    uwrite("random.dat",a,100);
    uread("random.dat",b,100);
    t1=working_time();
    syssort(b,100);//系统内置排序
    t1=working_time()-t1;
    printf("系统排序用时:%f s\n",t1);
    uwrite("syssort.dat",b,100);
    uread("random.dat",c,100);
    t2=working_time();
    usort(c,100);//冒泡排序
    t2=working_time()-t2;
    printf("冒泡排序用时:%f s\n",t2);
    uwrite("usort.dat",c,100);
    printf("查看文件中数组");
   system("cat random.dat");
    system("cat sysort.dat");
    system("cat usort.dat");
    return 0;

}
