#include<stdio.h>
int toconvert(int n)
{
	int mask=n>>31;
	return (mask+n)^mask;
}
int main()
{
	int x;
	printf("Enter:\n");
	scanf("%d",&x);
	printf("%d\n",toconvert(x));
}
