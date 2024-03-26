/*Assumindo que pulo[] é um vetor do tipo int, as seguintes expressões referenciam o valor do terceiro elemento do vetor: 

  A expressão  *(pulo + 2) referencia o conteúdo do terceito elemento do vetor.

  Já a expressão pulo + 2 referencia o endereço do terceiro elemento do vetor.

  As duas, teoricamente, mostram o mesmo resultado, sendo a primeira o valor inteiro que está no terceiro elemento do vetor, enquanto a segunda demonstra o endereço do terceiro elemento do vetor. Como aparentemente o enunciado quer apenas o valor do terceiro elemento, então a primeria expressão é a correta.

  A seguir, têm-se exemplos de saídas que se recebe quando utilizamos as expressões citadas acima: 
*/

#include <stdio.h>

int main(void){
  int pulo[5] = {1,2,3,4,5};

  /* para *(pulo + 2): */ 

  printf("pulo + 2 = %d\n", *(pulo + 2));

  /* para pulo + 2 */
  
  printf("pulo + 2 = %p\n", pulo + 2);
}