#include "arvore.h"

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
    nao_abb->esq->chave = 60;  // Violação: 60 > 50 na subárvore esquerda
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