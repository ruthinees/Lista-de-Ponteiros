#include "stdio.h"
#include <stdlib.h>

//Criação de uma função genérica para alocação de matrizes
int **alocamatriz(int linha, int coluna){
  int **matriz = malloc(linha*sizeof(int*));

  if (matriz == NULL) {
      printf("Erro ao alocar memória.\n");
      exit(1);
  }

  matriz[0] = malloc(linha*coluna*sizeof(int));

  if (matriz[0] == NULL) {
        printf("Erro ao alocar memória para matriz (2ª dimensão).\n");
        free(matriz); // Liberar memória alocada para a 1ª dimensão
        exit(1);
  }

  for(int i = 1; i < linha; i++){
    matriz[i] = matriz[i-1] + coluna;
  }

  return matriz;
}

//Criação de uma função genérica para printar as matrize.
void printmatriz(int **matriz, int linha, int coluna){
  for(int i = 0; i < linha; i++){
    for(int j = 0; j < coluna; j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

//Criação da função de multiplicação de matrizes
//Ela recebe como parãmetro 3 ponteiros para matrizes, o número de linhas e colunas de A e o número de colunas de B (leva-se em conta que o número de linhas de B é igual ao número de colunas de A).
void multiplicacaodematrizes
(int **A , int **B, int **C, int nlA, int ncA, int ncB){
  int i;
  int j;
  for (int i = 0; i < nlA; i++) {
      for (int j = 0; j < ncB; j++) {
          C[i][j] = 0;
          for (int k = 0; k < ncA; k++) {
              C[i][j] += A[i][k] * B[k][j];
          }
      }
  }
}

int main(void) {
  int **A, **B, **C; //Declarando as matrizes
  int nlA, ncA, ncB; //Variável do tamanho.


  printf("Digite o número de linhas de A: ");
  scanf("%d", &nlA);

  //Verificando que o número de linhas de A seja positivo;
  if(nlA <= 0){
    while (nlA <= 0){
      printf("TAMANHO INVÁLIDO!\n");
      printf("Dite novamente: ");
      scanf("%d", &nlA);
    }
  }

  printf("Digite o número de colunas de A: ");
  scanf("%d", &ncA);

  //Verificando que o número de colunas de A seja positivo;
  if(ncA <= 0){
    while (ncA <= 0){
      printf("TAMANHO INVÁLIDO!\n");
      printf("Dite novamente: ");
      scanf("%d", &ncA);
    }
  }

  printf("Digite o número de colunas de B: ");
  scanf("%d", &ncB);

  //Verificando que o número de colunas de B seja positivo;
  if(ncB <= 0){
    while (ncB <= 0){
      printf("TAMANHO INVÁLIDO!\n");
      printf("Dite novamente: ");
      scanf("%d", &ncB);
    }
  }

  //Alocando a memória das matrizes e garantindo que não haja erro.
  A = alocamatriz(nlA, ncA);
  B = alocamatriz(ncA, ncB);
  C = alocamatriz(nlA, ncB);
  
  //Pedidindo para o usuário os valores das matrizes A e B.

  printf("Digite os valores da matriz A:\n");
  for(int i = 0; i < nlA; i++){
    for(int j = 0; j < ncA; j++){
      printf("a[%d][%d] = ", i+1, j+1);
      scanf("%d", &A[i][j]);
    }
  }

  printf("\nDigite os valores da matriz B:\n");
  for(int i = 0; i < ncA; i++){
    for(int j = 0; j < ncB; j++){
      printf("b[%d][%d] = ", i+1, j+1);
      scanf("%d", &B[i][j]);
    }
  }

  //Chamando a função de multiplicação de matrizes.
  multiplicacaodematrizes(A, B, C, nlA, ncA, ncB);

  //Mostrando as matrizes A, B e C no terminal.
  printf("\nMatriz A:\n");
  printmatriz(A, nlA, ncA);

  printf("\nMatriz B:\n");
  printmatriz(B, ncA, ncB);

  printf("\nMatriz C:\n");
  printmatriz(C, nlA, ncB);

  //Liberando a memória das matrizes.
  free(A[0]);
  free(A);
  free(B[0]);
  free(B);
  free(C[0]);
  free(C);
}
