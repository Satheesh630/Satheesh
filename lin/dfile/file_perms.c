#include"header.h"
int main(int argc,char **argv)
{
	if(argc !=2)
	{
		printf("Usage:./a.out file_path\n");
		return 0;
	}
	DIR*dp=opendir(argv[1]);
		if(dp==0)
		{
			perror("opendir");
			return 0;
		}
	struct dirent *ptr;struct stat v;
	while(ptr=readdir(dp))
	{
		lstat(ptr->d_name,&v);
		printf("ino=%-8ld %-20s type=%-4d",v.st_ino,ptr->d_name,ptr->d_type);
		switch (v.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");
		
	}
	}
}
