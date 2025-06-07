#include <iostream>
#include <fcntl.h>   // For fcntl()
#include <unistd.h>  // For open(), write(), close()
#include <cstring>   // For strerror()
using namespace std;

int main() {
    int fd = open("data.txt", O_WRONLY); // Open file for writing
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;   // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 10;       // Lock from byte 10
    lock.l_len = 20;         // Lock 20 bytes (10-29)

    cout << "Trying to set a write lock on bytes 10-29...\n";

    // Apply the lock
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error locking file");
        close(fd);
        return 1;
    }

    cout << "✅ Write lock set on bytes 10-29. Writing data...\n";
    lseek(fd, 10, SEEK_SET);
    write(fd, "LOCKED DATA HERE!", 17);

    cout << "Sleeping for 30 seconds while holding the lock...\n";
    sleep(30);  // Hold the lock for 30 seconds

    // Unlock after writing
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    cout << "🔓 Write lock released.\n";

    close(fd);
    return 0;
}

