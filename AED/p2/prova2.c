#include "elemento.h"
#include "fila.h"
#include "filaviao.h"
#include "processo.h"
#include "lista.h"
#include "exec_fila.h"
#include "exec_lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Protótipos auxiliares
void preencherFilaExemplo(Fila* f);
void preencherFilaCharExemplo(Fila* f);
void preencherListaExemplo(Lista* l);
void menuFila();
void menuLista();
void menuAviao();
void menuProcessos();

int main() {
    int op;
    do {
        printf("\n=== SUITE DE TESTES - FILAS E LISTAS ===\n");
        printf("1. Executar funcoes de Fila\n");
        printf("2. Executar funcoes de Lista\n");
        printf("3. Simular Controle de Trafego Aereo (Avioes)\n");
        printf("4. Simular Gerenciador de Processos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
        getchar(); // limpar buffer

        switch (op) {
            case 1:
                menuFila();
                break;
            case 2:
                menuLista();
                break;
            case 3:
                menuAviao();
                break;
            case 4:
                menuProcessos();
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (op != 0);

    return 0;
}

// === Funções auxiliares ===
void preencherFila(Fila* f, int a, int b, int c, int d, int e) {
    inserirFila(f, a);
    inserirFila(f, b);
    inserirFila(f, c);
    inserirFila(f, d);
    inserirFila(f, e);
}

void preencherLista(Lista* l, int a, int b, int c, int d, int e) {
    inserirLista(l, a);
    inserirLista(l, b);
    inserirLista(l, c);
    inserirLista(l, d);
    inserirLista(l, e);
}

void menuFila(){
    int sub;
    do {
        printf("\n--- Funcoes de Fila (inteiros) ---\n");
        printf("01. Soma dos elementos\n");
        printf("02. Maior elemento\n");
        printf("03. Contar elementos (recursivo)\n");
        printf("04. Remover negativos\n");
        printf("05. Gerar fila com pares\n");
        printf("06. Tempo total de atendimento (soma)\n");
        printf("07. Intercalar duas filas\n");
        printf("08. Inverter F1 em F2\n");
        printf("09. Verificar se duas filas sao iguais\n");
        printf("10. Verificar se so tem maiusculas\n");
        printf("11. Contar vogais (recursivo)\n");
        printf("12. Inverter com pilha\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &sub);
        getchar();

        switch (sub) {
            case 1:{
                Fila* f = criarFila();
                preencherFila(f, 10, 20, 30, 25, 20);
                printf("\nFila: ");
                imprimirFila(f);
                printf("Soma: %d\n", somaFila(f));
                destruirFila(f);
                break;
            }
            case 2:{
                Fila* f = criarFila();
                preencherFila(f, 10, 20, 30, 25, 20);
                printf("\nFila: ");
                imprimirFila(f);
                printf("Maior: %d\n", maiorFila(f));
                destruirFila(f);
                break;
            }
            case 3:{
                Fila* f = criarFila();
                preencherFila(f, 10, 20, 30, 25, 20);
                printf("\nFila: ");
                imprimirFila(f);
                printf("Contagem recursiva: %d\n", contarRecursivo(f));
                destruirFila(f);
                break;
            }
            case 4:{
                Fila* f = criarFila();
                preencherFila(f, 10, -20, 30, -25, 20);
                printf("\nFila inteira: ");
                imprimirFila(f);
                printf("\nFila sem negativos: ");
                removerNegativos(f);
                imprimirFila(f);
                destruirFila(f);
                break;
            }
            case 5: {
                Fila* f1 = criarFila();
                preencherFila(f1, 10, 21, 30, 25, 20);
                printf("\nFila inteira: ");
                imprimirFila(f1);
                printf("\nFila de pares: ");
                Fila* f2= paresFila(f1);
                imprimirFila(f2);
                destruirFila(f1); destruirFila(f2);
                break;
            }
            case 6:{
                Fila* f = criarFila();
                preencherFila(f, 1, 2, 3, 5, 2);
                printf("\nFila: ");
                imprimirFila(f);
                printf("Tempo total de atendimento: %d minutos\n", tempoTotalAtendimento(f));
                destruirFila(f);
                break;
            }
            case 7: {
                Fila* f1 = criarFila(), *f2 = criarFila();
                preencherFila(f1, 10, 20, 30, 40, 50);
                printf("\nFila 1: ");
                imprimirFila(f1);
                preencherFila(f2, 15, 25, 35, 45, 55);
                printf("\nFila 2: ");
                imprimirFila(f2);
                Fila* f3 = intercalarFilas(f1, f2);
                printf("\nFila Intercalada: ");
                imprimirFila(f3);
                destruirFila(f1); destruirFila(f2); destruirFila(f3);
                break;
            }
            case 8: {
                Fila* f1 = criarFila(), *f2 = criarFila();
                preencherFila(f1, 10, 20, 30, 25, 20);
                printf("\nFila 1: ");
                imprimirFila(f1);
                inverterF1emF2(f1, f2);
                printf("F1 invertida em F2: ");
                imprimirFila(f2);
                destruirFila(f1); destruirFila(f2);
                break;
            }
            case 9: {
                Fila* f1 = criarFila(), *f2 = criarFila();
                preencherFila(f1, 10, 20, 30, 25, 20);
                printf("\nFila 1: ");
                imprimirFila(f1);
                preencherFila(f2, 10, 20, 30, 25, 20);
                printf("\nFila 2: ");
                imprimirFila(f2);
                printf("Filas iguais? %s\n", filasIguais(f1, f1) ? "Sim" : "Nao");
                destruirFila(f1); destruirFila(f2);
                break;
            }
            case 10:{
                Fila* f = criarFila();
                preencherFila(f, 'A', 'e', 'I', 'o', 'V');
                printf("\nFila: ");
                imprimirFilaChar(f);
                printf("So maiusculas? %s\n", soMaiusculas(f) ? "Sim" : "Nao");
                destruirFila(f);
                break;
            }
            case 11:{
                Fila* f = criarFila();
                preencherFila(f, 'A', 'e', 'I', 'o', 'V');
                printf("\nFila: ");
                imprimirFilaChar(f);
                printf("Vogais: %d\n", contarVogaisRec(f));
                destruirFila(f);
                break;
            }
            case 12:{
                Fila* f = criarFila();
                preencherFila(f, 10, 20, 30, 25, 20);
                printf("\nFila normal: ");
                imprimirFila(f);
                inverterFilaComPilha(f);
                printf("Fila invertida: ");
                imprimirFila(f);
                destruirFila(f);
                break;
            }
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (sub != 0);
}

void menuLista(){
    int sub, x;
    do {
        printf("\n--- Funcoes de Lista ---\n");
        printf("1. Maior e menor elemento\n");
        printf("2. Soma e media\n");
        printf("3. Contar acima da media\n");
        printf("4. Contar ocorrencias de X\n");
        printf("5. Converter decimal para binario\n");
        printf("6. Intersecao de duas listas\n");
        printf("7. Listas sem repeticao\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &sub);
        getchar();

        switch (sub) {
            case 1: {
                Lista* l = criarLista();
                preencherLista(l, 10, 20, 30, 25, 20);
                printf("\nLista: ");
                imprimirLista(l);
                Elemento* maior = maiorLista(l);
                Elemento* menor = menorLista(l);
                printf("\nMaior: %d | Menor: %d\n", maior ? maior->dado : 0, menor ? menor->dado : 0);
                destruirLista(l);
                break;
            }
            case 2:{
                Lista* l = criarLista();
                preencherLista(l, 10, 20, 30, 25, 20);
                printf("\nLista: ");
                imprimirLista(l);
                printf("Soma: %d | Media: %.2f\n", somaLista(l), mediaLista(l));
                destruirLista(l);
                break;
            }
            case 3:{
                Lista* l = criarLista();
                preencherLista(l, 10, 20, 30, 25, 20);
                printf("\nLista: ");
                imprimirLista(l);
                printf("Acima da media: %d\n", acimaMedia(l));
                destruirLista(l);
                break;
            }
            case 4:{
                Lista* l = criarLista();
                preencherLista(l, 10, 20, 30, 25, 20);
                printf("\nLista: ");
                imprimirLista(l);
                printf("\nDigite X: ");
                scanf("%d", &x);
                printf("Ocorrencias de %d: %d\n", x, repeteco(l, x));
                destruirLista(l);
                break;
            }
            case 5:{
                printf("\nDigite um numero decimal: ");
                scanf("%d", &x);
                Lista* bin = decimalParaBinario(x);
                printf("%d em binario: ", x);
                imprimirLista(bin);
                printf("\n");
                destruirLista(bin);
                break;
            }
            case 6: {
                Lista* l1 = criarLista(), *l2 = criarLista();
                preencherLista(l1, 10, 20, 30, 25, 20);
                printf("\nLista 1: ");
                imprimirLista(l1);
                preencherLista(l2, 10, 20, 30, 40, 50);
                printf("\nLista 2: ");
                imprimirLista(l2);
                Lista* inter = intersecao(l1, l2);
                printf("\nIntersecao: ");
                imprimirLista(inter);
                printf("\n");
                destruirLista(l1); destruirLista(l2); destruirLista(inter);
                break;
            }
             case 7: {
                Lista* l = criarLista();
                preencherLista(l, 10, 20, 30, 25, 20);
                printf("\nLista: ");
                imprimirLista(l);
                removerRepetidos(l);
                printf("\nLista sem repetidos: ");
                imprimirLista(l);
                printf("\n");
                destruirLista(l);
                break;
            }
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (sub != 0);
}

// === Menu Avião ===
void menuAviao() {
    FilaAviao* fa = criarFilaAviao();
    int op;
    do {
        printf("\n--- Controle de Trafego Aereo ---\n");
        printf("1. Adicionar aviao a fila\n");
        printf("2. Autorizar decolagem (remover primeiro)\n");
        printf("3. Listar todos os avioes\n");
        printf("4. Mostrar primeiro aviao\n");
        printf("5. Numero de avioes na fila\n");
        printf("6. Furar fila (aviao prioritario)\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1: {
                Aviao a;
                printf("Modelo: "); fgets(a.modelo, 50, stdin); a.modelo[strcspn(a.modelo, "\n")] = 0;
                printf("Prefixo: "); fgets(a.prefixo, 10, stdin); a.prefixo[strcspn(a.prefixo, "\n")] = 0;
                printf("Empresa: "); fgets(a.empresa, 50, stdin); a.empresa[strcspn(a.empresa, "\n")] = 0;
                printf("Numero do voo: "); scanf("%d", &a.numVoo); getchar();
                printf("Hora de decolagem (HH:MM): "); fgets(a.horaDecolagem, 10, stdin); a.horaDecolagem[strcspn(a.horaDecolagem, "\n")] = 0;
                enfileirarAviao(fa, a);
                break;
            }
            case 2:
                if (fa->inicio) {
                    Aviao a = desenfileirarAviao(fa);
                    printf("Decolando: %s (%s) - Voo %d as %s\n", a.modelo, a.prefixo, a.numVoo, a.horaDecolagem);
                } else {
                    printf("Nenhum aviao na fila!\n");
                }
                break;
            case 3:
                listarFila(fa);
                break;
            case 4:
                mostrarPrimeiro(fa);
                break;
            case 5:
                printf("Avioes na fila: %d\n", tamanhoFilaAviao(fa));
                break;
            case 6: {
                Aviao a = {"F-16 Militar", "XX-PRI", "Forca Aerea", 9999, "IMEDIATO"};
                furarFila(fa, a);
                printf("Aviao prioritario entrou na frente da fila!\n");
                break;
            }
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
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
        printf("2. Executar proximo processo\n");
        printf("3. Matar processo com maior espera\n");
        printf("4. Imprimir fila de processos\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1: {
                Processo p;
                printf("ID: "); scanf("%d", &p.id); getchar();
                printf("Nome: "); fgets(p.name, 50, stdin); p.name[strcspn(p.name, "\n")] = 0;
                printf("Prioridade (1-5): "); scanf("%d", &p.priority); getchar();
                printf("Tempo de espera: "); scanf("%d", &p.wait); getchar();
                enfileirarProcesso(fp, p);
                break;
            }
            case 2:
                if (fp->inicio) {
                    Processo p = executarProcesso(fp);
                    printf("Executado: %s (ID=%d)\n", p.name, p.id);
                } else {
                    printf("Nenhum processo na fila!\n");
                }
                break;
            case 3:
                if (fp->inicio) {
                    Processo p = matarMaiorEspera(fp);
                    printf("Processo morto: %s (wait=%d)\n", p.name, p.wait);
                } else {
                    printf("Fila vazia!\n");
                }
                break;
            case 4:
                imprimirProcessos(fp);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (op != 0);
}