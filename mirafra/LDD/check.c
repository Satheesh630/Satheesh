#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("/tmp/chintu_test.txt", "a");

    if (fp) {
        fprintf(fp, "a.out was executed by udev\n");
        fclose(fp);
    }

    return 0;
}
