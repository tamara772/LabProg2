#include <stdio.h>
//Exiba os números de 1 a 100.

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
    printf(" Soma= %d\n", soma);
    
 //Calculadora simples: Receba dois números e um operador (+, -, *, /) e execute a operação

int numero1=0;
int numero2=0;
char sinal='a';
int soma1=0;
int sub=0;
int mult=0;
float div=0;
printf("\n Digite um número inteiro: ");
    scanf("%d",&numero1);
    printf("\n Digite um número inteiro: ");
    scanf("%d",&numero2);
    printf("Digite a operação desejada (+, -, *, /)= ");
    scanf("%c",&sinal);
if (sinal=='+')
    {
    soma1=numero1+numero2
    }





return 0;
}