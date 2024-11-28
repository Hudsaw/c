#include <stdio.h>
#include <stdlib.h>

void funcao1(int* arr, int size){
    
    for (int i=0; i<size; i++){
        printf("Digite o valor#%d:", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<size; i++){
        printf("O valor#%d: %d\n", i+1, arr[i]);
    }
    free(arr);
}

void funcao2(int* arr, int size, int *par, int *impar){
    *par = 0;
    *impar = 0;
    for (int i=0; i<size; i++){
        if(arr[i]%2==0){
            *par++;
        }
        else{
            *impar++;
        }
    }
    printf("O array tem %d pares e %d impares\n", *par, *impar);
    free(arr);
}

void menu() {
    int escolha;
    int grades [5]; 
    do {
        printf("\nPrograma escrito para estudar!\n");
        printf("Escolha uma acao:\n");
        printf("1. Digite os numeros do array\n");
        printf("2. Digite o tamanho e o array\n");
        printf("3. Quantos pares e impares\n");
        printf("0. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:{
                int* arr = (int*) malloc(5 * sizeof(int));
                if (arr == NULL) {
                    printf("Erro ao alocar memória.\n");
                    return;
                }
                funcao1(arr, 5);
                break;
            }
            case 2:{
                int size;
                printf("Digite o tamanho do array: ");
                scanf("%d", &size);

                int* arr = (int*) malloc(size * sizeof(int));
                if (arr == NULL) {
                    printf("Erro ao alocar memória.\n");
                    return;
                }
                funcao1(arr, size);
                break;
            }
            case 3:{
                int size, par, impar;
                printf("Digite o tamanho do array: ");
                scanf("%d", &size);

                int* arr = (int*) malloc(size * sizeof(int));
                if (arr == NULL) {
                    printf("Erro ao alocar memória.\n");
                    return;
                }
                funcao1(arr, size);
                funcao2(arr, size, &par, &impar);
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
}
int main(void) {
    menu();
    return 0;
}