#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
void isr(int n)
{
    printf("In isr pid=%d n=%d\n",getpid(),n);
    sleep(4);
}
void main()
{
    printf("In parent %d \n",getpid());
    struct sigaction v,v1;
    v.sa_handler=isr;
    sigemptyset(&v.sa_mask);
    v.sa_flags=SA_NODEFER;
    sigaction(2,&v,0);
    printf("Hai....\n");
  
    while(1);
    
}
