#include <stdio.h>

int main() {
    int v[6][6] = {0}, x[36] = {0}, num = 0, cont=1;
    for (int i = 0; i < 6; i++) {
        printf("Digite a linha %d da matriz:\n", i + 1);
        for (int j = 0; j < 6; j++) {
            printf("Digite o numero %d:", j + 1);
            scanf("%d", &v[i][j]);
    }   }
    printf("Digite um numero inteiro!\n");
    scanf("%d", &num);
    printf("O vetor ficou:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            x[j*cont] = v[i][j] * num;
            printf("%d ", x[j*cont]);
        }
        cont++;
    }
    printf("\n");  
    return 0;  
}