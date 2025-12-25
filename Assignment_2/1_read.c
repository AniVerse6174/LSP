#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char filename[256];
    int fd;
    char buffer[512];  // buffer size for each read
    int bytesRead, totalBytes = 0;

    // Input file name
    printf("Enter file name: ");
    scanf("%255s", filename);

    // Open file in read-only mode
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read and print file content in chunks
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
        totalBytes += bytesRead;
    }

    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    // Show total bytes read
    printf("\n\nTotal bytes read: %d\n", totalBytes);

    close(fd);
    return 0;
}