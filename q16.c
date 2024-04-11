#include <stdio.h>
#include <stdlib.h>

//define um tamanho máximo para o vetor.
#define TAMMAX 100 

//Função que recebe dois ponteiros para valores constante e retorna ou zero (números iguai), maior que zero (a é maior que b, ou seja, ele vem depois de b) e menor que zero (a é menor que b, ou seja, ele vem antes de b)
int compare (const void * a, const void * b)
{
  return (*(float *)a - *(float *)b);
}

int main(void){

  float *n; //variável ponteiro para float que virá a ser o vetor.
  int n2; //variável do tamanho do vetor.

  n = malloc(TAMMAX * sizeof(float)); //alocando memória para o vetor.

  //Verificando se a memória foi alocada corretamente.
  if (n == NULL) {
      printf("Erro ao alocar memória.\n");
      return 1;
  }

  printf("Digite quantos valores você quer ordenar de forma crescente: ");
  scanf("%d", &n2);

  for(int i = 0; i < n2; i++){
    printf("Digite o %dº valor que será ordenado: ", i + 1);
    scanf("%f", &n[i]);
  }

  qsort (n, n2, sizeof(float), compare); //implementação da função qsort

  printf("\nValores ordenados de forma crescente:\n");
  for (int i = 0; i < n2; i++) {
      printf("%.2f ", n[i]);
  }
  printf("\n");

  free(n); //liberando a memória alocada para o vetor.
}
