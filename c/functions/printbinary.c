#include<stdio.h>
binary(int);
count(int);
void main()
{
	int num,c;
	printf("Enter a number \n");
	scanf("%d",&num);
	binary(num);
	c=count(num);
	printf("%d\n",c);
}
void binary(int n)
{
	int pos,i;
	for(pos=31;pos>=0;pos--)
		printf("%d",num>>pos&1);
	printf("\n");
}
int count(int num)
{
	int i,c=0,pos;
	for(i=0;i<=31;i++)
	{
		if(num>>pos&1)
			c++;
		return c;
	}
}

