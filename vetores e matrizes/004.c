// 4. Multiplicar matriz por vetor
#include <stdio.h>
#include "004.h"

void matriz_x_vetor(void) {
    printf("4. Multiplicar matriz por vetor\n");

    int m = 1, n = 1, cont=1;
    printf("Digite um numero linhas da matriz!\n");
    scanf("%d", &m);
    printf("Digite um numero colunas da matriz!\n");
    scanf("%d", &n);

    float a[100][100] = {0}, v[100] = {0}, r[100] = {0};

    printf("Vamos construir a matriz:\n");
    for (int i = 0; i < m; i++) {
        printf("Digite os numeros da linha %d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            printf("Digite o numero %d:", j + 1);
            scanf("%f", &a[i][j]);
        }
    }
    printf("A matriz A eh:\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
           printf("%.1f ", a[i][j]); 
        }
        printf("\n");
    }
    printf("Digite os numeros do vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("Digite o numero %d:", i + 1);
        scanf("%f", &v[i]);
    }
    printf("O vetor V eh:\n");
    for (int i = 0; i < n; i++){
        printf("%.1f ", v[i]);  
    }
    printf("\n");
    printf("Multiplicando a matriz com o vetor\n");
    printf("O vetor R ficou:\n");
    for (int i = 0; i < m; i++) {
        r[i] = 0;
        for (int j = 0; j < n; j++) {
            r[i] = a[i][j] * v[j];
            printf("%.1f ", r[i]);
        }
    }
    printf("\n");    
}