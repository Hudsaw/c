#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    int matricula;
    int media;
} Aluno;

void preencherAluno(Aluno *aluno) {
    printf("Digite o nome do aluno: ");
    scanf(" %s", aluno->nome);
    printf("Digite a matricula do aluno: ");
    scanf("%d", &aluno->matricula);
    printf("Digite a media do aluno: ");
    scanf("%d", &aluno->media);
}

void exibirAlunos(Aluno *alunos, int n) {
    for (int i = 0; i < n; i++) {
        printf("Aluno %d - matricula: %d.\nNome: %s. Media: %d\n", i + 1, alunos[i].matricula, alunos[i].nome, alunos[i].media);
    }
}

int main() {
    int escolha, num;
    Aluno *alunos = NULL;

    printf("Digite o numero de alunos a serem alocados: ");
    scanf("%d", &num);
    
    printf("Escolha uma funcao de alocacao de memoria:\n");
    printf("1. malloc\n");
    printf("2. calloc\n");
    printf("3. realloc\n");
    printf("0. sair\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            alunos = (Aluno *)malloc(num * sizeof(Aluno));
            if (alunos == NULL) {
                printf("Erro ao alocar memoria com malloc.\n");
                return 1;
            }
            printf("Memoria alocada com malloc.\n");
            break;

        case 2:
            alunos = (Aluno *)calloc(num, sizeof(Aluno));
            if (alunos == NULL) {
                printf("Erro ao alocar memoria com calloc.\n");
                return 1;
            }
            printf("Memoria alocada com calloc.\n");
            break;

        case 3:
            alunos = (Aluno *)malloc(1 * sizeof(Aluno));
            if (alunos == NULL) {
                printf("Erro ao alocar memoria inicial com malloc.\n");
                return 1;
            }
            printf("Memoria inicial alocada com malloc.\n");

            alunos = (Aluno *)realloc(alunos, num * sizeof(Aluno));
            if (alunos == NULL) {
                printf("Erro ao redimensionar memoria com realloc.\n");
                return 1;
            }
            printf("Memoria redimensionada com realloc.\n");
            break;

        case 0:
            printf("Saindo...\n");
            return 0;

        default:
            printf("Opcao invalida.\n");
            return 1;
    }

    for (int i = 0; i < num; i++) {
        printf("\nPreenchendo dados do aluno %d:\n", i + 1);
        preencherAluno(&alunos[i]);
    }

    printf("\nDados dos alunos:\n");
    exibirAlunos(alunos, num);

    free(alunos);
    printf("\nMemoria liberada.\n");

    return 0;
}
