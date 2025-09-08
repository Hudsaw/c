#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "revisao.h"
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
    
    // Pilhas originais
    Pilha* r_original = criarPilha();
    Pilha* s_original = criarPilha();
    Pilha* t_original = criarPilha();
    
    // Valores iniciais
    int valores_r[] = {10, 15, 20, 25, 30};
    int valores_s[] = {'+', '-', '*', '/'};
    int valores_t[] = {10, 15, 20, 25, 30};
    
    // Inicializar pilhas originais
    for (int i = 0; i < 5; i++) push(r_original, valores_r[i]);
    for (int i = 0; i < 4; i++) push(s_original, valores_s[i]);
    for (int i = 0; i < 5; i++) push(t_original, valores_t[i]);

    do {
        system("cls || clear");
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Exercicios de Revisao\n");
        printf("2. Exercicios de Recursividade\n");
        printf("3. Exercicios de TAD\n");
        printf("4. Exercicios de Pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer

        switch (opcao) {
            case 4: {
                int sub_opcao;
                do {
                    system("cls || clear");
                    printf("\n=== EXERCICIOS DE PILHA ===\n");
                    printf("1. Conversao para binario\n");
                    printf("2. Expressao pareada\n");
                    printf("3. Sequencia invertida\n");
                    printf("4. Estacionamento\n");
                    printf("5. Igualdade de pilhas\n");
                    printf("6. Comparar tamanho\n");
                    printf("7. Inverter pilha\n");
                    printf("8. Balanceamento\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &sub_opcao);
                    getchar();

                    // CRIAR CÓPIAS PARA CADA EXERCÍCIO
                    Pilha* r_copia = copiarPilha(r_original);
                    Pilha* s_copia = copiarPilha(s_original);
                    Pilha* t_copia = copiarPilha(t_original);

                    switch (sub_opcao) {
                        case 1: pilha1_binario(); break;
                        case 2: printf("Resultado: %d\n", pilha2_pareada(r_copia, s_copia)); break;
                        case 3: pilha3_invertida(r_copia); break;
                        case 4: pilha4_estacionamento(); break;
                        case 5: 
                            if (pilha5_igualdade(r_copia, t_copia)) 
                                printf("Pilhas iguais\n");
                            else 
                                printf("Pilhas diferentes\n");
                            break;
                        case 6: pilha6_comparar_tamanho(r_copia, s_copia); break;
                        case 7: pilha7_inverter_pilha(s_copia); break;
                        case 8: pilha8_balanceamento(); break;
                        case 0: break;
                        default: printf("Opcao invalida!\n");
                    }
                    if (r_copia) destruirPilha(r_copia);
                    if (s_copia) destruirPilha(s_copia);
                    if (t_copia) destruirPilha(t_copia);
                    if (sub_opcao != 0) pausar();
                } while (sub_opcao != 0);
                break;
            }
            
            case 3: {
                int sub_opcao;
                do {
                    system("cls || clear");
                    printf("\n=== EXERCICIOS DE TAD ===\n");
                    printf("1. Retangulo\n");
                    printf("2. Aluno\n");
                    printf("3. Moeda\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &sub_opcao);
                    getchar();

                    switch (sub_opcao) {
                        case 1: tad1_retangulo(); break;
                        case 2: tad2_aluno(); break;
                        case 3: tad3_moeda(); break;
                        case 0: break;
                        default: printf("Opcao invalida!\n");
                    }
                    if (sub_opcao != 0) pausar();
                } while (sub_opcao != 0);
                break;
            }
            
            case 2: {
                int sub_opcao;
                do {
                    system("cls || clear");
                    printf("\n=== EXERCICIOS DE RECURSIVIDADE ===\n");
                    printf("1. Fatorial\n");
                    printf("2. Soma\n");
                    printf("3. Divisao\n");
                    printf("4. Exponencial\n");
                    printf("5. Vetor\n");
                    printf("6. Inversao\n");
                    printf("7. Binario\n");
                    printf("8. Contador\n");
                    printf("9. Fibonacci\n");
                    printf("10. Padovan\n");
                    printf("11. Tribonacci\n");
                    printf("12. Jacobsthal\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &sub_opcao);
                    getchar();

                    switch (sub_opcao) {
                        case 1: rec1_fatorial(); break;
                        case 2: rec2_soma(); break;
                        case 3: rec3_divisao(); break;
                        case 4: rec4_exponencial(); break;
                        case 5: rec5_vetor(); break;
                        case 6: rec6_inversao(); break;
                        case 7: rec7_binario(); break;
                        case 8: rec8_contador(); break;
                        case 9: rec9_fibonacci(); break;
                        case 10: rec10_padovan(); break;
                        case 11: rec11_tribonacci(); break;
                        case 12: rec12_jacobsthal(); break;
                        case 0: break;
                        default: printf("Opcao invalida!\n");
                    }
                    if (sub_opcao != 0) pausar();
                } while (sub_opcao != 0);
                break;
            }
            
            case 1: {
                int sub_opcao;
                do {
                    system("cls || clear");
                    printf("\n=== EXERCICIOS DE REVISAO ===\n");
                    printf("1. Ponteiros e modificacao\n");
                    printf("2. Comparar enderecos\n");
                    printf("3. Ordenar valores\n");
                    printf("4. Enderecos de array\n");
                    printf("5. Imprimir array\n");
                    printf("6. Valores pares\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &sub_opcao);
                    getchar();

                    switch (sub_opcao) {
                        case 1: revisao1_ponteiros(); break;
                        case 2: revisao2_enderecos(); break;
                        case 3: revisao3_ordenar(); break;
                        case 4: revisao4_array_floats(); break;
                        case 5: revisao5_imprimir_array(); break;
                        case 6: revisao6_valores_pares(); break;
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
    destruirPilha(r_original);
    destruirPilha(s_original);
    destruirPilha(t_original);

    return 0;
}