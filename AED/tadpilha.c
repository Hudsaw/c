#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"

void pilha1_binario() {
    
    Pilha* p = criarPilha();
    int num;
    
    printf("Digite um número decimal: ");
    scanf("%d", &num);
    
    while (num != 0) {
        push(p, num % 2);  
        num /= 2;
    }
    
    while (p->topo) printf("%d", pop(p));

    printf("\n");

    destruirPilha(p);
}

int pilha2_pareada(Pilha* r, Pilha* s){
    int res, a, b, op;
    while (tamanho(s)>0){
        b = pop(r);
        a = pop(r);
        op = pop(s);
        res = 0;
        switch (op) {
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
            case '/': res = a / b; break;
        }
        push(r, res);
        printf("Operacao: %d %c %d = %d\n", a, op, b, res);
    }
    return res;
}

void pilha3_invertida(Pilha* p)
{
    printf("Sequencia na ordem inversa: ");
    while (p->topo) printf("%d ", pop(p));
    printf("\n");
}

void pilha4_estacionamento()
{
   Pilha* p = criarPilha();
    int N, k, carro;

    printf("Quantos carros tem na rua? ");
    scanf("%d", &N);

    printf("Digite os numeros da placa do carro %d:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &carro);
        push(p, carro);
    } 

    printf("Qual carro gostaria de retirar? ");
    scanf("%d", &k);

    printf("Os carros a serem retirados sao: ");
    while(p->topo){
        int valor = p->topo->dado;
        if (valor == k) {
            break;
        }
        printf("%d ", pop(p));
    }
    printf("\n");
    
    destruirPilha(p);
}

int pilha5_igualdade(Pilha* p1, Pilha* p2) {
    Elemento* a = p1->topo;
    Elemento* b = p2->topo;
    while (a != NULL && b != NULL) {
        if (a->dado != b->dado) {
            return 0;
        }
        a = a->prox;
        b = b->prox;
    }
    return (a == NULL && b == NULL);
}

void pilha6_comparar_tamanho(Pilha* p1, Pilha* p2) {
    int tamA=tamanho(p1);
    int tamB=tamanho(p2);

    if (tamA > tamB){
        printf("A primeira pilha eh maior.\n");
    }
    else if (tamA < tamB){
        printf("A segunda pilha eh maior.\n");
    }
    else{
        printf("As pilhas tem o mesmo tamanho.\n");
    }
}

void pilha7_inverter_pilha(Pilha* p) {
    Pilha* a = criarPilha();
    Pilha* b = criarPilha();

    while (p->topo) {
        push (a, pop(p));
    }
    while (a->topo) {
        push (b, pop(a));
    }
    while (b->topo) {
        push (p, pop(b));
    }

    printf("Pilha invertida!\n");

    destruirPilha(a);
    destruirPilha(b);
}

void pilha8_balanceamento() {
    int n; 
    char c;   
    Pilha* p = criarPilha();

    printf("Digite o numero  de elementos:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Digite o elementos %d: ", i+1);
        scanf(" %c", &c);

        if (c == '(' || c == '[' || c == '{') {
            push(p, c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (!p->topo) {
                printf("Sequencia nao balanceada\n");
                destruirPilha(p);
                return; 
            }
            int topo = pop(p);
            if (!((topo == '(' && c == ')') ||
                  (topo == '[' && c == ']') ||
                  (topo == '{' && c == '}'))) {
                printf("Sequencia nao balanceada\n");
                destruirPilha(p);
                return;
            }
        }
    }

    if (!p) {
        printf("Sequencia balanceada\n");
    } else {
        printf("Sequencia nao balanceada\n");
    }
    
    destruirPilha(p);
}

void pilha9_imprime_inverso(Pilha* p){
   if (!p || !p->topo) return;
   int valor = pop(p);
   pilha9_imprime_inverso(p);
   printf("%d ", valor); 
}