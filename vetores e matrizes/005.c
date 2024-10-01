// 5. Atualizar movimentacao de conta
#include <stdio.h>
#include "005.h"

void atualizar_conta(void) {
    printf("5. Atualizar movimentacao de conta\n");
    
    int num = 1, ope = 1;
    printf("Digite o numero de clientes!\n");
    scanf("%d", &num);
    
    int conta[100] = {0};
    float saldo[100] = {0};

    printf("Cadastre os dados dos clientes:\n");
    for (int i = 0; i < num; i++) {
        printf("Digite o numero e saldo da conta %d:\n", i + 1);
        scanf("%d %f", &conta[i], &saldo[i]);
    }
    
    printf("Extrato dos clientes:\n");
    for (int i = 0; i < num; i++){
        printf("Conta: %d, Saldo:R$ %.2f\n", conta[i],saldo[i]); 
    }

    printf("Digite o numero de operacoes do dia!\n");
    scanf("%d", &ope);

    for (int i = 0; i < ope; i++) {
        int numconta;
        char tipo;
        float valor;
        printf("Digite o numero da conta:\n");
        scanf("%d", &numconta);
        for (int j = 0; j < num; j++){
            if (numconta == conta[j]){
                printf("Digite o tipo de operacao(C ou D):\n");
                scanf(" %c", &tipo);
                float valor = 0;
                if (tipo == 'C'){
                    printf("Digite o valor da operacao:\n");
                    scanf("%f", &valor);
                    saldo[j] += valor;    
                }
                else if(tipo == 'D'){
                    printf("Digite o valor da operacao:\n");
                    scanf("%f", &valor);
                    saldo[j] -= valor;
                }
                break;
            }
        }
    }
        
    printf("Extrato dos clientes atualizado:\n");
    for (int i = 0; i < num; i++){
        printf("Conta: %d, Saldo:R$ %.2f\n", conta[i],saldo[i]); 
    }
}