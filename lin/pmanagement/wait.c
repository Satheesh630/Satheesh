#include"header.h"
int main()
{
	if(fork())
	{
		printf("Before..\n");
		int r=wait(0);	
		printf("After..\n");
	}
	else
	{
		printf("In child..\n");
		sleep(2);
		raise(18);
	}
}
