// 3. Somar elementos da matriz
#include <stdio.h>
#include "003.h"

void somar_elementos(void) {
    printf("3. Somar elementos da matriz\n");

    int num = 0, sum=0, sums = 0;
    int v[5][5] = {0};
    int escolha;

    printf("Vamos construir a matriz:\n");
    for (int i = 0; i < 5; i++) {
        printf("Digite os numeros da linha %d:\n", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("Digite o numero %d:", j + 1);
            scanf("%d", &v[i][j]);
        }
    }
    printf("\n");
    printf("A matriz M eh:\n");
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
           printf("%d ", v[i][j]); 
        }
        printf("\n");
    }
    
    do {
        printf("\nEscolha uma acao:\n");
        printf("1. Somar linha\n");
        printf("2. Somar coluna\n");
        printf("3. Somar diagonais\n");
        printf("4. Somar os elementos\n");
        printf("5. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        getchar();

        switch (escolha) {
            case 1:
                printf("Qual linha deseja somar:");
                scanf("%d", &num);
                sum = 0;
                for (int i = 0; i < 5; i++) {
                    sum += v[num-1][i];   
                }
                printf("a soma da linha %d eh: %d\n", num, sum);   
                break;
            case 2:
                printf("Qual coluna deseja somar:");
                scanf("%d", &num);
                sum = 0;
                for (int i = 0; i < 5; i++) {
                    sum += v[i][num-1];   
                }
                printf("a soma da coluna %d eh: %d\n", num, sum);
                break;
            case 3:
                sum = 0;
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (i == j) {
                            sum += v[i][j];
                        }
                        if (i + j == 4) {
                            sums += v[i][j];
                        }  
                    }
                }
                printf("a soma da diagonal principal eh: %d\n", sum);
                printf("a soma da diagonal secundaria eh: %d\n", sums);
                break;
            case 4:
                sum = 0;
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        sum += v[i][j];
                    }
                }
                printf("a soma dos elementos eh: %d\n", sum);
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha inválida. Tente novamente.\n");
                break;
        }
    } while (escolha != 5);
}