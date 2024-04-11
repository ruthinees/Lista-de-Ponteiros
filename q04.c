#include <stdio.h>
int main() {
  int valor;
  int *p1;
  float temp;
  float *p2;
  char aux;
  char *nome = "Ponteiros";
  char *p3;
  int idade;
  int vetor[3];
  int *p4;
  int *p5;

  /* (a) */
  valor = 10;
  p1 = &valor;
  *p1 = 20;
  printf("%d \n", valor);

  /*Espera-se que valor retorne 20 */

  /* (b) */
  temp = 26.5;
  p2 = &temp;
  *p2 = 29.0;
  printf("%.1f \n", temp);

  /*Espera-se que temp retorne 29.0 */

  /* (c) */
  p3 = &nome[0];
  aux = *p3;
  printf("%c \n", aux);

  /*Espera-se que aux retorne P */

  /* (d) */
  p3 = &nome[4];
  aux = *p3;
  printf("%c \n", aux);

  /*Espera-se que aux retorne e */

  /* (e) */
  p3 = nome;
  printf("%c \n", *p3);

  /* Espera-se que *p3 retorne P */

  /* (f) */
  p3 = p3 + 4;
  printf("%c \n", *p3);

  /* Espera-se que *p3 retorne e */

  /* (g) */
  p3--;
  printf("%c \n", *p3);

  /* Espera-se que *p3 retorne t */

  /* (h) */
  vetor[0] = 31;
  vetor[1] = 45;
  vetor[2] = 27;
  p4 = vetor;
  idade = *p4;
  printf("%d \n", idade);

  /* Espera-se que idade retorne 31 */

  /* (i) */
  p5 = p4 + 1;
  idade = *p5;
  printf("%d \n", idade);

  /* Espera-se que idade retorne 45 */

  /* (j) */
  p4 = p5 + 1;
  idade = *p4;
  printf("%d \n", idade);

  /* Espera-se que idade retorne 27 */

  /* (l) */
  p4 = p4 - 2;
  idade = *p4; 
  printf("%d \n", idade);

  /* Espera-se que idade retorne 31 */

  /* (m) */
  p5 = &vetor[2] - 1;
  printf("%d \n", *p5);

  /* Espera-se que *p5 retorne 45 */

  /* (n) */
  p5++;
  printf("%d \n", *p5);
  return(0);
  /* Espera-se que *p5 retorne 27 */
}

/* Saída do programa :
  20 
  29.0 
  P 
  e 
  P 
  e 
  t 
  31 
  45 
  27 
  31 
  45 
  27 
*/

/*Justificando pq as saídas obtidas eram esperadas: 

(a): Como p1 guarda o endereço de valor, ao atribuir-se o valor 20 para o conteúdo de *p1, o valor de valor também foi alterado.

(b): Como p2 guarda o endereço de temp, ao atribuir-se o valor 29 para o conteúdo de *p2, o valor de temp também foi alterado.

(c): a variável char em C é um vetor de caracteres, por isso, quando p3 recebe o endereço de nome[0], o conteúdo de *p3 é o caractere P. Logo, como aux recebe o conteúdo de *p3, aux recebe o caractere P.

(d): da mesma forma que a letra (c), p3 recebe o endereço de nome[4], o conteúdo de *p é o caractere e. Logo, como aux recebe o conteúdo de *p3, aux recebe o caractere e.

(e): como char é um vetor de caracteres, quando escrevemos que p3 = nome, dize-se que o ponteiro p3 aponta para o primeito caracter de nome, ou seja, o caractere P.

(f): como p3 é um ponteiro, ou seja, um endereço de memória, então p3 + 4 é como se estivessimos caminhando 4 "casas" a frente do endereço de p3, ou seja, o caractere e.

(g): como p3 é um ponteiro, ou seja, um endereço de memória, então p3-- é como se estivessemos caminhando 1 "casa" atrás do endereço de p3 (mesma coisa que escrever p3 = p3 - 1) ou seja, o caractere t.

(h): quando escrevemos que p4 = vetor, estamos dizendo que p4 recebe o primeiro valor de vetor, logo, *p4 = 31. Por isso, quando escrevemos idade = *p4, idade recebe o valor 31.

(i): como p4 equivale a &vetor[0], como p5 também é um ponteiro, então p5 recebe o endereço de memória de p4 mais uma "casa" a frente, logo, p5 = &vetor[1]. Então *p5 = 45. Como idade = *p5, idade recebe o valor 45.

(j): dessa vez, p4 está recebendo o endereço de memória de p5 mais uma "casa" a frente, logo, p4 = &vetor[2]. Então *p4 = 27. Como idade = *p4, idade recebe o valor 27.

(l): como p4 está recebendo seu endereço antigo (&vetor[2]) menos 2 "casas", logo, p4 = &vetor[0]. Então *p4 = 31. Como idade = *p4, idade recebe o valor 31.

(m): como p5 é um ponteiro, ele está recebendo o valor do endereço de memória de vetor[2] menos 1 "casa", logo, *p5 = 45. Como idade = *p5, idade recebe o valor 45.

(n): p5++ pode ser escrito como p5 = p5 + 1, como p5 é um ponteiro, estamos basicamente dizendo que p5 recebe o endereço de memória de p5 mais uma "casa". Como p5 na letra (m) recebeu o valor de vetor[2], p5++ recebe o valor de vetor[3]. Por isso, *p5 = 27.

*/
