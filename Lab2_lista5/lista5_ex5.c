/* Lista 5 - ExercÃ­cio 5 â€“ RemoÃ§Ã£o em lista encadeada
Com a mesma struct Node, crie uma funÃ§Ã£o:
â— Node* removerInicio(Node* inicio) que remove o primeiro elemento da
lista e retorna o novo inÃ­cio.
Teste inserindo 3 elementos, imprimindo a lista, removendo o primeiro e imprimindo
novamente*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

typedef struct Lista{
    Node* inicio;
} Lista;


// ----- INÃCIO DA ÃREA DE DECLARAÃ‡ÃƒO DAS FUNÃ‡Ã•ES ----- //
Lista* criarLista();
void inserirInicio(Lista* lista, int valor);
void inserirFim(Lista* lista, int valor);
Node* removerInicio(Node* inicio);
int removerElemento(Lista* lista, int valor);
void visualizar(Lista* lista);
void esperarEnter() ;

// ===== INÃCIO DO PROGRAMA PRINCIPAL ===== //

int main() {
    Lista* minhaLista = criarLista();
    int valor;
    int n=5;
                printf("\n > Digite um valor para inserir no *inÃ­cio: ");
                scanf("%d", &valor);
                inserirInicio(minhaLista, valor);
                
                for (int i=0;i<n;i++)
                {
                printf("\n > Digite um valor para inserir no fim* : ");
                scanf("%d", &valor);
                inserirFim(minhaLista, valor);
                }
                
                visualizar(minhaLista);
                
                minhaLista->inicio = removerInicio(minhaLista->inicio);
                
                visualizar(minhaLista);
                
                int m=3;
                for(int i=0;i<m;i++)
                {
                printf("\n > Digite um valor para remover: ");
                scanf("%d", &valor);
                valor = removerElemento(minhaLista, valor);
                if (valor != -1) {
                    printf("\n > Removido: %d\n", valor);
                               }
                }
                visualizar(minhaLista);
                
            
      return 0;
}
// ===== FIM DO PROGRAMA PRINCIPAL ===== //


// ----- INÃCIO DA ÃREA DE DEFINÃ‡ÃƒO DAS FUNÃ‡Ã•ES ----- //
/**
 * @brief: FunÃ§Ã£o para criar uma nova lista, a variÃ¡vel que gerencia a lista
 * @return Lista*: retorna um ponteiro do tipo Lista com o endereÃ§o de memÃ³ria alocado.
 */
Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

/**
 * @brief: FunÃ§Ã£o para inserir um elemento no inÃ­cio da lista.
 * @param lista: deve conter o endereÃ§o de memÃ³ria do tipo Lista jÃ¡ alocado.
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
 * @brief FunÃ§Ã£o para inserir um elemento no final da lista.
 * 
 * @param lista: deve conter o endereÃ§o de memÃ³ria do tipo Lista jÃ¡ alocado.
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

/*Remove o primeiro elemento da lista e retorna o próximo*/
Node* removerInicio(Node* inicio) 
{
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return NULL;
    }

    Node* temp = inicio;        // guarda o primeiro nó
    inicio = inicio->proximo;   // move o início para o próximo
    free(temp);                 // libera o nó removido
    return inicio;              // retorna o novo início
}



/**
 * @brief FunÃ§Ã£o para remover um nÃ³ especÃ­fico da lista
 *  * @param lista: deve conter o endereÃ§o de memÃ³ria do tipo Lista jÃ¡ alocado.
 * @param valor: deve conter um valor do tipo inteiro. 
 * @return int: retorna o valor inteiro da informaÃ§Ã£o removida.
 */
int removerElemento(Lista* lista, int valor) {
    if (lista->inicio == NULL) {
        printf("\n > Lista vazia! NÃ£o Ã© possÃ­vel remover.\n");
        esperarEnter();
        return -1;
    }
    Node* atual = lista->inicio;
    Node* anterior = NULL;
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) {
        printf("\n > Elemento %d nÃ£o encontrado na lista.\n", valor);
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
 * @brief FunÃ§Ã£o para visualizar os elementos da lista.
 * 
 * @param lista: deve conter o endereÃ§o de memÃ³ria do tipo Lista jÃ¡ alocado.
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
 * @brief FunÃ§Ã£o para limpar '\n' indesejados e parar o programa atÃ© que
 * o usuÃ¡rio tecle 'enter' para continuar.
 *
 * return void: sem retorno.
 */
void esperarEnter() {
    while (getchar() != '\n'); // limpa buffer
    printf("\n\n Tecle [enter] para continuar...");
    getchar();
}
// ----- FIM DA ÃREA DE DEFINÃ‡ÃƒO DAS FUNÃ‡Ã•ES ----- //