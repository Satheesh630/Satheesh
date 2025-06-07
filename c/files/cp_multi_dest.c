#include<stdio.h>
void cp_cmd(int argc,char **argv)
{
	if(argc<3)
	{
		printf("Usage:./a.out src_file dest_file\n");
		return;
	}
	
	FILE *fps=fopen(argv[1],"r");
	if(fps==0)
	{
		printf("Unable to open file %s file\n",argv[1]);
		return;
	}
	
	for(int i=2;i<argc;i++)
	{
	
	
	FILE *fpd=fopen(argv[i],"w");
	char ch;
	if(fpd==0)
	{
		printf("Uable to open file %s\n",argv[i]);
		return;
	}
	while((ch=fgetc(fps))!=EOF)
	{
		if(fputc(ch,fpd)==EOF)
		{
			printf("Error Occured\n");
			return;
		}
	}
	rewind(fps);
	}
}
void main(int argc,char **argv)
{
	
	cp_cmd(argc,argv);
}
