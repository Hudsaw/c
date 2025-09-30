/* Lista.c */
#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
	int dado;
	struct Elemento* prox;
} Elemento;

typedef struct Lista{
	Elemento* inicio;
} Lista;

Lista* criarLista() {
    Lista* l = malloc(sizeof(Lista));
    if (l) l->inicio = NULL;
    return l;
}

void destruirLista(Lista* l) {
    Elemento* aux = l->inicio;
    while (aux) {
        Elemento* proximo = aux->prox;
        free(aux);
        aux = proximo;
    }
    free(l);
}

int tamanho(Lista* l) {
    int cont = 0;
    Elemento* aux = l->inicio;
    while (aux) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

Elemento* buscarElemento(Lista* l, int x) {
    Elemento* aux;
    if (!l) return NULL;
    aux = l->inicio;
    while (aux) {
        if (aux->dado == x) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

Elemento* buscarPosicao(Lista* l, int pos) {
    int cont=1;
    Elemento* aux;
    if (!l) return NULL;
    aux = l->inicio;
    if(pos > tamanho(l)) return NULL;

    while (cont < pos) {
        aux = aux->prox;
        cont++;
    }
    return aux;
}

Elemento* inserirInicio(Lista* l, int x) {
    Elemento* e; 
    if (!l) return NULL;
    e = malloc(sizeof(Elemento));
    e->dado = x;
    e->prox = l->inicio;
    l->inicio = e;
    return e;
}

Elemento* inserir(Lista* l, int x) {
    Elemento* e, *aux;
    if (!l) return NULL;
    e = (Elemento*) malloc(sizeof(Elemento));
    e->dado = x;
    e->prox = NULL;
    aux=l->inicio;
    if(!aux){
        l->inicio = e;
        return e;
    }
    while(aux->prox)
        aux=aux->prox;
    aux->prox = e;
    return e;
}

Elemento* inserirPosicao(Lista* l, int x, int pos) {
    Elemento* e, *aux;
    int cont=1;
    if (!l) return NULL;
    if (!l->inicio || pos==0) return inserirInicio(l, x);
    aux = l->inicio;
    while(cont < pos-1){
        aux = aux->prox;
        cont++;
    }
    e = (Elemento*) malloc(sizeof(Elemento));
    e->dado = x;
    e->prox = aux->prox;
    aux->prox = e;
    return e;
}

void remover(Lista* l, int x) {
    Elemento *e, *aux;
    e = l->inicio;
    aux = e;
    if(e->dado == x){
        l->inicio = e->prox;
        free(e);
        return;
    }
    while(e->dado!=x){
        aux = e;
        e=e->prox;
        if(e==NULL)
            return;
    }
    aux->prox = e->prox;
    free(e);
}

Elemento* primeiro(Lista* l) {
    if (!l) return NULL;
    return l->inicio;
}

Elemento* ultimo(Lista* l) {
    Elemento* aux;
    if (!l || !l->inicio) return NULL;

    aux = l->inicio;
    while (aux->prox) aux = aux->prox;
    return aux;
}

void imprimirLista(Lista* l){
    if (!l) return;
    Elemento* aux = l->inicio; 
    while (aux) {     
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
}

int main(){
    Lista* l = criarLista(); 
    inserir(l, 1);
    inserir(l, 2);
    inserir(l, 3);
    inserir(l, 4);
    inserir(l, 5);
    
    remover(l, 3);
    inserirPosicao(l, 6, 2);
    inserir(l, 7);
    inserirInicio(l, 8);
    imprimirLista(l);
    return 0;

}

saída: 8 1 6 2 4 5 7 