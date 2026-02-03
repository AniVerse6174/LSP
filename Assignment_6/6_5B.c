#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle_lazy, *handle_now;
    int (*hello)();
    char *error;


    handle_lazy = dlopen("./liblazy.so", RTLD_LAZY);
    if (!handle_lazy) {
        fprintf(stderr, "RTLD_LAZY failed: %s\n", dlerror());
    } else {
        printf("RTLD_LAZY: Library loaded successfully\n");
        hello = dlsym(handle_lazy, "hello");
        if ((error = dlerror()) == NULL) {
            hello();
        }
        dlclose(handle_lazy);
    }

    
    handle_now = dlopen("./liblazy.so", RTLD_NOW);
    if (!handle_now) {
        fprintf(stderr, "RTLD_NOW failed: %s\n", dlerror());
    } else {
        printf("RTLD_NOW: Library loaded successfully\n");
        dlclose(handle_now);
    }

    return 0;
}