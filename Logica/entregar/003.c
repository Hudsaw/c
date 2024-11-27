#include <stdio.h>

int main() {
    int num = 0, vezes[100] = {0};;
    float numeros[100] = {0};
    
    printf("Digite a quantidade de numeros reais!(1 a 100)\n");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        printf("Digite o numero real %d:\n", i + 1);
        scanf("%f", &numeros[i]);
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (numeros[i] == numeros[j]) {vezes[i]++;}
    }   }

    for (int i = 0; i < num; i++) {
        int impresso = 0;
        for (int j = 0; j < i; j++) {
            if (numeros[i] == numeros[j]) {impresso = 1; break;}
        }
        if (!impresso) {
            printf("O numero %.1f ocorre %d vezes\n", numeros[i], vezes[i]);
    }   }   
    return 0;
}