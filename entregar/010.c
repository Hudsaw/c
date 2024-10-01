#include <stdio.h>

int main() {
    int num = 1, ope = 1, conta[100] = {0}; 
    float saldo[100] = {0};
    printf("Digite o numero de clientes!\n"); scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        printf("Digite o numero e saldo da conta %d:\n", i + 1);
        scanf("%d %f", &conta[i], &saldo[i]); }
    printf("Digite o numero de operacoes do dia!\n"); scanf("%d", &ope);
    for (int i = 0; i < ope; i++) {int numconta = 0; 
        printf("Digite o numero da conta:\n");
        scanf("%d", &numconta);
        for (int j = 0; j < num; j++){char tipo = {0}; 
            if (numconta == conta[j]){ float valor = 0;
                printf("Digite o tipo de operacao(C ou D):\n"); scanf(" %c", &tipo);
                if (tipo == 'C'){
                    printf("Digite o valor da operacao:\n");
                    scanf("%f", &valor); saldo[j] += valor;    
                }
                else if(tipo == 'D'){
                    printf("Digite o valor da operacao:\n");
                    scanf("%f", &valor); saldo[j] -= valor;
                }
                break;
    }   }   } 
    printf("Extrato dos clientes atualizado:\n");
    for (int i = 0; i < num; i++){
        printf("Conta: %d, Saldo:R$ %.2f\n", conta[i],saldo[i]); 
    }
    return 0;
}