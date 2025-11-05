//teste_pilha.c

#include <stdio.h>
#include "libpilha.h"

//funções

void teste_pilha () 
{
    Pilha* pilha = criarPilha();
    
    push(pilha, 10);
    if (top(pilha) == 10) {
        printf("PUSH 10 OK\n");
    } else {
        printf("PUSH 10 falhou\n");
    }
    
    push(pilha, 20);
    if (top(pilha) == 20) {
        printf("PUSH 20 OK\n");
    } else {
        printf("PUSH 20 falhou\n");
    }
    
    int topo = top(pilha);
    if (topo == 20) {
        printf("TOP 20 OK\n");
    } else {
        printf("TOP 20 falhou\n");
    }
    
    pop(pilha);
    if (top(pilha) == 10) {
        printf("POP 20 OK\n");
    } else {
        printf("POP 20 falhou\n");
    }

    int removido = pop(pilha);
    if (removido == 10) {
        printf("TOP 10 OK\n");
    } else {
        printf("TOP 10 falhou\n");
    }

}

int main() {
    teste_pilha();
    return 0;
}