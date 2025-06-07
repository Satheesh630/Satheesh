#include<stdio.h>
#include<sys/stat.h>
void main(int argc,char **argv)
{
if(argc !=3)
{
    printf("Usage:./a.out file name file_name\n");
    return;
}
    struct stat v,v1;
    stat(argv[1],&v);
    stat(argv[2],&v1);
    
    if(v.st_ino==v1.st_ino)
    {
        lstat(argv[1],&v);
        lstat(argv[2],&v1);
        if(v.st_ino==v1.st_ino)
        {
            printf("Hard link\n");
             printf("Ctime=%s\n",ctime(&v.st_ctime));
            printf("Mtime=%s\n",ctime(&v.st_mtime));
            printf("Atime=%s\n",ctime(&v.st_atime));
            }
        else
        {
            printf("soft link\n");
            printf("Ctime=%s\n",ctime(&v.st_ctime));
            printf("Mtime=%s\n",ctime(&	v.st_mtime));
            printf("Atime=%s\n",ctime(&v.st_atime));
            }
    }
    else 
    printf("No link present\n");
    
}

