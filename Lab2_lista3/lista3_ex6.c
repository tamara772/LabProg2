/* Lista 3 exercício 6. Desafio final
Escreva um programa que:
● Leia n inteiros do usuário (tamanho definido em tempo de execução)
● Aloque memória dinamicamente usando malloc
● Use ponteiros para preencher os valores
● Crie uma função que receba o vetor dinâmico e seu tamanho e retorne o maior valor
encontrado
● Mostre o resultado e libere a memória com free*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 int maior_valor(int *vetor, int tamanho) 
 {
    int maior = vetor[0];
    for (int i = 1; i < tamanho; i++) 
    {
        if (vetor[i] > maior) 
        {
            maior = vetor[i];
        }
    }
    return maior;
  }
   
  
int main()
{
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *vetor = (int *) malloc(n * sizeof(int));//aloca a memória
    if (vetor == NULL)
    {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

 
    for (int i = 0; i < n; i++)
    {
        printf("Digite o elemento %d: ", i + 1);//preenche com ponteiro
        scanf("%d", vetor + i);   
    }
//O scanf espera o endereço de memória onde deve guardar o número digitado.
//o vetor + i justamente fornece esse endereço.*/
    
     int maior = maior_valor(vetor, n);

    printf("\nO maior valor do vetor é: %d\n", maior);

    free(vetor);

    return 0;
}
  