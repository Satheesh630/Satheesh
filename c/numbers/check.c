#include <stdio.h>
#include <time.h>
void print_time() {
    time_t t;
    time(&t);
    printf("%s", ctime(&t));  // NOT THREAD-SAFE!
}
int main()
{

	print_time();
}

