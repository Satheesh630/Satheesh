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
	int c=0;
	struct dirent *p;
	//struct dirent **p=calloc(1,sizeof(struct dirent *));
	while((p=readdir(dp))!=0)
	{
		if(p->d_name[0]=='.' || strcmp(p->d_name,"..")==0)
			continue; 
			c++;
	}
	rewinddir(dp);
	struct dirent **q=calloc(c,sizeof(struct dirent *));
	int i=0;
	while((p=readdir(dp)) !=0)
	{
		if(p->d_name[0]=='.' || strcmp(p->d_name,"..")==0)
			continue; 
		q[i]=p;
		i++;
	}
	
	
	
	
}











