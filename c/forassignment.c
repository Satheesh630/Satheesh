#include<stdio.h>
void main()
{
// Question 13
int i,c,j,num,k,sub=0;
	printf("Enter rows\n");
	scanf("%d",&num);//nu==5
k=1;
for(i=0;i<num;i++,k++)
{
for(j=0,sub=0;j<=i;j++)
{
printf("%d",k+sub);
sub=num-1-j;
}
printf("\n");
}
}
/*
Question 12
{
	int i,j,k,num;
	char ch;
	printf("Enter rows\n");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		for(k=0,ch=('A'+num-1);k<i;k++,ch--)
		{
			printf("*");
		}
		for(j=0;j<num-i;j++,ch--)
		{
			printf("%c",ch);
		}
		printf("\n");
	}


}*/
/*
QUestion 11
{
	int i,j,k,num;
	printf("Enter rows\n");
	scanf("%d",&num);
	k=num;
	for(i=0;i<num;i++,k--)
	{
		for(j=1;j<=num;j++)
		{
			if(j==k)
				printf("*");
			else
				printf("%d",j);
		}
		printf("\n");
	}

}

*/


/*
Question 10
{
//Question 10
int i,j,k,num;
char ch;
	printf("Enter rows\n");
	scanf("%d",&num);
for(i=0;i<num;i++)
{
for(j=0;j<num-i-1;j++)
printf("#");
printf(k=0,ch='A';k<=i;k++,ch++);
{
printf("%c",ch);
}
printf("\n");
}

}
*/
/*{
	//Question 9
	int i,j,k,num,c;
	char ch;
	printf("Enter rows\n");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		for(j=0,ch='A';j<num-1-i;j++,ch++)
			printf(" ");
		for(k=0,c=1;k<=i;k++,ch++)
		{
			if(i%2==0)
				printf("%c",ch);
			else
			{
				printf("%d",c);
				c++;
			}
		}
			printf("\n");
	}
}

*/

/*

Question 8
{
int i,j,k,num;
printf("Enter rows\n");
scanf("%d",&num);
for(i=0;i<num;i++)
{
k=num;
for(j=0;j<=i;j++,k--)
{
if(i%2==0)
printf("%d ",k);
else
printf("* ");
}
printf("\n");
}
}
*/
/*
QUESTION 7
{
int i,j,k,num;
char ch;
printf("Enter a number \n");
scanf("%d",&num);
for(i=0;i<num;i++)
{
for(j=0,k=1,ch='A';j<num-i;j++)
{
if(j%2==0)
{
printf("%c",ch);
ch++;
}
else 
printf("%d",k++);

}
printf("\n");
}
}

*/


/*
Question 6
{
int i,j,k,num;
printf("Enter a number \n");
scanf("%d",&num);
for(i=0;i<num;i++)
{
for(j=0,k=1;j<num-i;j++,k+=2)
{
if(i%2==0)
printf("*");
else
printf("%d",k);
}
printf("\n");
}
}

*/

/*

Question 5:
{
	int i,j,num;
	char ch;
	printf("Enter a number \n");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		for(j=0,ch='A';j<=i;j++,ch++)
		{
			if(j%2==0)
				printf("%c",ch);
			else
				printf("*");
		}
		printf("\n");
	}
}*/






/*
Question 4

{
int i,j,k,l,num;
printf("Enter column nuber \n");
scanf("%d",&num);
	for(i=0;i<num;i++)
	{k=1;
		for(j=0;j<i;j++,k+=2)
		{
			printf(" ");
		}
		for(l=0;l<num-i;l++,k+=2)
		printf("%d",k);
		printf("\n");
	}

}

*/



/*
Question 3
void main()
{
for(int i=1;i<=6;i++)
{
for(int j=1,k=1;j<=7-i;j++)
{
printf("%d ",j);
}
printf("\n");
}
}
*/


/*
Assignment 3
Question 2

void main(){
for(int i=0;i<5;i++)
{
for(int j=0,k=2;j<=i;j++)
{
printf("%d ",k);
k+=2;
}
printf("\n");
}
}
*/





/*
Assignment 3
 
Quesition 1

	void main()
	{
	for(int i=0;i<5;i++)
	{
	for(int j=0,k=1;j<i;j++)
	{
	printf("%d ",k);
	k+=2;
	}
	printf("\n");
	}

	}
*/
