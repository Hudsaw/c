// 25. Calcular soma maxima
#include <stdio.h>
#include "025.h"


void soma_maxima(void) {
    printf("25. Calcular soma maxima\n");
    int num = 0, sum=0, bum=-999;
    printf("Digite a quantidade de numeros inteiros!(1 a 100)\n");
    scanf("%d", &num);

    int numeros[100] = {0};

    printf("Digite os numeros do segmento:\n");
    for (int i = 0; i < num; i++) {
        printf("Digite o numero inteiro %d:\n", i + 1);
        scanf("%d", &numeros[i]);
    }

    for (int i = 0; i < num; i++) {
        sum += numeros[i];
        if (sum > bum){
            bum = sum;
        }        
        if (sum < 0){
            sum = 0;
        }       
    }
    printf("A soma maxima do segmento eh: %d\n", bum);
}