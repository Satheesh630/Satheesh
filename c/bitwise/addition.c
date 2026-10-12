#include<stdio.h>
int main()
{
	int a ,b;
	printf("Enter numbers\n");
	scanf("%d%d",&a,&b);
	while(b)
	{
		int carry=(a&b)<<1;
		a=a^b;
		b=carry;
	}
	printf("Sum:%d\n",a);
}
