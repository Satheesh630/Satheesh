#include"header.h"
#include<sys/wait.h>
#include<sys/types.h>
void isr(int n)
{
    printf("In isr n=%d\n",n);
    exit(1);
}
int main()
{
 int i=0,pid;
if(pid=fork())
    {
    int i;
    printf("In parent pid=%d \n",getpid());
        if(fork())
        {
        printf("In parent pid=%d\n",getpid());
            if(fork())
            {
                printf("In parent pid=%d\n",getpid());
            }
            else {
            printf("In child ppid =%d pid=%d \n",getppid(),getpid());
            //exit(0);
            signal(2,isr);
            while(1);
            }
        }
        else{
        printf("In child ppid =%d pid=%d \n",getppid(),getpid());
        //exit(0);
        signal(2,isr);
        while(1);
        }
    
    waitpid(pid,WIFEXITED,0);
    printf("In parent i=%d===================================\n");
    } 
    else 
    {
        printf("In child ppid =%d pid=%d \n",getppid(),getpid());
        //exit();
        signal(2,isr);
        while(1);
    }     
     
}

