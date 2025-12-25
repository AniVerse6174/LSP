#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char dirname[256], filename[256];
    DIR *dir;
    struct dirent *entry;
    char fullpath[512];
    char absPath[512];

    printf("Enter directory name: ");
    scanf("%255s", dirname);

    printf("Enter file name to search: ");
    scanf("%255s", filename);

    dir = opendir(dirname);
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, filename) == 0) {
            snprintf(fullpath, sizeof(fullpath), "%s/%s", dirname, filename);

            if (realpath(fullpath, absPath) != NULL) {
                printf("File found: %s\n", absPath);
            } else {
                perror("Error for absolute path");
            }

            closedir(dir);
            return 0;
        }
    }

    closedir(dir);
    printf("File '%s' not found in '%s'\n", filename, dirname);
    return 0;
}