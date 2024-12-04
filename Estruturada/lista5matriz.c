#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void projetar(int *size){
    printf("Digite o numero de linhas: ");
    scanf("%d", &size[0]);
    printf("Digite o numero de colunas: ");
    scanf("%d", &size[1]);
}

int** matrizInt(int *size){
    int** matriz = (int**)malloc(size[0] * sizeof(int*));
    for (int i = 0; i < size[0]; i++) {
        matriz[i] = (int*)malloc(size[1] * sizeof(int));
    }
    if (!matriz) {
        printf("Erro ao alocar memoria.\n");
        exit (1);
    }
    return matriz;
}   

char** matrizChar(int *size){
    char** matriz = (char**)malloc(size[0] * sizeof(char*));
    for (int i = 0; i < size[0]; i++) {
        matriz[i] = (char*)malloc(size[1] * sizeof(char));
    }
    if (!matriz) {
        printf("Erro ao alocar memoria.\n");
        exit (1);
    }
    return matriz;
}   

void incluir(int** matriz, int* size) {
    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < size[0]; i++) {
        for (int j = 0; j < size[1]; j++) {
            printf("Matriz[%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void printar(int** matriz, int* size) {
    for (int i = 0; i < size[0]; i++) {
        for (int j = 0; j < size[1]; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    } 
}

int buscar(int** matriz, int* size){
    int busca;

    printf("\nDigite o valor a ser procurado: ");
    scanf("%d", &busca);

    for (int i = 0; i < size[0]; i++) {
        for (int j = 0; j < size[1]; j++) {
            if (matriz[i][j] == busca) {
                printf("O valor %d esta presente na matriz.\n", busca);
                return 1;  
            }
        }
    }
    printf("O valor %d nao esta presente na matriz.\n", busca);
    return 0; 
}

void liberarMatriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void menu() {
    int escolha;
    int size[2];
    int** matriz = NULL;
    char** texto = NULL;

    do{
        printf("\nPrograma feito para estudo.\n");
        printf("Selecione uma acao:\n");
        printf("1. Criar matriz de inteiros.\n");
        printf("2. Incluir valores na matriz.\n");
        printf("3. Buscar valor na matriz.\n");
        printf("4. Imprimir matriz.\n");
        printf("5. Criar matriz de texto\n");
        printf("0. Sair...\n");
        printf("Digite sua escolha:");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            if (matriz != NULL) {
                liberarMatriz(matriz, size[0]);
            }
            projetar(size);
            matriz = matrizInt(size);
            
            break;
        case 2:
            if (matriz == NULL) {
                printf("Crie a matriz primeiro!\n");
            } else {
                incluir(matriz, size);
            }
            break;
        case 3:
            if (matriz == NULL) {
                printf("Crie a matriz primeiro!\n");
            } else {
                buscar(matriz, size);
            }
            break;
        case 4:
            if (matriz == NULL) {
                printf("Crie a matriz primeiro!\n");
            } else {
                printar(matriz, size);
            }
            break;
        case 5:
                if (texto == NULL) {
                    projetar(size);
                    texto = matrizChar(size);
                    printf("Matriz de Texto alocado.\n");
                } else {
                    printf("Matriz de Texto já alocado.\n");
                }
                break;
        case 0:
            printf("Saindo...\n");
            if (matriz != NULL) {
                liberarMatriz(matriz, size[0]);
            }
            return;
        default:
            printf("Escolha invalida. Digite novamente!\n");
            break;
        }
        
    } while (escolha!=0);
}

int main(void){
    menu();
    return 0;
}
