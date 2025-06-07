#include<stdio.h>
#include<string.h>
#include<ctype.h>
void small_word(char* str,char *smallest)
{
	int min=100,i=0,j=0,len=0,flag=0;
	char word[30],*temp;
	while(1)
	{
		if(str[i]=='\0' || isspace(str[i]))
		{
			if(len>0 && len ==min)
			{
				if((strcmp(word,smallest)) <0 )
				{
					strcpy(smallest,word);
				}	
			}
			

			if(len>0 && len<min)
			{
				min=len;
				word[j]=0;
				strcpy(smallest,word);

			}
			j=0,len=0;
			if(str[i]=='\0')
				break;
			i++;

		}else
		{
			if(!flag)
			{
				temp=&str[i];
				flag=1;
			}
			word[j++]=str[i++];
			len++;
		}
	}
	printf("small pointer=%s\n",temp);
}
void main()
{
	char s[100],smallest[100];
	printf("Enter a string \n");
	fgets(s,sizeof(s),stdin);
	s[strcspn(s,"\n")]=0;
	small_word(s,smallest);
	printf("%s\n",smallest);

}
