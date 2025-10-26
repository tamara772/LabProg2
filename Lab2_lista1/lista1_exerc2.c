
/* Lista 1 - Exercício 2
4.	Receba dois inteiros e exiba:
- Soma, subtração, multiplicação, divisão, resto
5.	Receba raio e calcule a área da circunferência.
6.	Receba idade e calcule:
- Quantos dias viveu (aproximadamente).*/



#include <stdio.h>
int main (void)
{
    
    int n1=10, n2=20;
    float soma=0, sub=0, mult=0, div=0, resto=0;
    soma=n1+n2;
    sub=n2-n1;
    div=n2/n1;
    resto=n2-div*n1;
    printf("Soma= %.2f\nSubtração= %.2f\nDivisão= %.2f\nResto= %.2f", soma, sub, div,resto);
    float r=3, area=0, pi=3.14;
    area=pi*r*r;
    
    int idade=40;
    int dias=0;
    
    dias=idade*365;
    
    printf("\n Área do círculo de raio= %.2f é igual a %.2f m^2\n", r,area);
    printf(" \n %d Anos equivalem a %d dias.",  idade, dias);
}