/* fila.c */
#include "fila.h"

Fila* criarFila() {
    Fila* f = malloc(sizeof(Fila));
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
    if (!f || !f->inicio) {
        printf("Fila vazia!\n");
        return -999;
    }
    Elemento* aux = f->inicio;
    int valor = aux->dado;
    f->inicio = aux->prox;
    if (!f->inicio) f->fim = NULL;
    free(aux);
    return valor;
}

void destruirFila(Fila* f) {
    while (f && f->inicio) {
        remover(f);
    }
    free(f);
}

int tamanho(Fila* f) {
    int cont = 0;
    Elemento* aux = f->inicio;
    while (aux) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void reinicializarFila(Fila* f, int valores[], int n) {
    while (f->inicio) {
        remover(f);
    }
    for (int i = 0; i < n; i++) {
        inserir(f, valores[i]);
    }
}