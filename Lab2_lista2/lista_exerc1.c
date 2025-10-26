/*Lista 2 exercício 1. Vetor – Soma dos elementos
Implemente uma função que receba um vetor de inteiros e seu tamanho e retorne a soma de todos os elementos.
No main, peça para o usuário digitar os elementos do vetor e exiba o resultado.*/


#include <stdio.h>

   
    int soma_vetor (int vetor [],int n) 
        {
            int soma=0;
            for (int i=0; i<n; i++)
            {
                soma=soma+vetor[i];

            }
        return (soma);
        }
        
int main ()  
{
        int n=3;
        int vetor1 [n];  
        int soma;
        for (int i=0; i<n;i++)  
        {
        printf ("\nDigite um número inteiro: ");
        scanf(" %d", &vetor1[i]);
        }
        soma=soma_vetor(vetor1,3);// chama a função
        
        printf("#Elementos do vetor#\n");
        for (int i=0;i<n;i++)
        {
        printf(" %d ",vetor1[i]);
        }
        printf("\n A some dos elementos do vetor é: %d", soma);
            
        return 0;
    
}
        
        




