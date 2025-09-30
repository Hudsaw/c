#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Elemento{
	int dado;
	struct Elemento* prox;
} Elemento;

typedef struct Lista{
	Elemento* inicio;
} Lista;

// cria uma lista com tamanho definido
Lista* criarLista();

// destroi a lista
void destruirLista(Lista* l);

// retorna o tamanho da lista (numero de elementos inseridos)
int tamanho(Lista* l);

// busca um dado pela chave x. retorna NULL em caso de falha
Elemento* buscarElemento(Lista* l, int x);

// busca um dado pela posicao pos. retorna NULL em caso de falha
Elemento* buscarPosicao(Lista* l, int pos);

// insere um dado pela (chave x) no inicio da lista. retorna NULL em caso de falha
Elemento* inserirInicio(Lista* l, int x);

// insere um dado pela (chave x) na posicao pos. retorna NULL em caso de falha
Elemento* inserirPosicao(Lista* l, int x, int pos);

// insere um dado pela (chave x) na lista. retorna NULL em caso de falha
Elemento* inserir(Lista* l, int x);

// remove dado da lista
void remover(Lista* l, int x);

// retorna o primeiro da lista
Elemento* primeiro(Lista* l);

// retorna o ultimo da lista
Elemento* ultimo(Lista* l);

#endif // LISTA_H_INCLUDED