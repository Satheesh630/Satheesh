#include"header.h"
void main()
{
    int fd=open("data",O_WRONLY|O_CREAT|O_TRUNC,0664);
    if(fd<0)
    {
        perror("open");
        return;
    }
    struct sembuf v;
    v.l_type=WRLCK;
    v.l_whence=S
    
}
