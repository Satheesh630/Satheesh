#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
void fun(int n)
{
    printf("Signal number=%d pid=%d ppid=%d \n",n,getpid(),getppid());
    while(1);    
}
int main()
{
    signal(1,fun);
    sleep(10);
    
    
    
}
