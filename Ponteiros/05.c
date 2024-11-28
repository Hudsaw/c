#include <stdio.h>

void main(){
    int grade = 80;
    printf("tamanho da variavel = %d\n", sizeof(grade));
    
    double grades = 79.9;
    printf("tamanho da variavel = %d\n", sizeof(grades));
    
    int grade1 = 80, grade2 = 90;
    printf("tamanho da variavel = %d\n", sizeof(grade1+grade2));
    printf("tamanho da variavel = %d\n", sizeof(grade1)+sizeof(grade2));

    printf("tamanho do tipo double = %d\n", sizeof(double));
    printf("tamanho do tipo char = %d\n", sizeof(char));
    printf("tamanho do tipo int = %d\n", sizeof(int));
    printf("tamanho do tipo float = %d\n", sizeof(float));
    printf("tamanho do 'a' = %d\n", sizeof('a'));
    printf("tamanho do a = %d\n", sizeof("a"));

    int arr[3];
    printf("tamanho do array = %d\n", sizeof(arr));

    double brr[5];
    printf("tamanho do array = %d\n", sizeof(brr));

}