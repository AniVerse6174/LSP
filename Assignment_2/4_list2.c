#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    char dirname[256];
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    char path[512];

    //Accept directory name-
    printf("Enter directory name: ");
    scanf("%255s", dirname);

    //Open directory
    dir = opendir(dirname);
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    printf("Files and types in '%s':\n", dirname);

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Build full path
        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

        // Use lstat to get file info
        if (lstat(path, &fileStat) == -1) {
            perror("lstat failed");
            continue;
        }

        // Determine file type
        printf("%s - ", entry->d_name);
        if (S_ISREG(fileStat.st_mode))      printf("Regular File\n");
        else if (S_ISDIR(fileStat.st_mode)) printf("Directory\n");
        else if (S_ISLNK(fileStat.st_mode)) printf("Symbolic Link\n");
        else if (S_ISFIFO(fileStat.st_mode))printf("FIFO (Named Pipe)\n");
        else if (S_ISSOCK(fileStat.st_mode))printf("Socket\n");
        else if (S_ISCHR(fileStat.st_mode)) printf("Character Device\n");
        else if (S_ISBLK(fileStat.st_mode)) printf("Block Device\n");
        else                                printf("Unknown Type\n");
    }

    closedir(dir);
    return 0;
}