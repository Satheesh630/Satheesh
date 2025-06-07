#include<stdio.h>
struct st
{
int roll;
char name[20];
float marks;

};
void main()
{
struct st *p;
struct st v;
p=&v;
p->roll=10;
p->marks=20;

}
