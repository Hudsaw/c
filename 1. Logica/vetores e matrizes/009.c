// 9. Ordem Inversa
#include <stdio.h>
#include "009.h"

void ordem_inversa(void) {
    printf("9. Ordem Inversa\n");
    
    int v[100] = {0}, num=0;
    
    printf("Qual o número de elementos?\n");
    scanf("%d", &num);
    printf("Vamos incluir oo elementos no vetor:\n");
    for (int i = 0; i < num; i++){
        printf("Digite o valor numero %d:", i+1);
        scanf("%d", &v[i]);
    }
    printf("O resultado eh:\n");
    for (int i = num-1; i >= 0; i--){
        printf("%d ", v[i]); 
    }
}