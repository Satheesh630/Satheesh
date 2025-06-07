#include<stdio.h>
void main()
{
int i,j,*p;
p=calloc(5,4);
printf("%d\n",*(p+1));
}
