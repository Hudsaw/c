#ifndef FILA_H
#define FILA_H

typedef struct elemento {
    int dado;
    struct elemento *prox;
} Elemento;

typedef struct {
    Elemento *inicio;
    Elemento *fim;
} Fila;

// Funções básicas da pilha
Fila* criarFila();
void destruirFila(Fila* f);
void inserir(Fila* f, int valor);
int remover(Fila* f);
int tamanho(Fila* f);
void reinicializarFila(Fila* f, int valores[], int tamanho);

#endif