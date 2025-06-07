#include<string.h>
#include<stdio.h>
void main()
{
char s[50];
printf("Enter the string \n");
scanf("%s",s);
char *p=strncpy(s+2,s,4);
printf("%s\n",s);



}
