#include"header.h"
void ls(char *path);
int main(int argc,char **argv)
{
	if(argc==1)
	{
		ls(".");
	}		
}
void ls(char *path)
{
	DIR *dp=opendir(path);
	if(dp==0)
	{
		perror("opendir");
		return;
	}
	struct dirent *p;
	while((p=reddir(dp))!=0)
	{
		printf("%s    ",p->d_name);
	}
}
