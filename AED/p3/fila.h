/* fila.h */
#ifndef FILA_H
#define FILA_H
#include "elemento.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
    Elemento* inicio;
    Elemento* fim;
} Fila;

Fila* criarFila();
void inserirFila(Fila* f, int x);
int removerFila(Fila* f);
void destruirFila(Fila* f);
int tamanhoFila(Fila* f);
void reinicializarFila(Fila* f, int valores[], int tamanho);
void imprimirFila(Fila* l);
void imprimirFilaChar(Fila* l);


#endif