#include <stdio.h>
#include <stdlib.h>

// Define um tamanho máximo para o vetor.
#define TAMMAX 100

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
    int *n; // Ponteiro para o vetor.
    int n2; // Tamanho do vetor.

    // Aloca memória para o vetor.
    n = malloc(TAMMAX * sizeof(int));

    // Verifica se a alocação foi bem-sucedida.
    if (n == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite quantos valores você quer ordenar de forma crescente: ");
    scanf("%d", &n2);

    for(int i = 0; i < n2; i++) {
        printf("Digite o %dº valor que será ordenado: ", i + 1);
        scanf("%d", &n[i]);
    }

    // Chama a função de ordenação, passando o vetor, seu tamanho e a função de comparação.
    ordenacaocrescente(n, n2, compare);
  
    printf("\nValores ordenados de forma crescente:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");

    // Libera a memória alocada para o vetor.
    free(n);
}
