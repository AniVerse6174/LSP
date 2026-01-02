#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int fd_out, fd_in;
    char buffer[512];
    ssize_t bytesRead, bytesWritten;

    if (argc < 3) {
        write(2, "Error: Provide <output_file> followed by input files in sequence to merge.\n", 63);
        return 1;
    }

    fd_out = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out == -1) {
        perror("Error opening output file");
        return 1;
    }

    for (int i = 2; i < argc; i++) {
        fd_in = open(argv[i], O_RDONLY);
        if (fd_in == -1) {
            perror("Error opening input file");
            continue;
        }

        while ((bytesRead = read(fd_in, buffer, sizeof(buffer))) > 0) {
            bytesWritten = write(fd_out, buffer, bytesRead);
            if (bytesWritten == -1) {
                perror("Error writing to output file");
                close(fd_in);
                close(fd_out);
                return 1;
            }
        }

        if (bytesRead == -1)
            perror("Error reading input file");

        close(fd_in);
    }

    close(fd_out);
    return 0;
}
