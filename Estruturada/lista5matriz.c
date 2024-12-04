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

Cidade* criarCidade(int* bsize){
    printf("Digite o numero de cidades a serem cadastradas:");
    scanf("%d", &bsize[0]);
    
    Cidade* cidades = (Cidade*) malloc (bsize[2] * sizeof(Cidade));
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
    printf("Matriz de distâncias calculada com sucesso.\n");
}

void printar(int** matriz, int* size) {
    for (int i = 0; i < size[0]; i++) {
        for (int j = 0; j < size[1]; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    } 
}

void printarDistancias(int** distancias, int* size) {
    printf("Matriz de distâncias:\n");
    for (int i = 0; i < size[0]; i++) {
        for (int j = 0; j < size[1]; j++) {
            printf("%d ", distancias[i][j]);
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

void buscarDistancias(int** distancias, int* size) {
    int cidade1, cidade2;
    printf("Digite o índice das duas cidades para buscar a distância (0 a %d):\n", size[0] - 1);
    scanf("%d %d", &cidade1, &cidade2);

    if (cidade1 >= 0 && cidade1 < size[0] && cidade2 >= 0 && cidade2 < size[1]) {
        printf("Distância entre cidade %d e cidade %d: %d\n", cidade1, cidade2, distancias[cidade1][cidade2]);
    } else {
        printf("Índices inválidos!\n");
    }
}

void* realocar(void*srcblock, unsigned asize, unsigned bsize){
    void* resArr = malloc(bsize);
    if(!resArr) printf("Erro ao realocar a memoria!\n");
    unsigned minSize = (asize < bsize) ? asize : bsize;
    memcpy(resArr, srcblock, minSize);
    return resArr;
}

void liberarMatriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
void liberarTexto(char** texto, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(texto[i]);
    }
    free(texto);
}

void menu() {
    int escolha;
    int size[2], asize;
    int** matriz = NULL;
    char** texto = NULL;
    Cidade** cidades = NULL;
    int** distancias = NULL;

    do{
        printf("\nPrograma feito para estudo.\n");
        printf("Selecione uma acao:\n");
        printf("1. Criar matriz de inteiros.\n");
        printf("2. Incluir valores na matriz.\n");
        printf("3. Buscar valor na matriz.\n");
        printf("4. Imprimir matriz.\n");
        printf("5. Criar matriz de texto\n");
        printf("6. Criar matriz de cidades\n");
        printf("7. Incluir dados das cidades\n");
        printf("8. Imprimir matriz de distancia entre cidades\n");
        printf("9. Buscar distancia entre 2 cidades.\n");
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
        case 6:
            if (cidades != NULL) {
                cidades = 0;
            }
            criarCidade(&cidades, &asize);
            break;
        case 7:
            if (cidades == NULL) {
                printf("Crie o vetor primeiro!\n");
            } else {
                incluirCidade(cidades, asize);
            }
            break;
        case 8:
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
        case 9:
            if (cidades == NULL || distancias == NULL) {
                printf("Crie as cidades e calcule a matriz de distancias primeiro!\n");
            } else {
                buscarDistancias(distancias, size);
            }
            break;
        case 0:
            printf("Saindo...\n");
            if (matriz != NULL) liberarMatriz(matriz, size[0]);
            if (texto != NULL) liberarTexto(texto, size[0]);
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