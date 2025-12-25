#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char filename[256];
    int fd, N;
    char buffer[1024];
    int bytesRead;

    printf("Enter file name: ");
    scanf("%255s", filename);

    printf("Enter number of bytes to read: ");
    scanf("%d", &N);

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    bytesRead = read(fd, buffer, N);         // Read up to N bytes (not more than buffer size)
    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    write(STDOUT_FILENO, buffer, bytesRead);        // Print only the bytes actually read

    close(fd);
    return 0;
}