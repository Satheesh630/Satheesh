#include<stdio.h>
void main()
{
	int k,num;
	char ch='z';
	printf("Enter a number...\n");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		k=3;
		for(int j=0;j<num-j;j++,ch--)
		{
			if(j%2==0)
			printf("%c",ch);
			else{printf("%d",k);k++;}
		}
		printf("\n");
	}
}
