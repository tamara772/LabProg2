//slide 3 - exercício 5
/*5) Faça um programa que calcule e mostre a soma dos 50 primeiros números pares.*/


#include <stdio.h>

int main ()
{
    int soma=0;
    int i=0;
    while (i<50)
   { soma+=i;
    i=i+2;}
    
    printf("Soma %d \n", soma);
    return 0;
}