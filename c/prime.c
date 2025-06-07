#include<stdio.h>
void main()
{
int i,j,n;

for(n=2;n<=35;n++)
{
	int c=0;
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
		{
			c++;
		}
	}
	if(c==0)
		printf("%d \n",n);

}
}
