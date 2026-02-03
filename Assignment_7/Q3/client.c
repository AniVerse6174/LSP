#include <stdio.h>
#include "display.h"

int main() {
    char input[256];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    Display(input);
    return 0;
}