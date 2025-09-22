/* prova2.c */
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "filaviao.h"
#include "processo.h"

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

int main() {
    int opcao;
    do {
        system("cls || clear");
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Trafego Aereo\n");
        printf("2. Simulacao de Processos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Consumir \n

        switch (opcao) {
            case 1: {
                FilaAviao* fila = criarFilaAviao();
                int sub;

                do {
                    system("cls || clear");
                    printf("\n=== TRAFEGO AEREO ===\n");
                    printf("1. Adicionar aviao\n");
                    printf("2. Autorizar decolagem\n");
                    printf("3. Listar fila\n");
                    printf("4. Mostrar primeiro\n");
                    printf("5. Furar fila (prioridade)\n");
                    printf("6. Ver quantidade de avioes\n");
                    printf("0. Voltar\n");
                    printf("Opcao: ");
                    scanf("%d", &sub);
                    getchar();

                    Aviao a;
                    switch (sub) {
                        case 1:
                            printf("Modelo: "); scanf("%s", a.modelo);
                            printf("Prefixo: "); scanf("%s", a.prefixo);
                            printf("Empresa: "); scanf("%s", a.empresa);
                            printf("Numero do voo: "); scanf("%d", &a.numVoo);
                            printf("Hora de decolagem: "); scanf("%s", a.horaDecolagem);
                            enfileirarAviao(fila, a);
                            break;

                        case 2:
                            if (fila && fila->inicio) {
                                Aviao decolado = desenfileirarAviao(fila);
                                printf("Aviao %s (%d) autorizado a decolar.\n", decolado.modelo, decolado.numVoo);
                            } else {
                                printf("Fila vazia!\n");
                            }
                            pausar();
                            break;

                        case 3:
                            listarFila(fila);
                            pausar();
                            break;

                        case 4:
                            mostrarPrimeiro(fila);
                            pausar();
                            break;

                        case 5:
                            printf("(Prioridade) Modelo: "); scanf("%s", a.modelo);
                            printf("(Prioridade) Prefixo: "); scanf("%s", a.prefixo);
                            printf("(Prioridade) Empresa: "); scanf("%s", a.empresa);
                            printf("(Prioridade) Voo: "); scanf("%d", &a.numVoo);
                            printf("(Prioridade) Hora: "); scanf("%s", a.horaDecolagem);
                            furarFila(fila, a);
                            break;

                        case 6:
                            printf("Avioes na fila: %d\n", tamanhoFilaAviao(fila));
                            pausar();
                            break;

                        case 0:
                            printf("Voltando...\n");
                            break;

                        default:
                            printf("Opcao invalida!\n");
                            pausar();
                    }
                } while (sub != 0);
                break;
            }

            case 2: {
                FilaProcessos* fp = criarFilaProcessos();
                int sub;

                // Processos iniciais
                Processo p1 = {104, "Window Manager", 4, 20};
                Processo p2 = {201, "Chrome", 3, 45};
                Processo p3 = {99, "Antivirus", 2, 10};
                enfileirarProcesso(fp, p1);
                enfileirarProcesso(fp, p2);
                enfileirarProcesso(fp, p3);

                do {
                    system("cls || clear");
                    printf("\n=== SIMULACAO DE PROCESSOS ===\n");
                    printf("1. Adicionar processo\n");
                    printf("2. Matar processo com maior espera\n");
                    printf("3. Executar proximo processo\n");
                    printf("4. Listar processos\n");
                    printf("0. Voltar\n");
                    printf("Opcao: ");
                    scanf("%d", &sub);
                    getchar();

                    Processo p;
                    switch (sub) {
                        case 1:
                            printf("ID: "); scanf("%d", &p.id);
                            printf("Nome: "); scanf("%s", p.name);
                            printf("Prioridade: "); scanf("%d", &p.priority);
                            printf("Tempo de espera: "); scanf("%d", &p.wait);
                            enfileirarProcesso(fp, p);
                            break;

                        case 2:
                            matarMaiorEspera(fp);
                            pausar();
                            break;

                        case 3:
                            executarProcesso(fp);
                            pausar();
                            break;

                        case 4:
                            imprimirProcessos(fp);
                            pausar();
                            break;

                        case 0:
                            printf("Voltando...\n");
                            break;

                        default:
                            printf("Opcao invalida!\n");
                            pausar();
                    }
                } while (sub != 0);
                break;
            }

            case 0:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao inválida! Tente novamente.\n");
                pausar();
        }
    } while (opcao != 0);

    return 0;
}