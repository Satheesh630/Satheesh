#include<string.h>
#include<stdio.h>
int my_strlen(const char *);
void my_strcpy(const char *,char *);
void print(char *);
char * my_strchr(char*,char );
void my_strupr(char *);
int my_strcmp(const char *,const char *);
void my_strrev(char *);
void my_strnrev(char *,int,int);
void revword(char *);
void my_strcat(char *,char *);
void main()
{
char s[50],d[50],ch;
printf("Enter the string\n");
scanf("%[^\n]",s);
revword(s);
print(s);

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

void my_strcat(char *s,char *d)
{
int i;
s=s+strlen(s);
*s=' ';//to add space btwn two strings
while(*d)
{
*(s+1)=*d;
s++;d++;
}
*(s+1)=*d;

}







void my_strnrev(char *p,int index,int n)
{
int l=index+n;
if(l>strlen(p))
{
printf("Length Exceeded \n");
return;
}
p=p+index;
char *q;
q=p+n;
int i,t;
while(p<q)
{
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





int my_strcmp(const char*p,const char *q)
{
int i;
for(i=0;p[i];i++)
{
if(p[i] != q[i])
break;
}
return p[i]-q[i];
}








char* my_strchr(char *p,char ch)
{
int i;
for(i=0;p[i];i++)
{
if(p[i]==ch)
return &p[i];
}
return 0;
}








void print(char *s)
{//str print
	printf("%s\n",s);
}
void my_strcpy(const char *s,char *d)
{
	int i;
while(*s)
{
	*d=*s;
	s++;
	d++;
}
*d=*s;
}

int my_strlen(const char *p)
{//string length
	int i ;
	for(i=0;p[i];i++);
	return i;
}
void my_strupr(char *p)
{
	while(*p)
	{
		if(*p>='a' && *p<='z')
			*p=*p-32;
		p++;
	}
}
