#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct {
    int dado;
    struct Elemento* prox;
} Elemento;

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
Elemento* primeiro(Lista* l);
Elemento* ultimo(Lista* l);

#endif