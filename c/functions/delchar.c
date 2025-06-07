#include<stdio.h>
#include<string.h>
void my_strcpy(const char *,char *);
void main()
{
char s[50],ch,*p;
printf("Enter the string \n");
scanf("%s",s);
printf("Enter character\n");
scanf(" %c",&ch);
printf("Before :%s\n",s);
while(p=strchr(s,ch))
{
my_strcpy(p+1,p);
}
printf("After :%s\n",s);






/*	char s[50],*p;
	printf("Enter the string \n");
	scanf("%s",s);
	char ch='a';            //deleting single character
	p=strchr(s,ch);
	my_strcpy(p+1,p);
	printf("%s\n",s);

*/
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


