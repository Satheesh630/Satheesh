#include<stdio.h>
void main()
{
int b[2][3]={{1,2,3},{4,5,6}};
int (*p)[3];
p=b;

printf("b=%u\n",b);
printf("p=%u\n",p);
printf("p+1=%u\n",p+1);
printf("*p=%u\n",*p);
printf("*p+1=%u\n",*p+1);


/*for(int i=0;i<2;i++)
{
for(int j=0;j<3;j++)
printf("%d ",p[i][j]);
printf("\n");
}*/
}
