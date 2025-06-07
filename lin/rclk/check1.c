#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	char ch;
	int fd=open("data",O_WRONLY|O_CREAT|O_APPEND,0664);
	perror("open");
	
	lseek(fd,10,SEEK_SET);
	struct flock v;
	v.l_type=F_WRLCK;
	v.l_whence=SEEK_CUR;
	v.l_start=10;
	v.l_len=10;
	printf("Before...\n");
	fcntl(fd,F_WRLCK,&v);
	printf("After...\n");
	
	for(int i=0,ch='1';i<10;i++)
	{
		write(fd,&ch,1);
	}
}

