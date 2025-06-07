#include<stdio.h>
void main()
{
	double d;
	int *dp;
	printf("Enter a double number..\n");
	scanf("%le",&d);
	dp=(int *)&d;
	for(dp=dp+1;dp>=(int *)&d;dp--)
	{
		for(int i=31;i>=0;i--)
		{
			printf("%d",*dp>>i&1);
		}
	} 
	printf("\n");
}
