#include <stdio.h>

int main() {
    char frase[100], palavra[100];
    int j = 0, cont = 0;

    printf("Digite a frase:\n");
    gets(frase);
    printf("Digite a palavra:\n");
    gets(palavra);

    for (int i = 0; frase[i] != '\0'; i++) {
        for (j = 0; palavra[j] != '\0'; j++) {
            if (frase[i + j] != palavra[j]) {
                break;
            }
        }
        if (palavra[j] == '\0') {
            cont++;
        }
    }
    printf("A palavra '%s' ocorre %d vezes na frase.\n", palavra, cont);
    return 0;
}
