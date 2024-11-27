#include <stdio.h>
#include <stdlib.h>

int main(){

    int a=5, b=7;
    int *pA, *pB;

    printf("valor de a: %d, valor de b: %d\n", a, b);

    pA=&a;
    pB=&b;

    printf("valor de a: %d, valor de b: %d\n", a, b);

    *pA = *pA+1;
    *pB = *pB+3;

    printf("valor de a: %d, valor de b: %d\n", a, b);

    pA = pB;
    pB = pA;

    printf("valor de a: %d, valor de b: %d\n", a, b);
    printf("valor de pA: %d, valor de pB: %d\n", *pA, *pB);

    a = *pB;
    b = a - 3;
    pA=&a;

    printf("valor de a: %d, valor de b: %d\n", a, b);
    printf("valor de pA: %d, valor de pB: %d\n", *pA, *pB);

return 0;
}