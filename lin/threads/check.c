#include"header.h"
void * pthread_1(void *p)
{
	 static int i=100;
	while(1)
	{
	printf("Before i=%d\n",i);
	printf("In thread pid=%d\n",getpid());
		sleep(1);
	}
}
void main()
{
	pthread_t t1;
	pthread_create(&t1,0,pthread_1,0);;
	while(1)
	{
	printf("In main pid=%d ppid=%d \n",getpid(),getppid());
		sleep(1);
		pthread_exit(0);
	}
}
