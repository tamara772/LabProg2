//exemplo_pilha.c

#include <stdio.h>
#include "libpilha.h"

int main ()
{
    Pilha* pilha = criarPilha();
    
    printf("### Testando a biblioteca libpilha ##\n\n");
    push(pilha,10);
    push(pilha,20);
    push(pilha,30);
    push(pilha,40);
    push(pilha,50);
    int removido = pop(pilha);
    int topo = top(pilha);
    printf("Removido %d e Topo atual: %d\n", removido, topo);

    int i;
    int tamanho;
    int* vetor1 = vetorCopiarPilha(pilha, &tamanho);
    printf(" ##Pilha atual##\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d\n", vetor1[i]);
    }
    free(vetor1);        
   
   return 0; 
}