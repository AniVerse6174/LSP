#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    char srcDir[256], destDir[256];
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    char srcPath[512], destPath[512];
    int moved = 0;

    // Input source and destination directories
    printf("Enter source directory: ");
    scanf("%255s", srcDir);
    printf("Enter destination directory: ");
    scanf("%255s", destDir);

    dir = opendir(srcDir);
    if (dir == NULL) {
        perror("Error opening source directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Build full paths
        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        // Check if regular file
        if (stat(srcPath, &fileStat) == -1 || !S_ISREG(fileStat.st_mode))
            continue;

        // Try rename()
        if (rename(srcPath, destPath) == 0) {
            moved++;
            continue;
        }

        // If rename fails, do copy + delete
        int fd_src = open(srcPath, O_RDONLY);
        int fd_dest = open(destPath, O_WRONLY | O_CREAT | O_TRUNC, fileStat.st_mode);
        if (fd_src == -1 || fd_dest == -1) {
            if (fd_src != -1) close(fd_src);
            if (fd_dest != -1) close(fd_dest);
            continue;
        }

        char buffer[512];
        ssize_t bytes;
        while ((bytes = read(fd_src, buffer, sizeof(buffer))) > 0)
            write(fd_dest, buffer, bytes);

        close(fd_src);
        close(fd_dest);
        unlink(srcPath);  // delete original
        moved++;
    }

    closedir(dir);

    // Final-
    printf("Moved %d files from %s to %s\n", moved, srcDir, destDir);
    return 0;
}