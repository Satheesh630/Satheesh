#include<stdio.h>
void main()
{
	int n;
	printf("Enter How many numbers the binary is required..\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array elements..\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);


	for(int i=0;i<n;i++)
	{
		int num=a[i];
		for(int i=31;i>=0;i--)
			printf("%d",num>>i&1);
		printf("\n");
	}
}
