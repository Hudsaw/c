#include <stdio.h>

void main(){

    int *p1;
    int grade = 80;
    p1 = &grade;
    printf("Tamanho do ponteiro: %d\n", sizeof(p1));

    double *p2;
    double grade1 = 80;
    p2 = &grade1;
    printf("Tamanho do ponteiro: %d\n", sizeof(p2));
    printf("Tamanho do dado: %d\n", sizeof(*p2));

    int arr[6];
    int *p3 = arr;
    printf("Tamanho do array: %d\n", sizeof(arr));
    printf("Tamanho do ponteiro: %d\n", sizeof(p3));
    printf("Endereco do array: %p\n", arr);
    printf("Endereco do ponteiro: %p\n", p3);
}