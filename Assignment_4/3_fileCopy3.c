#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int fd_src, fd_dest;
    char buffer[512];
    ssize_t bytesRead, bytesWritten;
    off_t offset = 0;

    if (argc != 3) {
        write(2, "Error: Provide <source> and <destination> file names.\n", 54);
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

    while ((bytesRead = pread(fd_src, buffer, sizeof(buffer), offset)) > 0) {
        bytesWritten = pwrite(fd_dest, buffer, bytesRead, offset);
        if (bytesWritten == -1) {
            perror("Error writing to destination file");
            close(fd_src);
            close(fd_dest);
            return 1;
        }
        offset += bytesRead;
    }

    if (bytesRead == -1)
        perror("Error reading source file");

    close(fd_src);
    close(fd_dest);
    return 0;
}
