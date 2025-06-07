#include<stdio.h>
void main()
{
int a[5]={60,20,30,40,50};
int ele;
int l=a[0];
ele=sizeof(a)/sizeof(a[0]);
for(int i=1;i<ele;i++)
{
if(a[i]<l)
l=a[i];



}
printf("%d \n",l);


}
