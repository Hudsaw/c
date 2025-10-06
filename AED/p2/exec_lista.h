#ifndef EXEC_LISTA_H
#define EXEC_LISTA_H

#include "lista.h"

// Funções de análise da lista
int maiorLista(Lista* l);
int menorLista(Lista* l);
int somaLista(Lista* l);
double mediaLista(Lista* l);
int acimaMedia(Lista* l);
int contaX(Lista* l, int x);

// Funções de conversão e operações
Lista* decimalParaBinario(int n);
Lista* intersecao(Lista* l1, Lista* l2);

#endif 