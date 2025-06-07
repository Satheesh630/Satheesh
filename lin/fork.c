#include"header.h"
#include<wait.h>
void main()
{
 if(fork()==0)
 {
    printf("In child pid= %d ppid =%d\n",getpid(),getppid());
	
 }
 else 
 {  
     int s;
    printf("In parent  pid= %d ppid =%d\n",getpid(),getppid());
    wait(&s);
    printf("%d\n",s);
 }
}
