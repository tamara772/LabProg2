
/*Lista 2-exercício 3. Vetor – Procedimento de preenchimento
Crie um procedimento que receba um vetor de inteiros e um valor 
inteiro e preencha todas as posições do vetor com esse valor.
Depois, imprima o vetor no main.*/

#include <stdio.h>

   int declara_vetor ( int vetor[],int n)
   {
   int i=0;
   for (i=0;i<n;i++)
       {
       vetor[i]=n;
       }
    }
    
    int main ( )
    {   
    int n=3;
    int meu_vetor[n]; 
    declara_vetor(meu_vetor,n);  
   
    for (int i=0;i<n;i++)
    {
        printf("elementos do vetor:%d\n", meu_vetor[i]); 
    }
}