#include <stdio.h>
#include "mystring.h"

int main() {
    char input[256];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    int len = MyStrlen(input);
    printf("Length: %d\n", len);

    return 0;
}