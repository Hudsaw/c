#include <stdio.h>

int main() {
    int m[12][13] = {0}, l = 3, c = 4;
    for (int i = 0; i < l; i++) {
        printf("Digite os numeros da linha %d:\n", i + 1);
        for (int j = 0; j < c; j++) {
            printf("Digite o numero %d:", j + 1);
            scanf("%d", &m[i][j]);
    }   }
    printf("A matriz lida:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", m[i][j]); 
        }
        printf("\n");
    } 
    printf("a matriz modificada ficou:\n");
    for (int i = 0; i < l; i++) {
        int maior= -999;
        for (int j = 0; j < c; j++) {
            if (m[i][j] > maior){
                maior = m[i][j];
        }   }
        if (maior < 0){maior = -maior;}
        for (int j = 0; j < c; j++) {
            m[i][j] *= maior;
            printf("%d ", m[i][j]); 
        }
        printf("\n");
    } 
    return 0;  
}