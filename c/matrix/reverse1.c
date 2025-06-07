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
void reverse(int **arr,int r,int c)
{
//c=3
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
int main()
{
	int r,c;	
	printf("Enter rws and columns\n");
	scanf("%d %d",&r,&c);
	
	int **arr=creat(r,c);
	//printf("arr=%ld arr[0]=%ld arr[0][0]=%ld \n",sizeof(arr),sizeof(arr[0]),sizeof(arr[0][0]));
	printf("Enter array elements\n");
	input(arr,r,c);
	print(arr,r,c);
	printf("\n\n");
	reverse(arr,r,c);
	print(arr,r,c);
	
}














