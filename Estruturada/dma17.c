#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char nome [50];
    int eixoX;
    int eixoY;
    int nv;
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
        printf("Nivel: ");
        scanf("%d", &cidades[i].nv);
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

float calcularCusto(Cidade* cidades, int** distancias, int a, int b, float diesel){
    float nvmedia = (cidades[a].nv + cidades[b].nv) / 2.0;
    return (distancias[a][b] / diesel) / nvmedia;
}
   

void printarDistancias(int** distancias, int* size) {
    printf("   ");
    for (int i = 0; i < size[0]; i++) {
        printf("%5d", i);
    } 
    printf("\n");
    for (int i = 0; i < size[0]; i++) {
        printf("%2d ", i);  
        for (int j = 0; j < size[1]; j++) {
            printf("%5d", distancias[i][j]);
        }
        printf("\n");
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
        printf("5. Custo de  transporte entre 2 cidades.\n");
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
                if (distancias != NULL) {
                    liberarMatriz(distancias, asize);
                }
                size[0] = asize;
                size[1] = asize;
                distancias = matrizInt(size);
                calcularDistancias(cidades, asize, distancias);
            }
            break;
        case 3:
            if (cidades == NULL || distancias == NULL) {
                printf("Crie as cidades e calcule a matriz de distancias primeiro!\n");
            } else {
                printarDistancias(distancias, size);
            }
            break;
        case 4:
            if (cidades == NULL || distancias == NULL) {
                printf("Crie as cidades e calcule a matriz de distancias primeiro!\n");
            } else {
                int a, b;
                printf("Digite o codigo das duas cidades (0 a %d):\n", size[0] - 1);
                scanf("%d %d", &a, &b);
                printf("A distancia entre as cidades de %s e %s eh de %d km.\n", cidades[a].nome, cidades[b].nome, distancias[a][b]); 
            }
            break;
        case 5:
            if (cidades == NULL || distancias == NULL) {
                printf("Crie as cidades e calcule a matriz de distancias primeiro!\n");
            } else {
                int a, b;
                float diesel, res;
                printf("Digite o preco do diesel:");
                scanf("%f", &diesel);
                if (diesel <= 0) {
                    printf("Preco do diesel deve ser positivo.\n");
                    return;
                }
                printf("Digite o codigo das duas cidades (0 a %d):\n", size[0] - 1);
                scanf("%d %d", &a, &b);
                res=calcularCusto(cidades, distancias, a, b, diesel);
                printf("Com o diesel a R$ %.2f, o custo entre as cidades de %s e %s eh de R$ %.2f.\n", diesel, cidades[a].nome, cidades[b].nome, res); 
            }
            break;
        case 0:
            printf("Saindo...\n");
            if (cidades != NULL) {
                free(cidades);
            }
            if (distancias != NULL) {
                liberarMatriz(distancias, size[0]);
            }
            break;
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