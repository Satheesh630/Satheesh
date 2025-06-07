#include<stdio.h>
#include<string.h>
void my_strcpy(const char*,char *);
int my_strlen(const char*);
void main()
{
	char s[50],sub[10],*p;
	printf("Ente string\n");
	scanf("%[^\n]",s);
	printf("Enter substring\n");
	scanf("%[^\n]",sub);
	while(p=strstr(s,sub))
	{
		int l=my_strlen(sub);
		my_strcpy(p+l,p);
	}
	printf("After %s\n",s);
}

int my_strlen(const char *p)
{//string length
	int i ;
	for(i=0;p[i];i++);
	return i;
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
