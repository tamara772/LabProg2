/* Lista 5 - Exercício 3 – Struct com ponteiro para próxima
Crie uma struct Node com os campos:
● inteiro valor
● ponteiro prox para o próximo Node
Peça para o usuário digitar 5 números e monte manualmente uma lista encadeada (sem
usar funções). Depois, percorra a lista imprimindo os valores.*/

#include <stdio.h>
#include <stdlib.h>

// Definição da struct Node
typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

int main() {
    Node n1, n2, n3, n4, n5;  // criamos 5 nós
    Node *inicio = &n1;        // ponteiro para o início da lista

    // Pedir para o usuário digitar 5 números
    printf("Digite 5 números inteiros:\n");

    printf("Número 1: ");
    scanf("%d", &n1.valor);
    n1.prox = &n2;  // conecta n1/n2 - indica o próximo endereço

    printf("Número 2: ");
    scanf("%d", &n2.valor);
    n2.prox = &n3;  // conecta n2/n3

    printf("Número 3: ");
    scanf("%d", &n3.valor);
    n3.prox = &n4;  // conecta n3/n4

    printf("Número 4: ");
    scanf("%d", &n4.valor);
    n4.prox = &n5;  // conecta n4/n5

    printf("Número 5: ");
    scanf("%d", &n5.valor);
    n5.prox = NULL; // último nó aponta para NULL n5/n5

    // Percorrer a lista e imprimir os valores
    Node *atual = inicio;
    printf("\nValores na lista encadeada:\n");
    while (atual != NULL) {
        printf("%d", atual->valor); //percorrendo com ponteiros
        atual = atual->prox;
    }
    printf("\n");

    return 0;
}