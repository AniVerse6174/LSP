#include <stdio.h>
#include <string.h>
#include "display.h"

void Display(char *str) {
    printf("String: %s\n", str);
    printf("Total characters: %lu\n", strlen(str));
}