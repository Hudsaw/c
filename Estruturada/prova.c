#include <stdio.h>
#include <string.h> 

typedef struct {
    char letras[26];
    int numeros[26];
} Tabela;

typedef struct {
    int soma;
    int resultado;
    char letras[30];
    int posicao[30];
} Nome;

void encherTabela(Tabela *tabela) {
    strcpy(tabela->letras, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    tabela->numeros[0] = 1;
    tabela->numeros[1] = 2;
    tabela->numeros[2] = 3;
    tabela->numeros[3] = 4;
    tabela->numeros[4] = 5;
    tabela->numeros[5] = 6;
    tabela->numeros[6] = 7;
    tabela->numeros[7] = 8;
    tabela->numeros[8] = 9;
    tabela->numeros[9] = 1;
    tabela->numeros[10] = 2;
    tabela->numeros[11] = 3;
    tabela->numeros[12] = 4;
    tabela->numeros[13] = 5;
    tabela->numeros[14] = 6;
    tabela->numeros[15] = 7;
    tabela->numeros[16] = 8;
    tabela->numeros[17] = 9;
    tabela->numeros[18] = 1;
    tabela->numeros[19] = 2;
    tabela->numeros[20] = 3;
    tabela->numeros[21] = 4;
    tabela->numeros[22] = 5;
    tabela->numeros[23] = 6;
    tabela->numeros[24] = 7;
    tabela->numeros[25] = 8;
}

void incluirNome(Nome *nome, char *letras) {
    strcpy(nome->letras, letras);
}

void calcularSoma(Nome *nome, Tabela *tabela) {
    nome->soma = 0;
    for (int i = 0; i < strlen(nome->letras); i++) {
        for (int j = 0; j < 26; j++) {
            if (nome->letras[i] == tabela->letras[j]) {
                nome->soma += tabela->numeros[j];
            }
        }
    }
    if (nome->soma > 9) {
        nome->resultado = nome->soma % 10 + nome->soma / 10;
    } else {
        nome->resultado = nome->soma;
    }
}

void calcularTotal(Nome *nome, Nome *nome1, Nome *nome2) {
    int sum = nome->resultado + nome1->resultado + nome2->resultado;
    if (sum > 9) {
        sum = sum % 10 + sum / 10;
    }
    printf("\nTotal: %d", sum);
}

int main() {
    Nome hudson;
    Nome ricardo;
    Nome borges;
    Tabela tabela;

    encherTabela(&tabela);
    incluirNome(&hudson, "HUDSON");
    incluirNome(&ricardo, "RICARDO");
    incluirNome(&borges, "BORGES");

    calcularSoma(&hudson, &tabela);
    printf("\nA soma do nome %s eh: %d", hudson.letras, hudson.soma);
    printf("\nO resultado do nome %s eh: %d", hudson.letras, hudson.resultado);

    calcularSoma(&ricardo, &tabela);
    printf("\nA soma do nome %s eh: %d", ricardo.letras, ricardo.soma);
    printf("\nO resultado do nome %s eh: %d", ricardo.letras, ricardo.resultado);

    calcularSoma(&borges, &tabela);
    printf("\nA soma do nome %s eh: %d", borges.letras, borges.soma);
    printf("\nO resultado do nome %s eh: %d", borges.letras, borges.resultado);

    calcularTotal(&hudson, &ricardo, &borges);

    return 0;
}
