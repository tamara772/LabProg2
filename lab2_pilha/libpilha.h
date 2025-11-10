//libpilha.h
#ifndef LIBPILHA_H
#define LIBPILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Estrutura do nó
typedef struct NodeP {
    int dado;
    struct NodeP* prox;
} NodeP;

//Estrutura da pilha
typedef struct {
    NodeP* topo;
} Pilha;

//Função criar a pilha
Pilha* criarPilha();

//Função inserir valor int na Pilha
void push(Pilha* pilha, int valor);

//Função remover o topo da pilha
int pop(Pilha* pilha);

//Função verificar o topo da pilha
int top(Pilha* pilha);

//Função que transforma a pilha em string
void pilhaParaString(Pilha *pilha, char *saida); 


//Função visualizar pilha
// int  visualizar(Pilha* pilha);

//copia a pilha para um vetor
//int* vetorCopiarPilha(Pilha* pilha, int* tamanho);
 
 
 
 #endif