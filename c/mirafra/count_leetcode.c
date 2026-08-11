#include<stdio.h>
#include<stdlib.h>
void rev(char *ptr)
{
	int i=0,j=strlen(ptr)-1;
	while(i<j)
	{
		char temp=ptr[i];
		ptr[i]=ptr[j];
		ptr[j]=temp;
		i++,j--;
	}
}
char * count_str(int n)
{
	char *ptr=calloc(200,sizeof(char));
	int i=0;
	int curr=n%10,count=1;
	n/=10;
	while(n)
	{

		if(n%10 == curr)
		{
			count++;
			n/=10;
		}else if(curr != n%10)
		{
			ptr[i++]=curr+48;
			ptr[i++]=count+48;
			count=0;	
			curr=n%10;
			n/=10;
		}
	}
	ptr[i++]=curr+48;
	ptr[i++]=curr+48;
	rev(ptr);
	printf("%s\n",ptr);
return ptr;
}
int main()
{
	count_str(1216);

}
