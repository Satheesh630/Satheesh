#include"header.h"
void main()
{
	if(fork())
	{
	
	}
	else
	{
		  execlp("ls", "ls", "-l", NULL);
	}
}
