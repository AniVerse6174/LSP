#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void print_indent(int depth) {
    for (int i = 0; i < depth; i++)
        write(1, "  ", 2);
}

void print_entry(const char *name, mode_t mode, int depth) {
    print_indent(depth);

    if (S_ISDIR(mode))
        printf("[D] %s\n", name);
    else if (S_ISREG(mode))
        printf("[F] %s\n", name);
    else if (S_ISLNK(mode))
        printf("[L] %s\n", name);
    else
        printf("[?] %s\n", name);
}

void traverse(const char *dirpath, int depth) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char path[512];

    dir = opendir(dirpath);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(path, sizeof(path), "%s/%s", dirpath, entry->d_name);

        if (lstat(path, &st) == -1)
            continue;

        print_entry(entry->d_name, st.st_mode, depth);

        // Recurse into subdirectories (but skip symlinks)
        if (S_ISDIR(st.st_mode) && !S_ISLNK(st.st_mode))
            traverse(path, depth + 1);
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(2, "Error: Provide a directory path to traverse.\n", 45);
        return 1;
    }

    traverse(argv[1], 0);
    return 0;
}
