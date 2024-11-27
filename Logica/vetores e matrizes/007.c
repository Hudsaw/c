// 7. Resultado de loteria esportiva
#include <stdio.h>
#include "007.h"

void gabarito_loteria(void) {
    printf("7. Resultado de loteria esportiva\n");
    
    int g[13] = {0}, t[13] = {0}, num=0;

    printf("Vamos incluir o resultado:\n");
    for (int i = 0; i < 13; i++){
        printf("Digite o valor numero %d:", i+1);
        scanf(" %d", &g[i]);
    }
    printf("O resultado eh:\n");
    for (int i = 0; i < 13; i++){
        printf("%d: %d\n", i+1, g[i]); 
    }
    
    printf("Digite as respostas do bilhete para verificacao:\n");
    for (int i = 0; i < 13; i++){
        printf("Digite a resposta numero %d:", i+1);
        scanf("%d", &t[i]);
        if (g[i]==t[i]){num += 1;}
    }
    if (num==13){
        printf("O bilhete eh Ganhador!\n");
    } 
    else{
        printf("Pagou o imposto de pobre!\n");
    }
}