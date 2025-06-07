#include"header.h"
void * thread_1(void *ptr)
{
	while(1)
		printf("In THread\n");
}
int main()
{
	pthread_t t1;
	printf("Before..\n");
	pthread_create(&t1,0,thread_1,0);
	printf("After...\n");
	
}
