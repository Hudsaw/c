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
void push(Pilha* p, int valor);
int pop(Pilha* p);
int tamanho(Pilha* p);
void reinicializarPilha(Pilha* p, int valores[], int tamanho);

#endif