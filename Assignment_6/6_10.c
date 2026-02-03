#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char *argv[]) {
    void *handle;
    void *symbol;
    char *error;

    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <library_path> <symbol_name>\n", argv[0]);
        return 1;
    }



    handle = dlopen(argv[1], RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen failed: %s\n", dlerror());
        return 1;
    }

    // Clear errors
    dlerror();


    symbol = dlsym(handle, argv[2]);
    error = dlerror();

    if (error != NULL) {
        fprintf(stderr, "Symbol '%s' not found: %s\n", argv[2], error);
    } else {
        printf("Symbol '%s' found at address: %p\n", argv[2], symbol);
    }

    dlclose(handle);
    return 0;
}