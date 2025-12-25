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
    char largestFile[256] = "";
    off_t maxSize = 0;

    // Accept directory name-
    printf("Enter directory name: ");
    scanf("%255s", dirname);

    // Open directory
    dir = opendir(dirname);
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Build full path
        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

        // Get file info
        if (stat(path, &fileStat) == -1)
            continue;

        // Check if regular file and compare size
        if (S_ISREG(fileStat.st_mode) && fileStat.st_size > maxSize) {
            maxSize = fileStat.st_size;
            strncpy(largestFile, entry->d_name, sizeof(largestFile));
        }
    }

    closedir(dir);

    if (maxSize > 0)
        printf("Largest file: %s (%ld bytes)\n", largestFile, maxSize);
    else
        printf("No regular files found in directory.\n");

    return 0;
}