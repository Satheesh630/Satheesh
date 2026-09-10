#include<stdio.h>
#include<stdbool.h>
#define SIZE 3
typedef struct buf
{	
	int buffer[SIZE];
	int head,tail;
}circularbuffer;
void init(circularbuffer * cb)
{
	cb->head=0;
	cb->tail=0;
}
bool is_full(circularbuffer *cb)
{
	return cb->head == (cb->tail+1)%SIZE;
}
bool is_empty(circularbuffer *cb)
{
	return cb->head==cb->tail;
}
void display(circularbuffer *cb)
{
	if(is_empty(cb))
	{
		printf("Buffer is empty\n");
		return;
	}
	int i=0;
	while(((cb->head+i)%SIZE) != (cb->tail))
	{
		printf("%d ",cb->buffer[cb->head+i]);
		i++;
	}

}
bool enqueue(circularbuffer * cb, int  data)
{
	if(is_full(cb))
		return false;
	cb->buffer[cb->tail]=data;
	cb->tail=(cb->tail+1)%SIZE;
	return true;
}



int main()
{
	circularbuffer cb;
	init(&cb);
	enqueue(&cb,10);
	enqueue(&cb,20);
	if(!enqueue(&cb,13))
	{
		printf("Failed to enqueue\n");
	}
	display(&cb);	

}
