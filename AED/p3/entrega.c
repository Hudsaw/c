#include <stdlib.h>
#include <stdio.h>

typedef struct no_arvore {
    int chave;
    struct no_arvore *esq;
    struct no_arvore *dir;
} NoArvore;

typedef struct {
    NoArvore *raiz;
} Arvore;

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

// Exercício 3: Altura da Árvore
int altura_arvore(NoArvore *no) {
    if (!no) return -1;
    
    int altura_esq = altura_arvore(no->esq);
    int altura_dir = altura_arvore(no->dir);
    
    return (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
}

// Exercício 5: Verificação de ABB
int _verificar_abb_util(NoArvore *no, int *anterior) {
    if (!no) return 1;
    
    // Verifica subárvore esquerda
    if (!_verificar_abb_util(no->esq, anterior))
        return 0;
    
    // Verifica se o nó atual é maior que o anterior
    if (no->chave <= *anterior)
        return 0;
    
    *anterior = no->chave;
    
    // Verifica subárvore direita
    return _verificar_abb_util(no->dir, anterior);
}

int verificar_abb(NoArvore *no) {
    if (!no) return 1;
    int anterior = -1;
    return _verificar_abb_util(no, &anterior);
}

int main() {
    printf("=== EXERCÍCIOS SOBRE ÁRVORES BINÁRIAS DE BUSCA ===\n");
    
    // Exercício 1: Inserção e Percurso In-ordem
    printf("\n--- Exercício 1: Inserção e Percurso In-ordem ---\n");
    Arvore* a1 = criar_arvore();
    int arr[] = {50, 30, 20, 40, 70, 60, 80};

    for (int i = 0; i < 7; i++) {
        inserir_arvore(a1, arr[i]);
    }

    printf("Elementos em ordem crescente: ");
    imprimir_em_ordem(a1);

    // Exercício 2: Busca em uma ABB
    printf("\n--- Exercício 2: Busca em uma ABB ---\n");
    int testes[] = {20, 90, 50};
    for (int i = 0; i < 3; i++) {
        int valor = testes[i];
        NoArvore *resultado = buscar_arvore(a1, valor);
        if (resultado) {
            printf("%d: encontrado\n", valor);
        } else {
            printf("%d: NÃO encontrado\n", valor);
        }
    }

    // Exercício 3: Altura da Árvore
    printf("\n--- Exercício 3: Altura da Árvore ---\n");
    Arvore* a3 = criar_arvore();
    int arr3[] = {10, 5, 1, 7, 40, 50};
    
    for (int i = 0; i < 6; i++) {
        inserir_arvore(a3, arr3[i]);
    }
    
    printf("Árvore para teste de altura: ");
    imprimir_em_ordem(a3);
    printf("Altura da árvore: %d\n", altura_arvore(a3->raiz));

    // Exercício 4: Remoção de Nó
    printf("\n--- Exercício 4: Remoção de Nó ---\n");
    Arvore* a4 = criar_arvore();
    int arr4[] = {50, 30, 70, 20, 40, 60, 80};
    
    for (int i = 0; i < 7; i++) {
        inserir_arvore(a4, arr4[i]);
    }
    
    printf("Árvore original: ");
    imprimir_em_ordem(a4);
    
    // Remover nó folha (20)
    printf("Removendo 20 (nó folha): ");
    remover_arvore(a4, 20);
    imprimir_em_ordem(a4);
    
    // Remover nó com um filho (30)
    printf("Removendo 30 (nó com um filho): ");
    remover_arvore(a4, 30);
    imprimir_em_ordem(a4);
    
    // Remover nó com dois filhos (50 - raiz)
    printf("Removendo 50 (nó com dois filhos): ");
    remover_arvore(a4, 50);
    imprimir_em_ordem(a4);

    // Exercício 5: Verificação de ABB
    printf("\n--- Exercício 5: Verificação de ABB ---\n");
    
    // Teste com uma ABB válida
    Arvore* abb_valida = criar_arvore();
    int arr_valida[] = {50, 30, 70, 20, 40};
    for (int i = 0; i < 5; i++) {
        inserir_arvore(abb_valida, arr_valida[i]);
    }
    printf("ABB válida: %s\n", verificar_abb(abb_valida->raiz) ? "SIM" : "NÃO");
    
    // Teste com uma árvore que NÃO é ABB
    NoArvore* nao_abb = (NoArvore*)malloc(sizeof(NoArvore));
    nao_abb->chave = 50;
    nao_abb->esq = (NoArvore*)malloc(sizeof(NoArvore));
    nao_abb->esq->chave = 60;  
    nao_abb->esq->esq = NULL;
    nao_abb->esq->dir = NULL;
    nao_abb->dir = (NoArvore*)malloc(sizeof(NoArvore));
    nao_abb->dir->chave = 70;
    nao_abb->dir->esq = NULL;
    nao_abb->dir->dir = NULL;
    
    printf("Árvore que NÃO é ABB: %s\n", verificar_abb(nao_abb) ? "SIM" : "NÃO");

    // Limpeza de memória
    destruir_arvore(a1);
    destruir_arvore(a3);
    destruir_arvore(a4);
    destruir_arvore(abb_valida);
    
    // Liberar a árvore não ABB manualmente
    free(nao_abb->esq);
    free(nao_abb->dir);
    free(nao_abb);

    return 0;
}