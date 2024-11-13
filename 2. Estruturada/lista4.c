    #include <stdio.h>
    #include <string.h>

    void imprime(int val1, float val2, char val3) {
        printf("Inteiro: %d, Real: %.2f, Caractere: %c\n", val1, val2, val3);
    }

    void funcao1(){
        int inteiro = 10;
        float real = 5.5;
        char caractere = 'A';
        int *ptr_inteiro = &inteiro;
        float *ptr_real = &real;
        char *ptr_caractere = &caractere;

        printf("Antes da modificação:\n");
        imprime(inteiro, real, caractere);
        
        printf("Digite o novo valor do inteiro:\n");
        scanf("%d", ptr_inteiro);
        printf("Digite o novo valor do real:\n");
        scanf("%f", ptr_real);
        printf("Digite o novo valor do char:\n");
        scanf(" %c", ptr_caractere);

        printf("Após a modificação:\n");
        imprime(inteiro, real, caractere);
    }

    void funcao2(){
        int a, b;

        printf("Digite o valor da primeira variavel:\n");
        scanf("%d", &a);
        printf("Digite o valor da segunda variavel:\n");
        scanf("%d", &b);
        if (&a > &b) {
        printf("O maior endereco eh: %p (1a variavel)\n", (void*)&a);
        } else {
        printf("O maior endereco eh: %p (2a variavel)\n", (void*)&b);
        }
    }

    void inverter (int *a, int *b){
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

    void imprime2(int a, int b){
        printf("O valor da 1a variavel eh %d e o endereco: %p \n", a, (void*)&a);
        printf("O valor da 2a variavel eh %d e o endereco: %p \n", b, (void*)&b);
     }

    void funcao3(){
        int a, b;
        
        printf("Digite o valor da primeira variavel:\n");
        scanf("%d", &a);
        printf("Digite o valor da segunda variavel:\n");
        scanf("%d", &b);
        imprime2(a, b);
        inverter (&a,&b);
        imprime2(a, b);
    }

    void funcao4(){
        float matriz[3][3];

        for (int i = 0; i < 3; i++) {
            printf("\nDigite os valores da linha %d:\n", i+1);
            for (int j = 0; j < 3; j++) {
                printf("Digite o valor da posicao %d:", j+1);
                scanf("%f", &matriz[i][j]);
            }
        }
        printf("\nA matriz de valores:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf(" %.2f", matriz[i][j]);
            }
            printf("\n");
        }
        printf("\nEsta nos enderecos correspondentes:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf(" %p", (void*)&matriz[i][j]);
            }
            printf("\n");
        }
    }

    void funcao5(){
        char frase[100];
        char palavra[10];
        int cont = 0;

        printf("Digite a frase textual:\n");
        fgets(frase, sizeof(frase), stdin);
        frase[strcspn(frase, "\n")] = 0;

        printf("Digite uma palavra para busca:\n");
        fgets(palavra, sizeof(palavra), stdin);
        palavra[strcspn(palavra, "\n")] = 0; 

        char *ptr = frase;
        while ((ptr = strstr(ptr, palavra)) != NULL) {
            cont++;
            ptr ++;
        }

        printf("A palavra '%s' ocorre %d vezes na frase.\n", palavra, cont);
    }

    int min_max(int *array, int n, int *min, int *max) {
        *min = array[0];
        *max = array[0];
        for (int i = 1; i < n; i++) {
            if (array[i] < *min) {
                *min = array[i];
            }
            if (array[i] > *max) {
                *max = array[i];
            }
        }
}

    void funcao6(){
        int n, k;

        printf("Digite o tamanho do array: ");
        scanf("%d", &n);

        int array[50];
        
        for (int i = 0; i < n; i++) {
            printf("Digite o valor %d:", i+1);
            scanf("%d", &array[i]);
        }

        int min, max;
        min_max(array, n, &min, &max);

        printf("Digite o numero de elementos por linha: ");
        scanf("%d", &k);

        printf("\nArray com %d elementos por linha:\n", k);
        for (int i = 0; i < n; i++) {
            printf("%d ", array[i]);
            if ((i + 1) % k == 0) {
                printf("\n");
            }
        }
        printf("\n");

        printf("Endereco dos elementos do Array:\n", k);
        for (int i = 0; i < n; i++) {
            printf("%p ", (void*)&array[i]);
            if ((i + 1) % k == 0) {
                printf("\n");
            }
        }
        printf("\n");

        printf("O valor minimo do array eh: %d\n", min);
        printf("O valor maximo do array eh: %d\n", max);
        }
    
    void ler_notas(float *n1, float *n2) {
        printf("Digite a primeira nota: ");
        scanf("%f", n1);

        printf("Digite a segunda nota: ");
        scanf("%f", n2);
        }

    void calcular_medias(float n1, float n2, float *media_simples, float *media_ponderada) {
        *media_simples = (n1 + n2) / 2;
        *media_ponderada = (n1 + (n2 * 2)) / 3;
    }

    void funcao7() {
        float n1, n2, media_simples, media_ponderada;

        ler_notas(&n1, &n2);
        calcular_medias(n1, n2, &media_simples, &media_ponderada);

        printf("Media Simples: %.2f\n", media_simples);
        printf("Media Ponderada: %.2f\n", media_ponderada);
    }

    void menu() {
        int escolha, c;
        do {
            printf("\nPrograma escrito para estudar!\n");
            printf("Escolha uma acao:\n");
            printf("1. Variaveis em ponteiros\n");
            printf("2. Comparar endereco de ponteiros\n");
            printf("3. Inverter valores\n");
            printf("4. Imprimir enderecos de matriz\n");
            printf("5. Busca de texto\n");
            printf("6. Maior e menor valor\n");
            printf("7. Ler notas e calcular media\n");
            printf("0. Sair\n");
            printf("Digite sua escolha: ");
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    funcao1();
                    break;
                case 2:
                    funcao2();
                    break;
                case 3:
                    funcao3();
                    break; 
                case 4:
                    funcao4();
                    break;
                case 5:
                    while ((c = getchar()) != '\n' && c != EOF);
                    funcao5();
                    break; 
                case 6:
                    funcao6();
                    break;     
                case 7:
                    funcao7();
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
