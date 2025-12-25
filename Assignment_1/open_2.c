#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {

    char filename[256];
    char mode[10];
    int fd, flags = 0;


    printf("Enter file name to open: \n"); //Take file name from the user
    scanf("%255s", filename);

    printf("Enter mode (R/W/RW/A): ");
    scanf("%9s", mode);

    //Convert mode to flags and compare strings
    if (strcmp(mode, "R") == 0) {
        flags = O_RDONLY;
    } else if (strcmp(mode, "W") == 0) {
        flags = O_WRONLY | O_CREAT;
    } else if (strcmp(mode, "RW") == 0) {
        flags = O_RDWR | O_CREAT;
    } else if (strcmp(mode, "A") == 0) {
        flags = O_WRONLY | O_CREAT | O_APPEND;
    } else {
        printf("Invalid mode\n");
        return 1;
    }


    fd = open(filename, flags, 0644);  //open with Read-Only mode
    

    if (fd == -1) {
        perror("Error while opening file");
        return 1;
    }
    
    printf("File is opened with fd : %d\n", fd);

    close(fd);
    return 0;
}