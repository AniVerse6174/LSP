#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main() {
    void *handle;
    int (*func)(int, int);
    char *error;
    int a, b, choice;

    handle = dlopen("./libarith.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen failed: %s\n", dlerror());
        return 1;
    }

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("Select operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choice);

    dlerror();

    
    switch (choice) {
        case 1:
            func = dlsym(handle, "Addition");
            break;
        case 2:
            func = dlsym(handle, "Subtraction");
            break;
        case 3:
            func = dlsym(handle, "Multiplication");
            break;
        case 4:
            func = dlsym(handle, "Division");
            break;
        default:
            printf("Invalid choice\n");
            dlclose(handle);
            return 1;
    }


    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "dlsym failed: %s\n", error);
        dlclose(handle);
        return 1;
    }

    printf("Result: %d\n", func(a, b));

    dlclose(handle);
    return 0;
}