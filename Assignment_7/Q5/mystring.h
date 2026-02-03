#ifndef MYSTRING_H
#define MYSTRING_H

int MyStrlen(const char *);
char *MyStrcpy(char *, const char *);
char *MyStrncpy(char *, const char *, int);
char *MyStrcat(char *, const char *);
int MyStrcmp(const char *, const char *);
int MyStrncmp(const char *, const char *, int);
char *MyStrrev(char *);
char *MyStrchr(const char *, char);

#endif