//libtest.c                   (libtestfila.c e libtestpilha)
#include <stdio.h>
#include <string.h>
#include "libestruturas.h"
#include "libtest.h"

//Executar teste. Retorna 1 (sucesso)  ou 0 (falha).

int executarTeste(Teste* t, Fila* fila,Pilha* pilha, char* resultado) 
{
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

        sucesso = (strcmp(resultado, t->esperado) == 0);}
    
    else if (strcmp(t->operacao, "TOP") == 0) {
        if (pilha->topo == NULL)
            strcpy(resultado, "null");
        else
            sprintf(resultado, "%d", top(pilha));  

        sucesso = (strcmp(resultado, t->esperado) == 0);
         }

    else if (strcmp(t->operacao, "INSERIR") == 0) {
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
    else {
        strcpy(resultado, "operacao_invalida");
        sucesso = 0;
        }
    return sucesso;
}

//Registra resultado em arquivo de saída.

void registrarResultado(FILE* out, Teste* t, int sucesso, const char* resultado) 
{
        if (strcmp(t->operacao, "PUSH") == 0 ||    //mostram um inteiro
        strcmp(t->operacao, "INSERIR") == 0)   
    {
        fprintf(out, "%s %d ", t->operacao, t->valor);
    }
    else
    {
        fprintf(out, "%s _ ", t->operacao);
    }

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

    Pilha* pilha=criarPilha();
    if (!pilha) {
        printf("Erro ao criar pilha.\n");
        fclose(in);
        fclose(out);
        return; }
    
    Teste t;
  while (!feof(in)) 
{
    int lidos = fscanf(in, "%s", t.operacao);  // operações:PUSH POP TOP  INSERIR  REMOVER,
    if (lidos != 1) break; // fim do arquivo ou erro
    
    if (strcmp(t.operacao, "PUSH") == 0) {    // PUSH tem valor inteiro e estado esperado
        fscanf(in, "%d %s", &t.valor, t.esperado); } 
   else {
        fscanf(in, "%s", t.esperado);  // POP ou TOP  só têm estado esperado
        t.valor = 0; // para manter o campo limpo

    if (strcmp(t.operacao, "INSERIR") == 0) {    
        fscanf(in, "%d %s", &t.valor, t.esperado);//tem um valor inteiro e o estado esperado
        t.operacao[strcspn(t.operacao, "\r\n")] = '\0';// tentativa 1
        
    } 
    else {  
        fscanf(in, "%s", t.esperado); // remoção só tem estado esperado
        t.valor = 0; // mantém campo limpo
        }
}
    char resultado[100];

    int sucesso;  
    sucesso=executarTeste(&t,  fila, pilha,  resultado);
    registrarResultado(out, &t, sucesso, resultado);
}


    fclose(in);
    fclose(out);
}
