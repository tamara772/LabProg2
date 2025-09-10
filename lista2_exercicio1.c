//Lista 2 exercício 1.
// Soma dos elementos de um vetor
#include <stdio.h>

    
    int soma_vetor (int vetor[],int tamanho) 
        {
            int soma=0;
            int i=0;
            for (int i; i<tamanho; i++)
            {
                soma=soma+vetor[i];

            }
        return (soma);
        }

 int main ()
 {
    int vetor2 [3];
    int k=0;
    //for (k; k<3; k++);
    while (k<3)
    {
        printf("Insira um número inteiro: ");
        scanf("%d", &vetor2[k]);
        k++;
    }
    
    int soma1=0;
    soma1=soma_vetor (vetor2,3);
    printf("soma %d", soma1);
    return 0;

}
