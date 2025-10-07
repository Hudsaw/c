/* processo.h */
#ifndef PROCESSO_H
#define PROCESSO_H
#include <stdlib.h>
#include <stdio.h>

typedef struct Processo {
    int id;
    char name[50];
    int priority;
    int wait;
} Processo;

typedef struct NoProc {
    Processo proc;           
    struct NoProc* prox;
} NoProc;

typedef struct {
    NoProc* inicio;
    NoProc* fim;
} FilaProcessos;

FilaProcessos* criarFilaProcessos();
void enfileirarProcesso(FilaProcessos* fp, Processo p);
Processo matarMaiorEspera(FilaProcessos* fp);
Processo executarProcesso(FilaProcessos* fp);
void imprimirProcessos(FilaProcessos* fp);

#endif