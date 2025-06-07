#include<stdio.h>
#include<ctype.h>
int cp_cmd(const char *file)
{
	FILE *fps=fopen(file,"r");
	int c;
	if(fps==0)
	{
		printf("Unable to open file %s file\n",file);
		return -1;
	}
	
	char ch;
	while((ch=fgetc(fps))!=EOF)
	{
		if(!(isspace(ch)))
		c++;
	}
	return c;
}
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Usage:./a.out file\n");
		return;
	}
	int c=cp_cmd(argv[1]);
	printf("file %s size =%d\n",argv[1],c);
}
