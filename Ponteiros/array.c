#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

void funcao1(int* arr, int size){
    
    for (int i=0; i<size; i++){
        printf("Digite o valor#%d:", i+1);
        scanf("%d", &arr[i]);
    }
}

void funcao2(int* arr, int size){
    
    for (int i=0; i<size; i++){
        printf("O valor#%d: %d\n", i+1, arr[i]);
    }
}

void funcao3(int* arr, int size, int *sum, double *ave){
    
    for (int i=0; i<size; i++){
        *sum = *sum + arr[i]; 
    }
    *ave = (double) *sum/size;
    
    printf("Soma do array: %d\n", *sum);
    printf("Media do array: %.2f\n", *ave);
}

void funcao4(int* arr, int size, int *max, int *min){
    if(size <= 0){return;}
    *max = arr[0];
    *min = arr[0]; 
    
    for (int i=1; i<size; i++){
        if(*max < arr[i]){
            *max = arr[i];    
        }
        if(*min > arr[i]){
            *min = arr[i];    
        }
    }
    printf("O numero maximo no array %d\n", *max);
    printf("O numero minimo no array %d\n", *min);
}

void funcao5(int *arr, int size, int busca){
    for (int i=0; i<size; i++){
        if(busca==arr[i]){
            printf("Esta no array");
        }
    }
    printf("Nao esta no array");
}

void funcao6(int *arr, int size, int ind, int num){
    if (ind > 0 && ind <= size) {
        arr[ind - 1] = num;
        printf("O numero da posicao %d foi alterado para %d.\n", ind, num);
    } else {
        printf("Posicao invalida.\n");
    }
}

void menu() {
    int escolha;
    int grades [SIZE]; 
    do {
        printf("\nPrograma escrito para estudar!\n");
        printf("Escolha uma acao:\n");
        printf("1. Digite os numeros do array\n");
        printf("2. Mostre os numeros do array\n");
        printf("3. Soma e media de um array\n");
        printf("4. Maior e menor numero de um array\n");
        printf("5. Buscar um numero no array\n");
        printf("6. Atualizar numero no array\n");
        printf("0. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                funcao1(grades, SIZE);
                break;
            case 2:
                funcao2(grades,SIZE);
                break;
            case 3:{
                int sum = 0;
                double  ave = 0;
                funcao3(grades, SIZE, &sum, &ave);
                break;
            }
            case 4:{
                int max, min;
                funcao4(grades, SIZE, &max, &min);
                break;
            }
            case 5:{
                int busca;
                printf("Digite o numero para a busca:");
                scanf("%d", &busca);
                funcao5(grades, SIZE, busca);
                break;
            }
            case 6:{
                int ind, num;
                printf("Digite a posicao e o numero a alterar (0 0):");
                scanf("%d %d", &ind, &num);
                funcao6(grades, SIZE, ind, num);
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