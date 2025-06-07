#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<stdarg.h>
#include<unistd.h>
typedef struct student
{
int rollno;
char name[20];
float marks;
struct student *next;//Address of next node
}sll;
void add_begin(sll**);
void print_node(sll *);
void save_file(sll *);
void add_end(sll **);
void read_file(sll **);

