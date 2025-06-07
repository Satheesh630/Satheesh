#include<stdio.h>
#include<string.h>
void main()
{
    char *p="-78p.5A88";
    float f;
    printf("decimal=%d addr=%p \n",atoi(&p),(int)&p);
    printf("float=%f\n",p);
   // printf("double=%d\n",p);    
           
}
