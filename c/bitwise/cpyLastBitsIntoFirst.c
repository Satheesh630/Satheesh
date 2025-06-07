#include<stdio.h>
void print_bits(unsigned int num);
int tsk(unsigned int,int);
void main()
{

 print_bits(4294967294); 
 unsigned num=tsk(4294967294,1);
 //num<<=1;
 print_bits(num);
 
 
 // unsigned num=tsk(4294967294,4);
  //print_bits(num); 
     

}
int tsk(unsigned int num,int pos)
{

//num=4294967294,pos=4
    char bit;
    if(pos==0)
    {
        printf("Enter valid position >1\n");
        return num;
    }
    for(int i=0;i<pos;i++)
    {
        bit=(num>>31)&1;
        num =num<<1;
        num =num|bit;
    }

return num;
}
void print_bits(unsigned num)
{
    for(int i=31;i>=0;i--)
    {
        printf("%d ",(num>>i)&1);
    }
    printf("\n");
 }
