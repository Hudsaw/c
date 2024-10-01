// main.c
#include <stdio.h>
#include "001.h"
#include "002.h"
#include "003.h"
#include "004.h"
#include "005.h"
#include "006.h"
#include "007.h"
#include "008.h"
#include "009.h"
#include "010.h"
#include "011.h"
#include "012.h"
#include "013.h"
#include "014.h"
#include "015.h"
#include "023.h"
#include "025.h"


void menu() {
    int escolha;
    do {
        printf("\nPrograma escrito para estudar!\n");
        printf("\nEscolha uma acao:\n");
        printf("1. Retirar numero de matriz\n");
        printf("2. Multiplicar numero por matriz\n");
        printf("3. Somar elementos da matriz\n");
        printf("4. Multiplicar matriz por vetor\n");
        printf("5. Atualizar movimentacao de conta\n");
        printf("6. Gabarito de prova\n");
        printf("7. Resultado de loteria esportiva\n");
        printf("8. Divisao de matriz por maior elemento\n");
        printf("9. Ordem Inversa do vetor\n");
        printf("10. Listão de acertos na prova\n");
        printf("11. Verificar rolagem de dado\n");
        printf("12. Produto escalar de vetores\n");
        printf("13. Raios das circunferencias centradas\n");
        printf("14. Buscar palavra em frase\n");
        printf("15. Conferir repeticao de reais\n");
        printf("23. Calcular medias ponderadas\n");
        printf("25. Calcular soma maxima\n");
        printf("27. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        printf("\n");
        getchar();

        switch (escolha) {
            
            case 1:
                combinar_diferentes();
                break;
            case 2:
                escalar_matriz();
                break;
            case 3:
                somar_elementos();
                break;
            case 4:
                matriz_x_vetor();
                break;
            case 5:
                atualizar_conta();
                break;
            case 6:
                gabarito_prova();
                break;
            case 7:
                gabarito_loteria();
                break;
            case 8:
                matriz_modificada();
                break;
            case 9:
                ordem_inversa(); 
                break;
            case 10:
                listao(); 
                break;      
            case 11:
                rolar_dados(); 
                break;
            case 12:
                produto_escalar(); 
                break;
            case 13:
                raios_circunf(); 
                break;
            case 14:
                buscar_palavras(); 
                break;
            case 15:
                repeticao_reais(); 
                break;
            case 23:
                medias_ponderadas();
                break;
            case 25:
                soma_maxima();
                break;
            case 27:
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha inválida. Tente novamente.\n");
                break;
        }
    } while (escolha != 27);
}

int main(void) {
    menu(); // Chama a função do menu para execução do programa
    return 0;
}