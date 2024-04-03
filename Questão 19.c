#include "stdio.h"
#include <stdlib.h>

void somadevetores(int *vetor1, int *vetor2, int *vetor3, int tamanho){
  int i;
  for(i = 0; i < tamanho; i++){
    vetor3[i] = vetor1[i] + vetor2[i];
  }
}

int main(void) {
  int *vetor1, *vetor2, *vetor3;
  int tamanho;

  printf("Digite o tamanho dos vetores: ");
  scanf("%d", &tamanho);
  
  vetor1 = malloc(tamanho*sizeof(int));

  if (vetor1 == NULL) {
      printf("Erro ao alocar memória.\n");
      return 1;
  }

  vetor2 = malloc(tamanho*sizeof(int));

  if (vetor2 == NULL) {
      printf("Erro ao alocar memória.\n");
      return 1;
  }

  vetor3 = malloc(tamanho*sizeof(int));

  if (vetor3 == NULL) {
      printf("Erro ao alocar memória.\n");
      return 1;
  }

  printf("Digite os valores do vetor1: ");
  for(int i = 0; i < tamanho; i++){
      scanf("%d", &vetor1[i]);
  }

  printf("Digite os valores do vetor2: ");
  for(int i = 0; i < tamanho; i++){
      scanf("%d", &vetor2[i]);
  }

  somadevetores(vetor1, vetor2, vetor3, tamanho);

  printf("vetor1: ");
  for(int i = 0; i < tamanho; i++){
      printf("%d ", vetor1[i]);
  }

  printf("\nvetor2: ");
  for(int i = 0; i < tamanho; i++){
      printf("%d ", vetor2[i]);
  }

  printf("\nvetor3: ");
  for(int i = 0; i < tamanho; i++){
      printf("%d ", vetor3[i]);
  }

  free(vetor1);
  free(vetor2);
  free(vetor3);
}
