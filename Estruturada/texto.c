#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *txt; 
    char linha[256]; 

    txt = fopen("arq.txt", "r");
    if (txt == NULL) { 
        printf("Erro ao abrir o arquivo 'arq.txt'. Certifique-se de que ele existe.\n");
        return 1;
    }

    printf("Conteudo do arquivo 'arq.txt':\n");
    while (fgets(linha, sizeof(linha), txt)) {
        printf("%s", linha); 
    }

    fclose(txt);

    return 0;
}