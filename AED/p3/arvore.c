#include "arvore.h"

// TAD arvore
Arvore* criar_arvore() {
    Arvore *arv = (Arvore*) malloc(sizeof(Arvore));
    if (!arv) return NULL;
    arv->raiz = NULL;
    return arv;
}

NoArvore* _buscar_no(NoArvore *no, int chave) {
    if (!no || no->chave == chave)
        return no;
    if (chave < no->chave)
        return _buscar_no(no->esq, chave);
    else
        return _buscar_no(no->dir, chave);
}

NoArvore* buscar_arvore(Arvore *arv, int chave) {
    if (!arv) return NULL;
    return _buscar_no(arv->raiz, chave);
}

int inserir_arvore(Arvore *arv, int chave) {
    if (!arv) return -1; 

    if (buscar_arvore(arv, chave)) {
        return 0;
    }

    NoArvore *novo = (NoArvore*) malloc(sizeof(NoArvore));
    if (!novo) return -1;

    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;

    if (!arv->raiz) {
        arv->raiz = novo;
        return 1; 
    }

    NoArvore *atual = arv->raiz;
    NoArvore *pai = NULL;

    while (atual) {
        pai = atual;
        if (chave < atual->chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    if (chave < pai->chave)
        pai->esq = novo;
    else
        pai->dir = novo;

    return 1;
}

NoArvore* _encontrar_minimo(NoArvore *no) {
    NoArvore *atual = no;
    while (atual && atual->esq)
        atual = atual->esq;
    return atual;
}

NoArvore* _remover_no(NoArvore *no, int chave) {
    if (!no) return no;

    if (chave < no->chave) {
        no->esq = _remover_no(no->esq, chave);
    } else if (chave > no->chave) {
        no->dir = _remover_no(no->dir, chave);
    } else {
        // Caso 1: Nó sem filhos ou com apenas um filho
        if (!no->esq) {
            NoArvore *temp = no->dir;
            free(no);
            return temp;
        } else if (!no->dir) {
            NoArvore *temp = no->esq;
            free(no);
            return temp;
        }
        
        // Caso 2: Nó com dois filhos
        NoArvore *temp = _encontrar_minimo(no->dir);
        no->chave = temp->chave;
        no->dir = _remover_no(no->dir, temp->chave);
    }
    return no;
}

int remover_arvore(Arvore *arv, int chave) {
    if (!arv || !buscar_arvore(arv, chave)) return 0;
    
    arv->raiz = _remover_no(arv->raiz, chave);
    return 1;
}

void percorrer_pre_ordem(NoArvore *no) {
    if (no) {
        printf("%d ", no->chave);
        percorrer_pre_ordem(no->esq);
        percorrer_pre_ordem(no->dir);
    }
}

void percorrer_in_ordem(NoArvore *no) {
    if (no) {
        percorrer_in_ordem(no->esq);
        printf("%d ", no->chave);
        percorrer_in_ordem(no->dir);
    }
}

void percorrer_pos_ordem(NoArvore *no) {
    if (no) {
        percorrer_pos_ordem(no->esq);
        percorrer_pos_ordem(no->dir);
        printf("%d ", no->chave);
    }
}

void _liberar_no(NoArvore *no) {
    if (!no) return;
    _liberar_no(no->esq);
    _liberar_no(no->dir);
    free(no);
}

void destruir_arvore(Arvore *arv) {
    if (arv) {
        _liberar_no(arv->raiz);
        free(arv);
    }
}

void imprimir_em_ordem(Arvore *a) {
    if (!a || !a->raiz) {
        printf("Árvore vazia.\n");
        return;
    }
    percorrer_in_ordem(a->raiz);
    printf("\n");
}