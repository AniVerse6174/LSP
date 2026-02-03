#include <stdio.h>
#include "addition.h"
#include "substraction.h"

int main() {
    int A, B;
    printf("Enter two numbers: ");
    scanf("%d %d", &A, &B);

    printf("Addition: %d\n", Addition(A, B));
    printf("Substraction: %d\n", Substraction(A, B));

    return 0;
}