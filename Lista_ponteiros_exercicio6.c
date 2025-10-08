/* Lista ponteiros exercício 6. Desafio final
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

int valor_maximo (int *vetor, int n);

int main() 
{
    int n;
    printf("Quantidade de números inteiros: ");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));//aloca memória
    if (vetor == NULL) 
       {
        printf("Erro na alocação de memória.\n");
        return 1;
        }

    for (int i = 0; i < n; i++) 
       {
        printf("Digite o valor %d: ", i + 1);//para começar de 1
        scanf("%d", &vetor[i]); 
        }

    printf("Números digitados: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", *(vetor + i)); // desreferencia para obter o valor
    }
   
   int maximo = valor_maximo (vetor, n);
    printf("\nMaior valor: %d", maximo);
   
    free(vetor);

    return 0;
}

//definição da funçao maximo
int valor_maximo (int *vetor, int n) 
{
        int max = *vetor; 
    for (int i = 1; i < n; i++) 
       {
        if (*(vetor + i) > max) // desreferencia para obter valor
           { 
               max = *(vetor + i);
           }
               
       }
    return max;
}





/* Sobre ponteiros: Sempre que você coloca * na frente, você está entrando no endereço guardado
pelo ponteiro, ou seja, desreferenciando. 
Se não tem *, você está apenas manipulando o endereço armazenado no ponteiro.*/