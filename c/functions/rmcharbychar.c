#include<stdio.h>
#include<string.h>
void rmcharbychar(char*,char );
void main()
{
	char s[50],sub[10],t[20],ch;
	printf("Enter the string \n");
	scanf("%s",s);
	printf("Enter character\n");
	scanf(" %c",&ch);
rmcharbychar(s,ch);
printf("%s\n",s);




}
void rmcharbychar(char*s,char ch)
{
char *q,*p;
p=s;int n=0;
while(p=strchr(p,ch))
{
q=p+1;
if(n%2==0)
strcpy(p,q);
n++;
p=q;


}


}











/*while(p=strchr(s,ch))
{
strcpy(p,p+1);
}
printf("After %s\n",s);
*/

