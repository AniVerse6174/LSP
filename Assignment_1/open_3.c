#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {

    char filename[256];
    char mode[10];
    int result, flags;


    printf("Enter file name to open: \n"); //Take file name from the user
    scanf("%255s", filename);

    printf("Enter mode (read/write/execute): ");
    scanf("%9s", mode);

    //Convert mode to flags and compare strings
    if (strcmp(mode, "read") == 0) {
        flags = R_OK;
    } else if (strcmp(mode, "write") == 0) {
        flags = W_OK;
    } else if (strcmp(mode, "execute") == 0) {
        flags = X_OK;
    } else {
        printf("Invalid mode\n");
        return 1;
    }

    result = access(filename, flags); // access() to check permission
    

    if (result == 0) {
        printf("Accessible: %s permission available for current process.\n", mode);
    } else {
         perror("Not Accessible ");

    }
       
    return 0;
}