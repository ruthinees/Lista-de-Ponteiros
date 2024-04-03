#include "stdio.h"
#include <stdlib.h>

//Criação da função de soma de vetores.
//Ela recebe como parãmetro 3 ponteiros para vetores e o tamanho deles.
void somadevetores(int *vetor1, int *vetor2, int *vetor3, int tamanho){
  int i;
  for(i = 0; i < tamanho; i++){
    vetor3[i] = vetor1[i] + vetor2[i];
  }
}

int main(void) {
  int *vetor1, *vetor2, *vetor3; //Declarando os vetores.
  int tamanho; //Variável do tamanho.

  
  printf("Digite o tamanho dos vetores: ");
  scanf("%d", &tamanho);

  //Verificando que o tamanho seja positivo(tamanho>0);
  if(tamanho <= 0){
    while (tamanho <= 0){
      printf("TAMANHO INVÁLIDO!\n");
      printf("Digite novamente: ");
      scanf("%d", &tamanho);
    }
  }

  //Alocando a memória dos vetores e garantindo que não haja erro.
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

  //Chamando a função de soma de vetores.
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

  //Liberando a memória dos vetores.
  free(vetor1);
  free(vetor2);
  free(vetor3);
}
