#include <stdio.h>

int main() {
    float a = 5;
    float b = 2.5;

    float *p;

    p = &a; 

    printf("Valor de a: %.2f\n", a);

    *p = 10;

    printf("Novo valor de a: %.2f\n", a);

    p = &b; 

    printf("Valor de a: %.2f\n", b);

    *p = 11.5;

    printf("Novo valor de b: %.2f", b);

    return 0;
}