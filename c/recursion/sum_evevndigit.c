#include<stdio.h>
int sumof_edigit(int);
void main()
{
	int i=sumof_edigit(12456);
	printf("%d\n",i);

}
int sumof_edigit(int num)
{
if(num)
return num%10+sumof_edigit(num/10);


}
