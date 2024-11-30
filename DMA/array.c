#include <stdio.h>
#include <stdlib.h>
// #define SIZE 5

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

void menu() {
    int escolha;
    // Para malloc trocar isto: int grades [SIZE]; 
    // por isto: int *grades;
    // grades = (int*) malloc (SIZE * sizeof(int));
    // Porém com malloc podes decidir o tamanho do array depois. 

    int *grades, asize;
    printf("Digite o tamanho do array:");
    scanf("%d", &asize);
    grades = (int*) malloc (asize * sizeof(int));

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
            case 0:
                printf("Saindo...\n");
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