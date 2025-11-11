//libfila.c
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libfila.h"


Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}


void inserir(Fila* fila, int valor) {
  No* novoNo = (No*)malloc(sizeof(No));
  novoNo->valor = valor;
    novoNo->proximo = NULL;
    if (fila->fim == NULL) {
      fila->inicio = novoNo;
      fila->fim = novoNo;
    }
    else {
      fila->fim->proximo = novoNo;
      fila->fim = novoNo;
    }
}

void visualizar(Fila* fila) {
  if (fila->inicio == NULL) {
    printf("\n > Fila vazia!\n");
  }
  else {
    No* atual = fila->inicio;
    printf("\n > Elementos inseridos na fila: \n\n\t");
    while (atual != NULL) {
      printf(" -> %d", atual->valor);
      atual = atual->proximo;
    }
  }
}

int remover(Fila* fila) {
  if (fila->inicio == NULL) {
    printf("\n > Fila vazia! Nao e possivel remover.\n");
    return -1;
  }
  No* temp = fila->inicio;
  int valor = temp->valor;
  fila->inicio = fila->inicio->proximo;
  if (fila->inicio == NULL){
    fila->fim = NULL;
  } 
  free(temp);
  return valor;
}

void liberar_fila(Fila* fila) {
  No* atual = fila->inicio;
  No* proximo;
  while (atual != NULL) {
      proximo = atual->proximo;
      free(atual); // Libera o nó atual
      atual = proximo;
  }
  fila->inicio = NULL;
  fila->fim = NULL;
}

//Função que transforma fila em string

 void filaParaString(Fila* fila, char* saida) {
    saida[0] = '\0';  // inicializa string vazia
    No* atual = fila->inicio;
    char temp[20];    // string temporária

    while (atual != NULL) {
        sprintf(temp, "%d", atual->valor);
        strcat(saida, temp);  //concatena temp com saída
        if (atual->proximo != NULL)
            strcat(saida, ","); //adiciona vírgula entre os valores e sem espaços
        atual = atual->proximo;
    }
}

// Retorna o valor na frente da fila, sem remover
int front(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;  // ou outro valor indicando erro
    }
    return fila->inicio->valor;
}








/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

//Função para a transformar a pilha em uma string

void pilhaParaString(Pilha *pilha, char *saida) //percorre a pilha e cria string, do topo até a base
 {
    saida[0] = '\0'; // inicializa a string
    NodeP* atual = pilha->topo;
    char temp[20]; //string temporária que guarda a versão em texto do valor atual da pilha.
    while (atual != NULL) {
        sprintf(temp, "%d", atual->dado);
        strcat(saida, temp);//concatena na saída principal
        if (atual->prox != NULL)
            strcat(saida, ",");//acrescenta vírgula entre valores
        atual = atual->prox;
    }
}

void esperarEnter() {
    while (getchar() != '\n'); // limpa buffer
   { printf("\n\n Tecle [enter] para continuar...");
    getchar();}
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
/*int* vetorCopiarPilha(Pilha* pilha, int* tamanho) {

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
*/

