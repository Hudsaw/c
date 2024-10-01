#include <stdio.h>

int main() {
    int m = 1, n = 1, cont=1;
    printf("Digite um numero linhas e colunas da matriz!\n");
    scanf("%d %d", &m, &n);

    float a[100][100] = {0}, v[100] = {0}, r[100] = {0};
    for (int i = 0; i < m; i++) {
        printf("Digite a linha %d da matriz:\n", i + 1);
        for (int j = 0; j < n; j++) {
            printf("Digite o numero %d:", j + 1);
            scanf("%f", &a[i][j]);
    }   }
    printf("Digite os numeros do vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("Digite o numero %d:", i + 1);
        scanf("%f", &v[i]);
    }
    printf("O vetor R ficou:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            r[i] = a[i][j] * v[j];
            printf("%.1f ", r[i]);
    }   }
    return 0;    
}