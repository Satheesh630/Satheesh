#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>
void main()
{
    struct rlimit v;
    getrlimit(RLIMIT_FSIZE,&v);
    printf("Stack: soft limit =%d,Hard limit=%d\n",(int)v.rlim_cur,(int)v.rlim_max);
    
}
