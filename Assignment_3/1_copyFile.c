#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char src[256], dest[256];
    int fd_src, fd_dest;
    char buffer[512];
    ssize_t bytesRead, bytesWritten, total = 0;

    // Input source and destination file names
    printf("Enter source file name: ");
    scanf("%255s", src);
    printf("Enter destination file name: ");
    scanf("%255s", dest);

    // Open source file for reading
    fd_src = open(src, O_RDONLY);
    if (fd_src == -1) {
        perror("Error opening source file");
        return 1;
    }

    // Open/create destination file for writing (truncate if exists)
    fd_dest = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dest == -1) {
        perror("Error opening destination file");
        close(fd_src);
        return 1;
    }

    // Copy loop
    while ((bytesRead = read(fd_src, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(fd_dest, buffer, bytesRead);
        if (bytesWritten == -1) {
            perror("Error writing to destination");
            close(fd_src);
            close(fd_dest);
            return 1;
        }
        total += bytesWritten;
    }

    if (bytesRead == -1) {
        perror("Error reading source file");
    } else {
        printf("Copied %zd bytes from %s to %s\n", total, src, dest);
    }

    close(fd_src);
    close(fd_dest);
    return 0;
}