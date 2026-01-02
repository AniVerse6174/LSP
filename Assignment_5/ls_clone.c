#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void print_permissions(mode_t mode, char *perm) {
    strcpy(perm, "----------");

    if (S_ISDIR(mode)) perm[0] = 'd';
    else if (S_ISLNK(mode)) perm[0] = 'l';

    if (mode & S_IRUSR) perm[1] = 'r';
    if (mode & S_IWUSR) perm[2] = 'w';
    if (mode & S_IXUSR) perm[3] = 'x';
    if (mode & S_IRGRP) perm[4] = 'r';
    if (mode & S_IWGRP) perm[5] = 'w';
    if (mode & S_IXGRP) perm[6] = 'x';
    if (mode & S_IROTH) perm[7] = 'r';
    if (mode & S_IWOTH) perm[8] = 'w';
    if (mode & S_IXOTH) perm[9] = 'x';
}

const char* type_string(mode_t mode) {
    if (S_ISREG(mode)) return "file";
    if (S_ISDIR(mode)) return "dir";
    if (S_ISLNK(mode)) return "link";
    return "other";
}

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char path[512], perm[11];
    char timebuf[64];

    if (argc != 2) {
        write(2, "Error: Provide a directory path.\n", 33);
        return 1;
    }

    dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);

        if (stat(path, &st) == -1)
            continue;

        print_permissions(st.st_mode, perm);
        strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", localtime(&st.st_mtime));

        printf("%-20s %-6s %8ld %s %s\n",
               entry->d_name,
               type_string(st.st_mode),
               st.st_size,
               perm,
               timebuf);
    }

    closedir(dir);
    return 0;
}
