#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main()
{
	int s,pid,pid1;
	if(pid=fork())
	{
	
		if(pid1=fork())
		{
		    int coll=waitpid(pid,&s,WUNTRACED);
		    printf("Collected =%d\n",coll);m0
		   printf("s=%d\n",s);
		   printf("WTERMSIG=%d\n",WTERMSIG(s));
		    
		}
		else
		{
		 while(1);
		}
	}
	else 
	{
		printf("In child\n");
		printf("child pid =%d \n",getpid()); 
		//sleep(2);
		 //raise(1);
		//exit(3);
		
	}
	      
}
