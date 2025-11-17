//slide 4 - exercício 
/*9.4. 2) Escreva uma função que, dado um número real passado como parâmetro, 
retorne a parte inteira e a parte fracionária desse número por referência.
( Na passagem de parâmetros por referência não se passam para a função os valores das variáveis,
mas os endereços das variáveis na memória.)
Na chamada da função, é necessário  o operador “&” na frente do nome
da variável que será passada por referência para a função.*/

#include<stdio.h>

//declaração da função
void separa_numero(float num, int *inteira, float *frac);

int main ()
{
  float num;
  int  parte_inteira;
  float parte_frac;
   printf("Insira um número:\n");
   scanf("%f", &num);
   separa_numero(num, &parte_inteira,&parte_frac);
   printf("Número: %.2f, parte inteira: %d, parte fracionária: %.2f",num, parte_inteira,parte_frac);
   
   return 0;
}
//função separa partes inteira e fracionária
void separa_numero(float num, int *inteira, float *frac)
{    
    *inteira = (int) num;            
    *frac = num - *inteira;   
}