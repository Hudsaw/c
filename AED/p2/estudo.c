#include <stdio.h>
#include <stdlib.h>

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

// Verificação de palíndromo com restauração
int ehPalindromoFila(Fila* f){
    if (!f || !f->inicio) return 1;
    Elemento* e = f->inicio;
    Pilha* p = criarPilha();
    while(e) {
        inserirPilha(p, e->dado);
        e = e->prox;
    }
    e = f->inicio;
    while(e) {
        if(e->dado != removerPilha(p)) {
            destruirPilha(p);
            return 0;
        }
        e = e->prox;
    }
    destruirPilha(p);
    return 1;
}

// Intercalação com preservação total
Fila* intercalarPreservar(Fila* f1, Fila* f2){
    Fila* f3 = criarFila();
    Elemento* e1 = f1 ? f1->inicio: NULL;
    Elemento* e2 = f2 ? f2->inicio: NULL;  
    while(e1 && e2){
        inserirFila(f3, e1->dado);
        inserirFila(f3, e2->dado);
        e1 = e1->prox;
        e2 = e2->prox;
    }
    while(e1) inserirFila(f3, e1->dado);
    while(e2) inserirFila(f3, e2->dado);
    return f3;
}

// Rotação cíclica eficiente
void rotacionarFila(Fila* f, int k){
    if (!f || !f->inicio) return;
    int n = tamanhoFila(f);
    if(k>=n) return;
    while (k > 0) {
        inserirFila(f, removerFila(f));
        k--;
    }
}

// Fila de prioridade simples (com dois níveis)
void reordenarFila(Fila* f){
    if(!f || !f->inicio) return;
    Fila* f1 = criarFila();
    Fila* f2 = criarFila();
    Elemento* e = f->inicio;
    while(e){
        if (e->dado %2==0)inserirFila(f1, e->dado);
        if (e->dado %2!=0)inserirFila(f2, e->dado);
        e = e->prox;
    }
    destruirFila(f);
    while(f1->inicio)inserirFila(f, removerFila(f1));
    while(f2->inicio)inserirFila(f, removerFila(f2));
    destruirFila(f1);destruirFila(f2);
}

int compararFilas(Fila* f1, Fila* f2){
    if(!f1 || !f2) return 0;
    Elemento *e1 = f1->inicio;
    Elemento *e2 = f2->inicio;
    while(e1 && e2){
        if(e1->dado != e2->dado) return 0;
        e1 = e1->prox;
        e2 = e2->prox;
    }
    return (!e1 && !e2);
}

// LISTA 
int contarOcorrencias(Lista* l, int valor){
    if(!l || !l->inicio) return 0;
    Elemento *e = l->inicio;
    int cont=0;
    while(e){
        if(e->dado == valor) cont++;
        e= e->prox;
    } 
    return cont;
}

int todosPares(Lista* l){
    if(!l || !l->inicio) return 0;
    Elemento *e = l->inicio;
    while(e){
        if(e->dado %2 != 0) return 0; 
        e= e->prox;
    } 
    return 1;
}

