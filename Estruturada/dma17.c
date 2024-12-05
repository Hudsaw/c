#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char nome [50];
    int eixoX;
    int eixoY;
} Cidade;

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

Cidade* criarCidade(int* asize){
    printf("Digite o numero de cidades a serem cadastradas:");
    scanf("%d", asize);
    
    Cidade* cidades = (Cidade*) malloc ((*asize) * sizeof(Cidade));
    if(!cidades){
        printf("Memoria nao alocada!\n");
        exit(1);
    }
    return cidades;
}

void incluirCidade(Cidade* cidades, int asize){
    for (int i = 0; i < asize; i++) {
        printf("Digite os dados da cidade #%d:\n", i + 1);
        printf("Nome: ");
        getchar();
        fgets(cidades[i].nome, sizeof(cidades[i].nome), stdin);
        cidades[i].nome[strcspn(cidades[i].nome, "\n")] = '\0';
        printf("Coordenada X: ");
        scanf("%d", &cidades[i].eixoX);
        printf("Coordenada Y: ");
        scanf("%d", &cidades[i].eixoY);
    }
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

void calcularDistancias(Cidade* cidades, int asize, int** distancias) {
    for (int i = 0; i < asize; i++) {
        for (int j = 0; j < asize; j++) {
            if (i == j) {
                distancias[i][j] = 0;
            } else {
                int dx = cidades[j].eixoX - cidades[i].eixoX;
                int dy = cidades[j].eixoY - cidades[i].eixoY;
                distancias[i][j] = (int)round(sqrt(dx * dx + dy * dy));
            }
        }
    }
    printf("Matriz de distancias calculada com sucesso.\n");
}

void printarDistancias(int** distancias, int* size) {
    printf("Matriz de distancias:\n");
    for (int i = 0; i < size[0]; i++) {
        for (int j = 0; j < size[1]; j++) {
            if(j==0) printf(" %d ", i); 
            printf(" %d ", distancias[i][j]);
        }
        printf("\n");
    }
}

void buscarDistancias(int** distancias, int* size) {
    int cidade1, cidade2;
    printf("Digite o indice das duas cidades para buscar a distancia (0 a %d):\n", size[0] - 1);
    scanf("%d %d", &cidade1, &cidade2);

    if (cidade1 >= 0 && cidade1 < size[0] && cidade2 >= 0 && cidade2 < size[1]) {
        printf("Distancia entre cidade %d e cidade %d: %d\n", cidade1, cidade2, distancias[cidade1][cidade2]);
    } else {
        printf("Indices invalidos!\n");
    }
}

void liberarMatriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void menu() {
    int escolha;
    int size[2], asize;
    Cidade* cidades = NULL;
    int** distancias = NULL;

    do{
        printf("\nPrograma feito para estudo.\n");
        printf("Selecione uma acao:\n");
        printf("1. Criar matriz de cidades\n");
        printf("2. Incluir dados das cidades\n");
        printf("3. Imprimir matriz de distancia entre cidades\n");
        printf("4. Buscar distancia entre 2 cidades.\n");
        printf("0. Sair...\n");
        printf("Digite sua escolha:");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            if (cidades != NULL) {
                free(cidades);
                cidades = NULL;
            }
            cidades = criarCidade(&asize);
            break;
        case 2:
            if (cidades == NULL) {
                printf("Crie o vetor primeiro!\n");
            } else {
                incluirCidade(cidades, asize);
            }
            break;
        case 3:
            if (cidades == NULL) {
                printf("Crie o vetor de cidades primeiro!\n");
            } else {
                if (distancias != NULL) {
                    liberarMatriz(distancias, asize);
                }
                size[0] = asize;
                size[1] = asize;
                distancias = matrizInt(size);
                calcularDistancias(cidades, asize, distancias);
                printarDistancias(distancias, size);
            }
            break;
        case 4:
            if (cidades == NULL || distancias == NULL) {
                printf("Crie as cidades e calcule a matriz de distancias primeiro!\n");
            } else {
                buscarDistancias(distancias, size);
            }
            break;
        case 0:
            printf("Saindo...\n");
            if (cidades != NULL) free(cidades);
            if (distancias != NULL) liberarMatriz(distancias, size[0]);
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