    #include <stdio.h>

    typedef struct {
    int distancia;
    char inicio[50];
    char fim[50];
    int ordem;
    } Caminho;

    int intervalo(int inicio, int fim) {
        int soma = 0;
        for (int i = inicio; i <= fim; i++) {
            soma += i;
        }
        return soma;
    }

    void funcao1(){
        Caminho trajeto[6];
        int num=6;
        
        printf("Digite os trajetos possíveis:\n");
        scanf("%d", &num);

        for (int i = 0; i<num; i++){
            printf("Digite o trajeto numero %d:", i+1); 
            printf("Digite a origem:");
            scanf(" %s", trajeto[i].inicio);
            printf("Digite o destino:");
            scanf(" %s", trajeto[i].fim);
            printf("Digite a distancia:");
            scanf("%d", &trajeto[i].distancia);
            printf("Digite a ordem:");
            scanf("%d", trajeto[i].ordem);
            
        }
        for (int i = 0; i < 6; i++){
            printf("%d ", num[i]);
        }
        printf("\nO valor maximo eh: %d, na posição %d.", max, pmax);
        printf("\nO valor minimo eh: %d, na posição %d.\n", min, pmin);
    }

    void menu() {
        int escolha;
        do {
            printf("\nPrograma escrito para estudar!\n");
            printf("Escolha uma acao:\n");
            printf("1. \n");
            printf("0. Sair\n");
            printf("Digite sua escolha: ");
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    funcao1();
                    break;
                case 0:
                    printf("Saindo...\n");
                    return;
                default:
                    printf("Escolha invalida. Tente novamente.\n");
                    break;
            }
        } while (escolha!=0);
    }

    int main(void) {
        menu();
        return 0;
    }
