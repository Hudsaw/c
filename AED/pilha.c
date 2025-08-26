#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição das estruturas
typedef struct Elemento {
    int dado;
    struct Elemento* prox;
} Elemento;

typedef struct Pilha {
    Elemento* topo;
} Pilha;

// Funções da pilha
Pilha* criarPilha() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(Pilha* p, int x) {
    Elemento* e = (Elemento*) malloc(sizeof(Elemento));
    e->dado = x;
    e->prox = p->topo;
    p->topo = e;
}

int pop(Pilha* p) {
    if (p->topo == NULL) return -999;
    Elemento* aux = p->topo;
    p->topo = aux->prox;
    int valor = aux->dado;
    free(aux);
    return valor;
}

void destruirPilha(Pilha* p) {
    while (p->topo != NULL) {
        pop(p);
    }
    free(p);
}

int tamanho(Pilha* p) {
    Elemento* aux = p->topo;
    int cont = 0;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

// Funções crud
void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

// Funções dos exercícios
void exercicio1() {
    
    Pilha* p = criarPilha();
    int num;
    
    printf("Digite um número decimal: ");
    scanf("%d", &num);
    
    if (num == 0) {
        printf("0\n");
        destruirPilha(p);
        return;
    }
    
    while (num != 0) {
        push(p, num % 2);  
        num /= 2;
    }
    
    while (p->topo != NULL) {
        printf("%d", pop(p));
    }
    printf("\n");

    destruirPilha(p);
}

int exercicio2(Pilha* r, Pilha* s){
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

void exercicio3()
{
   Pilha* p = criarPilha();
    int N, valor;

    printf("Quantos numeros voce deseja inserir? ");
    scanf("%d", &N);

    printf("Digite os %d numeros:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &valor);
        push(p, valor);
    }

    printf("Sequencia na ordem inversa: ");
    while (p->topo != NULL) {
        printf("%d ", pop(p));
    }
    printf("\n");

    destruirPilha(p);
}

void exercicio4()
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
    while(p->topo != NULL){
        int topo = p->topo->dado;
        if (topo == k) {
            break;
        }
        printf("%d ", pop(p));
    }
    printf("\n");

    destruirPilha(p);
}

int exercicio5(Pilha* p1, Pilha* p2) {
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

void exercicio6(Pilha* p1, Pilha* p2) {
    int tamA=tamanho(p1);
    int tamB=tamanho(p2);

    if (tamA > tamB){
        printf("A primeira pilha é maior.\n");
    }
    else if (tamA < tamB){
        printf("A segunda pilha é maior.\n");
    }
    else{
        printf("As pilhas tem o mesmo tamanho.\n");
    }
}

void exercicio7(Pilha* p) {
    Pilha* a = criarPilha();
    Pilha* b = criarPilha();

    while (p->topo != NULL) {
        push (a, pop(p));
    }
    while (a->topo != NULL) {
        push (b, pop(a));
    }
    while (b->topo != NULL) {
        push (p, pop(b));
    }
    destruirPilha(a);
    destruirPilha(b);
}

int main()
{
    int opcao;

    Pilha* r = criarPilha();
    push(r, 10);
    push(r, 15);
    push(r, 20);
    push(r, 25);
    push(r, 30);

    Pilha* s = criarPilha();
    push(s, '+');
    push(s, '-');
    push(s, '*');
    push(s, '/');

    Pilha* t = criarPilha();
    push(t, 10);
    push(t, 15);
    push(t, 20);
    push(t, 25);
    push(t, 30);

    do {
        printf("\n=== MENU DE EXERCICIOS ===\n");
        printf("1. Binario\n");
        printf("2. Pareada\n");
        printf("3. Invertida\n");
        printf("4. Estacionamento\n");
        printf("5. Igualdade\n");
        printf("6. Qual a maior\n");
        printf("7. Inverter pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                exercicio1();
                pausar();
                break;
            case 2:
                printf("O resultado do pareamento eh: %d\n", exercicio2(r,s));
                pausar();
                break;
            case 3:
                exercicio3();
                pausar();
                break;
            case 4:
                exercicio4();
                pausar();
                break;
            case 5:
                if (exercicio5(r, t)) {
                    printf("As pilhas sao iguais.\n");
                } else {
                    printf("As pilhas sao diferentes.\n");
                }
                pausar();
                break;
            case 6:
                exercicio6(r, s);
                pausar();
                break;
            case 7:
                exercicio7(s);
                pausar();
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                pausar();
                break;
        }


    } while (opcao != 0);

    destruirPilha(r);
    destruirPilha(s);
    destruirPilha(t);

    return 0;
}



