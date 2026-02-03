#include <stdio.h>

int hello() {
    printf("Hello from shared library!\n");
    return 0;
}

int fail() {
    
    return *(int *)0; 
}