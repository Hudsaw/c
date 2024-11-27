// 6. Gabarito de prova
#include <stdio.h>
#include "006.h"

void gabarito_prova(void) {
    printf("6. Gabarito de prova\n");

    char g[20] = {0}, t[50][20] = {0};
    int quest = 0;
    printf("Digite o numero de questoes:");
    scanf(" %d", &quest);

    printf("Vamos construir o gabarito:\n");
    for (int i = 0; i < quest; i++){
        printf("Digite a resposta numero %d:", i+1);
        scanf(" %c", &g[i]);
    }

    printf("O gabarito eh:\n");
    for (int i = 0; i < quest; i++){
        printf("%d: %c\n", i+1, g[i]); 
    }
    
    int alunos = 0;
    printf("Digite o numero de alunos:");
    scanf(" %d", &alunos);

    for (int i = 0; i < alunos; i++){
        printf("Digite as respostas do aluno %d:\n", i+1);
        float sum = 0;
        for (int j = 0; j < quest; j++){
            printf("Digite a resposta numero %d:", j+1);
            scanf(" %c", &t[i][j]);
            if (g[j]==t[i][j]){
                sum += 1;
        }   }
        sum /= quest;
        if (sum>=0.6){
            printf("O aluno %d foi aprovado!\n", i+1);
        } 
        else{
            printf("O aluno %d foi reprovado!\n", i+1);
        }
    }
}