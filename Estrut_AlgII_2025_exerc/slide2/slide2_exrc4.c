//slide2_exercício4
/*4) Leia quatro valores do tipo float. Calcule e exiba a média aritmética desses valores.*/

#include <stdio.h>

int main()
{
    int i=0;
    float numero=0;
    float soma=0;
    float media=0;
    
    while (i<4)
    {printf("Insira um número:\n");
    scanf("%f", &numero);
    soma+=numero;
    i++;}
    media=soma/4;
    printf("\nMédia: %.2f ", media);

    return 0;
}