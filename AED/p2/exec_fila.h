#ifndef EXEC_FILA_H
#define EXEC_FILA_H
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

// Funções de manipulação de fila de inteiros
int somaFila(Fila* f);
int maiorFila(Fila* f);
int contarRecursivo(Fila* f);
void removerNegativos(Fila* f);
Fila* paresFila(Fila* f);
int tempoTotalAtendimento(Fila* f);
int filasIguais(Fila* f1, Fila* f2);
Fila* intercalarFilas(Fila* f1, Fila* f2);
void inverterF1emF2(Fila* f1, Fila* f2);

// Funções de manipulação de fila de caracteres
int soMaiusculas(Fila* f);
int contarVogaisRec(Fila* f);
void inverterFilaComPilha(Fila* f);

#endif 