
/*Lista 2 - exercício 4. Matriz – Soma dos elementos
Implemente uma função que receba uma matriz 3x3 e retorne a soma de todos os elementos.
No main, leia a matriz do teclado e mostre o resultado.*/

#include <stdio.h>

   int soma_matrix ( int n, int m, int matrix[n][m])
   {
    int soma=0;;
   for (int i=0;i<n;i++)
       {
            for (int j=0;j<m;j++)
            {
             soma=soma + matrix[i][j];
            }
       }
    return soma;
    }
    
    int main ( )
    {   
    int n=3;
    int m=3;
    int minha_matriz [n][m];
    printf("Digite os elementos da matriz 3X3: \n");
    
    for (int i=0;i<n;i++)
    {
        printf("Linha %d: ",i);
        for(int j=0;j<m;j++)
        {
         printf("Coluna %d: ",j);
         scanf("%d", &minha_matriz[i][j]);
        }
    }
    
    int resultado= soma_matrix(n, m, minha_matriz);
   
    printf("Resultado da soma dos elementos da matriz: %d", resultado);
}