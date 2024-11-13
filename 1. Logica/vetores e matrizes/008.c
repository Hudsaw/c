// 8. Divisao de matriz por maior elemento
#include <stdio.h>
#include "008.h"

void matriz_modificada(void) {
    printf("8. Divisao de matriz por maior elemento\n");

    int m[12][13] = {0}, l = 0, c = 0;

    printf("Vamos construir a matriz:\n");
    printf("Qual o número de linhas na matriz:\n");
    scanf(" %d", &l);
    printf("Qual o número de colunas na matriz:\n");
    scanf(" %d", &c);
    for (int i = 0; i < l; i++) {
        printf("Digite os numeros da linha %d:\n", i + 1);
        for (int j = 0; j < c; j++) {
            printf("Digite o numero %d:", j + 1);
            scanf("%d", &m[i][j]);
        }
    }
    printf("A matriz M eh:\n");
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
           printf("%d ", m[i][j]); 
        }
        printf("\n");
    }
    printf("a matriz modificada ficou:\n");
    for (int i = 0; i < l; i++) {
        int maior= -99999;
        for (int j = 0; j < c; j++) {
            if (m[i][j] > maior){
                maior = m[i][j];
        }   }
        if (maior < 0){maior = -maior;}
        for (int j = 0; j < c; j++) {
            m[i][j] *= maior;
            printf("%d ", m[i][j]); 
        }
        printf("\n");
    } 
}