#include "fila.h"
#include "pilha.h"

// 1. Soma dos elementos da fila
int somaFila(Fila* f) {
    if(!f || !f->inicio) return 0;
    int soma = 0;
    Elemento* e = f->inicio;
    while(e){
        soma+= e->dado;
        e = e->prox;
    }
    return soma;
}

// 2. Maior elemento da fila
int maiorFila(Fila* f) {
    if(!f || !f->inicio) return 0;
    Elemento* e = f->inicio;
    int maior = e->dado;
    while(e){
        if(e->dado > maior) maior = e->dado;
        e = e->prox;
    }
    return maior;
}

// 3. Contagem recursiva de elementos
int contarRecursivo(Fila* f) {
    if(!f || !f->inicio) return 0;
    int valor = removerFila(f);
    return 1 + contarRecursivo(f);
}

// 4. Verifica se todos os caracteres são maiúsculos
int soMaiusculas(Fila* f) {
    if (!f || !f->inicio) return 1;
    Elemento* e = f->inicio;
    while(e){
        char c = (char)e->dado;
        if (c < 'A' || 'Z' < c) return 0;
        e = e->prox;
    }
    return 1;
}

// 5. Inverte fila usando pilha auxiliar
void inverterFilaComPilha(Fila* f) {
    if (!f || !f->inicio) return;
    Pilha* p = criarPilha();
    while(f->inicio){
    inserirPilha(p, removerFila(f));
    }
    while(p->topo){
    inserirFila(f, removerPilha(p));
    }
    destruirPilha(p);
    return f;
}

// 6. Remove números negativos
void removerNegativos(Fila* f) {
    if (!f || !f->inicio) return;
    int n = tamanhoFila(f);
    int cont = 0;
    while(cont<=n){
        int x = removerFila(f);
        if(x >= 0) inserirFila(f, x);
        cont++;
    }
}

// 7. Conta vogais recursivamente
int ehVogal(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
int contarVogaisRec(Fila* f) {
    if (!f || !f->inicio) return 0;
    char c = (char)removerFila(f);
    return ehvogal(c) + contarVogaisRec(f);
}

// 8. Verifica se duas filas são idênticas
int filasIguais(Fila* f1, Fila* f2) {
    if (tamanhoFila(f1) != tamanhoFila(f2)) return 0;
    while(f1->inicio)
        if(removerFila(f1) != removerFila(f2)) return 0;
    return 1;
}

// 9. Retorna nova fila com elementos pares
Fila* paresFila(Fila* f) {
    if (!f || !f->inicio) return criarFila();
    Fila* n = criarFila();
    while(f->inicio){
        int x = remover(f);
        if(x % 2 == 0) inserirFila(n, x);
    }
    return n;
}

// 10. Tempo total de atendimento no caixa
int tempoTotalAtendimento(Fila* f) {
    return somaFila(f);
}


// 11. Intercala duas filas em uma terceira
Fila* intercalarFilas(Fila* f1, Fila* f2) {
    if (!f1 || !f2) return criarFila();
    Fila* f3 = criarFila();
    while (f1->inicio && f2->inicio){
        inserirFila(f3,removerFila(f1));
        inserirFila(f3,removerFila(f2));
    }
    while (f1->inicio) inserirFila(f3,removerFila(f1));
    while (f2->inicio) inserirFila(f3,removerFila(f2));
    return f3;
}

// Inverte F1 e coloca resultado em F2
void inverterF1emF2(Fila* f1, Fila* f2) {
    Pilha* p = criarPilha();
    while(f1->inicio) inserirPilha(p, removerFila(f1));
    while(p->topo) inserirFila(f2, removerPilha(p));
    destruirPilha(p);
}