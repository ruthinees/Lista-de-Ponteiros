/*
Memory leak ou vazamento de memória é quando um programa ou processo falha em liberar o espaço de memória que ele alocou.
o problema vai ficando pior a medida que o programa aloca mais e mais memória e não as libera.
se isso ocorrer diversas vezes a memória pode se exaurir e resultar em uma diminuição do desempenho do sistema e, em casos extremos, pode até causar falhas ou travamentos.
*/

//A seguir estão alguns programas em C que possuem vazameto de memória:

//Problema 01:

#include <stdio.h>
#include <stdlib.h>

int main(void){

  int nl = 4, nc = 5;
  int **z;

  z = malloc(nl*sizeof(int));

  z[0] = malloc(nl*nc*sizeof(int));

  for(int i = 1; i < nl; i++){
    z[i] = z[i - 1] + nc;
  }

  free(z);
}

/*
Esse problema possui vazamento de memória pois foi feita a alocação de memória do bloco auxiliar e das linhas da matriz, porém foi apenas liberado a memória do bloco auxiliar. Ou seja, as linhas da matriz continuaram sem libera os valores que estavam alocados.
*/

//Problema 02: 

#include <stdio.h>
#include <stdlib.h>

int* alocaMemoria() {
    int *ptr = (int *)malloc(sizeof(int));
    return ptr; 
}

int main() {
    int *ptr = alocaMemoria();
    return 0;
}

/*
No problema acima ocorre vazamento de memória pois o ponteiro é alocado na função alocaMemoria() porém nunca é liberado.
*/

//Problema 03: 

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *x;
  x = malloc(3*sizeof(int));

  for(i = 0; i < 3; i++){
    x[i] = i;
  }
}

/*
No último problema, ocorre vazamento de memória pois os espaços de memória do ponteiro x são alocados porém nunca liberados.
*/
