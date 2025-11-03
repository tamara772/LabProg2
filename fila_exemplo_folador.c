#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da fila, aquilo que guarda a 
// informação que se deseja e também o endereço do próximo da fila.
typedef struct No {
    int dado;
    struct No* proximo;
} No;

// Estrutura da fila, ela precisa ter ponteiros guardar o endereço 
// de memória do início e fim da fila, que são do tipo No.
typedef struct {
    No* inicio;
    No* fim;
} Fila;


// ----- INÍCIO DA ÁREA DE DECLARAÇÃO DAS FUNÇÕES ----- //
Fila* criarFila();
void inserir(Fila* fila, int valor);
int remover(Fila* fila);
void visualizar(Fila* fila);
//void liberarFila(Fila* fila);
int mostrarMenu();
void esperarEnter();
// ----- FIM DA ÁREA DE DECLARAÇÃO DAS FUNÇÕES ----- //


// ===== INÍCIO DO PROGRAMA PRINCIPAL ===== //
int main() {
    Fila* minhaFila = criarFila();
    int escolha, valor;

    do {
        escolha = mostrarMenu();
        switch (escolha) {
            case 1:
                printf("\n > Digite um valor para inserir: ");
                scanf("%d", &valor);
                inserir(minhaFila, valor);
                break;
            case 2:
                valor = remover(minhaFila);
                if (valor != -1) {
                    printf("\n > Removido: %d\n", valor);
                    esperarEnter();
                }
                break;
            case 3:
                visualizar(minhaFila);
                break;
            case 4:
                
                // liberarFila(minhaFila);
                
                printf("\n > Saindo...\n\n");
                break;
            default:
                printf("\n > Opção inválida! Tente novamente.\n");
                break;
        }
    } while (escolha != 4);

    return 0;
}
// ===== FIM DO PROGRAMA PRINCIPAL ===== //


// ----- INÍCIO DA ÁREA DE DEFINÇÃO DAS FUNÇÕES ----- //
/**
 * @brief: Função para criar uma nova fila, encontra espaço na memória e aloca.
 * @return Fila*: retorna um ponteiro do tipo Fila com o endereço de memória alocado.
 */
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

/**
 * @brief: Função para inserir um elemento na fila, aloca memória para o novo nó,
 * guarda o valor dentro do nó e ajusta a fila.
 * 
 * @param fila: deve conter o endereço de memória do tipo Fila já alocado.
 * @param valor: deve conter um valor do tipo inteiro.
 * @return void: sen retorno
 */
void inserir(Fila* fila, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = NULL;
    if (fila->fim == NULL) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
}

/**
 * @brief Função para remover um elemento da fila.
 * 
 * @param fila: deve conter o endereço de memória do tipo Fila já alocado.
 * @return int: retorna o valor inteiro da informação removida.
 */
int remover(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("\n > Fila vazia! Não é possível remover.\n");
        esperarEnter();
        return -1;
    }
    No* temp = fila->inicio;
    int valor = temp->dado;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(temp);
    return valor;
}

/**
 * @brief Função para visualizar os elementos da Fila.
 * 
 * @param fila: deve conter o endereço de memória do tipo Fila já alocado.
 * @return void: sem retorno.
 */
void visualizar(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("\n > Fila vazia!\n");
    }else{
        No* atual = fila->inicio;
        printf("\n > Elementos na fila: \n\n\t");
        while (atual != NULL) {
            printf("%d -> [ %p ]", atual->dado, (void*)atual);
            atual = atual->proximo;
        }
    }
    esperarEnter();
}

/**
 * @brief Função para liberar toda a memória alocada para a fila e cada nó
 * 
 * @param fila: deve conter o endereço de memória da do tipo Fila.
 * @return void: sem retorno
 */
void liberarFila(Fila* fila) {
    // codificar aqui!
}

/**
 * @brief Função para mostrar o menu e obter a escolha do usuário.
 * 
 * @return int: retorna um inteiro contendo a opção escolhida pelo usuário
 */
int mostrarMenu() {
    int escolha;
    system("clear || cls");
    printf("\n### FILA ###\n");
    printf("\n### Menu de Opções ###\n\n");
    printf("\t1. Inserir na fila\n");
    printf("\t2. Remover da fila\n");
    printf("\t3. Visualizar a fila\n");
    printf("\t4. Sair\n\n");
    printf("\tEscolha uma opção: ");
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