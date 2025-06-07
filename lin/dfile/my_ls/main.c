#include"header.h"
void ls_void() ;
void rm_lastword(char *ptr);
void bit(short int mode);
void file_info(int argc,char **argv);
void sort_names(struct dirent **arr,int n);
void print_names(struct dirent **arr,int n);
void main(int argc,const char **argv)
{
	if(argc==1)
		ls_void(".");
	
		
	
}
void file_info(int argc,char **argv)
{
	int c=0;
	
		DIR *dp=opendir(argv[1]);
		if(dp==0)
		{
			perror("opendir");
			return;
		}
		struct dirent *p;
		while(p=readdir(dp))
		{
			if(strcmp(p->d_name,".") !=0 && strstr(p->d_name,"..") !=0) 
			c++;
		}	
		printf("%d",c);	
}



void ls_void(char *path)   // present working directory
{
	int c=0;
	DIR *dp=opendir(path);
		if(dp==0)
		{
			perror("opendir");
			return;
		}
		struct dirent *p;
	//	struct stat v;
	while((p=readdir(dp)))
	{
		
		if(strcmp(p->d_name,".")!=0 &&  strcmp(p->d_name,"..")!=0)
			c++;	
	}
	rewinddir(dp);
	struct dirent **arr;
	arr=calloc(c,sizeof(struct dirent*));
	int i=0;
	while((p=readdir(dp)))
	{
			if(strcmp(p->d_name,".") !=0 && strcmp(p->d_name,"..") !=0)
			{
				arr[i++]=p;
			}
			//arr[i++]=p;
	}
	//printf("C=%d\n",c);
	
	print_names(arr,c);
	
	
/*	for(int j=0;i<c;j++)
	{
		printf(
	}
	printf("\n")*/
}
void print_names(struct dirent **arr,int n)
{
	sort_names(arr,n);
		struct stat v;
		for(int i=0;i<n;i++)
		{
			lstat(arr[i]->d_name,&v);
			if(v.st_mode&S_IXUSR || v.st_mode&S_IXGRP || v.st_mode&S_IXOTH)
				printf(BOLDGREEN"%s  "RESET,arr[i]->d_name);
			else if(v.st_mode&S_IFMT==S_IFDIR)
				printf(BOLDBLUE"%s  "RESET,arr[i]->d_name);
			else
			printf("%s  ",arr[i]->d_name);
		}
		printf("\n");
}
//int argc,ch;
void sort_names(struct dirent **arr,int n)
{
	for(int i=0;i<n-1;i++)
	{
	int swapped=0;
		for(int j=0;j<n-1-i;j++)
		{
		
			if(strcmp(arr[j]->d_name,arr[j+1]->d_name)>0)
			{
				struct dirent *tmp;
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
				swapped=1;
			}
		}
		if(!swapped)
		break;
	}
}

void rm_lastword(char *ptr)
{
	char *tmp=strrchr(ptr,'/');
	if(tmp==0)
	{
		return;
	}
	*(tmp+1)='\0';	
}
void bit(short int mode)
{
	for(int i=15;i<=0;i--)
	{
		printf("%d ",(mode>>i)&1);
	}
}
