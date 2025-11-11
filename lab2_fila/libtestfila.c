//libtestfila.c
#include <stdio.h>
#include <string.h>
#include "libfila.h"
#include "libtestfila.h"

//função executar teste. Retorna 1 (sucesso)  ou 0 (falha).

int executarTeste(Teste* t, Fila* fila, char* resultado) {
   
    int sucesso = 0;

    if (strcmp(t->operacao, "INSERIR") == 0) {
        inserir(fila, t->valor);
        filaParaString(fila, resultado);
        sucesso = (strcmp(resultado, t->esperado) == 0);
    }

    else if (strcmp(t->operacao, "REMOVER") == 0) {
        int removido = remover(fila); // remove o primeiro

        if (fila->inicio == NULL)
            strcpy(resultado, "null");
        else
            filaParaString(fila, resultado);// gera string da fila após a remoção

        sucesso = (strcmp(resultado, t->esperado) == 0);

        }

    return sucesso;
}



//Função  que registra resultado em arquivo de saída.

void registrarResultado(FILE* out, Teste* t, int sucesso, const char* resultado) 
{
    fprintf(out, "%s ", t->operacao);

    // Para inserir, mostra o valor inserido
    if (strcmp(t->operacao, "inserir") == 0)
        fprintf(out, "%d ", t->valor);
    // para remover ou ver inicio não há valor
    else if (strcmp(t->operacao, "remover") == 0)
        fprintf(out, "_ ");

    // Mostra o esperado e o obtido
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

   Fila* fila = criarFila();
    if (!fila) {
        printf("Erro ao criar a fila.\n");
        fclose(in);
        fclose(out);
        return; }

    Teste t;
  while (!feof(in)) 
{
    int lidos = fscanf(in, "%s", t.operacao);  // operações: INSERIR, REMOVER,
    if (lidos != 1) break; // fim do arquivo ou erro

    if (strcmp(t.operacao, "INSERIR") == 0) {    
        //tem um valor inteiro e o estado esperado
        fscanf(in, "%d %s", &t.valor, t.esperado);
    } 
    else {  
        // remoção só tem estado esperado
        fscanf(in, "%s", t.esperado);
        t.valor = 0; // mantém campo limpo
        }

    char resultado[100];

    int sucesso = executarTeste(&t, fila, resultado);
    registrarResultado(out, &t, sucesso, resultado);
}


    fclose(in);
    fclose(out);
}
