#include"header.h"
void isr(int n)
{
	printf("%d In isr %s\n",n,strsignal(n));
}
int main()
{
	int p1[2],p2[2];
	pipe2(p1,O_NONBLOCK);
	perror("Pipe1");
	char ch='a';
	int c=0;
	while(write(p1[1],&ch,1)!=EOF )
	c++;
	printf("Count=%d\n",c);



/*	if(fork())
	{
		//write
		char buf[20];
		while(1)
		{
			//close(p1[0]);
			//close(p2[1]);
			printf("Enter a string In process 1\n");
			scanf("%s",buf);
			write(p1[1],buf,strlen(buf));	
			
			bzero(buf,20);
			read(p2[0],buf,20);
			printf("Read by process 1 data=%s\n",buf);
		}
	}else
	{
		char buf[20];
		while(1)
		{
			//close(p1[1]);
			//close(p2[0]);
			bzero(buf,20);
			read(p1[0],buf,20);
			printf("Read data in Process 2=%s\n",buf);
			
			printf("In process 2 Enter a string\n");
			scanf("%s",buf);
			write(p2[1],buf,strlen(buf));
		
		}		
	
	}
	
*/
}
