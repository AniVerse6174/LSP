#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int fd_src, fd_dest;
    char buffer[512];
    ssize_t bytesRead, bytesWritten;

    // Check arguments
    if (argc != 3) {
        write(2, "Error: Please provide source and destination file names.\n", 57);
        return 1;
    }

    // Open source file
    fd_src = open(argv[1], O_RDONLY);
    if (fd_src == -1) {
        perror("Error opening source file");
        return 1;
    }

    // Open or create destination file (truncate if exists)
    fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dest == -1) {
        perror("Error opening destination file");
        close(fd_src);
        return 1;
    }

    // Copy loop
    while ((bytesRead = read(fd_src, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(fd_dest, buffer, bytesRead);
        if (bytesWritten == -1) {
            perror("Error writing to destination file");
            close(fd_src);
            close(fd_dest);
            return 1;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading source file");
    }

    close(fd_src);
    close(fd_dest);
    return 0;
}
