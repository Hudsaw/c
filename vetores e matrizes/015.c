// 15. Conferir repeticao de reais
#include <stdio.h>
#include "015.h"


void repeticao_reais(void) {
    printf("15. Conferir repeticao de reais\n");
    int num = 0;
    printf("Digite a quantidade de numeros reais!(1 a 100)\n");
    scanf("%d", &num);

    float numeros[100] = {0};
    int vezes[100] = {0};

    for (int i = 0; i < num; i++) {
        printf("Digite o numero real %d:\n", i + 1);
        scanf("%f", &numeros[i]);
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (numeros[i] == numeros[j]) {
                vezes[i]++;
            }
        }
    }

    for (int i = 0; i < num; i++) {
        int impresso = 0;
        for (int j = 0; j < i; j++) { //verifica os números anteriores para saber se foi impresso
            if (numeros[i] == numeros[j]) {
                impresso = 1;
                break;
            }
        }
        if (!impresso) {
            printf("O numero %.1f ocorre %d vezes\n", numeros[i], vezes[i]);
        }
    }
}