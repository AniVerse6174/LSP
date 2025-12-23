#include <stdio.h>
#include <fcntl.h>


int main() {

    int fd = creat("/mnt/d/LSP/Assignments/Test.txt", 0644);
    
    if (fd == -1) {
        printf("Unable to create file");
    }
    else
    {
        printf("File is created with fd : %d\n",fd);
    }
    return 0;
}