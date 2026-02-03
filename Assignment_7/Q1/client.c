#include <stdio.h>
#include "perfect.h"

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (IsPerfect(num))
        printf("%d is a Perfect Number\n", num);
    else
        printf("%d is NOT a Perfect Number\n", num);

    return 0;
}