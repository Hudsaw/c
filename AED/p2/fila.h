/* fila.h */
#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
    int dado;
    struct Elemento* prox;
} Elemento;

typedef struct Fila {
    Elemento* inicio;
    Elemento* fim;
} Fila;

Fila* criarFila();
void inserir(Fila* f, int x);
int remover(Fila* f);
void destruirFila(Fila* f);
int tamanho(Fila* f);
void reinicializarFila(Fila* f, int valores[], int tamanho);

#endif