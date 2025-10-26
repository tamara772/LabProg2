/*Lista 1 - Exerciicio 6
15. Usando vetores (array), receba uma frase e retorne sua escrita inversa.
16. Usando vetores de vetores (matriz), estruture e apresente um tabuleiro de xadrez.*/

#include <stdio.h>
#include <string.h>
int main() 
{
char frase [100];

printf("Insira uma frase:");
fgets(frase, sizeof(frase), stdin);
int tam=strlen(frase);
for (int i=tam;i>=0; i--)
printf("%c", frase[i]);

printf("\n\n");

//tabuleiro
  char matrix[8][8];

    // Preenche a matriz com padrão: "_" para linhas e "|" para colunas
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i % 2 == 0)    //verifica paridadde
                matrix[i][j] = '_';  // linha par - linha horizontal
            else
                matrix[i][j] = '|';  // linha impar - colunas
        }
    }

   
    printf("Tabuleiro:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
