#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int hora;
    int minuto;
    int segundo;
} Horario;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    Data data;
    Horario horario;
    char descricao[100];
} Compromisso;

typedef struct {
    char nome[50];
    int idade;
    char endereco[100];
} Pessoa;

typedef struct {
    char nome[50];
    int matricula;
    char curso[50];
} Aluno;

typedef struct {
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
} AlunoCurso;

typedef struct {
    int matricula;
    char nome[50];
    int codigoDisc;
    float nota1;
    float nota2;
} AlunoDisc;

typedef struct {
    double r;
    double a;
} Polar;

typedef struct {
    double x;
    double y;
} Cartesiano;

typedef struct {
    char nome[50];
    int idade;
    char sexo;
    int cpf;
    Data dataNasc;
    int codigo;
    char cargo [30];
    float salario;
} Funcionario;

typedef struct {
    char nome[50];
    int matricula;
    float media;
} AlunoMedia;

#define NUM_CARTAS 52
#define NUM_NAIPES 4
#define NUM_VALORES 13

typedef struct {
    char *valor;
    char *naipe;
    int pontuacao;
} Carta;

typedef struct {
    char nome[50];
    char endereco [100];
    Data dataNasc;
    char cidade[15];
    int cep;
    char email[30];
} Cadastro;

typedef struct{
    char marca[15];
    int ano;
    float preco;
} Carro;

typedef struct{
    char nome[15];
    char descricao[30];
} Genero;

typedef struct{
    char titulo[30];
    Genero genero;
    char autor[15];
    int ano;
} Livro;

typedef struct{
    char nome[15];
    int potencia;
    int tempo;
} Eletro;

typedef struct{
    int cod;
    char nome[15];
    float preco;
    int quant;
} Produto;

typedef struct{
    int cod, qsaida, qchegada; 
    char nome[15];
} Aeroporto;

typedef struct{
    int cod, origem, destino;
} Voos;

typedef struct{
    char rua[30], bairro[15], cidade[15], estado[3];
    int cep;
} Endereco;

typedef struct {
    int codigo;
    char nome[50];
    Endereco endereco;
    float salario;
    int cpf;
    char civil[15];
    int telefone;
    int idade;
    char sexo;
} CadastroFunc;

typedef struct{
    char nome[50];
    char email[30];
    Endereco endereco;
    int telefone;
    Data datanasc;
    char obs[100];
} Contato;

void funcao1() {
    Compromisso compromisso = {{11, 10, 2024}, {20, 30, 0}, "Reuniao de projeto"};
    
    printf("\nCompromisso: %02d/%02d/%d %02d:%02d:%02d - %s\n", 
           compromisso.data.dia, compromisso.data.mes, compromisso.data.ano, 
           compromisso.horario.hora, compromisso.horario.minuto, compromisso.horario.segundo, 
           compromisso.descricao);

    printf("Para qual data (DD MM AA) gostaria de alterar?\n");
    scanf("%d %d %d", &compromisso.data.dia, &compromisso.data.mes, &compromisso.data.ano);

    printf("Para qual horario (HH MM SS) gostaria de alterar?\n");
    scanf("%d %d %d", &compromisso.horario.hora, &compromisso.horario.minuto, &compromisso.horario.segundo);

    strcpy(compromisso.descricao, "Reuniao de projeto - Alterado");

    printf("Compromisso modificado: %02d/%02d/%d %02d:%02d:%02d - %s\n", 
           compromisso.data.dia, compromisso.data.mes, compromisso.data.ano, 
           compromisso.horario.hora, compromisso.horario.minuto, compromisso.horario.segundo, 
           compromisso.descricao);
}

void imprimirPessoa(Pessoa p) {
    printf("Nome: %s\nIdade: %d\nEndereco: %s\n", p.nome, p.idade, p.endereco);
}

void funcao2() {
    Pessoa pessoa;
    printf("\nDigite o nome (separe com _): ");
    scanf(" %s", pessoa.nome);
    printf("Digite a idade: ");
    scanf("%d", &pessoa.idade);
    printf("Digite o endereco (separe com _): ");
    scanf(" %s", pessoa.endereco);

    imprimirPessoa(pessoa);
}

void imprimirAlunos(Aluno alunos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Matricula: %d, Curso: %s\n", 
               alunos[i].nome, alunos[i].matricula, alunos[i].curso);
    }
}

void funcao3() {
    Aluno alunos[5];
    for (int i = 0; i < 5; i++) {
        printf("\nDigite o nome do aluno %d: ", i + 1);
        scanf(" %s", alunos[i].nome);
        printf("Digite a matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Digite o curso: ");
        scanf(" %s", alunos[i].curso);
    }
    imprimirAlunos(alunos, 5);
}

void Maior(AlunoCurso alunos[], int num){
    int maior=0;
    for (int i = 0; i < num; i++) {
        if (alunos[i].nota1 > maior) {
            maior = i;
        }
    }
    printf("Aluno com maior nota na primeira prova: %s\n", alunos[maior].nome);
}

void MaiorM(AlunoCurso alunos[], int num){
    int maiorM=0, media=0;
    for (int i = 0; i < num; i++) {
        media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
        if (media > (alunos[maiorM].nota1 + alunos[maiorM].nota2 + alunos[maiorM].nota3) / 3) {
            maiorM = i;
        }
    printf("Aluno com maior media geral: %s\n", alunos[maiorM].nome);
    }
}

void MenorM(AlunoCurso alunos[], int num){
    int menorM=0, media=0;
    for (int i = 0; i < num; i++) {
        media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
        if (media > (alunos[menorM].nota1 + alunos[menorM].nota2 + alunos[menorM].nota3) / 3) {
            menorM = i;
        }
    printf("Aluno com menor media geral: %s\n", alunos[menorM].nome);
    }
}

void Media (AlunoCurso alunos[], int num){
    for (int i = 0; i < num; i++) {
        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
        printf("Aluno %s - Media: %.2f - %s\n", alunos[i].nome, media, media >= 6.0 ? "Aprovado" : "Reprovado");
    }
}

