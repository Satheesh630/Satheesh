#include<stdio.h>
#include<string.h>
void revword(char *s);
void revsen(char*);
void my_strrev(char *);
void main()
{
	char s[50],sub[10],t[20],*p,ch;int n;
	printf("Enter the string \n");
	scanf("%[^\n]",s);
	revword(s);
	printf("%s\n",s);


}
void revsen(char *s)
{
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

//revword(s);

}



void revword(char *s)
{
char *p,*q,*l,*b,ch=' ';
p=s;
while(q=strchr(p,ch))
{
q--;                        //// abcd efgh ijklm
l=p;
b=q;
while(l<b)
{                              ////dcba hgfe mlkji
char t;
t=*l;
*l=*b;
*b=t;
l++;b--;
}
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
void my_strrev(char *p)
{
char *q,t;
int i;
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
