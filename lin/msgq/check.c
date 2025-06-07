#include<stdio.h>
#include"header.h"
void 	 main()
{
	int id;
	id=msgget(1,IPC_CREAT|0666);
	if(id<0)
	{
		perror("msgget");
		return;
	}
	
}



