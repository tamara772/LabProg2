#include <stdio.h>

float retorna_maior_valor (int vetor[], int tamanho )//recebe um vetor e retorna a componente de maior tamanho
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
//loat vetor1 [10];
    //int k=0;
    //while (k<10)
    //{
        //printf("Insira um número inteiro: ");
        //scanf("%f", &vetor1[k]);
       // k++;
    //}
    //float maior_valor=0;
    //maior_valor=retorna_maior_valor (vetor1,10 );
    //printf("Maior valor no vetor: %.2f",maior_valor);
    
    
    teste_max();
    
    return 0;

}