#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "mymath.h"

int main() {
    int choice;
    char s1[100], s2[100], ch;
    int a, b;

    while (1) {
        printf("\nMenu:\n");
        printf("1. MyStrlen\n2. MyStrcpy\n3. MyStrcat\n4. MyStrrev\n");
        printf("5. MyPow\n6. MySqrt\n7. MyGCD\n8. MyLCM\n0. Exit\n");
        scanf("%d", &choice);
        getchar();  // clear newline

        
        switch (choice) {
            case 1:
                printf("Enter string: ");
                fgets(s1, sizeof(s1), stdin);
                s1[strcspn(s1, "\n")] = 0;
                printf("Length: %d\n", MyStrlen(s1));
                break;
            case 2:
                printf("Enter source: ");
                fgets(s1, sizeof(s1), stdin);
                s1[strcspn(s1, "\n")] = 0;
                MyStrcpy(s2, s1);
                printf("Copied: %s\n", s2);
                break;
            case 3:
                printf("Enter first string: ");
                fgets(s1, sizeof(s1), stdin);
                s1[strcspn(s1, "\n")] = 0;
                printf("Enter second string: ");
                fgets(s2, sizeof(s2), stdin);
                s2[strcspn(s2, "\n")] = 0;
                MyStrcat(s1, s2);
                printf("Concatenated: %s\n", s1);
                break;
            case 4:
                printf("Enter string: ");
                fgets(s1, sizeof(s1), stdin);
                s1[strcspn(s1, "\n")] = 0;
                MyStrrev(s1);
                printf("Reversed: %s\n", s1);
                break;
            case 5:
                printf("Enter base and exponent: ");
                scanf("%d %d", &a, &b);
                printf("Power: %d\n", MyPow(a, b));
                break;
            case 6:
                printf("Enter number: ");
                scanf("%d", &a);
                printf("Sqrt: %d\n", MySqrt(a));
                break;
            case 7:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("GCD: %d\n", MyGCD(a, b));
                break;
            case 8:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("LCM: %d\n", MyLCM(a, b));
                break;
            case 0:
                return 0;
        }
    }
}