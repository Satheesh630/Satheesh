#include"header.h"
void main()
{
	int id=shmget(3,50,IPC_CREAT|0664);
	printf("%d\n",id);
	char *p;
	p=shmat(id,0,0);
	printf("%s\n",p);
	
}
