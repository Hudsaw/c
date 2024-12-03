#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int codigo;
    char nome [50];
    int quant;
    float preco;
} Produto;

void incluirProduto(Produto* produtos, int asize){
    for (int i=0; i < asize; i++){
        printf("Digite os dados do produto #%d:\n", i + 1);
        printf("Nome: ");
        getchar();
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quant);
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
    }
}

void printarproduto(Produto* produtos, int i){
    printf("O produto %d eh %s.\n", i + 1, produtos[i].codigo, produtos[i].nome);
    printf("Com %d em estoque a %.2f cada.\n", produtos[i].quant, produtos[i].preco);
    printf("-------------------------\n");
}

void adicionarproduto(Produto** produtos, int* asize){
    Produto* temp = (Produto*) realloc(*produtos, (*asize + 1) * sizeof(Produto));
    if (!temp) {
        printf("Memoria nao alocada!\n");
        exit(1);
    }
    *produtos = temp;
    (*asize)++;
    printf("Digite os dados do produto #%d:\n", *asize);
        printf("Nome: ");
        getchar();
        fgets((*produtos)[*asize - 1].nome, sizeof((*produtos)[*asize - 1].nome), stdin);
        (*produtos)[*asize - 1].nome[strcspn((*produtos)[*asize - 1].nome, "\n")] = '\0';
        printf("Quantidade: ");
        scanf("%d", &(*produtos)[*asize-1].quant);
        printf("Preco: ");
        scanf("%f", &(*produtos)[*asize-1].preco);  
}

int buscarCaro(Produto* produtos, int asize){
    int caro = 0;
    float temp=produtos[0].preco;
    for(int i=1; i < asize; i++){
        if(temp<produtos[i].preco){
            temp = produtos[i].preco;
            caro = i;
        } 
    }
    return caro; 
}

int buscarQuant(Produto* produtos, int asize){
    int quant = 0;
    int temp=produtos[0].quant;
    for(int i=1; i < asize; i++){
        if(temp<produtos[i].quant){
            temp = produtos[i].quant;
            quant = i;
        } 
    }
    return quant; 
}

void menu() {
    int escolha, asize;
    
    printf("Digite o numero de produtos a serem cadastrados:");
    scanf("%d", &asize);
    
    Produto* produtos = (Produto*) malloc (asize * sizeof(Produto));
    if(!produtos){
        printf("Memoria nao alocada!\n");
        exit(1);
    }
    incluirProduto(produtos, asize);

    do {
        printf("\nPrograma escrito para estudar!\n");
        printf("Escolha uma acao:\n");
        printf("1. Adicionar produto\n");
        printf("2. Mostrar dados dos produtos\n");
        printf("3. Mostrar dados do produto mais caro\n");
        printf("4. Mostrar dados do produto com maior quantidade\n");
        printf("0. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                adicionarproduto(&produtos, &asize);
                break;
            case 2:{
                printf("\nDados dos produtos cadastrados:\n");
                for (int i = 0; i < asize; i++) {
                    printarproduto(produtos, i);
                }
                break;
            }  
            case 3:{
                printf("\nDados dos produto de maior preco:\n");
                printarproduto(produtos, buscarCaro(produtos, asize));
                break;
            } 
            case 4:{
                printf("\nDados dos produto com maior quantidade:\n");
                printarproduto(produtos, buscarQuant(produtos, asize));
                break;
            }                           
            case 0:
                printf("Saindo...\n");
                return;
            default:
                printf("Escolha invalida. Tente novamente.\n");
                break;
        }
    } while (escolha!=0);
    
    free(produtos);

}
int main(void) {
    menu();
    
    return 0;
}