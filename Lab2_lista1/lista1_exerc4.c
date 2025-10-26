/* Lista 1 exercício 4
10.	Exiba os números de 1 a 100.
11.	Tabuada de 1 a 10 usando for.
12.	Receba números até que o usuário digite 0, e calcule a soma total.*/


#include <stdio.h>
int main (void)
{
int i=0;
for (i = 1; i <= 100; i++)
    {
    printf("%d \n", i);
    }
    
//Tabuada de 1 a 10 usando for

int k=0;
int m=0;
int prod=0;
for (k=1; k<=10; k++)
    {
    for (m=1; m<=10; m++)
      {
      prod=k*m;
      printf ("\n%d X %d = %d",k,m, prod);
      }
      printf("\n");
    }

    
    //Receba números até que o usuário digite 0, e calcule a soma total.

int numero=1;
int soma=0;
while (numero!=0)
 {
    printf("\n Digite um número inteiro: ");
    scanf("%d",&numero);
    soma=soma+numero;
 }
    printf("\n Soma dos números digitados = %d\n", soma);
}