/* lista 2 - exercício 7. Vetor e Funções Combinadas
Crie um programa que tenha:

●	Um procedimento para ler os elementos de um vetor.

●	Uma função que calcule a média aritmética dos valores.

●	Um procedimento que imprima apenas os valores acima da média.*/

#include <stdio.h>

void ler_vetor (int vetor [], int tamanho)
{
    for (int i=0; i<tamanho; i++)
    {
        printf("Digite um valor para o elemento %d: ", i+1);
        scanf("%d", &vetor[i]);
    }
}

float media_vetor(int vetor[], int tamanho)
{
    int soma=0;
    float media=0;
    for (int i=0; i<tamanho; i++)
    {
        soma=soma + vetor[i];
    }
    media=soma/tamanho;
   return media;  
}

void compara_vetor (int vetor [], int tamanho, float media)
{
    for (int i=0; i<tamanho; i++)
    {
        if (vetor [i]> media)
        {
        printf("\nElemento  %d é maior que a média %.2f\n", vetor[i],media);
        }
    }
}


int main ()
{
    int tamanho=5;
    int vetor[tamanho];
    float media=0;
    ler_vetor (vetor,  tamanho);
    media=media_vetor(vetor,  tamanho);
    compara_vetor (vetor, tamanho, media);

   return 0;
}



