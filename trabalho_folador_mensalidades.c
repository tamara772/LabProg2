/**
    

    Portanto, desenvolva um programa em linguagem C que simule o 
    controle de mensalidades de um curso. O programa deverá USAR FUNÇÕES
    e conter os seguintes itens principais:

    1. Perguntar ao usuário quantas mensalidades deseja registrar, 
       garantindo que o valor informado seja maior que zero.
       Caso contrário, o programa deve repetir a pergunta até que um 
       valor válido seja informado;
    2. Utilizar alocação dinâmica de memória com ponteiros para armazenar 
       os valores das mensalidades;
    3. Solicitar ao usuário que insira os valores de cada mensalidade, 
       também validando que cada valor seja maior que zero;
    4. Calcular a média dos valores das mensalidades;
    5. Exibir como resultado final:
            Todos os valores das mensalidades;
            O endereço de memória de cada valor armazenado;
            O valor da média calculada.
            Ex.: Parcela 01: R$ 425.50 [0xFAB12444]
                 ...
                 Parcela  n: R$ 585.50 [0xFAB124BB]
                 
                 Média das parcelas: R$ 597.74
 */

// A seguir tem-se um programa base para que vocês ajustem de acordo 
// o pedido anteriormente


#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n, i;
    float *mensal;
    //float *mens;

    // ajustar e validar a quantidade informada
    
    printf("Quantas mensalidades deseja registrar? ");
    scanf("%d", &n);
           while (n<=0)
            { printf("Quantas mensalidades? ");
                scanf("%d", &n);}

    // Usar a função calloc
       mensal= (float*) calloc(n, sizeof(float));
        
    if (mensal== NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Preencher os valores das mensalidades
        //int i=0;
    for (i = 0; i < n; i++) {
        printf("Mensalidade número  %d: ", i+1);
        scanf("%f", &mensal[i]);
        // validar a mmensalidade informada (while, do..while)//o que seria uma mensalidade inválida?
    }

    // Calcular média
     float soma=0;
     float media=0;
     for (i=0;i<n;i++)
            {
           soma=soma+mensal[i];
            }
    media=soma/n;
    printf("Média das mensalidades: %.02f", media);
     for (i=0;i<n; i++)
         {
            printf("\n parcela %i: valor %.02f e endereço %p", i+1,mensal[i],&mensal[i]);
         }

    // Libere a memória da área alocada
    free(mensal);

    return 0;
}


