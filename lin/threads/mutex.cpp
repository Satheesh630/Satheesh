#include<iostream>
#include<string.h>
//#include<mutex>
char  s[10];
pthread_mutex_t lock;

using namespace std;
void *thread_1(void *p)
{
	for(int i=0;i<5;i++)
	{
		s[i]='a'+i;
	}
	
}
void * thread_2(void *q)
{
	for(int i=5;i<10;i++)
	{
		s[i]='A'+i;
	}

}
int main()
{
	pthread_mutex_init(&lock,0);
	pthread_t t1,t2;

	pthread_create(&t1,0,thread_1,0);
	pthread_create(&t2,0,thread_2,0);
	pthread_join(t1,0);
	pthread_join(t2,0);
	for(int i=0;i<10;i++)
	cout<<s[i]<<" ";
	cout<<endl;
	
	
	
}
