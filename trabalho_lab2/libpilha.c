//libpilha.c
#include "libpilha.h"
 
//criar pilha
Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

//inserir elementos na pilha
void push(Pilha* pilha, int valor) {
    NodeP* novoNo = (NodeP*)malloc(sizeof(NodeP));
    novoNo->dado = valor;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
}

//remover elemento no topo da pilha
int pop(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("\n > Pilha vazia! Não é possível desempilhar.\n");
        return -1;
    }
    NodeP* temp = pilha->topo;
    int valor = temp->dado;
    pilha->topo = pilha->topo->prox;
    free(temp);
    return valor;
}

//Verificar o elemento no topo da pilha
int top(Pilha* pilha)
{   
    if (pilha->topo == NULL) {
        printf("Erro: pilha vazia\n");
        return -1; 
    }
    return pilha->topo->dado;
}

//visualizar pilha

/*int visualizar(Pilha* pilha) {
    int vetor[];
    int count=0;
    
    if (pilha->topo == NULL) {
        printf("\n > Pilha vazia!\n");
    }else{
        NodeP* atual = pilha->topo;
        printf("\n > Elementos na pilha: \n\n >");
        while (atual != NULL) {
            printf("\t%d \n", atual->dado);
            vetor[count]=atual->dado;
            atual = atual->prox;
            count++;
            }
        }
    return vetor;
}*/

//copia a pilha para um vetor
int* vetorCopiarPilha(Pilha* pilha, int* tamanho) {

    int count = 0;
    NodeP* atual = pilha->topo;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    *tamanho = count;

    if (count == 0) return NULL; // pilha vazia

    int* vetor = malloc(count * sizeof(int));//aloca memória para o vetor
    if (!vetor) {
        printf("Erro: sem memória!\n");
        *tamanho = 0;
        return NULL;
    }

    atual = pilha->topo; // preencher vetor
    int i=0;
    for (i = 0; i < count; i++) {
        vetor[i] = atual->dado;
        atual = atual->prox;
    }

    return vetor; // retorna o ponteiro
}


void esperarEnter() {
    while (getchar() != '\n'); // limpa buffer
   { printf("\n\n Tecle [enter] para continuar...");
    getchar();}
}
