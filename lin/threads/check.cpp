#include<iostream>
//#include<pthread>
#include<unistd.h>
#include<string.h>
using namespace std;
struct st
{
	string s;
	char c[10];
};
void * fun(void *p)
{
	cout<<"In  thread"<<endl;
	cout<<(char *) p<<endl;
	char * result = new char[10];
	strcpy(result,"bye");
	sleep(2); 
	pthread_exit((void *) result);
}

int main()
{
	pthread_t t; 
	char a[]="hello";
	pthread_create(&t,0,fun,a);
	char* p;
	pthread_join(t,(void **)&p);
	
	cout<<(char *)p<<endl;

}













