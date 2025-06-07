#include<stdio.h>
#include<unistd.h>
void main()
{
   if(fork())
   {
   printf("In parent pid =%d ppid =%d \n",getpid(),getppid());
   while(1);
   
   
   }
   else {
   printf("In child pid =%d ppid =%d \n",getpid(),getppid());
   while(1);
   }
}
