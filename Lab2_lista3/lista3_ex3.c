/*Lista 3 exercício 3. Ponteiros e vetores
Escreva um programa que:
● Crie um vetor de 5 inteiros
● Use apenas ponteiros (sem notação [ ]) para preencher os valores digitados pelo
usuário
● Depois percorra o vetor com aritmética de ponteiros e imprima todos os elementos*/

#include <stdio.h>

int main ()
{

int vet1[5];

int *point1;

point1=&vet1;

for (int i=0; i<5; i++)
{
printf("Digite um número inteiro:\n");
scanf("%d", &vet1[i]);
}

printf("\n # Vetor #\n");
for (int i = 0; i < 5; i++) 
{
printf("%d\n", *(point1 + i));
}

return 0;
}