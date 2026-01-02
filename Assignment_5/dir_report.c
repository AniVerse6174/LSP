#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int file_count = 0, dir_count = 0;
off_t total_size = 0, max_size = 0;
char largest_file[512] = "";

void scan(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char fullpath[512];

    dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    dir_count++;  // count this directory

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (lstat(fullpath, &st) == -1)
            continue;

        if (S_ISREG(st.st_mode)) {
            file_count++;
            total_size += st.st_size;

            if (st.st_size > max_size) {
                max_size = st.st_size;
                strncpy(largest_file, entry->d_name, sizeof(largest_file));
            }
        } else if (S_ISDIR(st.st_mode)) {
            scan(fullpath);  // recurse
        }
        // symlinks and others are ignored
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(2, "Error: Provide a directory path.\n", 33);
        return 1;
    }

    scan(argv[1]);

    printf("Files : %d\n", file_count);
    printf("Dirs  : %d\n", dir_count);
    printf("Total Size : %ld bytes\n", total_size);
    if (max_size > 0)
        printf("Largest : %s (%ld bytes)\n", largest_file, max_size);

    return 0;
}
