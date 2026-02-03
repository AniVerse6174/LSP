#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    int (*funcs[4])(int, int);
    const char *names[] = {"add", "subtract", "multiply", "divide"};
    char *error;
    int a = 20, b = 5;

    handle = dlopen("./libmathops.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen failed: %s\n", dlerror());
        return 1;
    }

    
    for (int i = 0; i < 4; i++) {
        funcs[i] = dlsym(handle, names[i]);
        if ((error = dlerror()) != NULL) {
            fprintf(stderr, "dlsym failed for %s: %s\n", names[i], error);
            dlclose(handle);
            return 1;
        }
    }

    for (int i = 0; i < 4; i++) {
        printf("Function %s at %p → Result: %d\n", names[i], (void *)funcs[i], funcs[i](a, b));
    }

    dlclose(handle);
    return 0;
}