#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter 2 numbers\n");
	scanf("%d%d",&a,&b);
	int borrow=0;
	while(b)
	{
		borrow=(~a&b)<<1;
		a=a^b;
		b=borrow;
	}
	printf("Difference:%d\n",a);
}
