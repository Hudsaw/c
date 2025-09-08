#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "pilha.c"

void pilha9_imprime_inverso(Pilha* p){
   if (!p || !p->topo) return;
   int valor = pop(p);
   pilha9_imprime_inverso(p);
   printf("%d ", valor); 
}

int main() {
    Pilha* p = criarPilha();
    push(p, 10);
    push(p, 20);
    push(p, 30);

    printf("Elementos em ordem de insercao:\n");
    pilha9_imprime_inverso(p);
    printf("\n");

    destruirPilha(p);
    return 0;
}