#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void list_files(const char *path) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *dir = opendir(path);
    
    if (!dir) {
        perror("opendir");
        return;
    }

    printf("\nContents of %s:\n", path);
    while ((entry = readdir(dir)) != NULL) {
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
        
        if (stat(fullPath, &fileStat) == 0) {
            printf("%s %s\n", (S_ISDIR(fileStat.st_mode)) ? "[DIR] " : "[FILE]", entry->d_name);
        }
    }
    closedir(dir);
}

void display_cpu_usage() {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("fopen");
        return;
    }
    
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), fp)) {
        printf("CPU Usage: %s", buffer);
    }
    fclose(fp);
}

int main() {
    char currentPath[1024];
    getcwd(currentPath, sizeof(currentPath));
    
    int choice;
    char newPath[1024];
    
    while (1) {
        printf("\n1. List Files\n2. Change Directory\n3. Show CPU Usage\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                list_files(currentPath);
                break;
            case 2:
                printf("Enter directory: ");
                scanf("%s", newPath);
                if (chdir(newPath) == 0) {
                    getcwd(currentPath, sizeof(currentPath));
                    printf("Changed to: %s\n", currentPath);
                } else {
                    perror("chdir");
                }
                break;
            case 3:
                display_cpu_usage();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

