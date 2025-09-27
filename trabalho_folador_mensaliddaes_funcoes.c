
#include <stdio.h>
#include <stdlib.h>
int entrada1 ();//sai n 
float *entrada2(int n);//sai mensalidades
float media (int n, float *mensal);//sai media
void saida ( int n, float *mensal, float media);//impressao


int main() 
{
  int n=0;
  n=entrada1 ();
  float *mensalidades;
  mensalidades = entrada2(n);
  float media1=0;
  media1=media(n,mensalidades);
  saida (n,mensalidades, media1);
    // Libere a memória da área alocada
    free(mensalidades);

    return 0;
}

//FUNÇÕES

int entrada1()
 {
 int n;
    
       // ajustar e validar a quantidade informada
    
    printf("Quantas mensalidades deseja registrar? ");
    scanf("%d", &n);
           while (n<=0)
            { printf("Quantas mensalidades? ");
                scanf("%d", &n);}

    return n;
 }
    
    float *entrada2 (int n)
    
    {
        float *mensal;
        // Usar a função calloc
       
       mensal= (float*) calloc(n, sizeof(float));
        
    if (mensal== NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
                    }
    // Preencher os valores das mensalidades
        int i=0;
    for (i = 0; i < n; i++) {
        printf("Mensalidade número  %d: ", i+1);
        scanf("%f", &mensal[i]);
        // validar a mmensalidade informada (while, do..while)//o que seria uma mensalidade inválida?
    }
    return  mensal;
 }
    
float media (int n, float* mensal) //calcular media. Quem entra?
{
     float soma = 0;
     float media = 0;
     for (int i=0;i<n;i++)
     {
         soma = soma + mensal[i];
     }
    media = soma/n;
    return media;
}

void saida (int n, float *mensal, float media)
{
    printf("Média das mensalidades: %.02f", media);
     for (int i=0;i<n; i++)
         {
            printf("\n parcela %i: valor %.02f e endereço %p", i+1,mensal[i],&mensal[i]);
         }
}