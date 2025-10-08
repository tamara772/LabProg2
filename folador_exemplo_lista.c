#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
} Lista;


// ----- INÍCIO DA ÁREA DE DECLARAÇÃO DAS FUNÇÕES ----- //
Lista* criarLista();
void inserirInicio(Lista* lista, int valor);
void inserirFim(Lista* lista, int valor);
// int contarQtdNos(Lista *lista);
// void inserirMeio(Lista* lista, int valor);
int removerElemento(Lista* lista, int valor);
void visualizar(Lista* lista);
// void liberarLista(Lista* lista);
int mostrarMenu();
void esperarEnter();
// ----- FIM DA ÁREA DE DECLARAÇÃO DAS FUNÇÕES ----- //


// ===== INÍCIO DO PROGRAMA PRINCIPAL ===== //
int main() {
    Lista* minhaLista = criarLista();
    int escolha, valor;

    do {
        escolha = mostrarMenu();
        switch (escolha) {
            case 1:
                printf("\n > Digite um valor para inserir no *início: ");
                scanf("%d", &valor);
                inserirInicio(minhaLista, valor);
                break;
            case 2:
                printf("\n > Digite um valor para inserir no fim* : ");
                scanf("%d", &valor);
                inserirFim(minhaLista, valor);
                break;
            case 3:
                printf("\nNÃO IMPLEMENTADO...");
                //inserirMeio(minhaLista, valor);
                esperarEnter();
                break;
            case 4:
                printf("\n > Digite um valor para remover: ");
                scanf("%d", &valor);
                valor = removerElemento(minhaLista, valor);
                if (valor != -1) {
                    printf("\n > Removido: %d\n", valor);
                    esperarEnter();
                }
                break;
            case 5:
                visualizar(minhaLista);
                break;
            case 6:
                //liberarLista(minhaLista);
                printf("\nNÃO IMPLEMENTADO...");
                printf("\n > Saindo...\n\n");
                esperarEnter();
                break;
            default:
                printf("\n > Opção inválida! Tente novamente.\n");
                esperarEnter();
                break;
        }
    } while (escolha != 6);

    return 0;
}
// ===== FIM DO PROGRAMA PRINCIPAL ===== //


// ----- INÍCIO DA ÁREA DE DEFINÇÃO DAS FUNÇÕES ----- //
/**
 * @brief: Função para criar uma nova lista, a variável que gerencia a lista
 * @return Lista*: retorna um ponteiro do tipo Lista com o endereço de memória alocado.
 */
Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

/**
 * @brief: Função para inserir um elemento no início da lista.
 * 
 * @param lista: deve conter o endereço de memória do tipo Lista já alocado.
 * @param valor: deve conter um valor do tipo inteiro.
 * @return void: sen retorno
 */
void inserirInicio(Lista* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = lista->inicio;
    lista->inicio = novoNo;
}

/**
 * @brief Função para inserir um elemento no final da lista.
 * 
 * @param lista: deve conter o endereço de memória do tipo Lista já alocado.
 * @param valor: deve conter um valor do tipo inteiro. 
 * @return void: sen retorno
 */
void inserirFim(Lista* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = novoNo;
    } else {
        No* atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}

/**
 * @brief Função para contar a quantidade de nós lincados na fila.
 * 
 * @param lista: deve conter o endereço de memória da Lista alocada.
 * @return int: será retornado o número de nós encontrados. 
 */
int contarQtdNos(Lista *lista) {
	// implementar...
}

/**
 * @brief Função para realizar a inserção de nó no meio da lista, considerando
 * que se a lista tiver um número ímpar de nós, o meio será considerado como
 * o valor inteiro da divisão. 
 * Ex.: 3 nós / 2: 1,5, portanto, o novo nó será inserido após o elemento 1.
 * 
 * @param lista: deve conter o endereço de memória do tipo Lista já alocado.
 * @param valor: deve conter um valor do tipo inteiro. 
 * @return void: sen retorno.
 */
void inserirMeio(Lista* lista, int valor) {
	// implementar...    
}

/**
 * @brief Função para remover um nó específico da lista
 * 
 * @param lista: deve conter o endereço de memória do tipo Lista já alocado.
 * @param valor: deve conter um valor do tipo inteiro. 
 * @return int: retorna o valor inteiro da informação removida.
 */
int removerElemento(Lista* lista, int valor) {
    if (lista->inicio == NULL) {
        printf("\n > Lista vazia! Não é possível remover.\n");
        esperarEnter();
        return -1;
    }
    No* atual = lista->inicio;
    No* anterior = NULL;
    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) {
        printf("\n > Elemento %d não encontrado na lista.\n", valor);
        esperarEnter();
        return -1;
    }
    if (anterior == NULL) {
        lista->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);
    return valor;
}

/**
 * @brief Função para visualizar os elementos da lista.
 * 
 * @param lista: deve conter o endereço de memória do tipo Lista já alocado.
 * @return void: sem retorno.
 */
void visualizar(Lista* lista) {
    if (lista->inicio == NULL) {
        printf("\n > Lista vazia!\n");
    }else{
        No* atual = lista->inicio;
        printf("\n > Elementos na lista: \n\n\t");
        while (atual != NULL) {
            printf("%d -> ", atual->dado);
            atual = atual->proximo;
        }
    }
    esperarEnter();
}

/**
 * @brief Função para liberar toda a memória alocada para a lista.
 * 
 * @param lista: deve conter o endereço de memória do tipo Lista já alocado.
 * @return void: sem retorno.
 */
void liberarLista(Lista* lista) {
	// codificar...
}

/**
 * @brief Função para mostrar o menu e obter a escolha do usuário.
 * 
 * @return int: retorna um inteiro contendo a opção escolhida pelo usuário
 */
int mostrarMenu() {
    int escolha;
    system("clear || cls");
    printf("\n### GERENCIA LISTA ###\n\n");
    printf("\n### Menu de Opções ###\n\n");
    printf("\t1. Inserir no *início da fila\n");
    printf("\t2. Inserir no fim* da lista\n");
    printf("\t3. Inserir no *meio* da lista\n");
    printf("\t4. Remover elemento\n");
    printf("\t5. Visualizar a lista\n");
    printf("\t6. Sair\n\n");
    printf("\t# Escolha uma opção: ");
    scanf("%d", &escolha);
    return escolha;
}

/**
 * @brief Função para limpar '\n' indesejados e parar o programa até que
 * o usuário tecle 'enter' para continuar.
 *
 * return void: sem retorno.
 */
void esperarEnter() {
    while (getchar() != '\n'); // limpa buffer
    printf("\n\n Tecle [enter] para continuar...");
    getchar();
}
// ----- FIM DA ÁREA DE DEFINÇÃO DAS FUNÇÕES ----- //
