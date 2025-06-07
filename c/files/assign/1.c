#include"header.h"
int main(int argc,char **argv)
{
	if(argc!=2){
		printf("Usage:./a.out file_name\n");
		return 1;
		}
		FILE * fd=fopen(argv[1],"r");
		if(fd==0)
		{
			perror("fopen");
			return 1;
		}
		char ch;
		while((ch=fgetc(fd))!=EOF){
			printf("%c",ch);
			}
		
	
}
