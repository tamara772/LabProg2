//slide 4 - exercício 1
/*9.4.1) Escreva uma função que receba por parâmetro dois números e retorne o maior deles.*/


#include<stdio.h>

//declaração da função
int retorna_maior(int n1, int n2);

int main ()
{
  int n1;
  int n2;
  int i;
  int resultado;
   printf("Insira um número inteiro positivo: \n");
   scanf("%d", &n1);
   printf("Insira um número inteiro positivo: \n");
   scanf("%d", &n2);
   resultado=retorna_maior(n1,n2);
   printf("Números: %d e %d, maior: %d\n", n1, n2, resultado);
   return 0;
}
//função retorna maior valor entre dois inteiros
int retorna_maior(int n1, int n2)
{    
    int maior;
    maior=(n1>n2?n1:n2);
return maior;
}