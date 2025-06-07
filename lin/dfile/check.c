#include"header.h"
int main(int argc,char **argv)
{
	DIR *p=opendir(argv[1]);
	if(p==0)
	{
			perror("opendir");
			return 0;
	}
	struct dirent *dp;
		
		
		
			while(dp=readdir(p))
			{
				if((dp->d_name[0]) !='0')
				 	printf("%s\n",d p->d_name);
			}			
}
