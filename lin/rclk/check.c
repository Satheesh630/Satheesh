#include"header.h"
void main()
{
	int fd=open("data",O_WRONLY|O_CREAT,0664);
	if(fd<0)
	{
		perror("open");
		return;
	}
	struct flock v;
	v.l_type=F_WRLCK;
	v.l_whence=SEEK_SET;
	v.l_start=10;
	v.l_len=10;
	printf("Before...\n");
	fcntl(fd,F_SETLKW,&v);
	perror("fcntl");
	printf("After...\n");
	char ch;
	for(int i=0,ch='1';i<26;i++)
	{
		write(fd,&ch,1);
		sleep(1);
		
	}
	v.l_type=F_UNLCK;

}
