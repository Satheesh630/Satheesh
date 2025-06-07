#include<dirent.h>
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
void main(int argc,char **argv)
{
    if(argc!=2)
    {
        printf("Usage:./a.out path\n");
        return;
    } 
    DIR *dp; 
    dp=opendir(argv[1]); 
    if(dp==0)
    {
        perror("opendir");
        return;
    }
    struct dirent *p;
    char s[100];
    struct stat v;
    while((p=readdir(dp)))
    {
        if(p->d_name[0]!='.')
        {
        
               
                strcpy(s,"/");
                strcpy(s,p->d_name);  
                lstat(s,&v	);
                printf("%ld  %ld  ",v.st_ino,v.st_size);
                printf("%s\n",p->d_name);
                                
        }
    }
    closedir(dp);
    
}
