#include"header.h"
void main()
{
	int p[2];
	pipe(p);
	if(fork())
	{//p
		if(fork())
		{
			close(p[0]);
			close(p[1]);
			exit(0);
			exit(0);
		
		}
		else
		{//c-2 ls -e
			close(p[0]);//closing read end of the file
			dup2(p[1],1);//1 refers to p[1] and if 1 is referring to any file it is closed internally.
			execlp("ps","ps","-e",NULL);
			
		}
	}
	else
	{//c-1
		close(p[1]);//closing write end of the file
		dup2(p[0],0);
		execlp("grep","grep","tty1",NULL);	
	}	
}
