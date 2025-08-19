#include <stdio.h>
#include <string.h>

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
    system("cls");
}

typedef struct {
    float base;
    float altura;
} Retangulo;
   
void inicializarRetangulo(Retangulo *r, float base, float altura) {
    r->base = base;
    r->altura = altura;
}

float calcularArea(Retangulo *r) {
    return r->base * r->altura;
}

float calcularPerimetro(Retangulo *r) {
    return 2 * (r->base + r->altura);
}

void exercicio1()
{
    Retangulo ret;
    float base, altura;
   
    printf("\nDigite a base: ");
    scanf("%f", &base);
    printf("\nDigite a altura: ");
    scanf("%f", &altura);
   
    inicializarRetangulo(&ret, base, altura);
   
    printf("Area do retangulo: %.2f\n", calcularArea(&ret));
    printf("Perimetro do retangulo: %.2f\n", calcularPerimetro(&ret));
}


typedef struct {
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
} Aluno;

void iniciarAluno(Aluno *a, char nome[], int matricula, float nota1, float nota2){
    strncpy(a->nome, nome, 50);
    a->nome[50] = nome;
    a->matricula = matricula;
    a->nota1 = nota1;
    a->nota2 = nota2;
}

float calcularMedia(Aluno *a){
    return (a->nota1 + a->nota2)/ 2;  
}

void exibirAluno(Aluno *a){
    printf("\n--- Informacoes do Aluno ---\n");
    printf("Nome: %s\n", a->nome);
    printf("Matricula: %d\n", a->matricula);
    printf("Nota 1: %.2f\n", a->nota1);
    printf("Nota 2: %.2f\n", a->nota2);
    printf("Media: %.2f\n", calcularMedia(a));
}

void exercicio2()
{
    Aluno a;
    char nome[50];
    int matricula;
    float nota1, nota2;

    getchar();
    printf("\nDigite o nome: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    printf("\nDigite a matricula: ");
    scanf("%d", &matricula);
    printf("\nDigite a nota 1: ");
    scanf("%f", &nota1);
    printf("\nDigite a nota 2: ");
    scanf("%f", &nota2);

    iniciarAluno(&a, nome, matricula, nota1, nota2);
    exibirAluno(&a);
}

typedef struct {
    int reais;
    int centavos;
} Moeda;

void iniciarMoeda(Moeda *m, int reais, int centavos) {
    m->reais = reais;
    m->centavos = centavos;
}

void somarMoedas(Moeda *m1, Moeda *m2, Moeda *resultado) {
    resultado->reais = m1->reais + m2->reais;
    resultado->centavos = m1->centavos + m2->centavos;
    if (resultado->centavos >= 100) {
        resultado->reais +=  1;
        resultado->centavos -= 100;
    }
}

void exibirMoeda(Moeda *m) {
    printf("Valor: R$ %d,%02d\n", m->reais, m->centavos);
}

void exercicio3()
{
    Moeda m1, m2, resultado;
    int reais1, centavos1, reais2, centavos2;
    
    printf("\nDigite o valor 1 (reais centavos): ");
    scanf("%d %d", &reais1, &centavos1);
    printf("\nDigite o valor 2 (reais centavos): ");
    scanf("%d %d", &reais2, &centavos2);

    iniciarMoeda(&m1, reais1, centavos1);
    iniciarMoeda(&m2, reais2, centavos2);
    somarMoedas(&m1, &m2, &resultado);
    exibirMoeda(&resultado);
}

int main()
{
    int opcao;

    do {
        printf("\n=== MENU DE EXERCICIOS ===\n");
        printf("1. Retangulo\n");
        printf("2. Aluno\n");
        printf("3. Moeda\n");
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

