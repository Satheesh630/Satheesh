#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter number\n");
	scanf("%d%d",&a,&b);
	int result=0;
	while(b)
	{
		if(b&1)
			result+=a;
		a<<=1;
		b>>=1;	
	}
	printf("Multiplication:%d\n",result);
}
