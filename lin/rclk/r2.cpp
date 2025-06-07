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
    lock.l_type = F_WRLCK;   // Request write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 10;       // Try to lock bytes 10-29
    lock.l_len = 20;

    cout << "Trying to acquire write lock on bytes 10-29...\n";

    // Try to apply the lock (non-blocking)
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("❌ Lock failed: Another process is holding the lock");
        close(fd);
        return 1;
    }

    cout << "✅ Write lock acquired! Writing new data...\n";
    lseek(fd, 10, SEEK_SET);
    write(fd, "NEW DATA HERE!", 14);

    cout << "Sleeping for 5 seconds while holding the lock...\n";
    sleep(5);

    // Unlock after writing
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    cout << "🔓 Write lock released.\n";

    close(fd);
    return 0;

}

