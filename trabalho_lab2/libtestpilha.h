//libtestpilha.h
#ifndef LIBTESTPILHA_H
#define LIBTESTPILHA_H
#include <stdio.h>
#include <string.h>
#include "libpilha.h" 

// Estrutura de uma linha de teste
typedef struct {
    char operacao[20]; //  "PUSH", "POP", "TOP"
    int valor1;        // valor usado na operação
    int esperado;      //valor esperado da operação
} Teste;

// Executa teste individual. Retorna 1 se passou, 0 se falhou
int executarTeste(Teste* t, Pilha* pilha);

// Registra o resultado no arquivo de saída
void registrarResultado(FILE* out, Teste* t, int sucesso);

// Lê o arquivo de testes e executa tudo
void rodarTestes(const char* nomeArquivoEntrada, const char* nomeArquivoSaida);

#endif
