//slide6_exerc1_fila.c               Aluna: Isabel Tamara Pedron
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó da fila, aquilo que guarda a 
// informação que se deseja e também o endereço do próximo da fila.
typedef struct No {
    //int dado;
    char nome [50];
    int idade;
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
void inserir(Fila* fila, char nome [50], int idade);
int remover(Fila* fila);
void visualizar(Fila* fila);
void liberarFila(Fila* fila);
int mostrarMenu();
void esperarEnter();
// ----- FIM DA ÁREA DE DECLARAÇÃO DAS FUNÇÕES ----- //


// ===== INÍCIO DO PROGRAMA PRINCIPAL ===== //
int main() {
    Fila* minhaFila = criarFila();
    int escolha;
    char nome [50];
    int idade;

    do {
        escolha = mostrarMenu();
        switch (escolha) {
            case 1:
                  printf("\n > Digite uma idade para inserir: ");
                  scanf("%d", &idade);
                while (getchar() != '\n'); // limpa o \n do buffer
                printf("\n > Digite um nome para inserir: ");
                fgets(nome, sizeof(nome), stdin);
                inserir(minhaFila,nome, idade);
                break;
            case 2:
                idade = remover(minhaFila);
                if (idade != -1) {
                    printf("\n > Removido: %d\n", idade);
                    esperarEnter();
                }
                break;
            case 3:
                visualizar(minhaFila);
                break;
            case 4:
                
                liberarFila(minhaFila);
                
                break;
            case 5:                                           
                printf("\n > Saindo...\n\n");
                break;
            
            default:
                printf("\n > Opção inválida! Tente novamente.\n");
                break;
        }
    } while (escolha != 5);

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
void inserir(Fila* fila, char nome [50], int idade) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->nome, nome);
    novoNo->idade=idade;
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
    int idade = temp->idade;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(temp);
    return idade;
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
            //printf("%d -> [%p]", atual->idade, (void*)atual);//elemento e endereço do nó
             printf("\n Nome: %s  Idade: %d", atual->nome, atual->idade);
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
    printf("\t4. Liberar fila\n");
    printf("\t5. Sair\n\n");
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

void liberar_fila(Fila* fila) {
  No* atual = fila->inicio;
  No* proximo;
  while (atual != NULL) {
      proximo = atual->proximo;
      free(atual); // Libera o nó atual
      atual = proximo;
  }
  fila->inicio = NULL;
  fila->fim = NULL;
}

// ----- FIM DA ÁREA DE DEFINÇÃO DAS FUNÇÕES ----- //