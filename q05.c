int main(void){
  float vet[5] = {1.1,2.2,3.3,4.4,5.5};
  float *f;
  int i;
  f = vet;
  printf("contador/valor/valor/endereco/endereco\n");
  for(i = 0 ; i <= 4 ; i++){
    printf("i = %d",i);
    printf(" vet[%d] = %.1f",i, vet[i]);
    printf(" *(f + %d) = %.1f",i, *(f+i));
    printf(" &vet[%d] = %X",i, &vet[i]);
    printf(" (f + %d) = %X",i, f+i);
    printf("\n");
  }
}

/*Saída do programa: 
  contador/valor/valor/endereco/endereco
  i = 0 vet[0] = 1.1 *(f + 0) = 1.1 &vet[0] = 6EB85380 (f + 0) = 6EB85380
  i = 1 vet[1] = 2.2 *(f + 1) = 2.2 &vet[1] = 6EB85384 (f + 1) = 6EB85384
  i = 2 vet[2] = 3.3 *(f + 2) = 3.3 &vet[2] = 6EB85388 (f + 2) = 6EB85388
  i = 3 vet[3] = 4.4 *(f + 3) = 4.4 &vet[3] = 6EB8538C (f + 3) = 6EB8538C
  i = 4 vet[4] = 5.5 *(f + 4) = 5.5 &vet[4] = 6EB85390 (f + 4) = 6EB85390
*/

/*Explicação da saída obtida: 
Era esperado pelo programa que fosse mostrado, primordialmente, a frase "o conteúdo do vetor e o endereço". Em seguida, dentro do for, o programa mostraria, a cada iteração, o conteúdo do vetor e o endereço de cada posição. Como a iteração é representada por i, o primeiro printf mostraria o valor da iteração, após isso, seria mostrado o conteúdo do vetor naquela iteração (vetor[i]), depois seria mostrado o valor do conteúdo de f+i (como f é um ponteiro que recebe vetor, nesse caso, quando não se tem indicação de qual elemento do vetor é recebido, entende-se que f rececebeu a primeira posição de vetor). Em seguida, seriam mostrados, respectivamente, o endereço de memória de vetor[i] e do ponteiro f+i.

Como pode-se ver, as saídas esperadas são mostradas, e o programa funcionou corretamente.
*/
