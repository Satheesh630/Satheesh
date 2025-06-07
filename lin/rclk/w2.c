#include"header.h"
void main()
{
	int fd;
	fd=open("data",O_WRONLY|O_CREAT|O_APPEND,0664);
	struct flock v;
	v.l_type=F_WRLCK;
	v.l_whence=SEEK_SET;
	v.l_start=0;
	v.l_len=0;
	printf("Before..\n");
	fcntl(fd,F_SETLKW,&v);
	printf("After...\n");
	for(char ch='A';ch<='Z';ch++)
	{
		write(fd,&ch,1);
		sleep(1);
	}
	v.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&v);
	
	
}
