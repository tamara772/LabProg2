//libtestpilha.c
#include <stdio.h>
#include <string.h>
#include "libpilha.h"
#include "libtestpilha.h"

//função executar teste. Retorna 1 (sucesso)  ou 0 (falha).

int executarTeste(Teste* t, Pilha* pilha, char* resultado) {
    int sucesso = 0;
   
    
    if (strcmp(t->operacao, "PUSH") == 0) {
        push(pilha, t->valor);
        pilhaParaString(pilha, resultado);
        sucesso = (strcmp(resultado, t->esperado) == 0);
    }

    else if (strcmp(t->operacao, "POP") == 0) {
        pop(pilha);
        if (pilha->topo == NULL)
            strcpy(resultado, "null");
        else
            pilhaParaString(pilha, resultado);

        sucesso = (strcmp(resultado, t->esperado) == 0);
    }

    else if (strcmp(t->operacao, "TOP") == 0) {
        if (pilha->topo == NULL)
            strcpy(resultado, "null");
        else
            sprintf(resultado, "%d", top(pilha));  // resultado só o valor do topo

        sucesso = (strcmp(resultado, t->esperado) == 0);
    }

    else {
        strcpy(resultado, "operacao_invalida");
        sucesso = 0;
    }

    return sucesso;
}



//Função  que registra resultado em arquivo de saída.
void registrarResultado(FILE* out, Teste* t, int sucesso, const char* resultado) 
{
    fprintf(out, "%s ", t->operacao);

    if (strcmp(t->operacao, "PUSH") == 0)  // Para PUSH mostra o valor empilhado
        fprintf(out, "%d ", t->valor);
    else if (strcmp(t->operacao, "TOP") == 0)
        fprintf(out, "_ ");

    // Mostra o que era esperado e o que foi obtido
    fprintf(out, "(esperado=%s, obtido=%s) -> %s\n",
            t->esperado,
            resultado,   
            sucesso ? "SUCESSO" : "FALHA");
}

// Função que roda o teste com os argumentos de comando
void rodarTestes(const char* nomeArquivoEntrada, const char* nomeArquivoSaida) {
    FILE* in = fopen(nomeArquivoEntrada, "r");
    if (!in) {
        printf("Erro ao abrir arquivo de testes.\n");
        return;
    }

    FILE* out = fopen(nomeArquivoSaida, "a"); // usa "a" para append
    if (!out) {
        printf("Erro ao criar arquivo de resultados.\n");
        fclose(in);
        return;
    }

    Pilha* pilha = criarPilha();
    if (!pilha) {
        printf("Erro ao criar pilha.\n");
        fclose(in);
        fclose(out);
        return; }

    Teste t;
    while (!feof(in)) 
    {
    int lidos = fscanf(in, "%s", t.operacao);  // PUSH  POP TOP
    if (lidos != 1) break; // final do arquivo ou erro

    if (strcmp(t.operacao, "PUSH") == 0) {    // PUSH tem valor inteiro e estado esperado
        fscanf(in, "%d %s", &t.valor, t.esperado);
    } else {
        fscanf(in, "%s", t.esperado);  // POP ou TOP  só têm estado esperado
        t.valor = 0; // para manter o campo limpo
    }

    char resultado[100];

    int sucesso = executarTeste(&t, pilha, resultado);
    registrarResultado(out, &t, sucesso, resultado);
    }

    fclose(in);
    fclose(out);
}
