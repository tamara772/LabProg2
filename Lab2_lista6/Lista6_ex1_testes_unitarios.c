
//Testes unitários

#include <stdio.h>

float retorna_maior_valor (int vetor[], int tamanho )//recebe um vetor e retorna componente de maior tamanho
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

void teste_max()
    {
        int vetor[5]={1,2,3,4,5};
        int resultado=retorna_maior_valor (vetor,5);
        if(resultado==5)
        {
           printf("Teste teste_max Passou!\n");
        }
        else
        {
            printf("Teste teste_max falhou! Esperado 10, obtido %d",resultado);
        }
    }
int main (void)
{

    teste_max();
    
    return 0;

}