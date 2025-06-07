#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<signal.h>

void isr(int n)
{
	printf("N=%d signal Caught\n",n);

}


int main()
{
struct st
{
	int a ;
	char buf[20];
};
int a[2];
pipe(a);
struct st v;
if(fork())
{
	////read
	
	/*read(a[0],&v,sizeof(v));
	printf("int=%d  str=%s \n",v.a,v.buf);
	close(a[0]);

*/
if(fork()==0)
{
read(a[0],&v,sizeof(v));
	printf("int=%d  str=%s \n",v.a,v.buf);
	close(a[0]);

}
	
}else
{
//wrinte
//	close(a[0]);
signal(SIGPIPE,isr);
printf("Enter int str\n");
scanf("%d%s",&v.a,v.buf);
write(a[1],&v,sizeof(v));

}

	
}
