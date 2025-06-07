#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

void main(int c,char **ptr)
{
    if(c!=2)
    {
        printf("Usage:./a.out file name\n");
        return ;
    }
    struct stat v;
    if(stat(ptr[1],&v)<0)
    {   
        perror("stat");
        return;
    }
    printf("Inode=%ld\nctime=%smtime=%satime=%sPermission=%#o\n",v.st_ino,ctime(&v.st_ctime),ctime(&v.st_mtime),ctime(&v.st_atime),v.st_mode);
    
}
