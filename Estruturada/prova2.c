#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char unNome[30];
} Nome;

typedef struct {
    int quantidadeNomes;
    Nome* ponteiroNomes;
} Controle;

void incluirNome(Controle* lista) {
    printf("Digite os nomes da lista:\n");
    for (int i = 0; i < lista->quantidadeNomes; i++) {
        printf("Nome #%d: ", i + 1);
        if (i == 0) getchar();
        fgets(lista->ponteiroNomes[i].unNome, sizeof(lista->ponteiroNomes[i].unNome), stdin);
        lista->ponteiroNomes[i].unNome[strcspn(lista->ponteiroNomes[i].unNome, "\n")] = '\0';
    }
}

void listarNomes(Controle* lista) {
    printf("Lista de Nomes:\n");
    for (int i = 0; i < lista->quantidadeNomes; i++) {
        printf("%d. %s\n", i + 1, lista->ponteiroNomes[i].unNome);
    }
}

void listarNomesOrdenados(Controle* lista) {
    Nome* copiaNomes = (Nome*)malloc(lista->quantidadeNomes * sizeof(Nome));
    if (!copiaNomes) {
        printf("Erro ao alocar memória para ordenação.\n");
        return;
    }

    for (int i = 0; i < lista->quantidadeNomes; i++) {
        strcpy(copiaNomes[i].unNome, lista->ponteiroNomes[i].unNome);
    }

    for (int i = 0; i < lista->quantidadeNomes - 1; i++) {
        for (int j = 0; j < lista->quantidadeNomes - i - 1; j++) {
            if (strcmp(copiaNomes[j].unNome, copiaNomes[j + 1].unNome) > 0) {
                Nome temp = copiaNomes[j];
                copiaNomes[j] = copiaNomes[j + 1];
                copiaNomes[j + 1] = temp;
            }
        }
    }

    printf("Nomes em ordem crescente:\n");
    for (int i = 0; i < lista->quantidadeNomes; i++) {
        printf("%d. %s\n", i + 1, copiaNomes[i].unNome);
    }

    free(copiaNomes);
}

void buscarNome(Controle* lista, char* busca) {
    for (int i = 0; i < lista->quantidadeNomes; i++) {
        if (strcmp(lista->ponteiroNomes[i].unNome, busca) == 0) {
            printf("O nome '%s' está na posicao %d.\n", busca, i + 1);
            return;
        }
    }
    printf("Nome '%s' nao encontrado.\n", busca);
}

void substituirNome(Controle* lista, char* busca) {
    for (int i = 0; i < lista->quantidadeNomes; i++) {
        if (strcmp(lista->ponteiroNomes[i].unNome, busca) == 0) {
            printf("Para qual nome gostaria de alterar? ");
            if (i == 0) getchar();
            fgets(lista->ponteiroNomes[i].unNome, sizeof(lista->ponteiroNomes[i].unNome), stdin);
            lista->ponteiroNomes[i].unNome[strcspn(lista->ponteiroNomes[i].unNome, "\n")] = '\0';
            printf("Nome alterado com sucesso!\n");
            return;
        }
    }
    printf("Nome '%s' nao encontrado.\n", busca);
}

void menu() {
    int escolha, asize;
    Controle lista;

    printf("Digite o tamanho inicial do vetor: ");
    scanf("%d", &asize);
    lista.quantidadeNomes = asize;
    lista.ponteiroNomes = (Nome*)malloc(asize * sizeof(Nome));

    if (!lista.ponteiroNomes) {
        printf("Memoria nao alocada!\n");
        exit(1);
    } else {
        printf("Memoria alocada com sucesso!\n");
    }

    do {
        printf("\nPrograma de Gerenciamento de Nomes\n");
        printf("Escolha uma acao:\n");
        printf("1. Incluir os nomes no vetor\n");
        printf("2. Listar todos os nomes\n");
        printf("3. Listar nomes em ordem crescente\n");
        printf("4. Procurar por um nome no vetor\n");
        printf("5. Substituir um nome no vetor\n");
        printf("0. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                incluirNome(&lista);
                break;
            case 2:
                listarNomes(&lista);
                break;
            case 3:
                listarNomesOrdenados(&lista);
                break;
            case 4: {
                char busca[30];
                printf("Digite o nome a ser procurado: ");
                getchar();
                fgets(busca, sizeof(busca), stdin);
                busca[strcspn(busca, "\n")] = '\0';
                buscarNome(&lista, busca);
                break;
            }
            case 5: {
                char busca[30];
                printf("Digite o nome a ser substituido: ");
                getchar(); 
                fgets(busca, sizeof(busca), stdin);
                busca[strcspn(busca, "\n")] = '\0';
                substituirNome(&lista, busca);
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha invalida. Tente novamente.\n");
                break;
        }
    } while (escolha != 0);

    free(lista.ponteiroNomes);
}

int main(void) {
    menu();
    return 0;
}
