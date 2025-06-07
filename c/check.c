#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
int main(int argc,char **argv)
{
	if(argc<2)
	{
		printf("Usage:cr file_name\n");
		return 1;
	}

	if(access(argv[1],F_OK)==0)
	{
		if(fork()==0)
		{
				execlp("gedit","gedit",argv[1],"&",(char*)NULL);
				
		}
		wait(NULL);
		return 0;
	}
	else
	{
	int fd=open(argv[1],O_RDWR|O_CREAT,0664);
	if(fd<0)
	{
		printf("Can't open file\n");
		return 0;
	}
	char ch[40]="#include <stdio.h>\nint main()\n{\n\n}\n";
	write(fd,ch,strlen(ch));
	execlp("gedit","gedit",argv[1],"",(char*)NULL);
	close(fd);
	}

}

