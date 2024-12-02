#include <stdio.h>
#include <stdlib.h>
// #define SIZE 5

void funcao1(int* arr, int asize){
    for (int i=0; i<asize; i++){
        printf("O valor#%d: %d\n", i+1, arr[i]);
    }
}

void funcao2(int* arr, int asize){
    int i=0;
    printf("Digite a posicao desejada:");
    scanf("%d", &i);
    printf("Digite o valor#%d:", i-1);
    scanf("%d", &arr[i]);
}

void funcao3(int* arr, int asize){
    int i=0;
    printf("Digite a posicao desejada:");
    scanf("%d", &i);
    printf("O valor#%d: %d\n", i+1, arr[i]);
}

void funcao4(int** arr, int* asize){
    int bsize;
    printf("Digite o novo tamanho do array de %d elementos:", *asize);
    scanf("%d", &bsize);
    int* brr = (int*) realloc (*arr, bsize * sizeof(int));
    if (brr == NULL) {
        printf("Erro ao realocar a memória!\n");
        return;
    }
    *arr = brr;
    *asize = bsize;
    printf("Memoria realocada com sucesso! Novo tamanho: %d elementos.\n", bsize);
}

void funcao5(int* arr, int size, int *par, int *impar){
    *par = 0;
    *impar = 0;
    for (int i=0; i<size; i++){
        if(arr[i]%2==0){
            (*par)++;
        }
        else{
            (*impar)++;
        }
    }
    printf("O array tem %d pares e %d impares\n", *par, *impar);
}

void funcao6(int* arr, int size, int busca){
    int cont=0;
    for (int i = 0; i < size; i++ ){
        if(arr[i]% busca == 0){
            printf("O numero %d eh multiplo de %d!", arr[i], busca);
            cont++;
        }
    }
    if(!cont){
        printf("o numero %d nao tem multiplos no array", busca);
    } else {
        printf("O numero %d tem %d multiplos no array.", busca, cont);
    }
}

void menu() {
    int escolha;
    // Para malloc trocar isto: int grades [SIZE]; 
    // por isto: int *grades;
    // grades = (int*) malloc (SIZE * sizeof(int));
    // Porém com malloc podes decidir o tamanho do array depois. 

    int *grades, asize;
    printf("Digite o tamanho do array:");
    scanf("%d", &asize);
    // grades = (int*) malloc (asize * sizeof(int));
    grades = (int*) calloc (asize, sizeof(int));
    // Com o calloc inicializa a variável com o valor 0, cuidado ao usar!

    if(!grades){
        printf("Memoria nao alocada!");
    } else{
        printf("Memoria alocada!");
    }

    do {
        printf("\nPrograma escrito para estudar!\n");
        printf("Escolha uma acao:\n");
        printf("1. Mostre os numeros do array\n");
        printf("2. Digite um numero no array\n");
        printf("3. Consultar posicao do array\n");
        printf("4. Alterar o tamanho do array\n");
        printf("5. Quantos pares e impares\n");
        printf("6. Achar multiplos\n");
        printf("0. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                funcao1(grades, asize);
                break;
            case 2:
                funcao2(grades, asize);
                break;
            case 3:
                funcao3(&grades, &asize);
                break;
            case 4:
                funcao4(&grades, &asize);
                break;
            case 5:{
                int par, impar;
                funcao5(grades, asize, &par, &impar);
                break;
            }
            case 6:{
                int busca;
                printf("\nDigite o numero para buscar multiplos:");
                scanf("%d", &busca);
                funcao6(grades, asize, busca);
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
    
    free(grades); //liberar a memoria antes de fechar o programa.

}
int main(void) {
    menu();
    
    return 0;
}