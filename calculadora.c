/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


float calculadora(float x, float y, int op)
{
    float res = 0;
    
    if (op == 1)
    {
        res = x + y;
    }
    else if (op == 2)
    { 
        res = x - y;
    }
    else if (op == 3)
    {
        res = x * y;
    }
    else if (op == 4)
    {
        res = x / y;
    }
    else if (op == 5)
    {
        res = pow(x,y);
    }
    return res;
}

int main()
{
   int op=0;
   printf("Escolha uma função:\n Digite 1 para soma \n Digite 2 para subtração \n Digite 3 Para multiplicação\n \
   Digite 4 para Divisão \n Digite 5 para potenciação\n Digite 6 para radiciação\n Digite 5 para Seno");
         
     scanf("%d", &op);    
    float numero1, numero2, resultado;
    printf("Digite um numero:\n ");
    scanf("%f", &numero1);
    printf("Digite outro numero: \n");
    scanf("%f", &numero2);
    
    
    resultado = calculadora(numero1, numero2, op);
    
    printf("REsultado: %.2f", resultado);
    return 0;
}