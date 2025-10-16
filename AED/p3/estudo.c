#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Elemento {
    int dado;
    struct Elemento* prox;
} Elemento;

typedef struct {
    Elemento *topo;
} Pilha;

typedef struct Fila {
    Elemento* inicio;
    Elemento* fim;
} Fila;

typedef struct {
	Elemento* inicio;
} Lista;

Pilha* criarPilha() {
    Pilha* p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void inserirPilha(Pilha* p, int x) {
    Elemento* e = malloc(sizeof(Elemento));
    if (!e) return;
    e->dado = x;
    e->prox = p->topo;
    p->topo = e;
}

int removerPilha(Pilha* p) {
    if (!p->topo) return -999;
    Elemento* aux = p->topo;
    p->topo = aux->prox;
    int valor = aux->dado;
    free(aux);
    return valor;
}

void destruirPilha(Pilha* p) {
    while (p->topo) {
        removerPilha(p);
    }
    free(p);
}

int tamanhoPilha(Pilha* p) {
    Elemento* aux = p->topo;
    int cont = 0;
    while (aux) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void reinicializarPilha(Pilha* p, int valores[], int tamanho) {
    while (p->topo) {
        removerPilha(p);
    }
    for (int i = 0; i < tamanho; i++) {
        inserirPilha(p, valores[i]);
    }
}

Fila* criarFila() {
    Fila* f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void inserirFila(Fila* f, int x) {
    Elemento* e = malloc(sizeof(Elemento));
    e->dado = x;
    e->prox = NULL;
    if (!f->fim) {
        f->inicio = e;
        f->fim = e;
    } else {
        f->fim->prox = e;
        f->fim = e;
    }
}

int removerFila(Fila* f) {
    if (!f || !f->inicio) {
        printf("Fila vazia!\n");
        return -999;
    }
    Elemento* aux = f->inicio;
    int valor = aux->dado;
    f->inicio = aux->prox;
    if (!f->inicio) f->fim = NULL;
    free(aux);
    return valor;
}

void destruirFila(Fila* f) {
    while (f && f->inicio) {
        removerFila(f);
    }
    free(f);
}

int tamanhoFila(Fila* f) {
    int cont = 0;
    Elemento* aux = f->inicio;
    while (aux) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void reinicializarFila(Fila* f, int valores[], int n) {
    while (f->inicio) {
        removerFila(f);
    }
    for (int i = 0; i < n; i++) {
        inserirFila(f, valores[i]);
    }
}

void imprimirFila(Fila* f){
    if (!f) return;
    Elemento* aux = f->inicio; 
    while (aux) {     
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
}

void imprimirFilaChar(Fila* f){
    if (!f) return;
    Elemento* aux = f->inicio; 
    while (aux) {     
        printf("%c ", (char)aux->dado);
        aux = aux->prox;
    }
}

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

int tamanhoLista(Lista* l) {
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
    if(pos > tamanhoLista(l)) return NULL;

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

Elemento* inserirLista(Lista* l, int x) {
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

void removerLista(Lista* l, int x) {
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

int removerListaRet(Lista* l) {
    if (!l || !l->inicio) return 0;
    Elemento* aux = l->inicio;
    int valor = aux->dado;
    l->inicio = aux->prox;
    return valor;
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

int estaOrdenado(Lista* l){
    if(!l || !l->inicio) return 1;
    Elemento *e = l->inicio;
    while(e->prox){
        if(e->dado>e->prox->dado) return 0;
        e = e->prox;
    }
    return 1;
}

void bubbleSort(Lista *l){
    if(!l || !l->inicio) return;
    int fim;
    do{
        fim = 0;
        Elemento *atual = l->inicio;
        while(atual->prox){
            if(atual->dado > atual->prox->dado){
            int temp = atual->dado;
            atual->dado = atual->prox->dado;
            atual->prox->dado = temp;
            fim = 1;
            }
            atual = atual->prox;
        }
        
    } while(fim);
}

Lista *criarDecrescente(int n){
    Lista *l = criarLista();
    for(int i=0; i<n;i++){
        inserirLista(l, rand()%100);
    }
    int fim;
    do{
        fim = 0;
        Elemento *atual = l->inicio;
        while(atual->prox){
            if(atual->dado < atual->prox->dado){
            int temp = atual->dado;
            atual->dado = atual->prox->dado;
            atual->prox->dado = temp;
            fim = 1;
            }
            atual = atual->prox;
        }
        
    } while(fim);
    return l;
}

void selectSort(Lista *l, int* comparacoes, int* trocas){
    if(!l || !l->inicio){
        *comparacoes = 0; *trocas = 0; return;
    } 
    Elemento *atual = l->inicio;
    while(atual->prox){
        Elemento *menor = atual;
        Elemento *busca = atual->prox;
        
        while(busca){
            (*comparacoes)++;
            if(busca->dado < menor->dado){
                menor = busca;
            }
            busca = busca->prox;
        }
        
        if(menor != atual){
            int temp = atual->dado;
            atual->dado = menor->dado;
            menor->dado = temp;
            (*trocas)++;
        }
        atual = atual->prox;
    }
}

void insertionSort(Lista* l) {
    if (!l || !l->inicio || !l->inicio->prox) return; 
    Elemento* atual = l->inicio->prox;
    while (atual){

    }
}


int main(){
    Lista* l = criarLista();
    l = criarDecrescente(10);
    int comparacoes=0, trocas=0;

    Lista* g = criarLista();
    inserirLista(g, 'A');
    inserirLista(g, 'Z');
    inserirLista(g, 'H');

    imprimirLista(l);
    selectSort(l, &comparacoes, &trocas);
    printf("\nComparacoes: %d e trocas: %d", comparacoes, trocas);
    printf("\nOrdenado? %d", estaOrdenado(l));
    printf("\n"); 
    imprimirLista(l);

    destruirLista(l); 
    return 0;
}

