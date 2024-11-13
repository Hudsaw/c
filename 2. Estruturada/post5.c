    #include <stdio.h>

    typedef struct {
    int distancia;
    char inicio[50];
    char fim[50];
    int ordem;
    } Caminho;

    void pegarTrechos(Caminho *trajeto, int num) {
        int t=0;

        for (int i = 0; i<num; i++){
            printf("\nDigite o trajeto numero %d:\n", i+1); 
            printf("Digite a ordem:");
            scanf("%d", &t);
            t--;
            trajeto[t].ordem = t + 1;
            printf("Digite a origem:");
            scanf(" %s", trajeto[t].inicio);
            printf("Digite o destino:");
            scanf(" %s", trajeto[t].fim);
            printf("Digite a distancia:");
            scanf("%d", &trajeto[t].distancia);
        }
    }

    void totalTrajeto(Caminho *trajeto, int num) {
        int soma=0;
        for (int i = 0; i<num; i++){
            soma += trajeto[i].distancia;
            
        }
        printf("\nO trajeto inicia em %s e termina em %s e percorre %d km de distancia.\n", trajeto[0].inicio, trajeto[num-1].fim, soma); 
    }

    void funcao1(){
        Caminho trajeto[50];
        int num=6;
        
        printf("Digite o numero de trechos possiveis no trajeto:");
        scanf("%d", &num);

        pegarTrechos(trajeto, num);
        
        for (int i = 0; i < num; i++){
            printf("O trecho numero %d, tem %d km de distancia, com origem: %s e destino: %s.\n", trajeto[i].ordem, trajeto[i].distancia, trajeto[i].inicio, trajeto[i].fim);
        }

        totalTrajeto(trajeto, num);
    }

    void menu() {
        int escolha;
        do {
            printf("\nPrograma escrito para estudar!\n");
            printf("Escolha uma acao:\n");
            printf("1. Trajeto e trechos de viagem\n");
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
