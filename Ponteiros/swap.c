#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}

void swapAdicao(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swapMultiplo(int *a, int *b){
    if (*a == 0 || *b == 0) { 
        printf("Um dos valores eh zero.\n");
        return;
    }*a = *a * *b;
    *b = *a / *b;
    *a = *a / *b;
}

void swapGenerica(void *a, void *b, int size){
    void *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}

void swapArray(int *arr, int size){
    for (int i=0; i < size/2; i++){
        swap(&arr[i], &arr[size-i-1]);
    }
}

void swapArrayResursivo(int *arr, int size){
    for (int i=0; i < size/2; i++){
        swap(arr+i, arr+size-i-1);
    }
}

int main(){

    int a, b;

    printf("Digite o numero1: ");
    scanf("%d",&a);
    printf("Digite o numero2: ");
    scanf("%d",&b);

    int *pA= &a, *pB = &b;

    printf("valor de a: %d\n", a);
    printf("valor de b: %d\n", b);

    swap(pA,pB);

    printf("valor depois swap a: %d\n", a);
    printf("valor depois swap b: %d\n", b);

    swapAdicao(pA,pB);

    printf("valor depois swapAdicao a: %d\n", a);
    printf("valor depois swapAdicao b: %d\n", b);

    if (a != 0 && b != 0) {
        swapMultiplo(&a, &b);
        printf("valor depois swapMultiplo a: %d\n", a);
        printf("valor depois swapMultiplo b: %d\n", b);
    } else {
        printf("swapMultiplo ignorado devido a zero.\n");
    }

    swapGenerica(&a, &b, sizeof(int));

    printf("valor depois swapGenerica a: %d\n", a);
    printf("valor depois swapGenerica b: %d\n", b);

    int arr[2]={a,b};
    swapArray(arr, 2);

    printf("valor depois swapArray a: %d\n", arr[0]);
    printf("valor depois swapArray b: %d\n", arr[1]);

    swapArrayResursivo(arr, 2);

    printf("valor depois swapArrayRecursivo a: %d\n", arr[0]);
    printf("valor depois swapArrayRecursivo b: %d\n", arr[1]);

return 0;
}