/*When ever the child gets terminated Parent gets the SIGCHILD Signal */
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
void isr(int n)
{
	printf("In Isr pid =%d n=%d\n",getpid(),n);
	int num=wait(&num);
	printf("Return Value by child =%d \n",num);
}
void main()
{
	if(fork()==0)
	{
		printf("In child pid=%d ppid=%d \n",getpid(),getppid());
		int num;
		printf("Enter the number\n");
		scanf("%d",&num);
		printf("Entered number =%d\n",num);
		while(1);
	}
	else
	{
			signal(SIGCHLD,isr);
			//while(1);
			sleep(10);		
	}
}
