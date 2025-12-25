#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main() {
    char dirname[256], path[512];
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    int count = 0;

    printf("Enter directory name: ");
    scanf("%255s", dirname);

    dir = opendir(dirname);
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

        if (stat(path, &fileStat) == -1)
            continue;

        if (S_ISREG(fileStat.st_mode) && fileStat.st_size == 0) {
            if (unlink(path) == 0) {
                printf("Deleted: %s\n", entry->d_name);
                count++;
            }
        }
    }

    closedir(dir);
    printf("Total empty files deleted: %d\n", count);
    return 0;
}