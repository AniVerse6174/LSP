#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    int (*count_lower)(const char *);
    int (*count_upper)(const char *);
    int (*count_digits)(const char *);
    char *error, input[256];

    handle = dlopen("./libstr.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen failed: %s\n", dlerror());
        return 1;
    }
    

    count_lower = dlsym(handle, "count_lower");
    count_upper = dlsym(handle, "count_upper");
    count_digits = dlsym(handle, "count_digits");

    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "dlsym failed: %s\n", error);
        dlclose(handle);
        return 1;
    }


    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    printf("Lowercase letters: %d\n", count_lower(input));
    printf("Uppercase letters: %d\n", count_upper(input));
    printf("Digits: %d\n", count_digits(input));

    dlclose(handle);
    return 0;
}