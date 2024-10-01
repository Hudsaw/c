// 2. Multiplicar numero por matriz
#include <stdio.h>
#include "002.h"

void escalar_matriz(void) {
    printf("2. Multiplicar numero por matriz\n");   
    
    int v[6][6] = {0}, x[36] = {0}, l = 0, c = 0;

    printf("Vamos construir a matriz:\n");
    printf("Qual o número de linhas na matriz:\n");
    scanf(" %d", &l);
    printf("Qual o número de colunas na matriz:\n");
    scanf(" %d", &c);
    printf("Digite os numeros da matriz:\n");
    for (int i = 0; i < l; i++) {
        printf("Digite os numeros da linha %d:\n", i + 1);
        for (int j = 0; j < c; j++) {
            printf("Digite o numero %d:", j + 1);
            scanf("%d", &v[i][j]);
        }
    }
    printf("A matriz M eh:\n");
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
           printf("%d ", v[i][j]); 
        }
        printf("\n");
    }

    int num = 0, cont=1;
    printf("Digite um numero inteiro!\n");
    scanf("%d", &num);
    printf("Multiplicando o elemento: %d\n", num);
    printf("O vetor ficou:\n");
    
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            x[j*cont] = v[i][j] * num;
            printf("%d ", x[j*cont]);
        }
        cont++;
    }
    printf("\n");    
}