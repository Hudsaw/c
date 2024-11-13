// 11. Verificar rolagem de dado
#include <stdio.h>
#include "011.h"


void rolar_dados(void) {
    printf("11. Verificar rolagem de dado\n");
    int num = 0, dados [100] = {0}, cont = 0, rolados[6] = {0};

    printf("Digite o numero de vezes para rolar os dados!\n");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Role o dado e digite o valor da rolagem %d:", i + 1);
        scanf("%d", &dados[i]);
    }
    for (int i = 0; i < num; i++){
        if (dados[i] < 4){
            if (dados[i] < 3){
                if (dados[i] < 2){
                    rolados[0]++;
                }
                else{
                    rolados[1]++;
                }
            }
            else{
                rolados[2]++;
            }
        }
        else {
            if (dados[i] > 4){
                if (dados[i] > 5){
                    rolados[5]++;
                }
                else{
                    rolados[4]++;
                }
            }
            else{
                rolados[3]++;
            }           
        }
    }

    printf("O dado rolado caiu:\n %d vezes o numero 1,\n %d vezes o numero 2,\n %d vezes o numero 3,\n %d vezes o numero 4,\n %d vezes o numero 5,\n %d vezes o numero 6.\n", rolados[0], rolados[1], rolados[2], rolados[3], rolados[4], rolados[5]);
}
