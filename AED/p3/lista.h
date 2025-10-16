#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "elemento.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	Elemento* inicio;
} Lista;

Lista* criarLista();
void destruirLista(Lista* l);
int tamanhoLista(Lista* l);
Elemento* buscarElemento(Lista* l, int x);
Elemento* buscarPosicao(Lista* l, int pos);
Elemento* inserirInicio(Lista* l, int x);
Elemento* inserirPosicao(Lista* l, int x, int pos);
Elemento* inserirLista(Lista* l, int x);
void removerLista(Lista* l, int x);
int removerListaRet(Lista* l);
Elemento* primeiro(Lista* l);
Elemento* ultimo(Lista* l);
void imprimirLista(Lista* l);


#endif