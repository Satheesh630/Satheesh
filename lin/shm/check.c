#include"header.h"
void main()
{
	int sid=shmget(3,10,IPC_CREAT|0664);
	printf("%d\n",sid);
	int *p;	
	p=(int *)shmat(sid,0,0);
	perror("shmat");
	printf("%d\n",*p);
	printf("Enter the data\n");
	scanf("%d",p);
}
