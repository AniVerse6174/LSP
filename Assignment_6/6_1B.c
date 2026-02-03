#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    int (*add)(int, int);
    int (*sub)(int, int);
    char *error;

    handle = dlopen("./libmathops.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }


    add = dlsym(handle, "Addition");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error: %s\n", error);
        dlclose(handle);
        return 1;
    }

    sub = dlsym(handle, "Substraction");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error: %s\n", error);
        dlclose(handle);
        return 1;
    }


    
    printf("Addition(10, 5) = %d\n", add(10, 5));
    printf("Substraction(10, 5) = %d\n", sub(10, 5));

    dlclose(handle);
    return 0;
}