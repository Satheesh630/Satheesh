#include<stdio.h>
#include<time.h>

void my_function(void)
{
	int i=20;
	while(i--);
}
int main()
{
    struct timespec start, end;
    double elapsed_time;

    clock_gettime(CLOCK_MONOTONIC, &start);

    my_function();

    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("Execution time: %.9f seconds\n", elapsed_time);

    return 0;
}
