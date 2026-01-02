#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int fd_src, fd_dest;
    off_t offset;
    char buffer[512];
    ssize_t bytesRead, bytesWritten;

    if (argc != 4) {
        write(2, "Error: Provide <source> <destination> <offset>\n", 47);
        return 1;
    }

    offset = atoi(argv[3]);
    if (offset < 0) {
        write(2, "Error: Offset must be non-negative\n", 35);
        return 1;
    }

    fd_src = open(argv[1], O_RDONLY);
    if (fd_src == -1) {
        perror("Error opening source file");
        return 1;
    }

    fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dest == -1) {
        perror("Error opening destination file");
        close(fd_src);
        return 1;
    }

    if (lseek(fd_src, offset, SEEK_SET) == -1) {
        perror("Error seeking in source file");
        close(fd_src);
        close(fd_dest);
        return 1;
    }

    while ((bytesRead = read(fd_src, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(fd_dest, buffer, bytesRead);
        if (bytesWritten == -1) {
            perror("Error writing to destination");
            close(fd_src);
            close(fd_dest);
            return 1;
        }
    }

    if (bytesRead == -1)
        perror("Error reading source file");

    close(fd_src);
    close(fd_dest);
    return 0;
}
