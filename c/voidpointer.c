#include<stdio.h>
void main()
{
int i=10;
char ch='a';
double d=23.44;
float f=32.234;
void *p;
p=&i;
printf("i=%d *p=%d\n",i,*(int *)p);

p=&ch;
printf("ch=%c *p=%c\n",ch,*(char *)p);
p=&d;
printf("d=%le *p=%le\n",d,*(double *)p);
p=&f;
printf("f=%f *p=%f\n",f,*(float *)p);
}
