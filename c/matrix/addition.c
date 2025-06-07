#include<stdio.h>
#include<stdlib.h>
void main()
{
	int r,c;
	printf("Enter rows and columns\n");
	scanf("%d %d",&r,&c);
	if(r!=c)
	{
		printf("Rows and columns  should be equal\n");
		return;
	}
	int **arr1=calloc(r,sizeof(int *));
	for(int i=0;i<r;i++)
		arr1[i]=calloc(c,sizeof(int));
		
	printf("Enter 1St array elements\n");
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d",&arr1[i][j]);
			
	
	int **arr2=calloc(r,sizeof(int *));
	for(int i=0;i<r;i++)
		arr2[i]=calloc(c,sizeof(int));		
		
	printf("Enter 2nd  array elements\n");
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d",&arr2[i][j]);
		
		int **new=calloc(r,sizeof(int *));
		for(int i=0;i<r;i++)
			new[i]=calloc(c,sizeof(int));
		
	int i,j,k;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			for(k=0;k<r;k++)
			{
				new[i][j] +=arr1[i][k]*arr2[k][j];
			}
		}
	}
		
		
for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			printf("%d ",new[i][j]);
		printf("\n");
	}	
	
			
}










