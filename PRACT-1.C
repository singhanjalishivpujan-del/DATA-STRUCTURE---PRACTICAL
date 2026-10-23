#include <stdio.h>

void callByValue(int x) {
    x = x + 10;
    printf("Inside call by value: %d\n", x);
}

void callByReference(int *x) {
    *x = *x + 10;
    printf("Inside call by reference: %d\n", *x);
}

int main() {
    int a = 10, b = 10;

    printf("Before call by value: %d\n", a);
    callByValue(a);
    printf("After call by value: %d\n", a);

    printf("\nBefore call by reference: %d\n", b);
    callByReference(&b);
    printf("After call by reference: %d\n", b);

    return 0;
}
