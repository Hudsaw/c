#include <stdlib.h>
#include "pilha.h"

Pilha* criarPilha() {
    Pilha* p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void inserirPilha(Pilha* p, int x) {
    Elemento* e = malloc(sizeof(Elemento));
    if (!e) return;
    e->dado = x;
    e->prox = p->topo;
    p->topo = e;
}

int removerPilha(Pilha* p) {
    if (!p->topo) return -999;
    Elemento* aux = p->topo;
    p->topo = aux->prox;
    int valor = aux->dado;
    free(aux);
    return valor;
}

void destruirPilha(Pilha* p) {
    while (p->topo) {
        pop(p);
    }
    free(p);
}

int tamanhoPilha(Pilha* p) {
    Elemento* aux = p->topo;
    int cont = 0;
    while (aux) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void reinicializarPilha(Pilha* p, int valores[], int tamanho) {
    while (p->topo) {
        pop(p);
    }
    for (int i = 0; i < tamanho; i++) {
        push(p, valores[i]);
    }
}