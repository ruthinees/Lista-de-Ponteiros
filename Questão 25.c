#include "stdio.h"
#include "stdlib.h"

//função genérica para alocar matrizes tridimensionais
//Recebe como paramêtros o número da altura, largura e profundidade.
//Retorna um ponteiro para uma matriz tridimensinal.
int ***alocamatriz(int altura, int largura, int profundidade){
  int ***matriz = malloc(altura*sizeof(int**)); //alocando a altura

  //testando se a alocação foi feita corretamente.
  if (matriz == NULL) {
      printf("Erro ao alocar memória para altura.\n");
      exit(1);
  }

  //alocando a largura. A altura é o bloco auxiliar da largura.
  for (int i = 0; i < altura; i++) {
      matriz[i] = (int **)malloc(largura * sizeof(int *));
      //testando se a alocação foi feita corretamente.
      if (matriz[i] == NULL) {
          printf("Erro ao alocar memória para a largura.\n");
          exit(1);
      }
  }

  //alocando a profundidade. Para cada valor da altura, haverá um bloco da largura e, esse bloco, será o bloc auxiliar da profundidade.
  for(int j = 0; j < altura; j++){
    for(int k = 0; k < largura; k++){
      matriz[j][k] = malloc(profundidade * sizeof(int));
      //testando se a alocação foi feita corretamente.
      if(matriz[j][k] == NULL){
        printf("Erro ao alocar memória para profundidade da matriz.\n");
        exit(1);
      }
    }
  }

  //retornando a matriz alocada.
  return matriz;
}

// Função genérica para liberar a memória alocada pela matriz tridimensional
//Não precisamos dar como paramêtro a profundidade pois ela é um bloco que depende da altura e largura, sendo M[altura[largura] = profundidade.
void liberarMatrizTridimensional(int ***matriz, int altura, int largura){
    int i, j;

    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            free(matriz[i][j]);
        }
        free(matriz[i]);
    }
    free(matriz);
}

// Função para imprimir um plano da matriz tridimensional
void imprimirPlano(int ***matriz, int altura, int largura, int profundidade, int plano) {
    int i, j;
    if(plano < 0 || plano >= profundidade){
      while(plano < 0 || plano >= profundidade){
         printf("Plano inválido.\n");
        printf("Digite novamente o plano que deseja imprimir: \n");
        scanf("%d", &plano);
      }
    }
    printf("Plano %d da matriz tridimensional:\n", plano);

    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            printf("[%d][%d][%d] = %d ", i, j, plano, matriz[i][j][plano]);
            
        }
        printf("\n");
    }
}

//função para modificar um elemento. 
//Recebe como paramêtros a matriz, altura, largura e profundidade e as coordenadas do valor que deseja modificar. Além disso, recebe o novo valor que deseja colocar na posição escolhida.
void modificarElemento(int ***matriz, int alt, int larg, int prof, int coord_alt, int coord_larg, int coord_prof, int novo_valor) {
    while (!(coord_alt >= 0 && coord_alt < alt && coord_larg >= 0 && coord_larg < larg && coord_prof >= 0 && coord_prof < prof)){
        printf("Coordenadas inválidas.\n");
        printf("Digite novamente as coordenadas do elemento que deseja modificar separadas por espaço: ");
        scanf("%d %d %d", &coord_alt, &coord_larg, &coord_prof);
        printf("\n");
    }

    printf("Digite o novo valor: ");
    scanf("%d", &novo_valor);
    printf("\n");

    matriz[coord_alt][coord_larg][coord_prof] = novo_valor;
    printf("Elemento [%d][%d][%d] modificado para %d\n", coord_alt, coord_larg, coord_prof, novo_valor);
}

//função para o preenchimento da matriz com valores dados pelo usuário
void preenchermatriz(int ***matriz, int altura, int largura, int profundidade){
  printf("Digite os valores da matriz: \n");

  for(int i = 0; i < altura; i++){
    for(int j = 0; j < largura; j++){
      for(int k = 0; k < profundidade; k++){
        printf("elemento[%d][%d][%d] = ", i, j, k);
        scanf("%d", &matriz[i][j][k]);
        if(matriz[i][j][k] != 0 && matriz[i][j][k] != 1){
          while(matriz[i][j][k] != 0 && matriz[i][j][k] != 1){
            printf("Valor inválido, digite novamente: \n");
            printf("elemento[%d][%d][%d] = ", i, j, k);
            scanf("%d", &matriz[i][j][k]);
          }
        }
      }
    }
  }
}


int main(void) {
  int alt, larg, prof;
  int coord_alt, coord_larg, coord_prof, novo_valor;
  int plano;

  int ***matriz;

  printf("Digite a altura, largura e profundidade da matriz separadas por espaços:  ");
  scanf("%d %d %d", &alt, &larg, &prof);

  matriz = alocamatriz(alt, larg, prof);

  preenchermatriz(matriz, alt, larg, prof);

  printf("Digite o plano que deseja imprimir: \n");
  scanf("%d", &plano);
  printf("\n");

  imprimirPlano(matriz, alt, larg, prof, plano);

  printf("\n");

  printf("Digite as coordenadas do elemento que deseja modificar separadas por espaço: ");
  scanf("%d %d %d", &coord_alt, &coord_larg, &coord_prof);
  printf("\n");
  
  modificarElemento(matriz, alt, larg, prof, coord_alt, coord_larg, coord_prof, novo_valor);

  printf("\n");

  //imprimir mesmo plano que modificou o elemento.
  imprimirPlano(matriz, alt, larg, prof, plano);

  printf("\n");

  liberarMatrizTridimensional(matriz, alt, larg);
}
