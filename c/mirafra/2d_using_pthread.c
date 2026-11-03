#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<errno.h>
struct st
{
	int **matrix;
	int index;
	int rows,column;
};
void * allocate_colum(void *number)
{
	struct st *obj=(struct st *)number;
	obj->matrix[obj->index]=malloc(sizeof(int)*obj->column);	
	return NULL;
}
int ** allocate_mem_thread(int rows,int column)
{
	if(!rows || !column)
		return NULL;
	struct st *obj=malloc(sizeof(struct st) * rows);
	int **matrix=malloc(sizeof(int *)*rows);
	pthread_t list[rows];
	//obj.column=column;
	//Bug using only one structure can cause race condition either use mutex or seperate variables
	
	for(int i=0;i<rows;i++)
	{	
		obj[i].index=i;
		obj[i].matrix=matrix;
		obj[i].column=column;
		//pthread_create(&list[i],NULL,allocate_colum,&obj[i]);
		if (pthread_create(&list[i], NULL,allocate_colum, &obj[i]) != 0)
		{
			printf("Failed to create thread\n");
			perror("pthread:"); 
		   	return NULL;
		}

	}
	for(int i=0;i<rows;i++)
		pthread_join(list[i],NULL);
return obj->matrix;
}
int main()
{
	int rows,column;
	printf("Enter number of rows and columns\n");
	scanf("%d%d",&rows,&column);
	int ** matrix=allocate_mem_thread(rows,column);	
	if(!matrix)
	{
		printf("Matrix not created\n");
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<column;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<column;j++)
		{
			printf("%d ",matrix[i][j]);
		}

		printf("\n");
	}

}
