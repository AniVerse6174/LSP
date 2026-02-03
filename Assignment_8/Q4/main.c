#include <stdio.h>
#include "helper.h"

int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("Addition: %d\n", Add(x, y));
    return 0;
}