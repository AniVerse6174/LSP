#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    char dirname[256];
    DIR *dir;
    struct dirent *entry;

    // Accept directory name-
    printf("Enter directory name: ");
    scanf("%255s", dirname);

    // Open directory-
    dir = opendir(dirname);
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    printf("Files in directory '%s':\n", dirname);

    // Read entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}