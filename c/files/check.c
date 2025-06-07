#include<stdio.h>
void fun()__attribute__((constructor));
int main()
{
	FILE *fp=fopen("data","w+");
	int a[20]={1,2,3,4,5,3,2,3,4,2,3,3,34};
	for(int i=0;i<13;i++)
	{
		fwrite(a,4,13,fp);
	}
	int s[13];
	rewind(fp);
	fread(s,4,13,fp);
	for(int i=0;i<13;i++)
		printf("%d ",s[i]);
	printf("\n");
}
