#include<stdio.h>
void main()
{
int n;
printf("Enter the number of Array elements\n");
scanf("%d",&n);
int a[n];
printf("Enter the array elements\n");
for(int i=0;i<n;i++)
scanf("%d",&a[i]);

for(int i=0,j=n-1;i<j;i++,j--)
{
int t;
if(a[i]!=a[j])
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
for(int i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
}
