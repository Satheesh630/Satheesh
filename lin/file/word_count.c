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
    int inword=0,count=0;
    char *ptr=p;
    while(*ptr)
    {
        if(*ptr==' '||*ptr=='\n')
        {
            inword=0;
        }
        else if(!inword)
        {
            count++;
            inword=1;
        }
        ptr++;
    }
    printf("coun=%d\n",count);
}
