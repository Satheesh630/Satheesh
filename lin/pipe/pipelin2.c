#include"header.h"
void main(int argc,char **argv)
{
	if(argc<4)
	{
		printf("Usage:./a.out ls ls_optns grep_optns\n");
		return;
	}
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
		{//c-2 grep
			close(p[1]);
			dup2(p[0],0);
			execlp("grep","grep",argv[3],NULL);
			
		}
	}
	else
	{//c-1 ls
		close(p[0]);
		dup2(p[1],1);
		execlp(argv[1],argv[1],argv[2],NULL);
		
	
	}
}
