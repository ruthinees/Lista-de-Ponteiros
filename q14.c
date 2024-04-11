/*
Esses ponteiros são usados para permitir que o código manipule funções de maneira dinâmica durante a execução do programa. 
Em essência, um ponteiro para função permite que você trate uma função como um dado, podendo passá-la como argumento para outra função, 
retorná-la de uma função ou armazená-la em uma estrutura de dados.

Utilizar ponteiros para funções é uma maneira eficiente de criar funções genéricas, podendo ser reutilizadas em diversas outras partes do programa.
*/

//Aqui está um exemplo de programa que usa ponteiro para função:

#include <stdio.h> //Adicionando a biblioteca padrão de entrada e saída

//Criando função de soma que recebe dois inteiros e devolve a soma deles
int soma (int a, int b){
  return a + b;
}

//Criando a função de multiplicação que recebe como argumentos:
//Um ponteiro para função (tal função recebe doi inteiros e retorna um inteiro)
//E dois inteiros a e b.
//Essa função retorna por meio da função printf o resultado da multiplicação de a+b por b.
void multiplicacao(int (*f) (int, int), int a, int b){
  printf("A multiplicação de (%d+%d)*%d = %d\n", a, b, b, f(a,b)*b);
}

int main(void){

  int (*ptrfuncao)(int, int); // Declarando o poneiro para função.

  ptrfuncao = soma; //Atribuindo o endereço da função soma ao ponteiro.

  multiplicacao(ptrfuncao, 5, 6); //Chamando a função multiplicação e passando o ponteiro para função como argumento e os dois valores de a e b.
}
