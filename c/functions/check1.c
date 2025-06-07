#include<stdio.h>
#include<string.h>
my_strrev(char *p
);
void main()
{

char s[50];
printf("Enter the characrter \n");
scanf("%[^\n]",s);


char *q,*p=s;
q=p;
q=q-1+strlen(p);
my_strrev(p);
while(p<q)
{
char t;
t=*p;
*p=*q;
*q=t;
p++;q--;
}

}

void my_strrev(char *p)
{
char *q,t;
zint i;
q=p;
while(*q)
{
q++;//holds \0 address
}
q--;
while(p<q)
{
t=*p;
*p=*q;
*q=t;
p++;
q--;
}

}


