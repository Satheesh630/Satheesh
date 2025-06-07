#include<stdio.h>
#include<stdlib.h>
int **transpose(int **array,int r,int c)
{
	int **new=calloc(c,sizeof(int*));
	for(int i=0;i<c;i++)
		new[i]=calloc(r,4);
	
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			new[j][i]=array[i][j];
			
	return new;
}	

int **creat(int r,int c)
 {
 	//r=3 c=3
 	int **arr=calloc(r,sizeof(int *));
 	for(int i=0;i<r;i++)
 		arr[i]=calloc(c,sizeof(int));
 	return arr;
 }
void input(int **array,int r,int c)
{
	for(int i=0;i<r;i++)
	for(int j=0;j<c;j++)
		scanf("%d",&array[i][j]);
}
void print(int **array,int r,int  c)
{
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
				printf("%d ",array[i][j]);
	printf("\n");
	}
}
void reverse(int **arr,int r,int c)
{
//c=3
//rows reversse
	for(int i=0;i<r;i++)
	{
		for(int j=0,k=c-1;j<c/2;j++,--k)
		{
			//if(arr[i][j] != arr[i][k])
			{
				int temp=arr[i][j];
				arr[i][j]=arr[i][k];
				arr[i][k]=temp;
			}
		}
	
	}
	
}
void reverse1(int **arr,int r,int c)
{
//c=3
//column rotation 
	for(int i=0;i<r;i++)
	{
		for(int j=0,k=c-1;j<c/2;j++,--k)
		{
			if(arr[j][i] != arr[k][i])
			{
				int temp=arr[j][i];
				arr[j][i]=arr[k][i];
				arr[k][i]=temp;
			}
		}
	
	}
}
void main()
{
	int r,c;
	printf("Enter rows and columns\n");
	scanf("%d %d",&r,&c);
	int **arr=creat(r,c);
	printf("Enter array elements\n");
	input(arr,r,c);
	print(arr,r,c);
	printf("Select the rotation\n");
	int op;
	printf("1.90 degree\n2.180 degree\n3.270 degree\n");
	scanf("%d",&op);
	switch (op)
	{
		case 1:
		{
			int **new=transpose(arr,r,c);
			reverse(new,c,r);
			print(new,c,r);
			break;
		}	
		case 2:
		{
			reverse(arr,r,c);
			reverse1(arr,r,c);
			print(arr,r,c);
			break;
		}
		case 3:
		{
			int **new=transpose(arr,r,c);
			reverse1(new,r,c);
			
			print(new,r,c);
			break;
		}
	}
	
}


















