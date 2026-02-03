#include "mymath.h"

int MyPow(int base, int exp) {
    int res = 1;
    while (exp--) res *= base;
    return res;
}

int MySqrt(int n) {
    int i = 0;
    while (i * i <= n) i++;
    return i - 1;
}

int MyAbs(int x) {
    return x < 0 ? -x : x;
}

int MyMax(int a, int b) {
    return a > b ? a : b;
}

int MyMin(int a, int b) {
    return a < b ? a : b;
}

int MyFactorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

int MyGCD(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int MyLCM(int a, int b) {
    return (a * b) / MyGCD(a, b);
}