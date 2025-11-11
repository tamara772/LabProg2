//libtestfila.h
#ifndef LIBTESTFILA_H
#define LIBTESTFILA_H

#include <stdio.h>
#include <string.h>
#include "libfila.h"

// Estrutura de uma linha de teste
typedef struct {
    char operacao[20];  // "PUSH", "POP", "TOP"
    int valor;          // valor usado na operação
    char esperado[100]; // estado esperado (lido na linha de testes)
} Teste;

// Executa teste individual. Retorna 1 se passou, 0 se falhou
int executarTeste(Teste* t, Fila* fila, char* resultado);

// Registra o resultado no arquivo de saída
void registrarResultado(FILE* out, Teste* t, int sucesso, const char* resultado);

// (opcional) Função para rodar todos os testes
void rodarTestes(const char* nomeArquivoEntrada, const char* nomeArquivoSaida);

#endif
