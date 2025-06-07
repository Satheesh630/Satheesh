#include<stdio.h>
int count(int);
int fact3product(int);
int l3sum(int);//Question 5
void perfect(int);
void main()
{
perfect(7);
}
void perfect(int num)
{
	if(num==0)
		return;

	static int i=0,sum=0;
	i++;
	if(sum==num)
		{
			printf("Perfect\n");
			return;
		}
		else printf("Not perfect\n");
	if(i<num)
	{
if(num%i==0)
		{
			sum=sum+i;
			perfect(num);
		}
	}

}




int revnum(int num)
{
	//Question 5
	static int rev=0;
	if(num==0)
		return rev;

	rev=(rev*10)+(num%10);
	return revnum(num/10); 

}


int l3sum(int num)
{
	//Question no 4 
	static int c=0;
	if(num==0)
		return 0;
	c++;
	if(c<=3)
		return (num%10)+l3sum(num/10);
	else return 0;
}




int fact3product(int num)
{
	//Question 3
	if(num==0)
		return 1;
	if((num%10)%3==0)
		return (num%10)*fact3product(num/10);
	else
		return fact3product(num/10);

}

int count(int num)
{//Question no 2
	if(num==0)
		return 0;
	int r=num%10;
	static int c=0;
	if(r<6)
	{
		c++;
		count(num/10);
	}
	else
		count(num/10);

	return c;


}
