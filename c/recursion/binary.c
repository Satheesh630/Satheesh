#include<stdio.h>
void binary(int);
void main()
{
	int n;
	printf("Enter number \n");
	scanf("%d",&n);
binary(n);
}
void binary(int n)
{
	static int i=31;
	if(i>=0)
	{
		printf("%d",(n>>i)&1);
		i--;
		binary(n);
	}
	else
		return;
}
