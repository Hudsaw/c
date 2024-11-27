#include <stdio.h>

int main() {
  int n, k, pesos[5];
  float notas[50][5], media_pond[50] = {0}, media_arit[5] = {0};

  printf("Digite o numero de alunos e de provas: ");
  scanf("%d %d", &n, &k);

  for (int i = 0; i < k; i++) {
    printf("Digite o peso da prova %d: ", i + 1);
    scanf("%d", &pesos[i]);
  }

  for (int i = 0; i < k; i++) {
     for (int j = 0; j < n; j++){
      printf("Digite a nota do aluno %d na prova %d: ", j + 1, i + 1);
      scanf("%f", &notas[i][j]);
      media_arit[i]+=notas[i][j];
    }
    media_arit[i]/=n;
    printf("A media aritmetica da prova %d eh %.1f\n", i + 1, media_arit[i]);
  }
  
  for (int i = 0; i < n; i++) {
    int sum_pesos = 0;
    for (int j = 0; j < k; j++) {
      media_pond[i] += notas[i][j] * pesos[j];
      sum_pesos += pesos[j];
    }
    media_pond[i] /= sum_pesos;
    printf("A media ponderada do aluno %d eh %.1f\n", i + 1, media_pond[i]);
  }
  return 0;
}