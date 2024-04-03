#include "stdio.h"
#include <stdlib.h>

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
  A = malloc(nlA*sizeof(int*));

  A[0] = malloc(nlA *ncA * sizeof(int));
  
  if (A == NULL || A[0] == NULL) {
      printf("Erro ao alocar memória.\n");
      return 1;
  }

  for(int i = 1; i < nlA; i++){
    A[i] = A[i-1] + ncA;
  }
  

  B = malloc(nlA*sizeof(int*));

  B[0] = malloc(ncA *ncB * sizeof(int));

  if (B== NULL || B[0] == NULL) {
      printf("Erro ao alocar memória.\n");
      return 1;
  }

  for(int i = 1; i < ncA; i++){
    B[i] = B[i-1] + ncB;
  }

  C = malloc(nlA*sizeof(int*));

  C[0] = malloc(nlA *ncB * sizeof(int));

  if (C== NULL || C[0] == NULL) {
      printf("Erro ao alocar memória.\n");
      return 1;
  }

  for(int i = 1; i < nlA; i++){
    C[i] = C[i-1] + ncB;
  }

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
  for(int i = 0; i < nlA; i++){
    for(int j = 0; j < ncA; j++){
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }

  printf("\nMatriz B:\n");
  for(int i = 0; i < ncA; i++){
    for(int j = 0; j < ncB; j++){
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }

  printf("\nMatriz C:\n");
  for(int i = 0; i < nlA; i++){
    for(int j = 0; j < ncB; j++){
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  //Liberando a memória das matrizes.
  free(A[0]);
  free(A);
  free(B[0]);
  free(B);
  free(C[0]);
  free(C);
}
