#include <stdio.h>

int main() {
    int sum = 0, suml=0, sumc = 0, sumdp = 0, sumds = 0, v[5][5] = {0};
    for (int i = 0; i < 5; i++) {
        printf("Digite os numeros da linha %d:\n", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("Digite o numero %d:", j + 1);
            scanf("%d", &v[i][j]);
            if (i==3){suml += v[i][j];}
            if (j==1){sumc += v[i][j];}
            if (i == j) {sumdp += v[i][j];}
            if (i + j == 4) {sumds += v[i][j];}
            sum += v[i][j];
        }
    }
    printf("a soma da linha 4 eh: %d\n", suml);
    printf("a soma da coluna 2 eh: %d\n", sumc);
    printf("a soma da diagonal principal eh: %d\n", sumdp);
    printf("a soma da diagonal secundaria eh: %d\n", sumds);
    printf("a soma dos elementos eh: %d\n", sum);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");   
    }
    return 0;
}