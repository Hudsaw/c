// 12. Produto escalar de vetores
#include <stdio.h>
#include "012.h"

void produto_escalar(void) {
    printf("12. Produto escalar de vetores\n");

    int num = 0, x[20]={0}, y[20]={0}, sum = 0;
    printf("Digite o numero de elementos:");
    scanf(" %d", &num);

    printf("Vamos construir o vetor X:\n");
    for (int i = 0; i < num; i++){
        printf("Digite o numero %d:", i+1);
        scanf(" %d", &x[i]);
    }
    printf("Vamos construir o vetor Y:\n");
    for (int i = 0; i < num; i++){
        printf("Digite o numero %d:", i+1);
        scanf(" %d", &y[i]);
    }

    printf("Os vetores são:\n");
    printf("X: ");
    for (int i = 0; i < num; i++){
        printf("%d ", x[i]); 
    }
    printf("\n");
    printf("Y: ");
    for (int i = 0; i < num; i++){
        printf("%d ", y[i]); 
    }
    printf("\n");
    
    for (int i = 0; i < num; i++){
        sum += (x[i]*y[i]);    
    }
    printf("O produto escalar dos dois vetores eh: %d!\n", sum);
}