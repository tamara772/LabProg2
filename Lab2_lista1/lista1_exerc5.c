/* Lista 1 exercício 5
13.	Calculadora simples: Receba dois números e um operador (+, -, *, /) e execute a operação.
14.	Conversor de temperaturas (C ↔ F): escolha do tipo de conversão com if.*/


#include <stdio.h>
int main (void)
{
float numero1=0;
float numero2=0;
char sinal='a';
float res=0;
float div=0;
printf("\n Digite um número: ");
    scanf("%f",&numero1);
    printf("\n Digite um número : ");
    scanf("%f",&numero2);
    printf("Digite a operação desejada (+, -, *, /) ");
    scanf(" %c",&sinal);
if (sinal=='+')
    {
    res=numero1+numero2;
    }
else if (sinal=='-')
    {
        res=numero1-numero2;
    }
else if (sinal=='*')
    {
        res=numero1*numero2;
    }
else 
    {res=numero1/numero2;
    }

printf("O resultado da operação  %c é:  %.2f",  sinal, res);

printf("\n\n");
    
//conversor de temperatura  9tc=5(tf-32)
float t=0;
float tf=0;
float tc=0;
char unid=0;
printf("Insira um valor para temperatura: ");
scanf("%f", &t);
printf("Insira a unidade para a sua temperatura: C para Celsius ou F para Fahrenheit: ");
scanf(" %c", &unid);
if (unid=='C')
{
    tf=(9.0/5.0) *t +32;
    printf(" A temperatura %.2f em Celsius  equivale a %0.2f em Fahrenheit.", t, tf);
}
else
{   tc=5.0*(t-32)/9.0;
    printf(" A temperatura %.2f em Fahrenheit  equivale a %0.2f em Celsius.", t, tc);
}

return 0;
}