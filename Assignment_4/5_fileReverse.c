#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int fd;
    off_t size;
    char ch;

    if (argc != 2) {
        write(2, "Error: Provide a file name to reverse.\n", 39);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    size = lseek(fd, 0, SEEK_END);
    if (size == -1) {
        perror("Error seeking to end");
        close(fd);
        return 1;
    }

    while (size > 0) {
        size--;
        if (lseek(fd, size, SEEK_SET) == -1) {
            perror("Error seeking backward");
            break;
        }

        if (read(fd, &ch, 1) == 1)
            write(1, &ch, 1);
    }

    close(fd);
    return 0;
}
