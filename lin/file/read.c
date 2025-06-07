#include"header.h"
#include<ctype.h>
void main()
{
 int fd=open("file",O_RDONLY);
 struct stat v;
 stat("file",&v);
 int size;
 printf("size of file=%ld\n",size=v.st_size);
    if(fd<0)
    {
        perror("open");
        return;
    }
    int *p=malloc(size);
    int c=0;
    while(read(fd,p,size)>0)
    {
        c++;
        printf("lines=%s c=%d\n",p,c);
    }
    lseek(fd,0,SEEK_SET);
    //printf("cont=%d\n",c);
    int fd1=open("file1",O_WRONLY|O_CREAT|O_TRUNC,0664);
    if(fd1<0)
    {
        perror("open");
        return;
    }
    write(fd1,p,size);
    
}
