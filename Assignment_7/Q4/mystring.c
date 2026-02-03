#include "mystring.h"

int MyStrlen(const char *str) {
    if (str == NULL)
        return 0;

    int len = 0;
    while (str[len] != '\0')
        len++;

    return len;
}