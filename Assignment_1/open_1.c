#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    char filename[256];
    int fd;

    printf("Enter file name to open: \n"); //Take file name from the user
    scanf("%255s", filename);  //1 byte reserved for null terminator(\0)

    fd = open(filename, O_RDONLY);  //open with Read-Only mode
    

    if (fd == -1) {
        perror("Error while opening file");
        return 1;
    }
    
    printf("File is opened with fd : %d\n", fd);

    //close(fd);
    return 0;
}