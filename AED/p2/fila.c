#include <stdlib.h>
#include "fila.h"

Fila* criarFila() {
    Fila* f = malloc(sizeof(Fila));
    if (!f) return NULL;
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void inserir(Fila* f, int x) {
    Elemento* e = malloc(sizeof(Elemento));
    e->dado = x;
    e->prox = NULL; 

    if (!f->fim) {
        f->inicio = e;
        f->fim = e;
    } else {
        f->fim->prox = e;
        f->fim = e;
    }
}

int remover(Fila* f) {
    if (!f || !f->inicio) return -999; 

    Elemento* aux = f->inicio;
    int valor = aux->dado;

    f->inicio = aux->prox; 

    if (!f->inicio) {
        f->fim = NULL;
    }

    free(aux);
    return valor;
}

void destruirFila(Fila* f) {
    if (!f) return;
    while (f->fim) {
        retirar(f);
    }
    free(f);
}

int tamanho(Fila* f) {
    if (!f) return 0;
    Elemento* aux = f->fim;
    int cont = 0;
    while (aux) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void reinicializarFila(Fila* f, int valores[], int tamanho) {
    while (f->fim) {
        retirar(f);
    }
    for (int i = 0; i < tamanho; i++) {
        inserir(f, valores[i]);
    }
}