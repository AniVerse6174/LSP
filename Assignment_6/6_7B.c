#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    void (*modify)(int);
    void (*display)();
    void (*reset)();
    char *error;

    handle = dlopen("./libglobal.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen failed: %s\n", dlerror());
        return 1;
    }
    

    modify = dlsym(handle, "modify");
    display = dlsym(handle, "display");
    reset = dlsym(handle, "reset");

    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "dlsym failed: %s\n", error);
        dlclose(handle);
        return 1;
    }


    modify(5);
    display();

    modify(10);
    display();

    reset();
    display();

    dlclose(handle);
    return 0;
}