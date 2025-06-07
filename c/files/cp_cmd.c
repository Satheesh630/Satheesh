#include<stdio.h>
void cp_cmd(const char *src,const char *dest)
{
	FILE *fps=fopen(src,"r");
	if(fps==0)
	{
		printf("Unable to open file %s file\n",src);
		return;
	}
	FILE *fpd=fopen(dest,"w");
	if(fpd==0)
	{
		printf("Uable to open file %s\n",dest);
		return;
	}
	char ch;
	while((ch=fgetc(fps))!=EOF)
	{
		if(fputc(ch,fpd)==EOF)
		{
			printf("Error Occured\n");
			return;
		}
	}
}
void main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("Usage:./a.out src_file dest_file\n");
		return;
	}
	cp_cmd(argv[1],argv[2]);
}
