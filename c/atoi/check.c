#include<stdio.h>
#include<stdlib.h>
int my_atoi(const char *);
void main(int argc,char **argv)
{
int num;
num=atoi(argv[1]);
printf("num=%d\n",num);
}
