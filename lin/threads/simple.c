#include"header.h"
void * thread(void *p)
{
	while(1)
	{
		printf("In thread...%d\n",getpid());
	}
}
void main()
{
	pthread_t t,t1;
	pthread_create(&t,0,thread,0);
	pthread_create(&t1,0,thread,0);
	
	printf("In main...%d\n",getpid());
	 pthread_exit(0);

}
