#include<stdio.h>
void main()
{
	int num,k=4;
	printf("Enter number..\n");
	scanf("%d",&num);
	printf("%d\n",num);
	printf("%d Byte:",k);
	for(int i=31;i>=0;i--)
	{
		printf("%d",num>>i&1);
		if(i%8==0 && i!=0)
		{
			k--;
			printf("\n");
			printf("%d Byte:",k);
		}
	}
	printf("\n");

}
