#include<stdio.h>

void print(int (*ptr)[3])
{
	 for(int i=0;i<2;i++)
	 {
	 for(int j=0;j<3;j++)
	 printf("%d ",ptr[i][j]);
	printf("\n");
	}
}
void main()
{
	int a[2][3][2],i,j;
	for(i=0;i<2;i++)
	for(j=0;j<3;j++)
	for(int k=0;k<2;k++)
	scanf("%d",&a[i][j]);
	
	print(a);

}
