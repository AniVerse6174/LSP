#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    void (*greet)();
    char *error;

    handle = dlopen("libcustom.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen failed: %s\n", dlerror());
        return 1;
    }


    greet = dlsym(handle, "greet");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "dlsym failed: %s\n", error);
        dlclose(handle);
        return 1;
    }

    
    greet();
    dlclose(handle);
    return 0;
}