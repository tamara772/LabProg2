/*1. Ponteiro básico
Escreva um programa que:
● Crie uma variável int com valor 15
● Crie um ponteiro que aponte para essa variável
● Exiba na tela:
○ O valor da variável
○ O endereço da variável
○ O valor armazenado no ponteiro
○ O valor acessado pelo ponteiro */

#include <stdio.h>
main ()
{
int var=15;

int *point;
point=&var;
printf("\n valor da variável: %d", var);
printf("\nendereço da variável: %p",&var);
printf("\nvalor armazenado no ponteiro: %p",&var);
printf("\n valor acessado pelo ponteiro: %d",*point);

return 0;

}