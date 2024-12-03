#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funcao1(int* arr, int asize){
    
    for (int i=0; i<asize; i++){
        printf("Digite o valor#%d:", i+1);
        scanf("%d", &arr[i]);
    }
}

void funcao2(int* arr, int asize){
    
    for (int i=0; i<asize; i++){
        printf("O valor#%d: %d\n", i+1, arr[i]);
    }
}

void funcao3(int** arr, int asize, int bsize){

    int* brr = (int*) realloc (*arr, bsize * sizeof(int));
    if (!brr) {
        printf("Erro ao realocar a memoria!\n");
    }
    *arr = brr;
}

void* realocar(void*srcblock, unsigned asize, unsigned bsize){
    void* resArr = malloc(bsize);
    if(!resArr) printf("Erro ao realocar a memoria!\n");
    unsigned minSize = (asize < bsize) ? asize : bsize;
    memcpy(resArr, srcblock, minSize);
    return resArr;
}

void menu() {
    int escolha;
    int *grades, asize;
    printf("Digite o tamanho do array:");
    scanf("%d", &asize);
    grades = (int*) malloc (asize * sizeof(int));
    // grades = (int*) calloc (asize, sizeof(int));

    if(!grades){
        printf("Memoria nao alocada!");
    } else{
        printf("Memoria alocada!");
    }

    do {
        printf("\nPrograma escrito para estudar!\n");
        printf("Escolha uma acao:\n");
        printf("1. Digite os numeros do array\n");
        printf("2. Mostre os numeros do array\n");
        printf("3. Alterar o tamanho do array para inteiros\n");
        printf("4. Alterar o tamanho do array generico\n");
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
            case 3:{
                int bsize;
                printf("Digite o novo tamanho do array de %d elementos:", asize);
                scanf("%d", &bsize);
                funcao3(&grades, asize, bsize);
                asize = bsize;
                break;
            }
            case 4:{
                int bsize;
                printf("Digite o novo tamanho do array de %d elementos:", asize);
                scanf("%d", &bsize);

                int *arr = (int*) realocar(grades, asize * sizeof(int), bsize * sizeof(int));
                if(!arr){
                    printf("Memoria nao alocada!");
                } else{
                    asize = bsize;
                    grades = arr;
                }
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