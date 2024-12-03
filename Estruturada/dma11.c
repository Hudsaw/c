#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int matricula;
    char sobrenome [30];
    Data nascimento;
} Registro;

void incluirAlunos(Registro* alunos, int asize){
    for (int i=0; i < asize; i++){
        printf("Digite os dados do aluno #%d:\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Sobrenome: ");
        scanf(" %s", alunos[i].sobrenome);
        printf("Data de Nascimento (dd mm aa): ");
        scanf("%d %d %d", &alunos[i].nascimento.dia, &alunos[i].nascimento.mes, &alunos[i].nascimento.ano);
    }
}

void printarAlunos(Registro* alunos, int asize){
    printf("\nDados dos alunos cadastrados:\n");
    for (int i = 0; i < asize; i++) {
        printf("O Aluno #%d de matricula %d.\n", i + 1, alunos[i].matricula);
        printf("Tem Sobrenome %s e nasceu em %d/%d/%d\n", alunos[i].sobrenome, alunos[i].nascimento.dia, alunos[i].nascimento.mes, alunos[i].nascimento.ano);
        printf("-------------------------\n");
    }
}

void adicionarAluno(Registro** alunos, int* asize){
    Registro* temp = (Registro*) realloc(*alunos, (*asize + 1) * sizeof(Registro));
    if (!temp) {
        printf("Memoria nao alocada!\n");
        exit(1);
    }
    *alunos = temp;
    (*asize)++;
    printf("Digite os dados do aluno #%d:\n", *asize);
    printf("Matricula: ");
    scanf("%d", &(*alunos)[*asize-1].matricula);
    printf("Sobrenome: ");
    scanf(" %s", (*alunos)[*asize-1].sobrenome);
    printf("Data de Nascimento (dd mm aa): ");
    scanf("%d %d %d", &(*alunos)[*asize-1].nascimento.dia, &(*alunos)[*asize-1].nascimento.mes, &(*alunos)[*asize-1].nascimento.ano);  
}

void menu() {
    int escolha, asize;
    
    printf("Digite o numero de alunos a serem cadastrados:");
    scanf("%d", &asize);
    
    Registro* alunos = (Registro*) malloc (asize * sizeof(Registro));
    if(!alunos){
        printf("Memoria nao alocada!\n");
        exit(1);
    }
    incluirAlunos(alunos, asize);

    do {
        printf("\nPrograma escrito para estudar!\n");
        printf("Escolha uma acao:\n");
        printf("1. Adicionar aluno\n");
        printf("2. Mostrar dados dos alunos\n");
        printf("0. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                adicionarAluno(&alunos, &asize);
                break;
            case 2:
                printarAlunos(alunos, asize);
                break;            
            case 0:
                printf("Saindo...\n");
                return;
            default:
                printf("Escolha invalida. Tente novamente.\n");
                break;
        }
    } while (escolha!=0);
    
    free(alunos);

}
int main(void) {
    menu();
    
    return 0;
}