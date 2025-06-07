#include<stdio.h>
void main()
{
	int a[10],i,j,ele;
	ele=sizeof(a)/sizeof(a[0]);
	for(i=0;i<ele-1;i++)
	{
		for(j=0;j<ele-1-i;j++)
		{
			int t;
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;

			}
		}
	}
	for(i=0;i<ele;i++)
		printf("%d ",a[i]);
	printf("\n");

}
