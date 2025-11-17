//slide 2 -exercício 14
/*14) Faça um programa que converta uma letra maiúscula em letra minúscula. 
Use a tabela ASCII para isso*/
/*A diferença entre uma letra minúscula  e sua maiúscula  correspondente é 32, na tabela ASCII
  Intervalo das letras maiúsculas na tabela ASCII (65 a 90)*/

#include <stdio.h>

int main ()
{
    char maiuscula;
    char minuscula;
        printf("Insira uma letra maiúscula: \n");
        scanf("%c", &maiuscula);
        if  (maiuscula >='A' && maiuscula <='Z')
             {minuscula=maiuscula+32;
             printf("\nLetra maiúscula %c e minúscula %c .", maiuscula, minuscula);
             }
        else
            {printf("Não é letra maiúsccula.");}
        
    return 0;
}