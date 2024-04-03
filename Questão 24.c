#include <stdio.h>

// Função auxiliar para imprimir um inteiro em binário
void printBinary(unsigned long num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%lu", (num >> i) & 1);
    }
}

// Função para enviar o estado via porta serial
void send(unsigned long estado) {
    // Implementação da função send()
    printf("Estado enviado via porta serial (em binário): ");
    printBinary(estado, 64); // 64 bits no total
    printf("\n");

    printf("\nEstado enviado via porta serial: %lu", estado);
}

int main() {
    // Definição da matriz de LEDs
    unsigned char m[8][8] = {
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1}
    };

    // Variável para armazenar o estado codificado
    unsigned long estado = 0;

    // Codificação da matriz de LEDs na variável de 64 bits
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // Desloca os bits à esquerda e atribui o valor do LED
            estado <<= 1;
            estado |= m[i][j]; // Define o bit menos significativo como o estado do LED
        }
    }

    // Envio do estado via porta serial
    send(estado);

    return 0;
}
