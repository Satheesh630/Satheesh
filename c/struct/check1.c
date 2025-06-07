#include<stdio.h>
#include<stdlib.h>
int * gym(int );
void main()
{
int *p=gym(10);
}
int* gym(int n)
{
int *p,i=10;
p=&i;
return p;
}
