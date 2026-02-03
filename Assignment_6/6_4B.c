#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    int (*func)();
    char *error;



    handle = dlopen("./libsimple.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen failed: %s\n", dlerror());
        return 1;
    }


    dlerror(); 
    func = dlsym(handle, "nonexistent_function");

    error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "dlsym failed: %s\n", error);
    } else {
        printf("Function result: %d\n", func());
    }

    dlclose(handle);
    return 0;
}