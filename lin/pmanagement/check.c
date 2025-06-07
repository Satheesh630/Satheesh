#include"header.h"
void handler(int n)
{
	printf("Signal received=%d\n",n);
	alarm(1);
}
int main(int argc,char **argv)
{
	struct sigaction v;
	v.sa_handler=handler;
	sigemptyset(&v.sa_mask);
	v.sa_flags=0;
	
	sigaction(14,&v,0);
	signal(2,handler);
	alarm(2);
	printf("Hai....\n");
	while(1);
}
