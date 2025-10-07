/* processos.c */
#include "processo.h"
#include <stdio.h>


// Função para criar fila de processos
FilaProcessos* criarFilaProcessos() {
    FilaProcessos* fp = malloc(sizeof(FilaProcessos));
    fp->inicio = NULL;
    fp->fim = NULL;
    return fp;
}

// Enfileirar processo
void enfileirarProcesso(FilaProcessos* fp, Processo p) {
    NoProc* novo = malloc(sizeof(NoProc));
    novo->proc = p;
    novo->prox = NULL;

    if (!fp->fim) {
        fp->inicio = fp->fim = novo;
    } else {
        fp->fim->prox = novo;
        fp->fim = novo;
    }
}

// Matar processo com maior tempo de espera
Processo matarMaiorEspera(FilaProcessos* fp) {
    if (!fp || !fp->inicio) {
        printf("Sem processos.\n");
        exit(1);
    }

    NoProc *alvo = fp->inicio, *antAlvo = NULL;
    NoProc *atual = fp->inicio;
    NoProc *ant = NULL;
    int maxWait = -1;

    while (atual) {
        if (atual->proc.wait > maxWait) {
            maxWait = atual->proc.wait;
            alvo = atual;
            antAlvo = ant;
        }
        ant = atual;
        atual = atual->prox;
    }

    if (antAlvo) {
        antAlvo->prox = alvo->prox;
    } else {
        fp->inicio = alvo->prox;
    }

    if (fp->fim == alvo) {
        fp->fim = antAlvo;
    }

    Processo p = alvo->proc;
    free(alvo);
    printf("Processo %s (ID:%d) morto por alto tempo de espera (%d).\n", p.name, p.id, p.wait);
    return p;
}

// Executar próximo processo
Processo executarProcesso(FilaProcessos* fp) {
    if (!fp || !fp->inicio) {
        printf("Nenhum processo para executar.\n");
        exit(1);
    }

    NoProc* temp = fp->inicio;
    Processo p = temp->proc;
    fp->inicio = temp->prox;
    if (!fp->inicio) {
        fp->fim = NULL;
    }
    free(temp);
    printf("Processo %s (ID:%d) executado.\n", p.name, p.id);
    return p;
}

// Listar todos os processos
void imprimirProcessos(FilaProcessos* fp) {
    if (!fp || !fp->inicio) {
        printf("Nenhum processo na fila.\n");
        return;
    }
    printf("\n=== FILA DE PROCESSOS ===\n");
    NoProc* atual = fp->inicio;
    while (atual) {
        Processo p = atual->proc;
        printf("ID: %d | Nome: %s | Prioridade: %d | Espera: %d\n",
               p.id, p.name, p.priority, p.wait);
        atual = atual->prox;
    }
    printf("==========================\n");
}