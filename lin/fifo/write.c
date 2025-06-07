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

    printf("Enter string\n");
    scanf("%s",s);
        write(fd,s,strlen(s));
    
    }

}
