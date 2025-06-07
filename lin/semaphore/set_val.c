#include"header.h"
void main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("Usage:./a.out sem_num sem_val\n");
		return;
	}
	int id=semget(3,5,IPC_CREAT| 0664);
	if(id<0)
	{
		perror("semget");
		return;
	}
	printf("id=%d\n",id);
	int r=semctl(id,atoi(argv[1]),SETVAL,atoi(argv[2]));
	perror("semctl");
	printf("r=%d\n",r);
	
}
