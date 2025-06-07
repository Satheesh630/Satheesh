#include<stdio.h>
#include<stdlib.h>
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
int main()
{
	int r,c;
	printf("Rows and columns\n");
	scanf("%d %d",&r,&c);
	int **arr1=creat(r,c);
	printf("Enter first array elements\n");
	input(arr1,r,c);
	printf("Before\n");
	print(arr1,r,c);
	int **new=transpose(arr1,r,c);
	print(new,c,r);
	
}
