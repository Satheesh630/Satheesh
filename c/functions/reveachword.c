#include<stdio.h>
#include<string.h>
void revword(char *s);
void main()
{
	char s[50],sub[10],t[20],*p,ch;int n;
	printf("Enter the string \n");
	scanf("%[^\n]",s);
	revword(s);
	printf("%s\n",s);


}
void revword(char *s)
{
char *p,*q,ch=' ';
p=s;
while(q=strchr(p,ch))
{
q=q-1;
char t;
t=*p;
*p=*q;
*q=t;
p=q+2;
}
q=p;
while(*q)
{
q++;
}
q--;
while(p<q)
{
char t;
t=*p;
*p=*q;
*q=t;
p++;q--;
}
}