void funcao4() {
    AlunoCurso alunos[50];
    int i, num=5;

    printf("\nDigite quantos alunos tem no curso:");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %s", alunos[i].nome);
        printf("Digite a nota da primeira prova: ");
        scanf("%f", &alunos[i].nota1);
        printf("Digite a nota da segunda prova: ");
        scanf("%f", &alunos[i].nota2);
        printf("Digite a nota da terceira prova: ");
        scanf("%f", &alunos[i].nota3);
    }

    Maior(alunos, num);
    MaiorM(alunos, num);
    MenorM(alunos, num);
    Media(alunos, num);
}

void funcao5() {
    AlunoDisc alunos[50];
    float media, soma;
    int i, num=10;

    printf("\nDigite quantos alunos tem na disciplina 101 - Estruturada:");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        alunos[i].codigoDisc = 101;
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %s", alunos[i].nome);
        printf("Digite a nota da primeira prova: ");
        scanf("%f", &alunos[i].nota1);
        printf("Digite a nota da segunda prova: ");
        scanf("%f", &alunos[i].nota2);
    }

    for (i = 0; i < num; i++) {

        float media = ((alunos[i].nota1 + alunos[i].nota2 *2) / 3);

        printf("Aluno %s da disciplina de %d teve media: %.2f - %s\n", alunos[i].nome, alunos[i].codigoDisc, media, media >= 6.0 ? "Aprovado" : "Reprovado");
    }
}

Cartesiano polarParaCart (Polar polar){
    Cartesiano cartesiano;
    cartesiano.x = polar.r * cos(polar.a);
    cartesiano.y = polar.r * sin(polar.a);
    return cartesiano;
}

void funcao6() {
    Polar cordPolar;
    Cartesiano cordCart;

    printf("\nDigite a coordenada polar (raio argumento): ");
    scanf("%lf %lf", &cordPolar.r, &cordPolar.a);

    cordCart = polarParaCart (cordPolar);

    printf("Coordenadas cartesianas:\n");
    printf("x: %.2f\n", cordCart.x);
    printf("y: %.2f\n", cordCart.y);
}

void ImprimirFuncionarios(Funcionario funcionario[], int n) {
    for (int i = 0; i < n; i++) {
        printf("O funcionario %s, do sexo %s, nascido em %02d/%02d/%04d, tem %d anos de idade, inscrito no CPF: %d, trabalha do setor: %d, como %s e recebe R$ %.2f de salario\n", 
            funcionario[i].nome, funcionario[i].sexo, funcionario[i].dataNasc.dia, funcionario[i].dataNasc.mes, funcionario[i].dataNasc.ano,funcionario[i].idade, funcionario[i].cpf, funcionario[i].codigo, funcionario[i].cargo, funcionario[i].salario);
    }
}

void funcao7() {
    Funcionario funcionario[50];
    int i, num=10;

    printf("\nDigite quantos funcionarios gostarias de cadastrar: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        printf("Digite o nome do funcionario %d (separe com _): ", i + 1);
        scanf(" %s", funcionario[i].nome);
        printf("Digite a idade do funcionario %d: ", i + 1);
        scanf("%d", &funcionario[i].idade);
        printf("Digite o sexo do funcionario %d (M/F): ", i + 1);
        scanf(" %s", &funcionario[i].sexo);
        printf("Digite o CPF do funcionario %d: ", i + 1);
        scanf("%d", &funcionario[i].cpf);
        printf("Digite a data de nascimento do funcionario %d (dd mm aaaa): ", i + 1);
        scanf("%d %d %d", &funcionario[i].dataNasc.dia, &funcionario[i].dataNasc.mes, &funcionario[i].dataNasc.ano);
        printf("Digite o codigo do setor do funcionario %d: ", i + 1);
        scanf("%d", &funcionario[i].codigo);
        printf("Digite o cargo que o funcionario %d ocupa (separe com _): ", i + 1);
        scanf(" %s", &funcionario[i].cargo); 
        printf("Digite o salario do funcionario %d: ", i + 1);
        scanf("%f", &funcionario[i].salario); 
    }

    ImprimirFuncionarios(funcionario, num);
}

void ImprimePessoa(Pessoa p[], int n) {
    Pessoa temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(p[i].nome, p[j].nome) > 0) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
    printf("Nome: %s\n", p[i].nome);
    printf("Endereco: %s\n", p[i].endereco);
    printf("Telefone: %d\n", p[i].idade);
    }
}

void funcao8() {
    Pessoa pessoas[50];
    int i, num=5;

    printf("\nDigite quantas pessoas gostarias de cadastrar: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        printf("Digite o nome da %d° pessoa (separe com _): ", i + 1);
        scanf(" %s", pessoas[i].nome);
        printf("Digite o endereco da %d° pessoa (separe com _): ", i + 1);
        scanf(" %s", &pessoas[i].endereco);
        printf("Digite o telefone da %d° pessoa: ", i + 1);
        scanf("%d", &pessoas[i].idade);
    }
    ImprimePessoa (pessoas, num);
}

void ImprimirAlunoMedia(AlunoMedia alunos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Aluno %s, de matricula %d, tem nota %.1f.\n", 
            alunos[i].nome, alunos[i].matricula, alunos[i].media);
    }
}

void funcao9() {
    AlunoMedia alunos[50], aprovados[50], reprovados[50];
    int menor=0, maior=0, num=10;

    printf("\nDigite quantos alunos tem na turma:");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %s", alunos[i].nome);
        printf("Digite a nota da media: ");
        scanf("%f", &alunos[i].media);
        if (alunos[i].media < 5) {
            reprovados[menor]=alunos[i];
            menor++;
            }
        else{
            aprovados[maior]=alunos[i];
            maior++;
        }
    }
    if(menor==0){
        printf("Nao ha alunos reprovados\n");
    }
    else{
        printf("Os alunos reprovados sao:\n");
        ImprimirAlunoMedia(reprovados, menor);
    }
    if(maior==0){
        printf("Nao ha alunos aprovados\n");
    }
    else{
        printf("Os alunos aprovados sao:\n");
        ImprimirAlunoMedia(aprovados, maior);
    }
}

