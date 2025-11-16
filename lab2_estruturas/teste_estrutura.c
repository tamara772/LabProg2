// teste_estrutura.c
#include <string.h>
#include <stdio.h>
#include "libestruturas.h"
#include "libtest.h"

int main() {
    FILE* in = fopen("testes.txt", "r");
    FILE* out = fopen("resultados.txt", "a");

    if (!in) {
        printf("Erro ao abrir arquivo de testes!\n");
        return 1;
    }
    if (!out) {
        printf("Erro ao abrir arquivo de saída!\n");
        fclose(in);
        return 1;
    }
    Pilha* pilha=criarPilha();
    Fila* fila = criarFila();
    Teste t;
    char resultado[100];// para armazenar o resultado
    char valorStr[20]; //string provisória que recebe os valores de entrada (campo 2)

    while (fscanf(in, "%s %s %s", t.operacao, valorStr, t.esperado) == 3) // Lê até três campos por linha
   {
        if (strcmp(valorStr, "-") == 0 || strcmp(valorStr, "_") == 0)// se o campo valor for "-" ou "_", não há número na entrada
        t.valor = 0; // valor não usado
    else
        t.valor = atoi(valorStr); // converte o número para int

    int sucesso = executarTeste(&t, fila,pilha, resultado); // executa o teste 
    registrarResultado(out, &t, sucesso, resultado);
    }

    fclose(in);
    fclose(out);
    printf("Testes executados. Resultados em resultados.txt\n");
    return 0;
}

