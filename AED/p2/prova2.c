#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "filas.h"
#include "recursividade.h"
#include "tad.h"
#include "tadpilha.h"

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

int main() {
    int opcao;
    char op;
    
    Fila* r = criarFila();
    
    int valores_r[] = {101, 102, 201, 301, 302};
    
    for (int i = 0; i < 5; i++) push(r, valores_r[i]);

    do {
        system("cls || clear");
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Exercicios de Pilha\n");
        printf("2. Exercicios de Recursividade\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {            
            case 1: {
                int sub_opcao;
                do {
                    system("cls || clear");
                    printf("\n=== EXERCICIOS DE REVISAO ===\n");
                    printf("1. Trafego Aereo\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &sub_opcao);
                    getchar();

                    switch (sub_opcao) {
                        case 1: trafego(); break;
                        case 0: break;
                        default: printf("Opcao invalida!\n");
                    }
                    if (sub_opcao != 0) pausar();
                } while (sub_opcao != 0);
                break;
            }
            
            case 0:
                printf("Saindo do programa.\n");
                break;
                
            default:
                printf("Opcao invalida! Tente novamente.\n");
                pausar();
                break;
        }
        
    } while (opcao != 0);

    // Liberar memória das pilhas
    destruirFila(r);

    return 0;
}