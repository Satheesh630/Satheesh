#include"header.h"
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Usage:./a.out semnum\n");
		return;
	}
	
	int id=semget(3,5,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return;
	}
	printf("id=%d\n",id);
	int r=semctl(id,atoi(argv[1]),GETVAL);
	if(r<0)
	{
		perror("semctl");
		return;
	}
	printf("val=%d\n",r);
	
	
}
