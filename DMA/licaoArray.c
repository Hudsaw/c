#include <stdio.h>
#include <stdlib.h>

int* createArray(int asize){
    
    int* arr = (int*) malloc (asize * sizeof(int));

    if(!arr){
        printf("Memoria nao alocada!\n");
        return NULL;
    } else{
        printf("Memoria alocada!\n");
        return arr;
    }
}

void initArray(int* arr, int asize){
    
    for (int i=0; i<asize; i++){
        printf("Digite o valor#%d:", i+1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int* arr, int asize){
    
    for (int i=0; i<asize; i++){
        printf("O valor#%d: %d\n", i+1, arr[i]);
    }
}

int doubleArray(int** arr, int asize){

    int* brr = (int*) realloc (*arr, asize * sizeof(int));
    if (!brr) {
        printf("Erro ao realocar a memoria!\n");
        return -1;
    }
    
    for(int i=0; i < asize; i++){
        brr[i]=0;
    }
    *arr = brr;
    return 0;
}

void freeMemory(int* arr){
    free(arr);
    printf("Memoria liberada!\n");
}

void menu() {
    int escolha;
    int *grades = NULL, asize = 0;
    

    do {
        printf("\nPrograma escrito para estudar!\n");
        printf("Escolha uma acao:\n");
        printf("1. Criar um array\n");
        printf("2. Digite os numeros do array\n");
        printf("3. Mostre os numeros do array\n");
        printf("4. Dobrar o tamanho do array\n");
        printf("0. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:{
                if (grades) {
                    freeMemory(grades);
                }printf("Digite o tamanho do array:");
                scanf("%d", &asize);
                grades = createArray(asize);
                break;
            }
            case 2:
                initArray(grades, asize);
                break;
            case 3:
                displayArray(grades, asize);
                break;
            case 4:
                asize = asize*2;
                doubleArray(&grades, asize);
                break;
            case 0:
                printf("Saindo...\n");
                freeMemory(grades);
                return;
            default:
                printf("Escolha invalida. Tente novamente.\n");
                break;
        }
    } while (escolha!=0);

}
int main(void) {
    menu();
    
    return 0;
}