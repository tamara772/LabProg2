
/*Lista 2 - exercício 5. Matriz – Transposta
Escreva um procedimento que receba uma matriz quadrada 3x3 e preencha uma segunda
matriz com a transposta dela.Mostre as duas matrizes no main.*/

#include <stdio.h>

void matriz_transposta(int matriz[3][3], int transposta[3][3]) 
{
    for (int i=0;i<3; i++) 
    {
        for (int j=0;j<3; j++) 
        {
            transposta[j][i]=matriz[i][j];
        }
    }
}

int main ()
{
    int matriz1[3][3];
    int matriz1_trans[3][3]; 

    printf("Digite os elementos de uma  matriz 3x3:\n");
    
    for (int i=0;i<3; i++) 
    {
        for (int j=0;j<3; j++) 
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }
    
    matriz_transposta(matriz1, matriz1_trans);
        
        printf("# Matriz Original #\n");
        
        for (int i=0;i<3; i++) 
        {
             for (int j=0;j<3; j++) 
             {
             printf(" %d ", matriz1[i][j]);
             }
        
            printf("\n");
        }
    
     printf("\n\n");
    
     printf("# Matriz Transposta #\n");
        
        for (int i=0;i<3; i++) 
        {
             for (int j=0;j<3; j++) 
             {
             printf(" %d ", matriz1_trans[i][j]);
             }
        printf("\n");
        }
    
    
        return 0;
}