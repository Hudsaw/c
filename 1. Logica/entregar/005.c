#include <stdio.h>

int main() {
    int num = 0, bum=-999, sum=0, numeros[100] = {0};
    printf("Digite a quantidade de numeros inteiros!(1 a 100)\n");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        printf("Digite o numero %d do segmento:\n", i + 1);
        scanf("%d", &numeros[i]);
    }
    for (int i = 0; i < num; i++) {
        sum += numeros[i];
        if (sum > bum){bum = sum;}        
        if (sum < 0){sum = 0;}       
    }
    printf("A soma maxima do segmento eh: %d\n", bum);
    return 0;
}