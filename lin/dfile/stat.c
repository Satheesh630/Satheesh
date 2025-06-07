#include"header.h"
void main(int argc,char **argv)
{
	if(argc !=2)
	{
		printf("Usage:./a.out path\n");
		return;
	}
	struct stat v;
	stat(argv[1],&v);
		printf("inode=%ld nlink=%ld\n",v.st_ino,v.st_nlink);
		
	lstat(argv[1],&v);
		printf("inode=%ld nlink=%ld\n",v.st_ino,v.st_nlink);
		 
}
