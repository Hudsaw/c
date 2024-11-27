#include <stdio.h>

int main() {
    int g[13] = {0}, t[13] = {0}, num=0;

    printf("Vamos incluir o resultado:\n");
    for (int i = 0; i < 13; i++){
        printf("Digite o valor numero %d:", i+1);
        scanf(" %d", &g[i]);
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
    return 0;
}