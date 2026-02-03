#include <ctype.h>

int count_lower(const char *s) {
    int count = 0;
    while (*s) {
        if (islower(*s)) count++;
        s++;
    }
    return count;
}

int count_upper(const char *s) {
    int count = 0;
    while (*s) {
        if (isupper(*s)) count++;
        s++;
    }
    return count;
}

int count_digits(const char *s) {
    int count = 0;
    while (*s) {
        if (isdigit(*s)) count++;
        s++;
    }
    return count;
}