void inverterLista(Lista* l){
    if(!l || !l->inicio) return;
    Elemento *ant = NULL;
    Elemento *atual = l->inicio;
    Elemento *prox;
    while(atual){
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    l->inicio = ant;
}

void trocarPares(Lista* l){
    if(!l || !l->inicio) return;
    Elemento aux;
    aux.prox = l->inicio;
    Elemento *ant = &aux;
    while (ant->prox && ant->prox->prox){
        Elemento *n1 = ant->prox;
        Elemento *n2 = ant->prox->prox;
        n1->prox = n2->prox;
        n2->prox = n1;
        ant->prox = n2;
        ant = n1;
    }
    l->inicio = aux.prox;
}

void moverParesParaFrente(Lista* l){
    if(!l || !l->inicio) return;
    Elemento *iniPar, *iniImpar, *fimPar, *fimImpar;
    Elemento *atual = l->inicio;
    while (atual){
        Elemento *next = atual->prox;
        atual->prox = NULL;
        if(atual->dado%2==0){
            if(!fimPar){
                iniPar = atual;
                fimPar = atual;
            } else {
                fimPar->prox = atual;
                fimPar = atual; 
            }
        } else {
            if(!fimImpar){
                iniImpar = atual;
                fimImpar = atual;
            } else{
                fimImpar->prox = atual;
                fimImpar = atual;
            }
        }
        atual = next;
    }
    if (fimPar) {
        fimPar->prox = iniImpar;
        l->inicio = iniPar;
    } else {
        l->inicio = iniImpar;
    }
}

void removerDuplicatas(Lista* l){
    if(!l || !l->inicio) return;
    Elemento *e = l->inicio;
    while(e){
        Elemento *ant = e;
        Elemento *atual = e->prox;
        while(atual){
            if(atual->dado == ant->dado){
                ant->prox = atual->prox;
                free(atual);
                atual = ant->prox;
            } else{
                ant = atual;
                atual = atual->prox;
            }
        }
        e = e->prox;
    }
}

Lista* mesclarSemRepeticao(Lista* l1, Lista* l2) {
    Lista *l = criarLista();
    Elemento *a = l1 ? l1->inicio: NULL;   
    Elemento *b = l2 ? l2->inicio: NULL;
    int d = 0;
    int c = 1;
    while(a || b){
        int e;
        if(!b || (a && a->dado <= b->dado)){
            e = a->dado;
            a = a->prox;
        } else {
            e = b->dado;
            b = b->prox;
        }
        if(c || e!= d){
            inserirLista(l, e);
            d = e;
            c = 0;
        }
    }  
    return l;    
}

void separarParesImpares(Lista* original, Lista* pares, Lista* impares){
    while(original->inicio){
        int x = removerListaRet(original);
        if(x%2==0){
            inserirLista(pares, x);
        } else{
            inserirLista(impares, x);
        } 
    }
}

Lista* somarNumeros(Lista* a, Lista* b){
    Elemento* e1 = a ? a->inicio: NULL;
    Elemento* e2 = b ? b->inicio: NULL;
    Lista *l = criarLista();
    while(e1 && e2){
        inserirLista(l, e1->dado+e2->dado);
        e1= e1->prox;
        e2= e2->prox;
    }
    if(e1){
        inserirLista(l, e1->dado);
        e1= e1->prox;
    } else{
        inserirLista(l, e2->dado);
        e2= e2->prox;
    }
    return l;
}

void removerImpares(Lista* l){
    if(!l || !l->inicio) return;
    while(l->inicio && l->inicio->dado%2 != 0){
        Elemento *temp = l->inicio;
        l->inicio = l->inicio->prox;
        free(temp);
    } 
    Elemento *e = l->inicio;
    while (e && e->prox){
        if (e->prox->dado %2 != 0){
            Elemento *temp = e->prox;
            e->prox = e->prox->prox;
            free(temp);
        } else{
            e = e->prox;
        }
    }
}

Lista* filaParaListaInvertida(Fila* f){
    Lista *l = criarLista();
    if(!f || !f->inicio) return l;
    Pilha *p = criarPilha();
    Elemento *e = f->inicio;
    while(e){
        inserirPilha(p, e->dado);
        e = e->prox;
    }
    while(p->topo){
        inserirLista(l, removerPilha(p));
    }
    destruirPilha(p);
    return l;
}

void removerPares(Lista* l){
    if(!l || !l->inicio) return;
    while(l->inicio && l->inicio->dado%2==0){
        Elemento *temp = l->inicio;
        l->inicio = l->inicio->prox;
        free(temp);
    } 
    Elemento *e = l->inicio;
    while (e && e->prox){
        if(e->prox->dado%2==0){
            Elemento *temp = e->prox;
            e->prox = e->prox->prox;
            free(temp);
        } else{
            e = e->prox;
        }
    }
}

void removerMaioresQue(Lista* l, int limite){
    if(!l || !l->inicio) return;
    while(l->inicio && l->inicio->dado > limite){
        Elemento *temp = l->inicio;
        l->inicio = l->inicio->prox;
        free(temp);
    }
    Elemento *e = l->inicio;
    while (e && e->prox){
        if(e->prox->dado > limite){
            Elemento *temp = e->prox;
            e->prox = e->prox->prox;
            free(temp);
        } else{
            e = e->prox;
        }
    }
}

void removerMultiplosDe(Lista* l, int k){
    if(!l || !l->inicio || k==0) return;
    while(l->inicio && l->inicio->dado%k==0){
        Elemento *temp = l->inicio;
        l->inicio = l->inicio->prox;
        free(temp);
    }
    Elemento *e = l->inicio;
    while(e && e->prox){
        if(e->prox->dado %k == 0){
            Elemento *temp = e->prox;
            e->prox = e->prox->prox;
            free(temp);
        } else{
            e = e->prox;
        }
    }
}

void removerRepetidosConsecutivos(Lista* l){
    if(!l || !l->inicio) return;
    Elemento *e = l->inicio;
    while(e && e->prox){
        if(e->prox->dado == e->dado){
            Elemento *temp = e->prox;
            e->prox = e->prox->prox;
            free(temp);
        } else{
            e = e->prox;
        }
    }
}

void manterUnicos(Lista* l){
    if(!l || !l->inicio) return;
    Elemento *e = l->inicio;
    while(e){
        int cont = 0;
        int valor = e->dado;
        Elemento *aux = l->inicio;
        while(aux){
            if (aux->dado == valor) cont++;
            aux = aux->prox; 
        }
        if(cont>1){
            while(l->inicio && l->inicio->dado == valor){
                Elemento *temp = l->inicio;
                l->inicio = l->inicio->prox;
                free(temp);
            } 
            Elemento *ant = l->inicio;
            while(ant && ant->prox){
                if(ant->prox->dado == valor){
                    Elemento *temp = ant->prox;
                    ant->prox = temp->prox;
                    free(temp);
                } else{
                    ant= ant->prox;
                }
            }
            e = l->inicio;
        } else {
            e = e->prox;
        }
    }
}

void removerNegativos(Lista* l){
    if (!l || !l->inicio) return;
    while (l->inicio && l->inicio->dado < 0){
            Elemento *temp = l->inicio;
            l->inicio = l->inicio->prox;
            free(temp);
    }
    Elemento *e = l->inicio;
    while(e && e->prox){
        if(e->prox->dado < 0){
            Elemento *temp = e->prox;
            e->prox = temp->prox;
            free(temp);
        }   else {
            e = e->prox;
        }
    }
}

void removerForaDoIntervalo(Lista* l, int min, int max){
    if(!l || !l->inicio) return;
    while (l->inicio && (l->inicio->dado < min || l->inicio->dado > max)){
        Elemento *temp = l->inicio;
        l->inicio = temp->prox;
        free(temp);
    }
    Elemento *e = l->inicio;
    while(e && e->prox){
        if(e->prox->dado < min || e-> prox->dado > max){
            Elemento *temp = e->prox;
            e->prox = temp->prox;
            free(temp);
        } else{
            e = e->prox;
        }
    }
}

void manterPrimeiroPar(Lista* l){
    if(!l || !l->inicio) return;
    Elemento *e = l->inicio;
    while(e && e->dado %2!=0) e = e->prox;
    while(e && e->prox){
        if(e->prox->dado %2==0){
            Elemento *temp = e->prox;
            e->prox = temp->prox;
            free(temp);
        } else{
            e = e->prox;
        }
    }
}

void limparRepetidas(Lista *l){
    if(!l || !l->inicio) return;
    Elemento *e = l->inicio;
    while(e){
        int valor = e->dado;
        Elemento *aux = e;
        while(aux->prox){
            if(aux->prox->dado == valor){
                Elemento *temp = aux->prox;
                aux->prox = temp->prox;
                free(temp);
            } else{
                aux = aux->prox;
            }
        }
        e = e->prox;
    }
}

int verificarEspelhoLista(Lista* l){
    if(!l || !l->inicio) return 1;
    Elemento *e = l->inicio;
    Pilha *p = criarPilha();
    while(e){
        inserirPilha(p, e->dado);
        e = e->prox;
    }
    e = l->inicio;
    while(e){
        if(e->dado == removerPilha(p)){
            e= e->prox;
        } else{
            return 0;
        }
    }
    destruirPilha(p);
    return 1;
}

void rotacionarListaK(Lista* l, int k){
    if(!l || !l->inicio) return;
    int n = tamanhoLista(l);
    if (n <= 1) return;
    k = k % n;
    if (k == 0) return;
    int cont = n-k-1;
    Elemento *e = l->inicio;
    for(int i=0; i<cont; i++){
        e= e->prox;
    }
    Elemento *iniRot = e->prox;
    Elemento *fimRot = iniRot;
    while(fimRot->prox) fimRot = fimRot->prox;
    fimRot->prox = l->inicio;
    l->inicio = iniRot;
    e->prox = NULL;
}

Lista* intercalarListasPreservando(Lista* l1, Lista* l2){
    Lista *l = criarLista();
    Elemento *a = l1 ? l1->inicio: NULL;   
    Elemento *b = l2 ? l2->inicio: NULL;
    while(a && b){
        inserirLista(l, a->dado);
        inserirLista(l, b->dado);
        a = a->prox;
        b = b->prox;
    }
    while(b) {
        inserirLista(l, b->dado);
        b = b->prox;
    }
    while(a) {
        inserirLista(l, a->dado);
        a = a->prox;
    }
    return l;
}

int main(){
    Lista* l = criarLista();
    inserirLista(l, 10);
    inserirLista(l, 35);
    inserirLista(l, 25);
    inserirLista(l, 30);
    inserirLista(l, 30);
    inserirLista(l, 40);

    Lista* g = criarLista();
    inserirLista(g, 'A');
    inserirLista(g, 'Z');
    inserirLista(g, 'H');

    imprimirLista(l);
    manterUnicos(l);
    printf("\n"); 
    imprimirLista(l);

    destruirLista(l); 
    return 0;
}

