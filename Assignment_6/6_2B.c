#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    int (*square)(int);
    int (*cube)(int);
    char *error;


    handle = dlopen("./libops.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen failed: %s\n", dlerror());
        return 1;
    }



    dlerror();

    //Address of square()
    square = dlsym(handle, "square");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "dlsym failed for square: %s\n", error);
        dlclose(handle);
        return 1;
    }

    // Address of cube()
    cube = dlsym(handle, "cube");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "dlsym failed for cube: %s\n", error);
        dlclose(handle);
        return 1;
    }



    printf("square(4) = %d\n", square(4));
    printf("cube(3) = %d\n", cube(3));


    dlclose(handle);
    return 0;
}

//////////////////////////
/*

dlopen(): Loads the shared library at runtime.

dlsym(): Resolves symbol name to function pointer.

dlerror(): Returns error string if dlopen() or dlsym() fails.

dlclose(): Unloads the shared library and resources are freed.
*/