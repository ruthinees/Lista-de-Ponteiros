#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de ordenação crescente genérica.
// Recebe um vetor, seu tamanho e uma função de comparação.


void ordenacaocrescente(int *vetor, int tamvet, int (*f) (int, int)) {
    int i, j, min_index;
    int temp;

    // Loop externo para percorrer todo o vetor.
    for (i = 0; i < tamvet - 1; i++) {
        min_index = i;

        // Loop interno para encontrar o menor elemento.
        for (j = i + 1; j < tamvet; j++) {
            // Se o elemento atual for menor que o mínimo, atualiza o índice do mínimo.
            if (f(vetor[j], vetor[min_index]) < 0) {
                min_index = j;
            }
        }

        // Troca o elemento atual com o menor elemento encontrado.
        temp = vetor[min_index];
        vetor[min_index] = vetor[i];
        vetor[i] = temp;
    }
}

// Função de comparação para ordenação.
// Retorna um valor negativo se a < b, zero se a == b, e um valor positivo se a > b.
int compare(int a, int b) {
    return a - b;
}

int main(void) {
    struct timespec start, end;
    double time_taken;

    
    int *n;
    int n2 = 5; // Tamanho do vetor.

    
    // Aloca memória para o vetor.
    n = malloc(n2 * sizeof(int));

    srand(time(NULL));
    for(int i = 0; i < n2; i++){
        n[i] = rand() % 100;
    }
    // Verifica se a alocação foi bem-sucedida.
    if (n == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    clock_gettime(CLOCK_MONOTONIC, &start);
    
  // Chama a função de ordenação, passando o vetor, seu tamanho e a função de comparação.
    ordenacaocrescente(n, n2, compare);

    clock_gettime(CLOCK_MONOTONIC, &end);

    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  
    printf("\nValores ordenados de forma crescente:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
  
    free(n);//libera a memória alocada

    printf("O tempo gasto pelo programa é: %f segundos", time_taken);
}




//Função que recebe dois ponteiros para valores constante e retorna ou zero (números iguai), maior que zero (a é maior que b, ou seja, ele vem depois de b) e menor que zero (a é menor que b, ou seja, ele vem antes de b)
int compare(const void * a, const void * b)
{
  return (*(int *)a - *(int *)b);
}

int main(void){

  struct timespec start, end;
    double time_taken;

    
    int *n;
    int n2 = 5; // Tamanho do vetor.

    
    // Aloca memória para o vetor.
    n = malloc(n2 * sizeof(int));

    srand(time(NULL));
    for(int i = 0; i < n2; i++){
        n[i] = rand() % 100;
    }
    // Verifica se a alocação foi bem-sucedida.
    if (n == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    clock_gettime(CLOCK_MONOTONIC, &start);
    
    // Chama o qsort;
    qsort(n, n2, sizeof(int), compare);

    clock_gettime(CLOCK_MONOTONIC, &end);

    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  
    printf("\nValores ordenados de forma crescente:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
  
    free(n); //libera a memória alocada.

    printf("O tempo gasto pelo programa é: %f segundos", time_taken);
  
}



/* 
Saída utilizando o qsort:
  Valores ordenados de forma crescente:
  7 21 54 71 87 
  O tempo gasto pelo programa é: 0.000001 segundos
*/

/*
Saída do programa sem o uso do qsort:
  Valores ordenados de forma crescente:
  0 10 25 68 71 
  O tempo gasto pelo programa é: 0.000000 segundos
*/

//É possível notar que, o programa sem o uso do qsort, é mais rápido do que o programa com o uso do qsort.
