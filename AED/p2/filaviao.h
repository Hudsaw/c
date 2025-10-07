/* filaviao.h */
#ifndef FILAVIAO_H
#define FILAVIAO_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char modelo[50];
    char prefixo[10];
    char empresa[50];
    int numVoo;
    char horaDecolagem[10];
} Aviao;

typedef struct ElementoAviao {
    Aviao aviao;
    struct ElementoAviao* prox;
} ElementoAviao;

typedef struct {
    ElementoAviao* inicio;
    ElementoAviao* fim;
} FilaAviao;

// Funções da fila de aviões
FilaAviao* criarFilaAviao();
void enfileirarAviao(FilaAviao* f, Aviao a);
Aviao desenfileirarAviao(FilaAviao* f);
void listarFila(FilaAviao* f);
void mostrarPrimeiro(FilaAviao* f);
void furarFila(FilaAviao* f, Aviao a);
int tamanhoFilaAviao(FilaAviao* f);

#endif