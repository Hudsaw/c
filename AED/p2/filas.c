#include <stdio.h>
#include <string.h>

typedef struct {
    char modelo;
    char prefixo;
    char companhia;
    int id; 
    int decolagem;
} Aviao;

typedef struct {
    Elemento *inicio;
    Elemento *fim;
} Fila;

typedef struct {
    Aviao* dado;
    Elemento* prox;
}Elemento; ;

void inserir(Fila* f, Aviao* a) {
    Elemento* e = malloc(sizeof(Elemento));
    e->dado = a;
    e->prox = NULL; 

    if (!f->fim) {
        f->fim = e;
        f->inicio = e;
    } else {
        f->fim->prox = e;
        f->fim = e;
    }
}

Aviao* remover(Fila* f) {
    if (!f || !f->inicio) return -999; 

    Elemento* aux = f->inicio;
    int valor = aux->dado;
    f->inicio = aux->prox; 

    if (!f->inicio) {
        f->fim = NULL;
    }
    free(aux);
    return valor;
}

void trafego()
{
    Aviao* a = malloc(sizeof(Aviao));
    
    float base, altura;
   
    printf("\nDigite a base: ");
    scanf("%f", &base);
    printf("\nDigite a altura: ");
    scanf("%f", &altura);
   
    inicializarRetangulo(&ret, base, altura);
   
    printf("Area do retangulo: %.2f\n", calcularArea(&ret));
    printf("Perimetro do retangulo: %.2f\n", calcularPerimetro(&ret));
}
