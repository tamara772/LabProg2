//arvoreBIN_NOV2025.c    //árvore binária, estrutura de dados II, Prof. Folador, nov2025
/**
 * Código base em Linguagem C para trabalhar com estrutura
 * não linear dinâmica do tipo árevore binária.
 * 
 * Autor: Prof. João Paulo Folador
 */
#include <stdio.h>
#include <stdlib.h>

// ============================================================
// Estrutura de Dados da Árvore Binária
// ============================================================
typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

// ============================================================
// Declarações de Funções
// ============================================================
No* criarNo(int valor);
No* inserir(No* raiz, int valor);
No* buscar(No* raiz, int valor);
No* encontrarMinimo(No* raiz);
No* remover(No* raiz, int valor);
void percorrerEmOrdem(No* raiz);
void percorrerPreOrdem(No* raiz);
void percorrerPosOrdem(No* raiz);
void liberarArvore(No* raiz);
void exibirArvore(No* raiz, int espaco);
void esperarEnter();
int mostrarMenu(void);

// ============================================================
// Função principal, o programa em si.
// ============================================================
int main() {
    No* raiz = NULL;
    int escolha, valor;
    No* resultado;

    do {
        escolha = mostrarMenu();
        switch (escolha) {
            case 1:
                printf("Digite um valor para inserir: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
            break;
            case 2:
                printf("Digite um valor para remover: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
            break;
            case 3:
                printf("Digite um valor para buscar: ");
                scanf("%d", &valor);
                resultado = buscar(raiz, valor);
                if (resultado != NULL) {
                    printf("Elemento %d encontrado na árvore.\n", valor);
                } else {
                    printf("Elemento %d não encontrado na árvore.\n", valor);
                }
                esperarEnter();
            break;
            case 4:
                printf("Percorrendo a árvore em ordem: ");
                percorrerEmOrdem(raiz);
                printf("\n");
                esperarEnter();
            break;
            case 5:
                printf("Percorrendo a árvore em pré-ordem: ");
                percorrerPreOrdem(raiz);
                printf("\n");
                esperarEnter();
            break;
            case 6:
                printf("Percorrendo a árvore em pós-ordem: ");
                percorrerPosOrdem(raiz);
                printf("\n");
                esperarEnter();
            break;
            case 7:
                printf("\nVisualização da árvore:\n");
                exibirArvore(raiz, 0);
                printf("\n");
                esperarEnter();
            break;
            case 8:
                liberarArvore(raiz);
                printf("Saindo...\n");
            break;
            default:
                printf("Opção inválida! Tente novamente.\n");
            break;
        }
    } while (escolha != 8);

    return 0;
}

// ============================================================
// Implementação das Funções
// ============================================================

/**
 * @brief Cria um novo nó da árvore binária.
 * @param valor Valor inteiro a ser armazenado no nó.
 * @return Ponteiro para o novo nó criado.
 */
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->dado = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

/**
 * @brief Insere um valor na árvore binária.
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param valor Valor a ser inserido.
 * @return Ponteiro para a nova raiz da árvore após a inserção.
 */
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

/**
 * @brief Busca um valor na árvore binária.
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param valor Valor a ser buscado.
 * @return Ponteiro para o nó encontrado, ou NULL se não encontrado.
 */
No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) {
        return raiz;
    }
    if (valor < raiz->dado) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

/**
 * @brief Encontra o nó com o menor valor em uma subárvore.
 * @param raiz Ponteiro para o nó raiz da subárvore.
 * @return Ponteiro para o nó que contém o menor valor.
 * Sófunciona se a árvore for uma árvore binária de busca (BST).SE estiver desordenada não funciona.
 */
No* encontrarMinimo(No* raiz) {
    while (raiz != NULL && raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

/**
 * @brief Remove um valor da árvore binária.
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param valor Valor a ser removido.
 * @return Ponteiro para a nova raiz após a remoção.
 */
No* remover(No* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }
    if (valor < raiz->dado) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        // Nó encontrado
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        No* temp = encontrarMinimo(raiz->direita);
        raiz->dado = temp->dado;
        raiz->direita = remover(raiz->direita, temp->dado);
    }
    return raiz;
}

/**
 * @brief Percorre a árvore em ordem (esquerda, raiz, direita).
 * @param raiz Ponteiro para o nó raiz.
 */
void percorrerEmOrdem(No* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->dado);
        percorrerEmOrdem(raiz->direita);
    }
}

/**
 * @brief Percorre a árvore em pré-ordem (raiz, esquerda, direita).
 * @param raiz Ponteiro para o nó raiz.
 */
void percorrerPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        percorrerPreOrdem(raiz->esquerda);
        percorrerPreOrdem(raiz->direita);
    }
}

/**
 * @brief Percorre a árvore em pós-ordem (esquerda, direita, raiz).
 * @param raiz Ponteiro para o nó raiz.
 */
void percorrerPosOrdem(No* raiz) {
    if (raiz != NULL) {
        percorrerPosOrdem(raiz->esquerda);
        percorrerPosOrdem(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

/**
 * @brief Libera toda a memória alocada para a árvore.
 * @param raiz Ponteiro para o nó raiz da árvore.
 */
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

/**
 * @brief Exibe a árvore binária em formato de árvore rotacionada.
 * A impressão da árvore mostra a raiz à esquerda e os filhos à direita,
 * permitindo uma visualização hierárquica da estrutura. É como se a árvore
 * estivesse tombada com a raiz para a esquerda do observador da tela.
 *
 * @param raiz Ponteiro para o nó raiz da árvore.
 * @param espaco Nível de indentação atual (use 0 ao chamar inicialmente).
 */
void exibirArvore(No* raiz, int espaco) {
    const int DISTANCIA = 5;  // Espaçamento horizontal entre níveis
    if (raiz == NULL) {
        return;
    }
    espaco += DISTANCIA;

    exibirArvore(raiz->direita, espaco);

    printf("\n");
    int i=0;
    for ( i = DISTANCIA; i < espaco; i++) {
        printf(" ");
    }
    printf("%d\n", raiz->dado);

    exibirArvore(raiz->esquerda, espaco);
}

void esperarEnter() {
    while (getchar() != '\n'); // limpa buffer
    printf("\n\n Tecle [enter] para continuar...");
    getchar();
}
/**
 * @brief Exibe o menu principal e lê a opção do usuário.
 * @return Inteiro representando a opção escolhida.
 */
int mostrarMenu(void) {
    int escolha;
    printf("\n========== MENU ==========\n");
    printf("1. Inserir na árvore\n");
    printf("2. Remover da árvore\n");
    printf("3. Buscar na árvore\n");
    printf("4. Percorrer em ordem\n");
    printf("5. Percorrer em pré-ordem\n");
    printf("6. Percorrer em pós-ordem\n");
    printf("7. Exibir árvore graficamente (formato textual)\n");
    printf("8. Sair\n");
    printf("==========================\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);
    return escolha;
}
