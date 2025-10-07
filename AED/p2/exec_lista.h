#ifndef EXEC_LISTA_H
#define EXEC_LISTA_H
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

// Funções de análise da lista
Elemento* maiorLista(Lista* l);
Elemento* menorLista(Lista* l);
int somaLista(Lista* l);
int somaListaRec(Lista* l);
float mediaLista(Lista* l);
int acimaMedia(Lista* l);
int repeteco(Lista* l, int x);

// Funções de conversão e operações
Lista* decimalParaBinario(int n);
Lista* intersecao(Lista* l1, Lista* l2);
void removerRepetidos(Lista* l);

#endif 