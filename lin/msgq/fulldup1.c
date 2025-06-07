#include"header.h"
struct buf
{
	long mtype;
	char data[20];
};
void main(int argc,char **argv)
{
	int id=msgget(1,IPC_CREAT|0666);
	struct buf v;
	if(fork())
	{
		
		
		while(1)
		{
			scanf("%s",v.data);
			v.mtype=3;
			msgsnd(id,&v,strlen(v.data)+1,0);
		
		}
	}
	else
	{
		while(1)
		{
			msgrcv(id,&v,sizeof(v.data),2,0);
			printf("\t%s\n",v.data);
		
		}
	
	
	}
}
