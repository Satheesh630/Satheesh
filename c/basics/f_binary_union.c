#include<stdio.h>
union u
{
	float f;
	unsigned int num;
}v;
int main()
{
char i=31;
scanf("%f",&v.f);
while(i>=0)
{
	printf("%d ->%d\n",i,(v.num>>i)&1);
	i--;
}

}
