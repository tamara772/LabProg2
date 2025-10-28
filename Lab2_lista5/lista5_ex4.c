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


// -----  DECLARAÇÃO DAS FUNÇÕES ----- //
Lista* criarLista();
void inserirInicio(Lista* lista, int valor);
void inserirFim(Lista* lista, int valor);
void visualizar(Lista* lista);
void esperarEnter() ;


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
//fim do programa principal

// ----- DEFINÇÃO DAS FUNÇÕES ----- //

//Função para criar uma nova lista, a variável que gerencia a lista,
//retorna um ponteiro do tipo Lista com o endereço de memória alocado.
 
Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

//Função para inserir um elemento no início da lista.
 
void inserirInicio(Lista* lista, int valor) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->valor = valor;
    novoNo->proximo = lista->inicio;
    lista->inicio = novoNo;
}

//Função para inserir um elemento no final da lista.
 
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

//Função para visualizar os elementos da lista.
 
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

//Função para limpar '\n' indesejados e parar o programa até tecla 'enter'.
 
void esperarEnter() {
    while (getchar() != '\n'); // limpa buffer
    printf("\n\n Tecle [enter] para continuar...");
    getchar();
}
// ----- FIM DA ÁREA DE DEFINÇÃO DAS FUNÇÕES ----- //

