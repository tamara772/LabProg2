
/*Lista 2.Exercício 2. Vetor – Maior elemento
Escreva uma função que receba um vetor de float e seu tamanho e retorne o maior valor armazenado.
Teste a função com um vetor de 10 números lidos do teclado.*/

#include <stdio.h>

float retorna_maior_valor (float vetor[], int tamanho )//recebe um vetor e retorna a componente de maior tamanho
{
float vmax=vetor[0];
int i=0;
for (i=0; i<tamanho; i++)
   {
      if  (vetor[i]>vmax)
          { vmax=vetor[i];
          }
   }
return vmax;
}

int main (void)
{
float vetor1 [10];
    int k=0;
    while (k<10)
    {
        printf("Insira um número inteiro: ");
        scanf("%f", &vetor1[k]);
        k++;
    }
    
    float maior_valor=0;
    maior_valor=retorna_maior_valor (vetor1,10 );
    printf("\nMaior valor no vetor: %.2f",maior_valor);
    return 0;

}