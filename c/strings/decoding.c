#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100

//12[a3[bc]]x3[ds]

void decode(char *str)
{
	char strstack[SIZE][SIZE];
	int stack[SIZE];
	char result[SIZE]="\0";
	int top=-1,i=0;
	while(str[i]!='\0')
	{
		if(isdigit(str[i]))
		{
			int num=0;
			while(isdigit(str[i])){
			num=num*10+(str[i]-'0');
			i++;
			}
			stack[++top]=num;
		}
		if(str[i]=='[')
		{
			strcpy(strstack[top],result);
			result[0]='\0';
			i++;
			
		}else if(str[i]==']')
		{
			int repeat=stack[top];
			char temp[SIZE];
			strcpy(temp,result);
			strcpy(result,strstack[top]);
			top--;
			for(int k=0;k<repeat;k++)
				strcat(result,temp);
			i++;
		}
		else{
			int len=strlen(result);
			result[len]=str[i];
			result[len+1]='\0';
			i++;
		}
	}
	printf("%s\n",result);
}

int main()
{
	printf("Enter a string :");
	char str[SIZE];
	scanf("%[^\n]",str);
	decode(str);

}
