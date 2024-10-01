// 1. Retirar numero de matriz
#include <stdio.h>
#include "001.h"

void combinar_diferentes(void) {
    printf("1. Retirar numero de matriz\n");
    int v[30][30] = {0}, x[30][30] = {0}, l = 0, c = 0;

    printf("Vamos construir a matriz:\n");
    printf("Qual o número de linhas na matriz:\n");
    scanf(" %d", &l);
    printf("Qual o número de colunas na matriz:\n");
    scanf(" %d", &c);
    for (int i = 0; i < l; i++) {
        printf("Digite os numeros da linha %d:\n", i + 1);
        for (int j = 0; j < c; j++) {
            printf("Digite o numero %d:", j + 1);
            scanf("%d", &v[i][j]);
        }
    }
    printf("A matriz V eh:\n");
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
           printf("%d ", v[i][j]); 
        }
        printf("\n");
    }
    
    int num = 0;
    printf("Digite um numero inteiro!\n");
    scanf("%d", &num);
    printf("Retirando o elemento: %d\n", num);
    printf("A matriz X ficou:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (v[i][j] == num){
                x[i][j] = 0;
            }
            else {
                x[i][j] = v[i][j];
            }
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}