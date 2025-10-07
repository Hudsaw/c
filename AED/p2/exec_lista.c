#include <stdio.h>
#include "lista.h"

// 1. Maior e menor elemento
Elemento* maiorLista(Lista* l) {
    if(!l || !l->inicio) return NULL;
    Elemento* e = l->inicio;
    Elemento* pMaior = e;
    while(e){
        if(e->dado > pMaior->dado) pMaior = e;
        e = e->prox;
    }
    return pMaior;
}


Elemento* menorLista(Lista* l) {
    if(!l || !l->inicio) return NULL;
    Elemento* e = l->inicio;
    Elemento* pMenor = e;
    while(e){
        if(e->dado < pMenor->dado) pMenor = e;
        e = e->prox;
    }
    return pMenor;
}


// 2. Soma dos elementos
int somaLista(Lista* l) {
    if(!l || !l->inicio) return 0;
    int soma = 0;
    Elemento* e = l->inicio;
    while(e){
        soma+= e->dado;
        e = e->prox;
    }
    return soma;
}


int somaListaRec(Lista* l){
    if(!l || !l->inicio) return 0;
    int soma = removerListaRet(l);
    return soma + somaLista(l);
}


// 3. Media dos elementos
float mediaLista(Lista* l) {
    if(!l || !l->inicio) return 0;
    return (float)somaLista(l)/tamanhoLista(l);
}


// 4. Qtos acima da mediaLista
int acimaMedia(Lista* l){
    Elemento* e = l->inicio;
    float media = mediaLista(l);
    if(!media) return 0;
    int cont = 0;
    while(e){
        if(e->dado > media) {
            cont++;
        }
        e = e->prox;
    }
    return cont;
}


// 5. Qtas vezes repete
int repeteco(Lista* l, int x){
    if(!l || !l->inicio) return 0;
    Elemento* e = l->inicio;
    int cont = 0;
    while(e){
        if(x == e->dado){
            cont++;
        }
        e = e->prox;
    }
    return cont;
}


// 6. Decimal para binário usando lista
Lista* decimalParaBinario(int n) {
    Lista* l = criarLista();
    if(!n) inserirLista(l, 0);
    while(n>0){
        inserirInicio(l, n%2);
        n = n/2;
    } 
    return l;
}

// 7. Interseção de duas listas
Lista* intersecao(Lista* l1, Lista* l2) {
    Lista* l3 = criarLista();
    Elemento* e = l1->inicio;
    while (e) {
        if(buscarElemento(l2, e->dado)) inserirLista(l3, e->dado);
        e = e->prox;
    }
    return l3;
}


// 8. Remover Repetidos
void removerRepetidos(Lista* l) {
    if (!l || !l->inicio) return;
    Elemento *atual = l->inicio;
    while (atual) {
        Elemento *procurar = atual->prox;
        Elemento *anterior = atual;
        while (procurar) {
            if (procurar->dado == atual->dado) {
                anterior->prox = procurar->prox;
                free(procurar);
                procurar = anterior->prox;
            } else {
                anterior = procurar;
                procurar = procurar->prox;
            }
        }
        atual = atual->prox;
    }
}

