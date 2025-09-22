/* filaviao.c */
#include "filaviao.h"
#include <stdio.h>

FilaAviao* criarFilaAviao() {
    FilaAviao* f = malloc(sizeof(FilaAviao));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void enfileirarAviao(FilaAviao* f, Aviao a) {
    ElementoAviao* novo = malloc(sizeof(ElementoAviao));
    novo->aviao = a;
    novo->prox = NULL;

    if (!f->fim) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

Aviao desenfileirarAviao(FilaAviao* f) {
    if (!f || !f->inicio) {
        printf("Fila vazia!\n");
        exit(1);
    }
    ElementoAviao* temp = f->inicio;
    Aviao a = temp->aviao;
    f->inicio = temp->prox;
    if (!f->inicio) f->fim = NULL;
    free(temp);
    return a;
}

int tamanhoFilaAviao(FilaAviao* f) {
    int cont = 0;
    ElementoAviao* atual = f->inicio;
    while (atual) {
        cont++;
        atual = atual->prox;
    }
    return cont;
}

void listarFila(FilaAviao* f) {
    if (!f->inicio) {
        printf("Nenhum aviao na fila.\n");
        return;
    }
    printf("\n=== FILA DE ESPERA PARA DECOLAGEM ===\n");
    ElementoAviao* atual = f->inicio;
    int pos = 1;
    while (atual) {
        Aviao a = atual->aviao;
        printf("%d. Modelo: %s | Prefixo: %s | Empresa: %s | Voo: %d | Hora: %s\n",
               pos++, a.modelo, a.prefixo, a.empresa, a.numVoo, a.horaDecolagem);
        atual = atual->prox;
    }
    printf("=====================================\n");
}

void mostrarPrimeiro(FilaAviao* f) {
    if (!f->inicio) {
        printf("Fila vazia!\n");
        return;
    }
    Aviao a = f->inicio->aviao;
    printf("\n=== PRIMEIRO AVIAO NA FILA ===\n");
    printf("Modelo: %s\n", a.modelo);
    printf("Prefixo: %s\n", a.prefixo);
    printf("Empresa: %s\n", a.empresa);
    printf("Numero do Voo: %d\n", a.numVoo);
    printf("Hora de Decolagem: %s\n", a.horaDecolagem);
    printf("===============================\n");
}

void furarFila(FilaAviao* f, Aviao a) {
    ElementoAviao* novo = malloc(sizeof(ElementoAviao));
    novo->aviao = a;
    novo->prox = f->inicio;
    f->inicio = novo;
    if (!f->fim) f->fim = novo;
    printf("Aviao %s (%d) furou a fila!\n", a.modelo, a.numVoo);
}