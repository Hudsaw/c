#ifndef PILHA_H
#define PILHA_H
#include "elemento.h"

typedef struct {
    Elemento *topo;
} Pilha;

// Funções básicas da pilha
Pilha* criarPilha();
void destruirPilha(Pilha* p);
void inserirPilha(Pilha* p, int valor);
int removerPilha(Pilha* p);
int tamanhoPilha(Pilha* p);
void reinicializarPilha(Pilha* p, int valores[], int tamanho);

#endif