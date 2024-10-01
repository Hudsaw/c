// 10. Listão de acertos na prova
#include <stdio.h>
#include "010.h"

void listao(void) {
    printf("10. Listão de acertos na prova\n");

    char g[30] = {0}, aux = {0};
    int quest = 0, t[50], alunos = 0;
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
    
    printf("Digite o numero de alunos:");
    scanf(" %d", &alunos);

    for (int i = 0; i < alunos; i++){
        printf("Digite as respostas do aluno %d:\n", i+1);
        for (int j = 0; j < quest; j++){
            printf("Digite a resposta numero %d:", j+1);
            scanf(" %c", &aux);
            if (g[j]==aux){
                t[i] += 1;
            }   
        }        
    }
    for (int i = 0; i < alunos; i++){
        printf("O aluno %d acertou %d questoes!\n", i+1, t[i]);
    }
}