#include <stdio.h>


void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar(); 
    system("cls"); 
}

int fatorial(int num){
    if(num == 0) return 1;
    printf("\n numero: %d", num);
    return num * fatorial(num-1);
}


void exercicio1() {
    int x;

    printf("=== Exercicio 1 ===\n");
    printf("Digite o valores fatorial: ");
    scanf("%d", &x);
    
    int y = fatorial(x);
    printf("\nO fatorial de %d eh %d: ", x, y);
    
}


int limite(int num){
    if(num == 0) return 0;
    printf("\n numero: %d", num);
    return num + limite(num-1);
}

void exercicio2() {
    int x;

    printf("=== Exercicio 2 ===\n");
    printf("Digite o valor limite: ");
    scanf("%d", &x);
    
    int y = limite(x);
    printf("\nO limite de %d eh %d: ", x, y);
    
}

float divisao(float num){
    if(num == 0) return 0;
    printf("\n numero: 1/%.f", num);
    return 1.0/num + divisao(num-1);
}

void exercicio3() {
    int x;

    printf("=== Exercicio 3 ===\n");
    printf("Digite o valor limite: ");
    scanf("%d", &x);
    
    float y = divisao(x);
    printf("\nA soma da divisao de %d eh %.2f: ", x, y);
    
}

int expoente(int n1, int n2){
    if(n2 == 0) return 1;
    printf("\n numero: %d na %d", n1, n2);
    return n1 * expoente(n1, n2-1);
}

void exercicio4() {
    int x, y;

    printf("=== Exercicio 4 ===\n");
    printf("Digite o valor base e expoente: ");
    scanf("%d %d", &x, &y);
    
    int z = expoente(x, y);
    printf("\nA expoenciacao de %d na %d eh %d: ", x, y, z);
    
}

float vetor(float vet[], int tam){
    if(tam <= 1) return vet[tam-1];
    return vet[tam - 1] + vetor(vet, tam-1);
}

void exercicio5() {
    
    int n;
    
    printf("=== Exercicio 5 ===\n");
    printf("Quantos elementos tem o vetor? ");
    scanf("%d", &n);
    
    float vet[n];

    printf("Digite os %d valores reais do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &vet[i]);
    }
    
    float z = vetor(vet, n);
    printf("\nA soma dos numeros do vetor eh %f: ", z);
    
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

void exercicio6() {
    
    int n, ini, fim;
    
    printf("=== Exercicio 6 ===\n");
    printf("Quantos elementos tem o vetor? ");
    scanf("%d", &n);
    
    int vet[n];

    
    printf("Digite os %d valores do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vet[i]);
    }
    
    printf("Digite o inicio e fim da troca:");
    scanf("%d %d", &ini, &fim);
    
     for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    
    inverter(vet, ini, fim);
    printf("\nO atual vetor eh: ");
    imprime(vet, n);
    
    
}

void binario(int num){
    if(num > 1) binario(num/2);
    printf(" %d ", num % 2);
}

void exercicio7() {
    
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

void exercicio8() {
    
    int num, k;
    printf("=== Exercicio 8 ===\n");
    printf("Digite o numero para busca: ");
    scanf("%d", &num);
    printf("Digite o numero para buscar:\n");
    scanf("%d", &k);
    
    int z = comparar(num, k);
   
    printf("\nO numero %d aparecer %dvezes em %d", k, z, num);
    
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

void exercicio9() {
    
    int n;
    printf("=== Exercicio 9 ===\n");
    printf("Digite o numero de algarismos de fibonacci: ");
    scanf("%d", &n);
    printf("Sequencia de Fibonacci (%d termos): ", n);
    imprimir_fibonacci(n, 0);
    printf("\n");
}

int main()
{
    int opcao;

    do {
        printf("\n=== MENU DE EXERCICIOS ===\n");
        printf("1. Fatorial\n");
        printf("2. Soma\n");
        printf("3. Divisao\n");
        printf("4. Exponencial\n");
        printf("5. Vetor\n");
        printf("6. Inversao\n");
        printf("7. Binario\n");
        printf("8. Contador\n");
        printf("9. Fibonacci\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                exercicio1();
                pausar();
                break;
            case 2:
                exercicio2();
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
                exercicio5();
                pausar();
                break; 
            case 6:
                exercicio6();
                pausar();
                break;
            case 7:
                exercicio7();
                pausar();
                break;
            case 8:
                exercicio8();
                pausar();
                break;
            case 9:
                exercicio9();
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

    return 0;
}