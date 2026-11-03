#include<stdio.h>
#include<pthread.h>
void *task(void *arg)
{
	printf("Hello Im in Thead\n");
}
int main()
{
	pthread_t t1;
	pthread_create(&t1,NULL,task,NULL);
	pthread_join(t1,NULL);
	printf("Main finished\n");

}
