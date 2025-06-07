#include<stdio.h>
#include<string.h>
void main()
{
char s[50],sub[10],*p;
printf("Enter the string \n");
scanf("%s",s);
printf("Enter the substring\n");
scanf("%s",sub);
p=strstr(s,sub);
int l=strlen(sub);
strcpy(p,p+l);
printf("%s\n",s);

}
