//libtestpilha.c

#include "libpilha.h"
#include "libtestpilha.h"

//função executar teste. Retorna 1 (sucesso)  ou 0 (falha).

int executarTeste(Teste* t, Pilha* pilha) {
    int sucesso = 0;
    char* resultado[];
    int i;

    if (strcmp(t->operacao, "PUSH") == 0) {
        push(pilha, t->valor1);
        sucesso = 1;}// sempre ok se não deu erro

    else if (strcmp(t->operacao, "POP") == 0) {      ver aqui
         pop(pilha);
          while (top(pilha) !NULL
        sucesso = (resultado == t->esperado);}

    else if (strcmp(t->operacao, "TOP") == 0) {
        resultado = top(pilha);
        sucesso = (resultado == t->esperado);}

    
    return sucesso;
}

//Função  que registra resultado em arquivo de saída.
void registrarResultado(FILE* out, Teste* t, int sucesso) {
    fprintf(out, "%s ", t->operacao);

    if (strcmp(t->operacao, "PUSH") == 0)  // Se for PUSH, imprime o valor inserido
        fprintf(out, "%d -> ", t->valor1);
    else
        fprintf(out, "(esperado=%d) -> ", t->esperado);

    fprintf(out, "%s\n", sucesso ? "SUCESSO" : "FALHA");
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
    while (fscanf(in, "%s %d %d",
                  t.operacao, &t.valor1, &t.esperado) >= 1) {
        int sucesso = executarTeste(&t, pilha);
        registrarResultado(out, &t, sucesso);
    }

    fclose(in);
    fclose(out);
}

