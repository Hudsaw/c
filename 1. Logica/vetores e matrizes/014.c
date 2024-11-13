// 14. Buscar palavra em frase
#include <stdio.h>
#include "014.h"

void buscar_palavras(void) {
    printf("14. Buscar palavra em frase\n");
    char frase[100], palavra[100];
    int i, j, cont = 0;
    int frase_len = 0, palavra_len = 0;

    printf("Digite uma frase:\n");
    gets(frase);

    while (frase[frase_len] != '\0') {
        frase_len++;
    }

    printf("Digite a palavra a ser encontrada:\n");
    gets(palavra);

    while (palavra[palavra_len] != '\0') {
        palavra_len++;
    }

    for (i = 0; i <= frase_len - palavra_len; i++) {
        for (j = 0; j < palavra_len; j++) {
            if (frase[i + j] != palavra[j]) {
                break;
            }
        }
        if (j == palavra_len) {
            cont++;
        }
    }

    printf("A palavra '%s' ocorre %d vezes na frase.\n", palavra, cont);

}
