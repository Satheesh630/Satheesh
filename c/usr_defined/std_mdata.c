#include<stdio.h>
#include<stdlib.h>
typedef struct st
{ 
  int roll;
  char name[20];
  float marks;
}std;
void main()
{
  int n;
  printf("Enter numer of students\n");
  scanf("%d",&n);
//  std *p[n];
  std **p=malloc(sizeof(std)*n);
  for(int i=0;i<n;i++)
  {
    p[i]=malloc(sizeof(std));
    printf("Enter roll name marks\n");
    scanf("%d %s %f",&p[i]->roll,p[i]->name,&p[i]->marks);
  
  }

  for(int i=0;i<n;i++)
  {
    printf("%d %s %f \n",p[i]->roll,p[i]->name,p[i]->marks);
    
  }  
  
   
	
}
