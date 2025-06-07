#include"header1.h"
void main()
{
    struct stat v,v1;
    stat("msgq",&v);
    printf("%ld\n",v.st_dev);
    //stat("header1.h",&v1);
    //printf("Header.h second=%d\n",v1.st_nlink);
}
