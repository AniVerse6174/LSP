#include "mystring.h"

int MyStrlen(const char *s) {
    int len = 0;
    while (s && s[len]) len++;
    return len;
}

char *MyStrcpy(char *dest, const char *src) {
    int i = 0;
    while ((dest[i] = src[i])) i++;
    return dest;
}

char *MyStrncpy(char *dest, const char *src, int n) {
    int i = 0;
    while (i < n && src[i]) {
        dest[i] = src[i];
        i++;
    }
    while (i < n) dest[i++] = '\0';
    return dest;
}

char *MyStrcat(char *dest, const char *src) {
    int i = 0, j = 0;
    while (dest[i]) i++;
    while ((dest[i++] = src[j++]));
    return dest;
}

int MyStrcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) s1++, s2++;
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int MyStrncmp(const char *s1, const char *s2, int n) {
    while (n-- && *s1 && (*s1 == *s2)) s1++, s2++;
    return n < 0 ? 0 : *(unsigned char *)s1 - *(unsigned char *)s2;
}

char *MyStrrev(char *s) {
    int i = 0, j = MyStrlen(s) - 1;
    while (i < j) {
        char t = s[i];
        s[i++] = s[j];
        s[j--] = t;
    }
    return s;
}

char *MyStrchr(const char *s, char c) {
    while (*s) {
        if (*s == c) return (char *)s;
        s++;
    }
    return NULL;
}