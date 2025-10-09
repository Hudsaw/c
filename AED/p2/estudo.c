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


// 📥 FILA – Exercícios
// Verificação de palíndromo com restauração
// Escreva int ehPalindromoFila(Fila* f) que verifica se uma fila de caracteres forma um palíndromo (ex: 'A','B','A').
// → Restrinção: a fila original deve permanecer intacta após a verificação. Use apenas uma pilha auxiliar.

// Intercalação com preservação total
// Implemente Fila* intercalarPreservar(Fila* f1, Fila* f2) que cria uma terceira fila intercalando f1 e f2, sem modificar nenhuma das filas originais.

// Rotação cíclica eficiente
// Crie void rotacionarFila(Fila* f, int k) que move os primeiros k elementos para o final da fila.
// → Ex: [1,2,3,4], k=2 → [3,4,1,2]
// → Não use vetor auxiliar; use apenas operações de fila.

// Fila de prioridade simples (com dois níveis)
// Dada uma fila de inteiros onde números pares têm prioridade sobre ímpares, reorganize a fila de modo que todos os pares fiquem antes dos ímpares, mantendo a ordem relativa dentro de cada grupo.
// → Ex: [3, 2, 5, 4, 1] → [2, 4, 3, 5, 1]

// Simulação de round-robin com limite de tempo
// Considere uma fila de processos (use FilaProcessos como base). Escreva uma função que simule 1 ciclo de round-robin:
// Cada processo tem um campo tempoRestante (adicione à estrutura se necessário).
// A função executa o primeiro processo por quantum unidades de tempo.
// Se o processo não terminar, volta ao final da fila com tempo atualizado.
// → Retorne 1 se o processo terminou, 0 caso contrário.

// Ordenação de fila usando apenas operações de fila
// Implemente void ordenarFilaCrescente(Fila* f) que ordena a fila em ordem crescente usando exclusivamente inserir() e remover().
// → Proibido: vetor, lista, pilha, recursão profunda, ou qualquer estrutura externa.
// → Dica: use múltiplas passagens e seleção do menor.

// Detecção de padrão cíclico
// Escreva int temPadraoRepetido(Fila* f) que verifica se a fila é composta por repetições de um mesmo bloco.
// → Ex: [1,2,1,2] → sim (bloco [1,2])
// → Ex: [1,2,3,1,2] → não
// → Restaurar a fila após a verificação.

// Mistura perfeita (perfect shuffle)
// Implemente void misturaPerfeita(Fila* f) que divide a fila ao meio e intercala as metades como em um baralho:
// [1,2,3,4,5,6] → [1,4,2,5,3,6]
// Se o tamanho for ímpar, a primeira metade tem um elemento a mais.
// → Use no máximo uma fila auxiliar.

// LISTA 
// Remoção de duplicatas com preservação de ordem
// Implemente void removerDuplicatas(Lista* l) que remove todas as ocorrências repetidas, mantendo apenas a primeira aparição de cada valor.
// → Não use vetor ou tabela hash; percorra com ponteiros.

// Inversão in-place de sublista
// Escreva void inverterSublista(Lista* l, int inicio, int fim) que inverte apenas os elementos entre as posições inicio e fim (0-based).
// → Ex: [1,2,3,4,5], inicio=1, fim=3 → [1,4,3,2,5]
// Mesclagem de listas ordenadas sem repetição
// Dadas duas listas ordenadas, crie Lista* mesclarSemRepeticao(Lista* l1, Lista* l2) que retorna uma nova lista ordenada com todos os elementos únicos.


// Conversão binária com verificação de potência de 2
// Escreva int ehPotenciaDeDois(int n) usando apenas a função decimalParaBinario e análise da lista resultante (deve ter exatamente um 1).

// Divisão em listas pares e ímpares
// Implemente void separarParesImpares(Lista* original, Lista* pares, Lista* impares) que esvazia original e distribui seus elementos em pares e impares, mantendo a ordem.


// Detecção e remoção de ciclo (algoritmo de Floyd)
// Suponha que uma lista possa conter um ciclo (último nó aponta para um anterior).
// Escreva int detectarCiclo(Lista* l) usando dois ponteiros (lento e rápido).
// Escreva void removerCiclo(Lista* l) que corrige a lista, tornando-a linear.

// Lista como número grande – soma de dois números
// Considere que uma lista armazena um número inteiro com dígitos em ordem normal (ex: [1,2,3] = 123).
// Implemente Lista* somarNumeros(Lista* a, Lista* b) que retorna uma nova lista com a soma.
// → Trate vai-um (carry) e tamanhos diferentes.

// Reorganização em zig-zag
// Escreva void zigZag(Lista* l) que reorganiza a lista de modo que:
// l[0] ≤ l[1] ≥ l[2] ≤ l[3] ≥ ...
// → Ex: [4,3,7,8,6,2,1] → [3,7,4,8,2,6,1]
// → In-place, sem alocação extra.

int main(){
    Fila* f = criarFila();
    inserirFila(f, 10);
    inserirFila(f, 20);
    inserirFila(f, 25);
    inserirFila(f, 30);
    inserirFila(f, 35);
    inserirFila(f, 40);

    Fila* g = criarFila();
    inserirFila(g, 'A');
    inserirFila(g, 'Z');
    inserirFila(g, 'H');

    imprimirFila(f);
    inverterFila(f);
    imprimirFila(f);
    printf("%d\n", maiorFila(f)); 

    destruirFila(f); 
    return 0;
}

