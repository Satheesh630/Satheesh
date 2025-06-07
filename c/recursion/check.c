#include<stdio.h>
int rec_fun_sum(int,int);
int rec_fun_product(int);
void main()
{
int num=rec_fun_sum(1234567,3);
printf("%d\n",num);



}
int rec_fun_product(int num)
{
if(num==0)
return 1;
int r=(num%10);
if((r%3)==0)
return r*rec_fun_product(num/10);
else
return rec_fun_product(num/10);

}



int rec_fun_sum(int num,int c)
{
static int i=0;
if(num==0||i>=c)
{
return 0;
}
i++;
return (num%10)+rec_fun_sum(num/10,c);


}


