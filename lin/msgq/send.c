#include"header.h"
void main(int argc,char **argv)
{
	int id=msgget(3,IPC_CREAT|0664);
	if(argc<3)
	{
		printf("Usage:./a.out key message\n");
		return;
	}
	
	struct st
	{
		long mtype;
		char data[20];
	}v;
	
	strcpy(v.data,argv[2]);
	v.mtype=atoi(argv[1]);
	msgsnd(id,&v,strlen(v.data),0);
	perror("msgsnd");
	
	
}
