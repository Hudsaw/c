#include <stdio.h>
#include <stdlib.h>

void revisao1_ponteiros() {
    int inteiro = 10;
    float real = 3.14;
    char caractere = 'A';

    int *p_int = &inteiro;
    float *p_real = &real;
    char *p_char = &caractere;

    printf("=== Exercicio 1 ===\n");
    printf("Valores antes da modificacao:\n");
    printf("inteiro = %d, real = %.2f, caractere = %c\n", inteiro, real, caractere);

    *p_int = 42;
    *p_real = 7.89;
    *p_char = 'Z';

    printf("Valores apos modificacao via ponteiros:\n");
    printf("inteiro = %d, real = %.2f, caractere = %c\n", inteiro, real, caractere);
}

void revisao2_enderecos() {
    int a;
    int b;

    printf("=== Exercicio 2 ===\n");
    printf("Endereco de a: %p\n", &a);
    printf("Endereco de b: %p\n", &b);

    if (&a > &b) {
        printf("O maior endereco eh: %p (variavel a)\n", &a);
    } else {
        printf("O maior endereco eh: %p (variavel b)\n", &b);
    }
}

void ordenar(int *a, int *b) {
    if (*a < *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

void revisao3_ordenar() {
    int x, y;

    printf("=== Exercicio 3 ===\n");
    printf("Digite dois valores inteiros: ");
    scanf("%d %d", &x, &y);

    printf("Antes: x = %d, y = %d\n", x, y);

    ordenar(&x, &y);

    printf("Depois (maior em x, menor em y): x = %d, y = %d\n", x, y);
}

void revisao4_array_floats() {
    float array[10];

    printf("=== Exercicio 4 ===\n");
    printf("Enderecos das posicoes do array de 10 floats:\n");

    for (int i = 0; i < 10; i++) {
        printf("array[%d] -> %p\n", i, &array[i]);
    }
}

void imprimir(float *arr, int tamanho) {
    printf("Conteudo do array (usando ponteiros):\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%.2f ", *(arr + i));
    }
    printf("\n");
}

void revisao5_imprimir_array() {
    float array[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    printf("=== Exercicio 5 ===\n");
    imprimir(array, 5);
}

void revisao6_valores_pares() {
    int array[5];

    printf("=== Exercicio 6 ===\n");
    printf("Digite 5 numeros inteiros: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enderecos das posicoes com valores pares:\n");
    for (int i = 0; i < 5; i++) {
        if (array[i] % 2 == 0) {
            printf("array[%d] = %d -> endereco: %p\n", i, array[i], &array[i]);
        }
    }
}