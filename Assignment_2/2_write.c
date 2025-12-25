#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char filename[256];
    char input[512];
    int fd, bytes;

    // Input file name
    printf("Enter file name: ");
    scanf("%255s", filename);

    getchar(); // clear leftover newline

    // Input string
    printf("Enter string to write: ");
    fgets(input, sizeof(input), stdin);

    // Open file in append mode
    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Write string using write()
    bytes = write(fd, input, strlen(input));
    if (bytes == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    printf("Written %d bytes to %s\n", bytes, filename);

    close(fd);
    return 0;
}