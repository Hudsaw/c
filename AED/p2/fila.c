/* fila.c */
#include "fila.h"

Fila* criarFila() {
    Fila* f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void inserirFila(Fila* f, int x) {
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

int removerFila(Fila* f) {
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
        removerFila(f);
    }
    free(f);
}

int tamanhoFila(Fila* f) {
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
        removerFila(f);
    }
    for (int i = 0; i < n; i++) {
        inserirFila(f, valores[i]);
    }
}

void imprimirFila(Fila* f){
    if (!f) return;
    Elemento* aux = f->inicio; 
    while (aux) {     
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
}

void imprimirFilaChar(Fila* f){
    if (!f) return;
    Elemento* aux = f->inicio; 
    while (aux) {     
        printf("%c ", (char)aux->dado);
        aux = aux->prox;
    }
}