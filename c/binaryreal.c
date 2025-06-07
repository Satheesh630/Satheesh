#include<stdio.h>
void main()
{
float f;
int *ip;
printf("Enter float number...\n");
scanf("%f",&f);
ip=(int *)&f;
for(int i=31;i>=0;i--)
{
printf("%d",*ip>>i&1);
}
printf("\n");
}
