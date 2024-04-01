/* Sabendo que x é um array de 4 elementos e o endereço de memória de x[0] é 4092 e o tipo char ocupa 1 byte, o tipo int ocupa 2 bytes, o tipo float ocupa 4 bytes e do tipo double ocupa 8 bytes. Os valores de x+1, x+2 e x+3 serão:
  
  01 - Quando x for declarado como char: 
       x+1 = 4093, x+2 = 4094, x+3 = 4095.

  02 - Quando x for declarado como int:
       x+1 = 4094, x+2 = 4096, x+3 = 4098.

  03 - Quando x for declarado como float:
       x+1 = 4096, x+2 = 4100, x+3 = 4104.

  04 - Quando x for declarado como double:
       x+1 = 4100, x+2 = 4108, x+3 = 4116.
*/

/*Exemplo de programa para analisar o tamanho que cada tipo ocupa na máquina que está sendo usada: */


#include <stdio.h>
int main(void){
  char x[4];
  int x2[4];
  float x3[4];
  double x4[4];

  printf("Tamanhos ocupados pelo tipo char no endereço de memória:\n");
  printf("x+1 = %p\nx+2 = %p\nx+3 = %p\n", x+1, x+2, x+3);

  printf("\nTamanhos ocupados pelo tipo int no endereço de memória:\n");
  printf("x2+1 = %p\nx2+2 = %p\nx2+3 = %p\n", x2+1, x2+2, x2+3);

  printf("\nTamanhos ocupados pelo tipo float no endereço de memória:\n");
  printf("x3+1 = %p\nx3+2 = %p\nx3+3 = %p\n", x3+1, x3+2, x3+3);

  printf("\nTamanhos ocupados pelo tipo double no endereço de memória:\n");
  printf("x4+1 = %p\nx4+2 = %p\nx4+3 = %p\n", x4+1, x4+2, x4+3);

}

/*Saída obtida: 

  Tamanhos ocupados pelo tipo char no endereço de memória:
  x+1 = 0x7fff2ad4f3dd
  x+2 = 0x7fff2ad4f3de
  x+3 = 0x7fff2ad4f3df

  Tamanhos ocupados pelo tipo int no endereço de memória:
  x2+1 = 0x7fff2ad4f3c4
  x2+2 = 0x7fff2ad4f3c8
  x2+3 = 0x7fff2ad4f3cc

  Tamanhos ocupados pelo tipo float no endereço de memória:
  x3+1 = 0x7fff2ad4f3b4
  x3+2 = 0x7fff2ad4f3b8
  x3+3 = 0x7fff2ad4f3bc

  Tamanhos ocupados pelo tipo double no endereço de memória:
  x4+1 = 0x7fff2ad4f398
  x4+2 = 0x7fff2ad4f3a0
  x4+3 = 0x7fff2ad4f3a8
*/

/*Fazendo uma comparação da minha máquina com a do exercício, é possível notar que os tipos char, float e double ocupam o mesmo espaço de memória dado pelo exercício (char ocupa 1 byte, float ocupa 4 bytes e double ocupa 8 bytes na minha máquina). Já o tipo int ocupa espaço diferente ao dado no exercício (int ocupa 4 bytes na minha máquina).
*/