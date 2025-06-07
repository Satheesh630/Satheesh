#include"header.h"
void main()
{

	
	int id=msgget(3,IPC_CREAT|0666);
	
	struct st
	{
		long mtype;
		char data[30];
	}v={2};	
	while(1)
	{
	bzero(v.data,sizeof(v.data));
	msgrcv(id,&v,sizeof(v.data),v.mtype,0);
	
	
	printf("Received data = %s\n",v.data);
	
	}
}
