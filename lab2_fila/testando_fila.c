// testando_fila.c
#include <string.h>
#include <stdio.h>
#include "libfila.h"
#include "libtestfila.h"

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

    Fila* fila = criarFila();
    Teste t;
    char resultado[100];// para armazenar o resultado
    char valorStr[20]; 

    // Lê até três campos por linha (por ex.: inserir 10 10,20)
   while (fscanf(in, "%s %s %s", t.operacao, valorStr, t.esperado) == 3) {

    // se o campo valor for "-" ou "_", não há número (ex: remover)
    if (strcmp(valorStr, "-") == 0 || strcmp(valorStr, "_") == 0)
        t.valor = 0; // valor não usado
    else
        t.valor = atoi(valorStr); // converte o número para int

    // executa o teste normalmente
    int sucesso = executarTeste(&t, fila, resultado);
    registrarResultado(out, &t, sucesso, resultado);
}

    fclose(in);
    fclose(out);
    printf("Testes executados. Resultados em resultados.txt\n");
    return 0;
}