void inicializarBaralho(Carta *baralho) {
    char *valores[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char *naipes[] = {"Copas", "Espadas", "Ouros", "Paus"};
    int k = 0;

    for (int i = 0; i < NUM_VALORES; i++) {
        for (int j = 0; j < NUM_NAIPES; j++) {
            baralho[k].valor = valores[i];
            baralho[k].naipe = naipes[j];
            baralho[k].pontuacao = i + 2;
            k++;
        }
    }
}

void embaralhar(Carta *baralho) {
    for (int i = 0; i < NUM_CARTAS; i++) {
        int j = rand() % NUM_CARTAS;
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

void distribuirCartas(Carta *baralho, Carta *mao, int *indiceBaralho, int numCartas) {
    for (int i = 0; i < numCartas; i++) {
        mao[i] = baralho[(*indiceBaralho)++];
    }
}

void mostrarMao(Carta *mao, int num, char *jogador) {
    printf("\n%s possui as seguintes cartas:\n", jogador);
    for (int i = 0; i < num; i++) {
        printf("%d. %s de %s\n", i + 1, mao[i].valor, mao[i].naipe);
    }
}

int escolheCarta(Carta *mao, int num, char *jogador) {
    int escolha;
    printf("\n%s, escolha uma carta para jogar (1-%d): ", jogador, num);
    scanf("%d", &escolha);
    return escolha - 1;
}

void jogarRodada(Carta *jogador, Carta *npc, int *numJogador, int *numNPC, Carta *baralho, int *indiceBaralho) {
    mostrarMao(jogador, *numJogador, "Jogador");
    int escolhaJogador = escolheCarta(jogador, *numJogador, "Jogador");
    printf("Jogador jogou: %s de %s\n", jogador[escolhaJogador].valor, jogador[escolhaJogador].naipe);

    int escolhaNPC = rand() % (*numNPC);
    printf("NPC jogou: %s de %s\n", npc[escolhaNPC].valor, npc[escolhaNPC].naipe);
    
    if (jogador[escolhaJogador].pontuacao > npc[escolhaNPC].pontuacao) {
        printf("Jogador vence a rodada!\n");
        npc[*numNPC] = baralho[(*indiceBaralho)++];
        (*numNPC)++;
    }
    else if (jogador[escolhaJogador].pontuacao < npc[escolhaNPC].pontuacao){
        printf("NPC vence a rodada!\n");
        jogador[*numJogador] = baralho[(*indiceBaralho)++];
        (*numJogador)++;
    }else {
        printf("A rodada empatou!\n");
        jogador[*numJogador] = baralho[(*indiceBaralho)++];
        (*numJogador)++;
        npc[*numNPC] = baralho[(*indiceBaralho)++];
        (*numNPC)++;
    }

    for (int i = escolhaJogador; i < *numJogador - 1; i++) {
        jogador[i] = jogador[i + 1];
    }
    (*numJogador)--;

    for (int i = escolhaNPC; i < *numNPC - 1; i++) {
        npc[i] = npc[i + 1];
    }
    (*numNPC)--;
}

void funcao10() {
    srand(time(NULL));

    Carta baralho[NUM_CARTAS];
    Carta jogador[NUM_CARTAS];
    Carta npc[NUM_CARTAS];
    int indiceBaralho = 0;
    int numJogador = 5;
    int numNPC = 5;

    inicializarBaralho(baralho);
    embaralhar(baralho);
    distribuirCartas(baralho, jogador, &indiceBaralho, numJogador);
    distribuirCartas(baralho, npc, &indiceBaralho, numNPC);

    while (numJogador > 0 && numNPC > 0) {
        jogarRodada(jogador, npc, &numJogador, &numNPC, baralho, &indiceBaralho);
    }

    if (numJogador == 0) {
        printf("\nJogador venceu o jogo!\n");
    } else {
        printf("\nNPC venceu o jogo!\n");
    }
    
}

void cadastrar(Cadastro *cadastro, int num) {
    
    printf("\nDigite seus dados pessoais:");
    printf("\nDigite o nome (separe com _): ");
    scanf(" %s", cadastro[num].nome);
    printf("Digite o endereco (separe com _): ");
    scanf(" %s", cadastro[num].endereco);
    printf("Digite a Cidade (separe com _): ");
    scanf(" %s", cadastro[num].cidade);
    printf("Digite o CEP 00000000: ");
    scanf("%d", &cadastro[num].cep);
    ;printf("Digite a data de nascimento dd mm aa: ");
    scanf("%d %d %d", &cadastro[num].dataNasc.dia, &cadastro[num].dataNasc.mes, &cadastro[num].dataNasc.ano);
    printf("Digite o email: ");
    scanf(" %s", cadastro[num].email);
}

void comparar(Cadastro *cadastro, int num){
    while(strstr(cadastro[num].email, "@") == NULL){
        printf("Email errado, digite novamente!");
        scanf(" %s", cadastro[num].email);
    }
    while(cadastro[num].cep < 10000000 || cadastro[num].cep > 99999999){
        printf("CEP errado, digite novamente!");
        scanf("%d", &cadastro[num].cep);
    }
    while(cadastro[num].dataNasc.dia < 01 || cadastro[num].dataNasc.dia > 31){
        printf("Dia na data errado, digite novamente!");
        scanf("%d", &cadastro[num].dataNasc.dia);
    }
    while(cadastro[num].dataNasc.mes < 01 || cadastro[num].dataNasc.mes > 12){
        printf("Mes na data errado, digite novamente!");
        scanf("%d", &cadastro[num].dataNasc.mes);
    }
    while(cadastro[num].dataNasc.ano < 0 || cadastro[num].dataNasc.ano > 99){
        printf("Ano na data errado, digite novamente!");
        scanf("%d", &cadastro[num].dataNasc.ano);
    }

    printf("Os dados parecem corretos!");
}

void imprimeCadastro(Cadastro *cadastro, int num){
    printf("\n%s ", cadastro[num].nome);
    printf("que mora na rua %s, ", cadastro[num].endereco);
    printf("%s,", cadastro[num].cidade);
    printf(" CEP %d. ", cadastro[num].cep);
    ;printf("Nascido em %d/%d/%d,", cadastro[num].dataNasc.dia, cadastro[num].dataNasc.mes, cadastro[num].dataNasc.ano);
    printf(" tem o email: %s.", cadastro[num].email);
}

void funcao11() {
    Cadastro cadastro[50];
    int num;

    printf("\nQuantos usuarios gostarias de cadastrar? ");
    scanf("%d", &num);

    for (int i=0; i<num; i++){
        cadastrar(cadastro, i);
        comparar(cadastro, i);
    }
    for (int i=0; i<num; i++){
        imprimeCadastro(cadastro, i);
    }
}

void cadastrarCarro(Carro *carro, int num){

    printf("\nDigite os dados do %do carro:\n", num+1);
    printf("Marca: ");
    scanf(" %s", carro[num].marca);
    printf("Ano: ");
    scanf("%d", &carro[num].ano);
    printf("Preco: ");
    scanf("%f", &carro[num].preco);
}

void buscarCarro(Carro *carro, float p, int num){
    int cont=0;
    for (int i=0; i<num; i++){
        if(carro[i].preco<=p){
            printf("\nO carro %s de %d custa R$ %.2f", carro[i].marca, carro[i].ano, carro[i].preco);
            cont++;
        }
    }
    if (!cont){
        printf("\nSem carros nesta faixa de preco de R$ %.2f!\n", p);
    }
    printf("\n");
}

void funcao12() {
    Carro carro[50];
    int num;
    float p=0;
    printf("\nQuantos carros gostarias de cadastrar? ");
    scanf("%d", &num);

    for (int i=0; i<num; i++){
        cadastrarCarro(carro, i);
    }

    printf("\nQual o valor maximo do carro que procuras? ");
    scanf("%f", &p);

    buscarCarro(carro, p, num);
}

void cadastrarGenero(Genero *genero, int num){
    
    printf("\nDigite os dados do genero:\n");
    printf("Nome: ");
    getchar();
    fgets(genero[num].nome, sizeof(genero[num].nome), stdin);
    genero[num].nome[strcspn(genero[num].nome, "\n")] = '\0';
    printf("Descricao: ");
    fgets(genero[num].descricao, sizeof(genero[num].descricao), stdin);
    genero[num].descricao[strcspn(genero[num].descricao, "\n")] = '\0';

}

void cadastrarLivro(Livro *livro, int num){

    printf("\nDigite os dados do %do livro:\n", num+1);
    printf("Titulo: ");
    getchar();
    fgets(livro[num].titulo, sizeof(livro[num].titulo), stdin);
    livro[num].titulo[strcspn(livro[num].titulo, "\n")] = '\0';
    printf("Autor: ");
    fgets(livro[num].autor, sizeof(livro[num].autor), stdin);
    livro[num].autor[strcspn(livro[num].autor, "\n")] = '\0';
    printf("Genero: ");
    fgets(livro[num].genero.nome, sizeof(livro[num].genero.nome), stdin);
    livro[num].genero.nome[strcspn(livro[num].genero.nome, "\n")] = '\0';
    printf("Ano: ");
    scanf("%d", &livro[num].ano);
}

void buscarLivro(Livro *livro, char *busca, int num, int tipo){
    int cont=0;
    if(tipo ==1){
        printf("\nBusca pelo titulo %s iniciada:", busca);
        for (int i=0; i<=num; i++){
            if(strstr(livro[i].titulo, busca) != NULL){
            printf("\nTitulo: %s, autor: %s, ano: %d", livro[i].titulo, livro[i].autor, livro[i].ano);
            cont++;
            }
        }
    } else if(tipo==2){
        printf("\nBusca pelo genero %s iniciada:", busca);
        for (int i=0; i<=num; i++){
            if(strstr(livro[i].genero.nome, busca) != NULL){
            printf("\nTitulo: %s, autor: %s, ano: %d", livro[i].titulo, livro[i].autor, livro[i].ano);
            cont++;
            }
        }
    } else if(tipo==3){
        printf("\nBusca pelo autor %s iniciada:", busca);
        for (int i=0; i<=num; i++){
            if(strstr(livro[i].autor, busca) != NULL){
            printf("\nTitulo: %s, genero: %s, ano: %d", livro[i].titulo, livro[i].genero.nome, livro[i].ano);
            cont++;
            }
        }
    }
    if (!cont){
        printf("\nNenhum livro encontrado com %s!\n", busca);
    }
}

void funcao13() {
    Livro livro[50];
    Genero genero[50];
    int num=-1, gen=-1, tipo, esc=0;
    char busca[20];

    do{
        printf("\n1. Cadastrar livros.");
        printf("\n2. Cadastrar genero.");
        printf("\n3. Buscar pelo titulo.");
        printf("\n4. Buscar pelo genero.");
        printf("\n5. Buscar pelo autor.");
        printf("\n0. Sair.");
        printf("\nEscolha uma funcao:");
        scanf("%d", &esc);
        getchar();
        switch (esc){
            case 1:
                num++;
                cadastrarLivro(livro, num);
                break;
            case 2:
                gen++;
                cadastrarGenero(genero, gen);
                break;
            case 3:
                printf("\nQual o titulo que procuras? ");
                fgets(busca, sizeof(busca), stdin);
                busca[strcspn(busca, "\n")] = '\0';
                buscarLivro(livro, busca, num, 1);
                break;
            case 4:
                printf("\nQual o genero que procuras? ");
                fgets(busca, sizeof(busca), stdin);
                busca[strcspn(busca, "\n")] = '\0';
                buscarLivro(livro, busca, num, 2);
                break;
            case 5:
                printf("\nQual o autor que procuras? ");
                fgets(busca, sizeof(busca), stdin);
                busca[strcspn(busca, "\n")] = '\0';
                buscarLivro(livro, busca, num, 3);
                break;
            case 0:
                printf("Saindo...\n");
                return;
            default:
                printf("Escolha invalida. Tente novamente.\n");
                break;
            }
    } while (esc != 0);

}

void cadastrarCompromisso(Compromisso *compromisso, int num){
    
    printf("\nDigite os dados do %do compromisso:\n", num+1);
    printf("Para qual data (DD MM AA) gostaria de agendar?\n");
    scanf("%d %d %d", &compromisso[num].data.dia, &compromisso[num].data.mes, &compromisso[num].data.ano);

    printf("Para qual horario (HH MM SS) gostaria de agendar?\n");
    scanf("%d %d %d", &compromisso[num].horario.hora, &compromisso[num].horario.minuto, &compromisso[num].horario.segundo);

    printf("Qual o contexto do compromisso?\n");
    getchar();
    fgets(compromisso[num].descricao, sizeof(compromisso[num].descricao), stdin);
    compromisso[num].descricao[strcspn(compromisso[num].descricao, "\n")] = '\0';
}

void buscarAgenda(Compromisso *compromisso, int mes, int ano, int num){
    int cont=0;
    for (int i=0; i<num; i++){
        if(compromisso[i].data.mes == mes && compromisso[i].data.ano == ano){
         printf("\nCompromisso: %02d/%02d/%d %02d:%02d:%02d - %s\n", 
           compromisso[i].data.dia, compromisso[i].data.mes, compromisso[i].data.ano, 
           compromisso[i].horario.hora, compromisso[i].horario.minuto, compromisso[i].horario.segundo, 
           compromisso[i].descricao);
        cont++;
        }
    }
    if (!cont){
        printf("\nNenhum compromisso encontrado para o mes %d do ano %d!\n", mes, ano);
    }
    printf("\n");
}

void funcao14() {
    Compromisso compromisso[50];
    int num, mes, ano;

    printf("\nQuantos compromissos gostarias de cadastrar? ");
    scanf("%d", &num);
    
    for (int i=0; i<num; i++){
        cadastrarCompromisso(compromisso, i);
    }

    printf("\nQual o mes e ano que procuras (MM AA)? ");
    scanf("%d %d", &mes, &ano);
    
    buscarAgenda(compromisso, mes, ano, num);
}

void cadastrarEletro(Eletro *eletro, int num){
    
    printf("\nDigite os dados do %do eletrodomestico:\n", num+1);
    printf("Nome: ");
    getchar();
    fgets(eletro[num].nome, sizeof(eletro[num].nome), stdin);
    eletro[num].nome[strcspn(eletro[num].nome, "\n")] = '\0';
    printf("Potencia (kW): ");
    scanf("%d", &eletro[num].potencia);
    printf("Tempo ativo por dia (HH): ");
    scanf("%d", &eletro[num].tempo);

}

void buscarConsumo(Eletro *eletro, int tempo, int num){
    float cont[50], soma=0;
    
    for (int i=0; i<num; i++){
        cont[i] = eletro[i].potencia*(eletro[i].tempo*tempo);
        soma+= cont[i];
    }

    for (int i=0; i<num; i++){
        printf("\nO eletrodomestico %s, consumiu %.1f%% do total nos %d dias", eletro[i].nome, (cont[i]/soma)*100, tempo);
    }
    printf("\nO consumo total dos eletrodomesticos foi de %.1fkW nos %d dias", soma, tempo);
    
    if (!soma){
        printf("\nNenhum eletrodomestico encontrado para calcular consumo dos %d dias!\n", tempo);
    }
    printf("\n");
}

void funcao15(){
    Eletro eletro[50];
    int num, tempo;

    printf("\nQuantos eletrodomesticos gostarias de cadastrar? ");
    scanf("%d", &num);
    
    for (int i=0; i<num; i++){
        cadastrarEletro(eletro, i);
    }

    printf("\nQual o tempo de consumo gostarias de verificar (DD)? ");
    scanf("%d", &tempo);
    
    buscarConsumo(eletro, tempo, num);
}

void cadastrarProduto(Produto *produto, int num){
    
    printf("\nDigite os dados do %do produto:\n", num+1);
    printf("Codigo: ");
    scanf("%d", &produto[num].cod);
    printf("Nome: ");
    getchar();
    fgets(produto[num].nome, sizeof(produto[num].nome), stdin);
    produto[num].nome[strcspn(produto[num].nome, "\n")] = '\0';
    printf("Preco: ");
    scanf("%f", &produto[num].preco);
    printf("Quantidade: ");
    scanf("%d", &produto[num].quant);

}

void buscarProduto(Produto *produto, int codigo, int num){
    int cont=0;
    for(int i=0; i<num; i++){
        if(produto[i].cod == codigo){
            printf("\nO produto %s de codigo %d tem em estoque %d unidades", produto[i].nome, produto[i].cod, produto[i].quant);
            cont++;
        }
    }
    if(!cont){
        printf("\nProduto nao encontrado!");
    }
}

void venderProduto(Produto *produto, int codigo, int quant, int num){
    int cont=0;
    for(int i=0; i<num; i++){
        if(produto[i].cod==codigo){
            if(produto[i].quant < quant){
                printf("\nNao foi possivel efetuar a venda de %d unidades.", quant);
            }
            else{
                produto[i].quant-=quant;
                printf("\nVenda de %dunid de %s, valor total R$ %.2f.", quant, produto[i].nome, produto[i].preco*quant);
            }
            cont++;
        }
    }
    if(!cont){
        printf("\nProduto nao encontrado!");
    }
}

void funcao16(){
    Produto produto[50];
    int num, codigo, quant;
    
    printf("\nQuantos produtos gostarias de cadastrar? ");
    scanf("%d", &num);
    
    for (int i=0; i<num; i++){
        cadastrarProduto(produto, i);
    }

    printf("\nQual o codigo do produto que gostarias de comprar?");
    scanf("%d", &codigo);
    buscarProduto(produto, codigo, num);

    printf("\nQuantas unidades do produto %d gostarias de comprar?", codigo);
    scanf("%d", &quant);
    venderProduto(produto, codigo, quant, num);

    buscarProduto(produto, codigo, num);
}

void cadastrarAeroporto(Aeroporto *aeroporto, int num) {
    printf("\nDigite os dados do %do aeroporto:\n", num+1);
    printf("Codigo: ");
    scanf("%d", &aeroporto[num].cod);
    printf("Nome: ");
    getchar();  
    fgets(aeroporto[num].nome, sizeof(aeroporto[num].nome), stdin);
    aeroporto[num].nome[strcspn(aeroporto[num].nome, "\n")] = '\0';
    aeroporto[num].qsaida = 0;
    aeroporto[num].qchegada = 0;
}

int encontrarAeroporto(Aeroporto *aeroporto, int numa, int codigo) {
    for (int i = 0; i < numa; i++) {
        if (aeroporto[i].cod == codigo) {
            return i;
        }
    }
    return -1; 
}

void cadastrarVoos(Voos *voos, Aeroporto *aeroporto, int numa, int numv) {
    int pos;

    printf("\nDigite os dados do %do voo:\n", numv+1);
    printf("Codigo do voo: ");
    scanf("%d", &voos[numv].cod);

    while (1) {
        printf("Codigo do aeroporto de origem: ");
        scanf("%d", &voos[numv].origem);
        pos = encontrarAeroporto(aeroporto, numa, voos[numv].origem);
        if (pos != -1) {
            aeroporto[pos].qsaida++;
            break;
        } else {
            printf("Codigo errado, digite novamente: \n");
        }
    }

    while (1) {
        printf("Codigo do aeroporto de destino: ");
        scanf("%d", &voos[numv].destino);
        if(voos[numv].destino != voos[numv].origem){
            pos = encontrarAeroporto(aeroporto, numa, voos[numv].destino);
            if (pos != -1) {
                aeroporto[pos].qchegada++;
                break;
            } else {
                printf("Codigo errado, digite novamente: \n");
            }
        } else {
            printf("Origem e destinos nao podem ser iguais!\n");
        }
    }
}

void imprimeSaidas(Aeroporto *aeroporto, Voos *voos, int numa, int numv) {
    int cont;
    for (int i = 0; i < numa; i++) {
        cont = 0;
        printf("\nAeroporto %s, lista das %d saidas:\n", aeroporto[i].nome, aeroporto[i].qsaida);
        for (int j = 0; j < numv; j++) {
            if (voos[j].origem == aeroporto[i].cod) {
                int destinoIdx = encontrarAeroporto(aeroporto, numa, voos[j].destino);
                if (destinoIdx != -1) {
                    printf("Voo de codigo %d com destino a %s\n", voos[j].cod, aeroporto[destinoIdx].nome);
                    cont++;
                }
            }
        }
        if (cont == 0) {
            printf("Nenhuma saida programada para o aeroporto %s\n", aeroporto[i].nome);
        }
    }
}

void imprimeChegadas(Aeroporto *aeroporto, Voos *voos, int numa, int numv) {
    int cont;
    for (int i = 0; i < numa; i++) {
        cont = 0;
        printf("\nAeroporto %s, lista das %d chegadas:\n", aeroporto[i].nome, aeroporto[i].qchegada);
        for (int j = 0; j < numv; j++) {
            if (voos[j].destino == aeroporto[i].cod) {
                int origemIdx = encontrarAeroporto(aeroporto, numa, voos[j].origem);
                if (origemIdx != -1) {
                    printf("Voo de codigo %d com origem em: %s\n", voos[j].cod, aeroporto[origemIdx].nome);
                    cont++;
                }
            }
        }
        if (cont == 0) {
            printf("Nenhuma chegada programada para o aeroporto %s\n", aeroporto[i].nome);
        }
    }
}

void imprimirAeroportos(Aeroporto *aeroporto, Voos *voos, int numa, int numv) {
    imprimeSaidas(aeroporto, voos, numa, numv);
    imprimeChegadas(aeroporto, voos, numa, numv);
}

void funcao17() {
    Aeroporto aeroporto[50];
    Voos voos[50];
    int numa, numv;

    printf("\nQuantos aeroportos gostaria de cadastrar? ");
    scanf("%d", &numa);

    for (int i = 0; i < numa; i++) {
        cadastrarAeroporto(aeroporto, i);
    }

    printf("\nQuantos voos gostaria de cadastrar? ");
    scanf("%d", &numv);

    for (int i = 0; i < numv; i++) {
        cadastrarVoos(voos, aeroporto, numa, i);
    }

    imprimirAeroportos(aeroporto, voos, numa, numv);
}

void cadastrarEndereco(Endereco *endereco, int i) {
    printf("Rua: ");
    fgets(endereco[i].rua, sizeof(endereco[i].rua), stdin);
    endereco[i].rua[strcspn(endereco[i].rua, "\n")] = '\0';

    printf("Bairro: ");
    fgets(endereco[i].bairro, sizeof(endereco[i].bairro), stdin);
    endereco[i].bairro[strcspn(endereco[i].bairro, "\n")] = '\0';

    printf("Cidade: ");
    fgets(endereco[i].cidade, sizeof(endereco[i].cidade), stdin);
    endereco[i].cidade[strcspn(endereco[i].cidade, "\n")] = '\0';

    printf("Estado (XX): ");
    fgets(endereco[i].estado, sizeof(endereco[i].estado), stdin);
    endereco[i].estado[strcspn(endereco[i].estado, "\n")] = '\0';
    getchar();

    printf("CEP (00000000): ");
    scanf("%d", &endereco[i].cep);
    getchar();
}

void cadastrarFunc(CadastroFunc *funcionario, int i) {
    
    printf("Digite o codigo do funcionario %d: ", i + 1);
    scanf("%d", &funcionario[i].codigo);
    while (getchar() != '\n');

    printf("Digite o nome do funcionario %d (separe com _): ", funcionario[i].codigo);
    fgets(funcionario[i].nome, sizeof(funcionario[i].nome), stdin);
    funcionario[i].nome[strcspn(funcionario[i].nome, "\n")] = '\0';
    
    printf("Digite o salario do funcionario %s: ", funcionario[i].nome);
    scanf("%f", &funcionario[i].salario);
    while (getchar() != '\n');

    printf("Digite o CPF do funcionario %s: ", funcionario[i].nome);
    scanf("%d", &funcionario[i].cpf);
    while (getchar() != '\n');

    printf("Digite o estado civil do funcionario %s: ", funcionario[i].nome);
    fgets(funcionario[i].civil, sizeof(funcionario[i].civil), stdin);
    funcionario[i].civil[strcspn(funcionario[i].civil, "\n")] = '\0';

    printf("Digite o telefone do funcionario %s: ", funcionario[i].nome);
    scanf("%d", &funcionario[i].telefone);
    while (getchar() != '\n');

    printf("Digite a idade do funcionario %s: ", funcionario[i].nome);
    scanf("%d", &funcionario[i].idade);
    while (getchar() != '\n'); 

    printf("Digite o sexo do funcionario %s (M/F): ", funcionario[i].nome);
    scanf(" %c", &funcionario[i].sexo);
    while (getchar() != '\n');
    
    printf("Digite o endereco do funcionario %s:\n", funcionario[i].nome);
    cadastrarEndereco(&funcionario[i].endereco, i);
}

void maisVelho(CadastroFunc *funcionario, int num){
    int velho = 0, pos= -1;
    for (int i = 0; i < num; i++) {
        if (funcionario[i].idade > velho) {
            velho = funcionario[i].idade;
            pos = i;
        }
    }
    if (pos != -1) {
        printf("\nO funcionario mais velho eh:\n");
        printf("Funcionario: %s, com %d anos de idade.\n", funcionario[pos].nome, funcionario[pos].idade);
    }
}

void selecaoGenero(CadastroFunc *funcionario, int num, char gen){
    int cont=0;
    if (gen=='M'){
        printf("\nLista dos funcionarios do genero masculino:\n");
    } else if (gen=='F'){
        printf("\nLista dos funcionarios do genero feminino:\n");
    } else {
        printf("\nLista dos funcionarios do sem genero definido:\n");
    }
    
    for (int i = 0; i < num; i++) {
        if (funcionario[i].sexo == gen) {
            printf("Funcionario: %s.\n", funcionario[i].nome);
            cont++;
        }
    }

    if (!cont){
        printf("\nNao tem funcionarios do genero %c", gen);
    }
}

void selecaoSalario(CadastroFunc *funcionario, int num, float salario){
    int cont=0;
    printf("\nLista dos funcionarios com salario acima de R$ %.2f:\n", salario);
    
    for (int i = 0; i < num; i++) {
        if (funcionario[i].salario >= salario) {
            printf("Funcionario: %s, com salario de R$ %.2f.\n", funcionario[i].nome, funcionario[i].salario);
            cont++;
        }
    }

    if (!cont){
        printf("\nNao tem funcionarios com salario de R$ %.2f", salario);
    }
}

void funcao18(){
    CadastroFunc funcionario[50];
    int num, esc=0;
    char gen;
    float salario;

    printf("\nDigite quantos funcionarios gostarias de cadastrar: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        cadastrarFunc(funcionario, i);
    }
    do {
        printf("\nEscolha uma acao:\n");
        printf("1. Ordene por idade!\n");
        printf("2. Selecione por genero!\n");
        printf("3. Selecione por salario!\n");
        printf("0. Sair\n");
        printf("Digite sua escolha:");
        scanf("%d", &esc);
        switch (esc) {
            case 1:
                maisVelho(funcionario, num);
                break;
            case 2:
                printf("Por qual genero gostaria de selecionar:");
                scanf(" %c",&gen);
                selecaoGenero(funcionario, num, gen);
                break;
            case 3:
                printf("Por qual valor de salario gostaria de selecionar: R$ ");
                scanf("%f",&salario);
                selecaoSalario(funcionario, num, salario);
                break;
            case 0:
                printf("Saindo...\n");
                return;
            default:
                printf("Escolha invalida. Tente novamente.\n");
                break;
        }
    } while (esc != 0);
}

int isBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int contarDias(Data data) {
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dias = data.dia;

    for (int i = 0; i < data.mes - 1; i++) {
        dias += diasPorMes[i];
    }
    if (data.mes > 2 && isBissexto(data.ano)) {
        dias += 1;
    }
    for (int i = 0; i < data.ano; i++) {
        dias += isBissexto(i) ? 366 : 365;
    }
    return dias;
}

int diferencaDias(Data inicio, Data final) {
    int diasinicio = contarDias(inicio);
    int diasfinal = contarDias(final);

    int diferenca =  diasfinal - diasinicio;
    return diferenca;
}

void funcao19(){
    Data inicio, final;

    printf("\nDigite a data de inicio:");
    scanf("%d %d %d", &inicio.dia, &inicio.mes, &inicio.ano);
    printf("Digite a data final:");
    scanf("%d %d %d", &final.dia, &final.mes, &final.ano);

    int diasEntreDatas = diferencaDias(inicio, final);
    printf("\nO numero entre as duas datas eh de %d dias \n", diasEntreDatas);

}

void cadastrarContato(Contato *contato, int i){
    
    printf("Digite o nome do contato %d (separe com _): ", i+1);
    fgets(contato[i].nome, sizeof(contato[i].nome), stdin);
    contato[i].nome[strcspn(contato[i].nome, "\n")] = '\0';
    
    printf("Digite o email do %s: ", contato[i].nome);
    fgets(contato[i].email, sizeof(contato[i].email), stdin);
    contato[i].email[strcspn(contato[i].email, "\n")] = '\0';
    
    printf("Digite o telefone do %s: ", contato[i].nome);
    scanf("%d", &contato[i].telefone);
    while (getchar() != '\n');

    printf("Digite a data de nascimento do %s (DD MM AA): ", contato[i].nome);
    scanf("%d %d %d", &contato[i].datanasc.dia, &contato[i].datanasc.mes, &contato[i].datanasc.ano);
    while (getchar() != '\n');

    printf("Digite observacoes do %s: ", contato[i].nome);
    fgets(contato[i].obs, sizeof(contato[i].obs), stdin);
    contato[i].obs[strcspn(contato[i].obs, "\n")] = '\0';
    
    printf("Digite o endereco do %s:\n", contato[i].nome);
    cadastrarEndereco(&contato[i].endereco, i);
}

void imprimirContato(Contato contato, int i) {
    printf("\n%d. Nome: %s, Email: %s\n", i+1, contato.nome, contato.email);
    printf("Telefone: %d, Data de nascimento: %02d/%02d/%d\n", contato.telefone, contato.datanasc.dia, contato.datanasc.mes, contato.datanasc.ano);
    printf("Endereco: %s, %s, %s, %s, CEP: %d\n", contato.endereco.rua, contato.endereco.bairro, contato.endereco.cidade, contato.endereco.estado, contato.endereco.cep);
    printf("Observacoes: %s\n", contato.obs);
}

void buscaNome(Contato *contato, char *busca, int num) {
    int cont = 0;
    for (int i = 0; i < num; i++) {
        if (strstr(contato[i].nome, busca) != NULL) {
            imprimirContato(contato[i], i);
            cont++;
        }
    }
    if (!cont) {
        printf("\nNenhum contato encontrado com %s!\n", busca);
    }
    printf("\n");
}

void buscaMes(Contato *contato, int mes, int num) {
    int cont = 0;
    for (int i = 0; i < num; i++) {
        if (contato[i].datanasc.mes == mes) {
            imprimirContato(contato[i], i);
            cont++;
        }
    }
    if (!cont) {
        printf("\nNenhum contato encontrado nascido em %d!\n", mes);
    }
    printf("\n");
}

void insereOrdenado(Contato *contato, int *num, Contato novoContato) {
    int i = (*num) - 1;
    while (i >= 0 && strcmp(contato[i].nome, novoContato.nome) > 0) {
        contato[i + 1] = contato[i];
        i--;
    }
    contato[i + 1] = novoContato;
    (*num)++; 
}

void excluiContato(Contato *contato, int ex, int *num) {
    for (int i = ex; i < (*num) - 1; i++) {
        contato[i] = contato[i + 1]; 
    }
    (*num)--; 
}

void imprimeAgenda(Contato *contato, int opcao, int num) {
    for (int i = 0; i < num; i++) {
        if (opcao == 1) {
            printf("%d. Nome: %s, Telefone: %d, Email: %s\n", i+1, contato[i].nome, contato[i].telefone, contato[i].email);
        } else if (opcao == 2) {
            imprimirContato(contato[i], i);
        }
    }
}

void funcao20() {
    Contato novoContato;
    Contato agenda[100];
    int num = 0, esc = 0, ex, mes;
    char temp[30];

    do {
        printf("\nEscolha uma acao:\n");
        printf("1. Cadastrar contato\n");
        printf("2. Buscar por nome\n");
        printf("3. Buscar por mes de aniversario\n");
        printf("4. Remover contato\n");
        printf("5. Imprimir agenda - Nome, telefone, email\n");
        printf("6. Imprimir agenda - Todos os dados\n");
        printf("0. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &esc);
        while (getchar() != '\n'); 
        switch (esc) {
            case 1: 
                cadastrarContato(&novoContato, num);
                insereOrdenado(agenda, &num, novoContato); 
                break;
            case 2:
                printf("Digite um nome para busca: ");
                fgets(temp, sizeof(temp), stdin);
                temp[strcspn(temp, "\n")] = '\0';
                buscaNome(agenda, temp, num);
                break;
            case 3:
                printf("Digite o mes para a busca: ");
                scanf(" %d", &mes);
                buscaMes(agenda, mes, num);
                break;
            case 4:
                printf("Digite o numero do contato que deseja excluir: ");
                scanf(" %d", &ex);
                ex--;
                excluiContato(agenda, ex, &num);
                break;
            case 5:
                imprimeAgenda(agenda, 1, num);
                break;
            case 6:
                imprimeAgenda(agenda, 2, num);
                break;
            case 0:
                printf("Saindo...\n");
                return;
            default:
                printf("Escolha invalida. Tente novamente.\n");
                break;
        }
    } while (esc != 0);
}

void menu() {
    int escolha;
    do {
        printf("\nPrograma escrito para estudar!\n");
        printf("Escolha uma acao:\n");
        printf("1. Novos tipos de dados\n");
        printf("2. Leitura de dados de uma pessoa\n");
        printf("3. Cadastro de alunos\n");
        printf("4. Notas dos alunos\n");
        printf("5. Media ponderada dos alunos\n");
        printf("6. Coordenadas polares em cartesianas\n");
        printf("7. Armazenamento de registro\n");
        printf("8. Impressao em ordem\n");
        printf("9. Exibir aprovados e reprovados\n");
        printf("10. Jogo de cartas\n");
        printf("11. Cadastro correto\n");
        printf("12. Busca de carros\n");
        printf("13. Buscar livros\n");
        printf("14. Checar agenda\n");
        printf("15. Consumo energetico\n");
        printf("16. Estoque de mercado\n");
        printf("17. Voos e aeroportos\n");
        printf("18. Cadastro e busca de funcionarios\n");
        printf("19. Diferenca de datas\n");
        printf("20. Agenda de contatos\n");
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
                funcao5();
                break;
            case 6:
                funcao6();
                break;
            case 7:
                funcao7();
                break;
            case 8:
                funcao8();
                break;
            case 9:
                funcao9();
                break;
            case 10:
                funcao10();
                break;
            case 11:
                funcao11();
                break;
            case 12:
                funcao12();
                break;
            case 13:
                funcao13();
                break;
            case 14:
                funcao14();
                break;
            case 15:
                funcao15();
                break;
            case 16:
                funcao16();
                break;
            case 17:
                funcao17();
                break;
            case 18:
                funcao18();
                break;
            case 19:
                funcao19();
                break;
            case 20:
                funcao20();
                break;
            case 0:
                printf("Saindo...\n");
                return;
            default:
                printf("Escolha invalida. Tente novamente.\n");
                break;
        }
    } while (escolha != 0);
}

int main(void) {
    menu();
    return 0;
}
