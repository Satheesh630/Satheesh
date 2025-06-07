#include<stdio.h>
#include<string.h>
void main()
{
	char s[50],sub[10],t[20],*p,ch;int n;
	printf("Enter the string \n");
	scanf("%s",s);
	printf("Enter character\n");
	scanf(" %c",&ch);
	printf("Enter where to add\n");
	scanf("%d",&n);
	p=s+n;
	strcpy(t,p);
	*p=ch;
	strcpy(p+1,t);
	printf("%s\n",s);
}
