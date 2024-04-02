#include <stdio.h>
#include <stdlib.h>

//define um tamanho máximo para o vetor.
#define TAMMAX 100

// Função de ordenação crescente que recebe um ponteiro para um vetor e o valor do seu tamanho.
void ordenacaocrescente(float *vetor, int tamvet){
  int i, j, min_index;
  float temp;

  //A cada iteração, o índice que conter o menor valor será atualizado se o valor mínimo não for o valor mínimo atual. A iteração só irá até o penúltimo elemento do vetor, pois o último elemento já será o maior valor.
  for (i = 0; i < tamvet - 1; i++) {
    min_index = i;
    for (j = i + 1; j < tamvet; j++) {
        if (vetor[j] < vetor[min_index]) {
            min_index = j;
        }
    }
    // Troca os valores
    temp = vetor[min_index];
    vetor[min_index] = vetor[i];
    vetor[i] = temp;
  }
}

int main(void){

  float *n; //variável ponteiro para float que virá a ser o vetor.
  int n2; //variável do tamanho do vetor.

  n = malloc(TAMMAX * sizeof(float)); //alocando memória para o vetor.

  //Verificando se a memória foi alocada corretamente

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

  ordenacaocrescente(n, n2);

  printf("\nValores ordenados de forma crescente:\n");
  for (int i = 0; i < n2; i++) {
      printf("%.2f ", n[i]);
  }
  printf("\n");

  free(n);
}
