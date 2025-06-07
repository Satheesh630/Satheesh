#include<stdio.h>
void main()
{
	int a[]={10,10,35,63,52},ele,l;
	ele=sizeof(a)/sizeof(a[0]);
	int j=0,b[ele];
	while(j<ele)
	{
		int i=31,c=0;
		while(i>0)
		{
			if(a[j]>>i&1==1)
				c++;
			i--;
		}
		b[j]=c;
		j++;
	}
int i=0;
while(i<ele)
{
printf("%d ",b[i]);
i++;
}
}
/*
Question 8

int a[]={12,10,35,63,52},ele,num;
ele=sizeof(a)/sizeof(a[0]);
for(int i=0;i<ele;i++)
{
num=a[i];
num=num>>1;
a[i]=num;
printf("%d ",a[i]);


}
*/

/*

Question 7
int a[]={123,24,423,2323,423,32},num,ele,r,i,result,mul,t,count,j;
ele=sizeof(a)/sizeof(a[0]);	
for(i=0;i<ele;i++)
{
num=a[i];
printf(" %d:",a[i]);
for(j=31;j>=0;j--)
{
printf("%d",num>>j&1);
}
printf("\n");
}

}

*/

/* Question 6


	int a[]={123,24,423,2323,423,32},num,ele,r,i,result,mul,t,count,j;
	ele=sizeof(a)/sizeof(a[0]);	
	for(i=0;i<ele;i++)
	{
		result=0,mul=1,count=0;
		num=a[i];
		t=num;
		while(t){
			t/=10;
			count++;
		}
		for(j=1;j<count;j++)
		{
			r=num%10;
			result=result+r*mul;
			mul *=10;
			num /=10;
		}
		a[i]=result;
	}
	for(i=0;i<ele;i++){
		printf("%d ",a[i]);
		printf("\n");
	}
*/



/*
Question 5

	int a[]={123,24,423,2323,423,32},ele,r,sum=0,num,i;
	ele=sizeof(a)/sizeof(a[0]);
	for(i=0;i<ele;i++)
	{
		num=a[i];
		while(num)
		{
			r=num%10;
			num=num/10;
		}
		sum=r+sum;

	}
	printf("sum=%d\n",sum);

*/


/*
question 4


	int a[]={1,2,3,4,5,6},sum=0,i,ele;
	ele=sizeof(a)/sizeof(a[0]);
for(i=0;i<ele;i++)
{
sum +=a[i];
}
printf(" sum=%d \n",sum);	

*/


/*

Question 3

	int a[]={1,4,2,7,3,8,4,9},i,j,ele,t;
	ele=sizeof(a)/sizeof(a[0]);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3-i;j++)
		{
			if(a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}

	}





	for(i=0;i<ele;i++)
		printf(" %d",a[i]);
	printf("\n");




*/
