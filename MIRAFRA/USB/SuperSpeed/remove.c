#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
void calc_freq(char *str,char *count)
{
	for(int i=0;str[i];i++)
	{
		count[str[i]]++;
	}
}
bool anag_pal(char *str)
{
	int len=strlen(str);
 	char count[256]={0};
	calc_freq(str,count);
	int flag=0;
	for(int i=0;i<256;i++)
	{
		if((count[i] %2 !=0) && flag){
				return false;
		}else if((count[i]%2 !=0) && flag==0)
		{
			flag=1;
		}
	}
	return true;
}

int main()
{  
        char str[100];
        printf("Enter a string: ");
        scanf("%s",str);
        bool ret=anag_pal(str);
        if(ret)
        {
                printf("The string is an anagram of a palindrome.\n");
        }
        else
        {
                printf("The string is not an anagram of a palindrome.\n");
        }
        return 0;
    }
