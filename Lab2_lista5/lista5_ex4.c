/* Lista 5 - Exercício 4 – Inserção em lista encadeada - com base no exemplo Folador
Reutilize a struct Node do exercício anterior.
Agora crie funções:
● Node* inserirInicio(Node* inicio, int valor) que insere um elemento
no início da lista
● void imprimirLista(Node* inicio) que imprime a lista
Teste inserindo alguns elementos e exibindo a lista*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

typedef struct Lista{
    Node* inicio;
} Lista;


// ----- INÍCIO DA ÁREA DE DECLARAÇÃO DAS FUNÇÕES ----- //
Lista* criarLista();
void inserirInicio(Lista* lista, int valor);
void inserirFim(Lista* lista, int valor);
void visualizar(Lista* lista);
void esperarEnter() ;

// ===== INÍCIO DO PROGRAMA PRINCIPAL ===== //

int main() {
    Lista* minhaLista = criarLista();
    int valor;
    int n=5;
                printf("\n > Digite um valor para inserir no *início: ");
                scanf("%d", &valor);
                inserirInicio(minhaLista, valor);
                
                for (int i=0;i<n;i++)
                {
                printf("\n > Digite um valor para inserir no fim* : ");
                scanf("%d", &valor);
                inserirFim(minhaLista, valor);
                }
                
                visualizar(minhaLista);
                
            
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
 * @param lista: deve conter o endereço de memória do tipo Lista já alocado.
 * @param valor: deve conter um valor do tipo inteiro.
 * @return void: sem retorno
 */
void inserirInicio(Lista* lista, int valor) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->valor = valor;
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
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = novoNo;
    } else {
        Node* atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}

/**
 * @brief Função para visualizar os elementos da lista.
 * 
 * @param lista: deve conter o endereço de memória do tipo Lista já alocado.
 * @return void: sem retorno.
 */
void visualizar(Lista* lista) 
{
    if (lista->inicio == NULL) {
        printf("\n > Lista vazia!\n");
        }   
        else{
        Node* atual = lista->inicio;
        printf("\n > Elementos na lista: \n\n\t");
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
            }
        }
    esperarEnter();
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
