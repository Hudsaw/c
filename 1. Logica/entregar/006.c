#include <stdio.h>

int main() {
    int v[30][30] = {0}, x[30][30] = {0}, num = 0;

    for (int i = 0; i < 30; i++) {
        printf("Digite a linha %d da matriz:\n", i + 1);
        for (int j = 0; j < 30; j++) {
            printf("Digite o numero %d:", j + 1);
            scanf("%d", &v[i][j]);
        }
    }
    printf("Digite um numero inteiro!\n");
    scanf("%d", &num);
    
    printf("A matriz X ficou:\n");
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if (v[i][j] == num){x[i][j] = 0;}
            else {x[i][j] = v[i][j];}
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
    return 0;
}