// 23. Calcular medias ponderadas
#include <stdio.h>
#include "023.h"


void medias_ponderadas(void) {
  printf("23. Calcular medias ponderadas\n");
  int num, k;
  float pesos[5], notas[50][5], medias_ponderadas[50], medias_provas[5] = {0};

  printf("Digite o numero de alunos (1 a 50): ");
  scanf("%d", &num);

  printf("Digite o numero de provas (1 a 5): ");
  scanf("%d", &k);

  for (int i = 0; i < k; i++) {
    printf("Digite o peso da prova %d (0 a 10): ", i + 1);
    scanf("%f", &pesos[i]);
  }

  for (int j = 0; j < k; j++) {
    for (int i = 0; i < num; i++) {
      printf("Digite a nota do aluno %d na prova %d: ", i + 1, j + 1);
      scanf("%f", &notas[i][j]);
    }
  }

  for (int j = 0; j < k; j++) {
  float soma_notas = 0;
    for (int i = 0; i < num; i++) {
        soma_notas += notas[i][j];
    }
    medias_provas[j] = soma_notas / num;
    printf("A media aritmetica da prova %d eh %.1f\n", j + 1, medias_provas[j]);
  }
  
  for (int i = 0; i < num; i++) {
    float soma_ponderada = 0;
    float soma_pesos = 0;
    for (int j = 0; j < k; j++) {
        soma_ponderada += notas[i][j] * pesos[j];
        soma_pesos += pesos[j];
    }
    medias_ponderadas[i] = soma_ponderada / soma_pesos;
    printf("A media ponderada do aluno %d eh %.1f\n", i + 1, medias_ponderadas[i]);
  }
}