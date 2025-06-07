#include <iostream>
#include <fcntl.h>  // For open()
#include <unistd.h> // For write() and close()
using namespace std;

int main() {
    int fd = open("data", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
	int k=3232;
	dprintf(fd, "%d", k);
	lseek(fd,0,SEEK_SET);
	char ch[4];
	read(fd,ch,4);
	cout<<ch<<endl;
    close(fd);
    return 0;
}

