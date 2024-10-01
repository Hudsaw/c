#include <stdio.h>

int main() {
    char g[20] = {0}, t[50][20] = {0};
    int quest = 20, alunos = 50;

    printf("Vamos construir o gabarito:\n");
    for (int i = 0; i < quest; i++){
        printf("Digite a resposta numero %d:", i+1);
        scanf(" %c", &g[i]);
    }
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
    }   }
    return 0;
}