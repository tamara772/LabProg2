/* Lista 3 exrcício  1. Ponteiro básico
Escreva um programa que:
● Crie uma variável int com valor 15
● Crie um ponteiro que aponte para essa variável
● Exiba na tela:
○ O valor da variável
○ O endereço da variável
○ O valor armazenado no ponteiro
○ O valor acessado pelo ponteiro*/

#include <stdio.h> 

int main ()
{
    int var=15;
    int *pvar=NULL;
    pvar=&var;
    
    printf("\n Valor da variável: %d",var);
    printf("\n Endereço da variável: %p",&var);
    printf("\n Valor armazenado no ponteiro: %p",pvar);
    printf("\n Valor acessado pelo ponteiro: %d",*pvar);
    
    return 0;
}