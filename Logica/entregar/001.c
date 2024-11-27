#include <stdio.h>

int main() {
    int num = 0, dados = 0, cont = 0, rolados[6] = {0};
    printf("Digite o numero de vezes para rolar os dados!\n");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        printf("Role o dado e digite o valor da rolagem %d:", i + 1);
        scanf("%d", &dados);
        rolados[dados-1]+=1; 
    }
    printf("O dado rolado caiu:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d vezes o numero %d.\n", rolados[i], i+1);
    }
    return 0;
}