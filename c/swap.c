#include<stdio.h>
void main ()
{
float  a,b;
printf("Enter two numbers ....\n");
scanf("%f%f",&a,&b);
/*a=a+b;
b=a-b;
a=a-b;*/
b=a+b-(a=b);
printf("The swapped valuse are a=%f b=%f \n",a,b);


}

