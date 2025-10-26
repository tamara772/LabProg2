
/*1.	Crie um programa que exiba:
- Seu nome
- Sua idade
- Seu curso
2.	Exiba um poema ou letra de música formatado com \n.
3.	Exiba uma tabuada fixa (ex: do 2).*/


#include <stdio.h>
int main (void)
{
printf("\t Nome: tamara\n\t Idade: 18 \n\t Curso: Ciência da Computação\n");
   

printf("\nQuem me dera ao menos uma vez\n"
"Explicar o que ninguém consegue entender \n"
"Que o que aconteceu ainda está por vir\n"
"E o futuro não é mais como era antigamente.\n");

printf("\n\n");

int valor=0;
int i;
    for (i = 1; i <= 10; i++)
    {
    valor=valor+7;
      printf("7 x %d = %d\n", i, valor);
   }

}