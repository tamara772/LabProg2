//slide 3 - exercício 14
/*14) Escreva um programa que leia um número inteiro, maior ou igual a zero, do usuário. 
Imprima o enésimo termo da sequência de Fibonacci. Essa sequência começa no termo de ordem zero, 
e, a partir do segundo termo, seu valor é dado pela soma dos dois termos anteriores. 
Alguns termos dessa sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34.*/


#include <stdio.h>

int main ()
{
  int numero;
  int vetor [numero];
  int i;
  
   printf("Insira um número inteiro positivo: \n");
   scanf("%d", &numero);
    vetor[0]=0;
    vetor[1]=1;
    for (i=2;i<numero;i++)
        {vetor[i]=vetor[i-1]+vetor[i-2];}
   printf(" # Sequência de Fibonacci até %d #\n", numero);
   for (i=0 ;i<numero; i++)
   {printf("%d\n", vetor[i]);}
   
  
    return 0;
}