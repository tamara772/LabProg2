//libfila.h
#ifndef LIBFILA_H
#define LIBFILA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Estrutura da fila
// Definição da estrutura do nó da fila, aquilo que guarda a 
// informação que se deseja e também o endereço do próximo da fila.
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Estrutura da fila, ela precisa ter ponteiros guardar o endereço 
// de memória do início e fim da fila, que são do tipo No.
typedef struct {
    No* inicio;
    No* fim;
} Fila;

Fila* criarFila();
void inserir(Fila* fila, int valor);
int remover(Fila* fila);
void visualizar(Fila* fila);
void esperarEnter();Fila* criarFila();
void inserir(Fila* fila, int valor);
int remover(Fila* fila);
void visualizar(Fila* fila);
void liberarFila(Fila* fila);
void esperarEnter();
//Função que transforma a fila em string
void filaParaString(Fila *fila, char *saida); 
int front(Fila* fila);



/*

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
//int* vetorCopiarPilha(Pilha* pilha, int* tamanho);*/
 
 
 
 #endif