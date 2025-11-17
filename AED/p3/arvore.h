#ifndef ARVORE_H
#define ARVORE_H

typedef struct no_arvore {
    int chave;
    struct no_arvore *esq;
    struct no_arvore *dir;
} NoArvore;

typedef struct {
    NoArvore *raiz;
} Arvore;

Arvore* criar_arvore();
NoArvore* _buscar_no(NoArvore *no, int chave);
NoArvore* buscar_arvore(Arvore *arv, int chave);
int inserir_arvore(Arvore *arv, int chave);
NoArvore* _encontrar_minimo(NoArvore *no)
NoArvore* _remover_no(NoArvore *no, int chave)
int remover_arvore(Arvore *arv, int chave);
void percorrer_pre_ordem(NoArvore *no);
void percorrer_in_ordem(NoArvore *no);
void percorrer_pos_ordem(NoArvore *no);
void _liberar_no(NoArvore *no);
void destruir_arvore(Arvore *arv);
void imprimir_em_ordem(Arvore *a);

#endif