#include<stdio.h>
void print_u32(unsigned num)
{
	char pos=31;
	while(pos>=0)
	{
		printf("%d",((num>>pos)&1));
		pos--;
	}
	printf("\n"); 
}
void print_u8(unsigned char num)
{
char i=7;
while(i>=0)
{
	printf("%d",(num>>i)&1);
	i--;
}
printf("\n");

}
void print_s8(char  num)
{
for(char ch=7;ch>=0;ch--)
{
	printf("%d ",((num>>ch)&1));
}
printf("\n");
}
void print_s32(int num)
{
	char pos=31;
	while(pos>=0)
	{
		printf("%d",((num>>pos)&1));
		pos--;
	}
	printf("\n"); 
}
void print_s16(short num)
{
	char pos=15;
	while(pos>=0)
	{
		printf("%d",((num>>pos)&1));
		pos--;
	}
	printf("\n"); 
}
void print_u16(unsigned short int  num)
{
	char pos=15;
	while(pos>=0)
	{
		printf("%d",((num>>pos)&1));
		pos--;
	}
	printf("\n"); 
}
//////////////////
void number2()
{
	char num=79,i=0,j=7;
	for(;i<j;i++,j--)
	{
		if(((num>>i)&1)!=((num>>j)&1))
		{
		num=num^(1<<i);
		num=num^(1<<j);
		}
	}
	print_u8(79);
	print_u8(num);
}
void number3()
{
///A given number is divisible by 8
	int num;
	printf("Enter a number\n");
	scanf("%d",&num);
	(num&0x7)?printf("Not devisible by 8\n"):printf("Divisible by 8\n");
}
///////////////////
void number4()
{
	short  number;
	printf("Enter a number only signed\n");
	scanf("%hd",&number);
	char i;
	printf("How many bits to rotate\n");
	scanf("%hhd",&i);
	printf("Before\n");
	print_s16(number);
	char bit;
	while(i>0)
	{
		i--;
		bit=(number&1);
		number=number>>1;
	
		if(bit==0)
		continue;
		
		number=(number|(bit<<15));
	}
	printf("After\n");
	print_s16(number);
}
void number5()
{
	unsigned num,left,right;
	char pos=2,bit=4;
	printf("Enter number\n");
	scanf("%u",&num);
	printf("Number=");
	print_u32(num);
	
	right=num&((1<<2)-1);
//	printf("%d\n",right);
	left=(num>>(pos+bit));
	left<<=pos;
//	printf("left=%d\n",left);
	num=left|right;
	printf("number=%d\n",num);
	print_u32(num);
}
void number6()
{
	printf("Enter a number\n");
	int num;
	scanf("%d",&num);
	printf("Before...\n");
	print_s32(num);
	printf("Enter how many bits to swap\n");
	int bit;
	scanf("%d",&bit);
	char i=0,j=31;
	for(int k=0;k<bit;k++,i++,j--)
	{
		if(((num>>j)&1) != ((num>>i)&1))
		{
			num=num^(1<<j);
			num=num^(1<<i);
		}
	}
	printf("After..\n");
	print_s32(num);
}
void number7()
{
	short int num;
	printf("Enter number in hex format\n");
	scanf("%hx",&num);
	printf("Before\n");
	print_u16(num);
	num|=0xf;
	num=num^0xf00;
	print_u16(num);
}
void number8()
{
	int num;
	printf("Enter  a number...\n");
	scanf("%d",&num);
	int sum=0,tmp;
	while(num)
	{
		tmp=num%10;
		if((tmp&1)==0)
		{
			sum=sum+tmp;
		}
		num/=10;
	}
	printf("sum=%d\n",sum);
	
}	
void main()
{
	number8();
}




















