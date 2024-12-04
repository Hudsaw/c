#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void funcao3(int** arr, int* asize){
    int bsize;
    printf("Digite o novo tamanho do array de %d elementos:", *asize);
    scanf("%d", &bsize);
    int* brr = (int*)realloc(*arr, bsize * sizeof(int));
    if (!brr) {
        printf("Erro ao realocar a memória!\n");
        return;
    }
    *arr = brr;
    *asize = bsize;
    printf("Memoria realocada com sucesso! Novo tamanho: %d elementos.\n", bsize);
}

void funcao4(int* arr, int size, int *par, int *impar){
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

void funcao5(int* arr, int size, int busca){
    int cont=0;
    for (int i = 0; i < size; i++ ){
        if(arr[i] % busca == 0){
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

int* funcao6(int* arr, int* brr, int* bsize){
    int* crr = NULL;
    int asize = 0;
    for (int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(arr[i]==brr[j]){
                asize++;
                int* temp = (int*)realloc(crr, asize * sizeof(int));
		        if (!temp) {
                    free(crr);
                    return NULL;
                }
		        crr = temp;
                crr[asize-1] = arr[i];
                break;
            }
        }
    }
    *bsize=asize;
    return crr;
}

int* funcao7(int** arr, int* asize){
    int num, bsize = 0;
    int* brr = NULL;

    while (1){
        printf("Digite o #%d: ", bsize+1);
        scanf("%d", &num);
        if(num<0) break;
        
        int* crr = (int*)realloc(brr, (bsize+1) * sizeof(int));
        if (!crr){
            free(brr);
            return NULL;
        } 
        brr=crr;
        brr[bsize] = num;
        bsize++;
    }
    *arr = brr;
    *asize = bsize;
    return *arr;
}

double aleatorio(unsigned inicio, unsigned fim){
    return inicio +((double)rand()/RAND_MAX) * (fim - inicio);
}

void funcao8(double* arr, int asize){

    for (int i = 0; i < asize; i++ ){
        arr[i] = aleatorio(1,100);
        printf("O valor #%d eh: %.1f\n",i+1, arr[i]);
    }
}

int* funcao9(int** arr, int* asize){
    int num, bsize = *asize;
    int* brr = *arr;

    while (1){
        printf("Digite o #%d: ", bsize+1);
        scanf("%d", &num);
        if(num<=0) break;
        
        if (bsize >= *asize) {
            *asize += 10;
            int* crr = malloc((*asize) * sizeof(int));
            if (!crr){
                free(brr);
                return NULL;
            } 
            // Por não usar o realloc
            for (int i = 0; i < bsize; i++) {
                crr[i] = brr[i];
            }
            free(brr);
            //
            brr=crr;
        }
        brr[bsize] = num;
        bsize++;
    }
    *arr = brr;
    *asize = bsize;
    return *arr;
}

void funcao10(int* arr, int size){
    for (int i = 0; i < size; i++ )
        arr[i]=i;
    for (int i = 0; i < size; i++ ){
        if(i<10||i>=(size-10))
        printf("\nO valor #%d: eh %d", i, arr[i]);
    }
}

void menu() {
    int escolha;

    int *grades, asize;
    printf("Digite o tamanho inicial do array:");
    scanf("%d", &asize);
    grades = (int*) malloc (asize * sizeof(int));
   
    if (!grades) {
        printf("Memória não alocada!\n");
        exit(1);
    } else {
        printf("Memória alocada com sucesso!\n");
    }

    srand(time(NULL));

    do {
        printf("\nPrograma escrito para estudar!\n");
        printf("Escolha uma acao:\n");
        printf("1. Digite os numeros do array\n");
        printf("2. Mostre os numeros do array\n");
        printf("3. Alterar o tamanho do array\n");
        printf("4. Quantos pares e impares\n");
        printf("5. Achar multiplos\n");
        printf("6. Numeros da loteria\n");
        printf("7. Armazene quantidade aleatoria\n");
        printf("8. Vetor de double aleatorios\n");
        printf("9. Armazenamento progressivo 10 em 10\n");
        printf("10. Substituir numeros pelo indice\n");
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
            case 4:{
                int par, impar;
                funcao4(grades, asize, &par, &impar);
                break;
            }
            case 5:{
                int busca;
                printf("\nDigite o numero para buscar multiplos:");
                scanf("%d", &busca);
                funcao5(grades, asize, busca);
                break;
            }
            case 6:{
                int meuBilhete[6], resLoteria[6];
                int* acertos;
                int tam;

                printf("\nDigite o resultado da loteria:\n");
                funcao1(resLoteria, 6);
                printf("\nDigite o seu bilhete:\n");
                funcao1(meuBilhete, 6);
                acertos = funcao6(resLoteria, meuBilhete, &tam);
                printf("\nNumeros sorteados pela loteria\n");
                funcao2(resLoteria,6);
                if(tam==0){
                    printf("\nSem acertos!");
                } 
                else{
                    printf("\nNumeros acertados:\n");
                    funcao2(acertos, tam);
                    free(acertos);
                }
                break;
            }
            case 7:
                funcao7(&grades, &asize);
                break;
            case 8: {
                double* vetor = (double*)malloc(asize * sizeof(double));
                    if (!vetor) {
                        printf("Erro ao alocar memoria!\n");
                    }
                funcao8(vetor, asize);
                free(vetor);
                break;
            }
            case 9:
                funcao9(&grades, &asize);
                break;
            case 10:
                funcao10(&grades, &asize);
                break;
            case 0:
                printf("Saindo...\n");
                return;
            default:
                printf("Escolha invalida. Tente novamente.\n");
                break;
        }
    } while (escolha!=0);
    
    free(grades);

}
int main(void) {
    menu();
    
    return 0;
}