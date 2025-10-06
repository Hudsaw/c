#include "lista.h"
#include <math.h>

// 1. Maior e menor elemento
int maiorLista(Lista* l) {
    if (!l || !l->inicio) return -1;
    Elemento* p = l->inicio;
    int maior = p->dado;
    while (p) {
        if (p->dado > maior) maior = p->dado;
        p = p->prox;
    }
    return maior;
}

int menorLista(Lista* l) {
    if (!l || !l->inicio) return -1;
    Elemento* p = l->inicio;
    int menor = p->dado;
    while (p) {
        if (p->dado < menor) menor = p->dado;
        p = p->prox;
    }
    return menor;
}

// 2. Soma dos elementos
int somaLista(Lista* l) {
    if (!l || !l->inicio) return 0;
    Elemento* p = l->inicio;
    int soma = 0;
    while (p) {
        soma += p->dado;
        p = p->prox;
    }
    return soma;
}

// 3. Média dos valores
double mediaLista(Lista* l) {
    int n = tamanhoLista(l);
    if (n == 0) return 0.0;
    return (double)somaLista(l) / n;
}

// 4. Conta elementos acima da média
int acimaMedia(Lista* l) {
    double media = mediaLista(l);
    int cont = 0;
    Elemento* p = l->inicio;
    while (p) {
        if (p->dado > media) cont++;
        p = p->prox;
    }
    return cont;
}

// 5. Conta ocorrências de X
int contaX(Lista* l, int x) {
    int cont = 0;
    Elemento* p = l->inicio;
    while (p) {
        if (p->dado == x) cont++;
        p = p->prox;
    }
    return cont;
}

// 6. Decimal para binário usando lista
Lista* decimalParaBinario(int n) {
    Lista* l = criarLista();
    if (n == 0) {
        inserirInicio(l, 0);
        return l;
    }
    while (n > 0) {
        inserirInicio(l, n % 2);
        n /= 2;
    }
    return l;
}

// 7. Interseção de duas listas
Lista* intersecao(Lista* l1, Lista* l2) {
    Lista* res = criarLista();
    Elemento* p1 = l1->inicio;
    while (p1) {
        if (buscarElemento(l2, p1->dado) && !buscarElemento(res, p1->dado)) {
            inserirLista(res, p1->dado);
        }
        p1 = p1->prox;
    }
    return res;
}