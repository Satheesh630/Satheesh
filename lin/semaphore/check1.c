#include"header.h"
void main()
{
	int id=semget(3,2,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return ;
	}	
	semctl(id,1,SETVAL,1);
}
