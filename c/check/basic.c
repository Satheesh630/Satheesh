#include<stdio.h>
void sum(int *ptr)
{
	int *str=&(*ptr);
	*str=300;
}
int main()
{
	int a=10;
	int *sub=&a;
	sum(&sub);
	printf("%d \n",a);

}
