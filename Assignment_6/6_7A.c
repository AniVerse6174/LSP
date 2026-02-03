#include <stdio.h>

int counter = 0;  // global variable

void modify(int value) {
    counter += value;
}

void display() {
    printf("Current counter value: %d\n", counter);
}

void reset() {
    counter = 0;
}