/* lista 2 - exercício 6. Matriz – Diagonal principal
Faça uma função que receba uma matriz 4x4 e retorne a soma dos elementos da diagonal principal.
Teste a função com valores lidos do teclado.*/

#include <stdio.h>

int diagonal (int n,int m,int matriz[n][m])
{
    int soma=0;
    
    for (int i=0;i<n;i++)
         {
         for (int j=0; j<m;j++)
              {
              if (i==j)
                 {
                 soma=soma+matriz[i][j];
                 }
              }
         }
         
         return soma;
}

int main ()
{
    int n=4;
    int m=4;
    int matriz[n][m];
    int soma_diagonal=0;
    
    printf("Digite os elementos de uma  matriz 4x4:\n");
    
    for (int i=0;i<n; i++) 
    {
        for (int j=0;j<m; j++) 
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    soma_diagonal=diagonal ( n, m,matriz);
    
    printf(" # Matriz de entrada #\n");
   for (int i=0;i<n; i++) 
    {
        for (int j=0;j<m; j++) 
        {
            printf("%d ", matriz[i][j]);
            
        }
        printf("\n");
    }
    
    printf(" Soma dos elementos da diagonal principal: %d",soma_diagonal);
    
    
}