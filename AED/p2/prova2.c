#include "fila.h"
#include "filaviao.h"
#include "processo.h"
#include "lista.h"
#include "exec_fila.h"
#include "exec_lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int dado;
    struct Elemento* prox;
} Elemento;

// Protótipos auxiliares
void preencherFilaExemplo(Fila* f);
void preencherFilaCharExemplo(Fila* f);
void preencherListaExemplo(Lista* l);
void menuAviao();
void menuProcessos();

int main() {
    int op;
    do {
        printf("\n=== SUITE DE TESTES - FILAS E LISTAS ===\n");
        printf("1. Executar funções de Fila (inteiros)\n");
        printf("2. Executar funções de Fila (caracteres)\n");
        printf("3. Executar funções de Lista\n");
        printf("4. Simular Controle de Tráfego Aéreo (Aviões)\n");
        printf("5. Simular Gerenciador de Processos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        getchar(); // limpar buffer

        switch (op) {
            case 1: {
                Fila* f = criarFila();
                preencherFilaExemplo(f);
                int sub;
                do {
                    printf("\n--- Funções de Fila (inteiros) ---\n");
                    printf("1. Soma dos elementos\n");
                    printf("2. Maior elemento\n");
                    printf("3. Contar elementos (recursivo)\n");
                    printf("4. Remover negativos\n");
                    printf("5. Gerar fila com pares\n");
                    printf("6. Tempo total de atendimento (soma)\n");
                    printf("7. Intercalar duas filas\n");
                    printf("8. Inverter F1 em F2\n");
                    printf("9. Verificar se duas filas são iguais\n");
                    printf("0. Voltar\n");
                    printf("Escolha: ");
                    scanf("%d", &sub);
                    getchar();

                    if (sub == 7) {
                        Fila* f1 = criarFila(), *f2 = criarFila();
                        inserirFila(f1, 1); inserirFila(f1, 3);
                        inserirFila(f2, 2); inserirFila(f2, 4);
                        Fila* f3 = intercalarFilas(f1, f2);
                        printf("Fila intercalada: ");
                        while (f3->inicio) printf("%d ", removerFila(f3));
                        printf("\n");
                        destruirFila(f1); destruirFila(f2); destruirFila(f3);
                    } else if (sub == 8) {
                        Fila* f2 = criarFila();
                        inverterF1emF2(f, f2);
                        printf("F1 invertida em F2: ");
                        while (f2->inicio) printf("%d ", removerFila(f2));
                        printf("\n");
                        destruirFila(f2);
                        // restaurar f para testes posteriores
                        reinicializarFila(f, (int[]){1, -2, 3, 4, -5}, 5);
                    } else if (sub == 9) {
                        Fila* fA = criarFila(), *fB = criarFila();
                        inserirFila(fA, 1); inserirFila(fA, 2);
                        inserirFila(fB, 1); inserirFila(fB, 2);
                        printf("Filas iguais? %s\n", filasIguais(fA, fB) ? "Sim" : "Não");
                        destruirFila(fA); destruirFila(fB);
                    } else if (sub == 1) {
                        printf("Soma: %d\n", somaFila(f));
                    } else if (sub == 2) {
                        printf("Maior: %d\n", maiorFila(f));
                    } else if (sub == 3) {
                        printf("Contagem recursiva: %d\n", contarRecursivo(f));
                    } else if (sub == 4) {
                        removerNegativos(f);
                        printf("Fila sem negativos: ");
                        Fila* tmp = criarFila();
                        while (f->inicio) {
                            int v = removerFila(f);
                            printf("%d ", v);
                            inserirFila(tmp, v);
                        }
                        while (tmp->inicio) inserirFila(f, removerFila(tmp));
                        printf("\n");
                        destruirFila(tmp);
                        reinicializarFila(f, (int[]){1, -2, 3, 4, -5}, 5);
                    } else if (sub == 5) {
                        Fila* pares = paresFila(f);
                        printf("Pares: ");
                        while (pares->inicio) printf("%d ", removerFila(pares));
                        printf("\n");
                        destruirFila(pares);
                    } else if (sub == 6) {
                        printf("Tempo total de atendimento: %d minutos\n", tempoTotalAtendimento(f));
                    }
                } while (sub != 0);
                destruirFila(f);
                break;
            }

            case 2: {
                Fila* f = criarFila();
                preencherFilaCharExemplo(f);
                int sub;
                do {
                    printf("\n--- Funções de Fila (caracteres) ---\n");
                    printf("1. Verificar se só tem maiúsculas\n");
                    printf("2. Contar vogais (recursivo)\n");
                    printf("3. Inverter com pilha\n");
                    printf("0. Voltar\n");
                    printf("Escolha: ");
                    scanf("%d", &sub);
                    getchar();

                    if (sub == 1) {
                        printf("Só maiúsculas? %s\n", soMaiusculas(f) ? "Sim" : "Não");
                    } else if (sub == 2) {
                        printf("Vogais: %d\n", contarVogaisRec(f));
                    } else if (sub == 3) {
                        inverterFilaComPilha(f);
                        printf("Fila invertida: ");
                        while (f->inicio) printf("%c ", (char)removerFila(f));
                        printf("\n");
                        // recriar para próximos testes
                        preencherFilaCharExemplo(f);
                    }
                } while (sub != 0);
                destruirFila(f);
                break;
            }

            case 3: {
                Lista* l = criarLista();
                preencherListaExemplo(l);
                int sub, x;
                do {
                    printf("\n--- Funções de Lista ---\n");
                    printf("1. Maior e menor elemento\n");
                    printf("2. Soma e média\n");
                    printf("3. Contar acima da média\n");
                    printf("4. Contar ocorrências de X\n");
                    printf("5. Converter decimal para binário\n");
                    printf("6. Interseção de duas listas\n");
                    printf("0. Voltar\n");
                    printf("Escolha: ");
                    scanf("%d", &sub);
                    getchar();

                    if (sub == 1) {
                        printf("Maior: %d | Menor: %d\n", maiorLista(l), menorLista(l));
                    } else if (sub == 2) {
                        printf("Soma: %d | Média: %.2f\n", somaLista(l), mediaLista(l));
                    } else if (sub == 3) {
                        printf("Acima da média: %d\n", acimaMedia(l));
                    } else if (sub == 4) {
                        printf("Digite X: ");
                        scanf("%d", &x);
                        printf("Ocorrências de %d: %d\n", x, contaX(l, x));
                    } else if (sub == 5) {
                        printf("Digite um número decimal: ");
                        scanf("%d", &x);
                        Lista* bin = decimalParaBinario(x);
                        printf("%d em binário: ", x);
                        Elemento* p = bin->inicio;
                        while (p) { printf("%d", p->dado); p = p->prox; }
                        printf("\n");
                        destruirLista(bin);
                    } else if (sub == 6) {
                        Lista* l2 = criarLista();
                        inserirLista(l2, 20); inserirLista(l2, 30); inserirLista(l2, 40);
                        Lista* inter = intersecao(l, l2);
                        printf("Interseção: ");
                        Elemento* p = inter->inicio;
                        while (p) { printf("%d ", p->dado); p = p->prox; }
                        printf("\n");
                        destruirLista(l2); destruirLista(inter);
                    }
                } while (sub != 0);
                destruirLista(l);
                break;
            }

            case 4:
                menuAviao();
                break;

            case 5:
                menuProcessos();
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (op != 0);

    return 0;
}

// === Funções auxiliares ===

void preencherFilaExemplo(Fila* f) {
    reinicializarFila(f, (int[]){1, -2, 3, 4, -5}, 5);
}

void preencherFilaCharExemplo(Fila* f) {
    char str[] = "AeIoU";
    for (int i = 0; str[i]; i++) {
        inserirFila(f, (int)str[i]);
    }
}

void preencherListaExemplo(Lista* l) {
    inserirLista(l, 10);
    inserirLista(l, 20);
    inserirLista(l, 30);
    inserirLista(l, 25);
}

// === Menu Avião ===
void menuAviao() {
    FilaAviao* fa = criarFilaAviao();
    int op;
    do {
        printf("\n--- Controle de Tráfego Aéreo ---\n");
        printf("1. Adicionar avião à fila\n");
        printf("2. Autorizar decolagem (remover primeiro)\n");
        printf("3. Listar todos os aviões\n");
        printf("4. Mostrar primeiro avião\n");
        printf("5. Número de aviões na fila\n");
        printf("6. Furar fila (avião prioritário)\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);
        getchar();

        if (op == 1) {
            Aviao a;
            printf("Modelo: "); fgets(a.modelo, 50, stdin); a.modelo[strcspn(a.modelo, "\n")] = 0;
            printf("Prefixo: "); fgets(a.prefixo, 10, stdin); a.prefixo[strcspn(a.prefixo, "\n")] = 0;
            printf("Empresa: "); fgets(a.empresa, 50, stdin); a.empresa[strcspn(a.empresa, "\n")] = 0;
            printf("Número do voo: "); scanf("%d", &a.numVoo); getchar();
            printf("Hora de decolagem (HH:MM): "); fgets(a.horaDecolagem, 10, stdin); a.horaDecolagem[strcspn(a.horaDecolagem, "\n")] = 0;
            enfileirarAviao(fa, a);
        } else if (op == 2) {
            if (fa->inicio) {
                Aviao a = desenfileirarAviao(fa);
                printf("Decolando: %s (%s) - Voo %d às %s\n", a.modelo, a.prefixo, a.numVoo, a.horaDecolagem);
            } else {
                printf("Nenhum avião na fila!\n");
            }
        } else if (op == 3) {
            listarFila(fa);
        } else if (op == 4) {
            mostrarPrimeiro(fa);
        } else if (op == 5) {
            printf("Aviões na fila: %d\n", tamanhoFilaAviao(fa));
        } else if (op == 6) {
            Aviao a = {"F-16 Militar", "XX-PRI", "Força Aérea", 9999, "IMEDIATO"};
            furarFila(fa, a);
            printf("Avião prioritário entrou na frente da fila!\n");
        }
    } while (op != 0);
}

// === Menu Processos ===
void menuProcessos() {
    FilaProcessos* fp = criarFilaProcessos();
    int op;
    do {
        printf("\n--- Gerenciador de Processos ---\n");
        printf("1. Incluir novo processo\n");
        printf("2. Executar próximo processo\n");
        printf("3. Matar processo com maior espera\n");
        printf("4. Imprimir fila de processos\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);
        getchar();

        if (op == 1) {
            Processo p;
            printf("ID: "); scanf("%d", &p.id); getchar();
            printf("Nome: "); fgets(p.name, 50, stdin); p.name[strcspn(p.name, "\n")] = 0;
            printf("Prioridade (1-5): "); scanf("%d", &p.priority); getchar();
            printf("Tempo de espera: "); scanf("%d", &p.wait); getchar();
            enfileirarProcesso(fp, p);
        } else if (op == 2) {
            if (fp->inicio) {
                Processo p = executarProcesso(fp);
                printf("Executado: %s (ID=%d)\n", p.name, p.id);
            } else {
                printf("Nenhum processo na fila!\n");
            }
        } else if (op == 3) {
            if (fp->inicio) {
                Processo p = matarMaiorEspera(fp);
                printf("Processo morto: %s (wait=%d)\n", p.name, p.wait);
            } else {
                printf("Fila vazia!\n");
            }
        } else if (op == 4) {
            imprimirProcessos(fp);
        }
    } while (op != 0);
}