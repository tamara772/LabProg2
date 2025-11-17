//slide 4 - exercício 3
/*9.4.3 ) Escreva uma função recursiva que calcule a soma dos primeiros n cubos:1^3+2^3+ ...+n^3*/


#include<stdio.h>

//declaração da função
int soma_cubos (int n);

int main ()
{
  int num=0;
  int resultado=0;
  
  printf("Digite um número inteiro:\n");
  scanf("%d", &num);
  resultado=soma_cubos(num);
  
  printf("A soma dos cubos até %d  é %d .", num, resultado);
   
   return 0;
}

//função qque soma os n primeiros cubos
int soma_cubos (int n)
{    
    if(n==1)
    return 1;//fim da recursão
    else
    return (n*n*n)+ soma_cubos(n-1);
    
    }