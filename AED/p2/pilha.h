#ifndef PILHA_H
#define PILHA_H

typedef struct elemento {
    int dado;
    struct elemento *prox;
} Elemento;

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