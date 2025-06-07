#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
void main()
{
mkfifo("f1",0664);
int fd=open("f1",O_RDWR);
    char s[20];
    while(1)
    {
        bzero(s,sizeof(s));
        read(fd,s,sizeof(s));
        printf("Data=%s\n",s);
    
    }

}
