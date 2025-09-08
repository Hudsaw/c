#include <stdio.h>

int fatorial(int num){
    if(num == 0) return 1;
    printf("\n numero: %d", num);
    return num * fatorial(num-1);
}


void rec1_fatorial() {
    int x;

    printf("=== Exercicio 1 ===\n");
    printf("Digite o valores fatorial: ");
    scanf("%d", &x);

    printf("\nO fatorial de %d eh %d: ", x, fatorial(x));
}


int limite(int num){
    if(num == 0) return 0;
    printf("\n numero: %d", num);
    return num + limite(num-1);
}

void rec2_soma() {
    int x;

    printf("=== Exercicio 2 ===\n");
    printf("Digite o valor limite: ");
    scanf("%d", &x);

    printf("\nO limite de %d eh %d: ", x, limite(x));
}

float divisao(int num){
    if(num == 0) return 0;
    printf("\n numero: 1/%.f", num);
    return 1.0/num + divisao(num-1);
}

void rec3_divisao() {
    int x;

    printf("=== Exercicio 3 ===\n");
    printf("Digite o valor limite: ");
    scanf("%d", &x);

    printf("\nA soma da divisao de %d eh %.2f: ", x, divisao(x));
}

int expoente(int n1, int n2){
    if(n2 == 0) return 1;
    printf("\n numero: %d na %d", n1, n2);
    return n1 * expoente(n1, n2-1);
}

void rec4_exponencial() {
    int x, y;

    printf("=== Exercicio 4 ===\n");
    printf("Digite o valor base e expoente: ");
    scanf("%d %d", &x, &y);

    printf("\nA expoenciacao de %d na %d eh %d: ", x, y, expoente(x, y));
}

float vetorial(float vet[], int tam){
    if(tam == 0) return vet[0];
    return vet[tam] + vetorial(vet, tam-1);
}

void rec5_vetor() {
    float vet[5];
    printf("=== Exercicio 5 ===\n");
    printf("Digite os 5 valores reais do vetor:\n");
    for (int i = 0; i < 5; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &vet[i]);
    }
    
    printf("\nA soma dos numeros do vetor eh %f: ", vetorial(vet, 5));
}

void inverter(int vet[], int ini, int fim){
    int temp;
    if(ini >= fim) return;
     temp = vet[ini];
     vet[ini] = vet[fim];
     vet[fim] = temp;
     inverter (vet, ini+1, fim-1);
}

void imprime(int vet[], int tam){
    if(tam <= 1){
    printf(" %d ", vet[tam - 1]);
    return;
    }
    imprime(vet, tam -1);
    printf(" %d ", vet[tam - 1]);
}

void rec6_inversao() {
    
    int ini, fim;
    
    printf("=== Exercicio 6 ===\n");  
    int vet[5];
    
    printf("Digite os 5 valores do vetor:\n");
    for (int i = 0; i < 5; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vet[i]);
    }
    
    printf("Digite o inicio e fim da troca:");
    scanf("%d %d", &ini, &fim);
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", vet[i]);
    }
    
    inverter(vet, ini, fim);
    printf("\nO atual vetor eh: ");
    imprime(vet, 5);    
}

void binario(int num){
    if(num > 1) binario(num/2);
    printf(" %d ", num % 2);
}

void rec7_binario() {
    
    int num;
    
    printf("=== Exercicio 7 ===\n");
    printf("Digite o numero inteiro? ");
    scanf("%d", &num);
    
    printf("\nO binario de %d eh: ", num);
    binario(num);
}

int comparar(int num, int k){
    if(num == 0) return 0;
    return ((k == num % 10) ? 1 : 0) + comparar(num/10, k);
}

void rec8_contador() {
    
    int num, k;
    printf("=== Exercicio 8 ===\n");
    printf("Digite o numero para busca: ");
    scanf("%d", &num);
    printf("Digite o numero para buscar:\n");
    scanf("%d", &k);
   
    printf("\nO numero %d aparecer %dvezes em %d", k, comparar(num, k), num);
}

int fibonacci(int n){
    if (n == 0 || n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void imprimir_fibonacci(int n, int i) {
    if (i >= n) return;
    printf("%d ", fibonacci(i));
    imprimir_fibonacci(n, i + 1);
}

void rec9_fibonacci() {
    
    int n;
    printf("=== Exercicio 9 ===\n");
    printf("Digite o numero de algarismos de fibonacci: ");
    scanf("%d", &n);
    printf("Sequencia de Fibonacci (%d termos): ", n);
    imprimir_fibonacci(n, 0);
    printf("\n");
}

int padovan(int n){
    if (n == 0 || n == 1 || n == 2) return 1;
    return padovan(n - 2) + padovan(n - 3);
}

void imprimir_padovan(int n, int i) {
    if (i >= n) return;
    printf("%d ", padovan(i));
    imprimir_padovan(n, i + 1);
}

void rec10_padovan() {
    
    int n;
    printf("=== Exercicio 10 ===\n");
    printf("Digite o numero de algarismos de Padovan: ");
    scanf("%d", &n);
    printf("Sequencia de Padovan (%d termos): ", n);
    imprimir_padovan(n, 0);
    printf("\n");
}

int tribonacci(int n){
    if(n==0 || n==1 || n==2) return 1;
    return tribonacci(n-1)+ tribonacci(n-2)+tribonacci(n-3);
}

void imprimir_tribonacci(int n, int i) {
    if (i >= n) return;
    printf("%d ", tribonacci(i));
    imprimir_tribonacci(n, i + 1);
}

void rec11_tribonacci() {
    
    int n;
    printf("=== Exercicio 11 ===\n");
    printf("Digite o numero de algarismos de Tribonacci: ");
    scanf("%d", &n);
    printf("Sequencia de Tribonacci (%d termos): ", n);
    imprimir_tribonacci(n, 0);
    printf("\n");
}

int jacobsthal(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return jacobsthal(n-1)+ 2*jacobsthal(n-2);
}

void imprimir_jacobsthal(int n, int i) {
    if (i >= n) return;
    printf("%d ", jacobsthal(i));
    imprimir_jacobsthal(n, i + 1);
}

void rec12_jacobsthal() {
    
    int n;
    printf("=== Exercicio 12 ===\n");
    printf("Digite o numero de algarismos de Jacobsthal: ");
    scanf("%d", &n);
    printf("Sequencia de Jacobsthal (%d termos): ", n);
    imprimir_jacobsthal(n, 0);
    printf("\n");
}