//slide6_exerc2_pilha.c               Aluna: Isabel Tamara Pedron

/*EStudar o código pilha.c e alterar o nó para que tenha um salário, 
a função do funcionário (enum:comum, supervisor, gerente) e uma taxa de seguro*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    COMUM,
    SUPERVISOR,
    GERENTE
} Funcao;


typedef struct No {
    int dado;
    float salario;
    Funcao tipo;
    float taxa; 
    struct No* proximo;
} No;

typedef struct {
    No* topo;
} Pilha;

// ----- INÍCIO DA ÁREA DE DECLARAÇÃO DAS FUNÇÕES ----- //
Pilha* criarPilha();
void empilhar(Pilha* pilha, float salario, Funcao tipo, float taxa);
//int desempilhar(Pilha* pilha);
void visualizar(Pilha* pilha);
void liberarPilha(Pilha* pilha);
int mostrarMenu();
void esperarEnter();
// ----- FIM DA ÁREA DE DECLARAÇÃO DAS FUNÇÕES ----- //


// ===== INÍCIO DO PROGRAMA PRINCIPAL ===== //
int main() {
    Pilha* minhaPilha = criarPilha();
    int escolha, valor;

    do {
        escolha = mostrarMenu();
        switch (escolha) {
            case 1:
                float salario=0;
                printf("\n > Insira valor  para  salário: \n");
                scanf("%f", &salario);
                char tipo_funcao[20];
               printf("\n > Insira uma função:COMUM/SUPERVISOR/GERENTE \n");
                scanf("%s", &tipo_funcao);
                
                  Funcao tipo;

               if (strcmp(tipo_funcao, "COMUM") == 0) 
               {   tipo = COMUM;}
               else if (strcmp(tipo_funcao, "SUPERVISOR") == 0) 
               {   tipo = SUPERVISOR; } 
               else if (strcmp(tipo_funcao, "GERENTE") == 0) 
               {   tipo = GERENTE;} 
               else 
               {
               printf("Tipo inválido!");
        }

               float taxa=0;
               
               printf("\n > Insira o valor para a taxa de seguro:\n");
               scanf("%f", &taxa);
               empilhar(minhaPilha, salario,tipo,taxa);
                break;
            
            case 2:
                /*valor = desempilhar(minhaPilha);
                if (valor != -1) {
                    printf("\n > Desempilhado: %d\n", valor);*/
               {     printf("Não implementado\n");
                    esperarEnter();
                }
                break;
            case 3:
                visualizar(minhaPilha);
                break;
            case 4:
                liberarPilha(minhaPilha);
                break;
            case 5:
                printf("\n > Saindo...\n\n");
                break;
            default:
                printf("\n > Opção inválida! Tente novamente.\n");
                esperarEnter();
                break;
        }
    } while (escolha != 5);

    return 0;
}
// ===== FIM DO PROGRAMA PRINCIPAL ===== //


// ----- INÍCIO DA ÁREA DE DEFINÇÃO DAS FUNÇÕES ----- //
/**
 * @brief Função para criar a variável que faz a gerência da pilha.
 * 
 * @return Pilha*: retorna um ponteiro do tipo Pilha com o endereço de memória alocado.
 */
Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

/**
 * @brief Função para empilhar (inserir / push) um nó na pilha.
 * 
 * @param pilha: deve conter o endereço de memória do tipo Pilha já alocado.
 * @param valor: deve conter um valor do tipo inteiro.  
 */
/*void empilhar(Pilha* pilha, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}*/
void empilhar(Pilha *pilha, float salario, Funcao tipo, float taxa) {
    No *novo = (No*) malloc(sizeof(No));
    novo->salario = salario;
    novo->tipo = tipo;
    novo->taxa = taxa;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

/**
 * @brief Função para desempilhar/remover/pop um nó da pilha.
 * 
 * @param pilha: deve conter o endereço de memória do tipo Pilha já alocado.
 * @return int: retorna o valor inteiro da informação removida.
 */
int desempilhar(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("\n > Pilha vazia! Não é possível desempilhar.\n");
        return -1;
    }
    No* temp = pilha->topo;
    int valor = temp->dado;
    pilha->topo = pilha->topo->proximo;
    free(temp);
    return valor;
}

/**
 * @brief Função para visualizar os elementos da pilha.
 * 
 * @param pilha: deve conter o endereço de memória do tipo Pilha já alocado.
 * @return void: sem retorno.
 */
/*void visualizar(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("\n > Pilha vazia!\n");
    }else{
        No* atual = pilha->topo;
        printf("\n > Elementos na pilha: \n\n >");
        while (atual != NULL) {
            printf("\t%d \n", atual->dado);
            atual = atual->proximo;
        }
    }
    esperarEnter();
}*/

void visualizar(Pilha* pilha) {
    const char* tipoFuncao[] = {"COMUM", "SUPERVISOR", "GERENTE"};

    if (pilha->topo == NULL) {
        printf("\n > Pilha vazia!\n");
    } else {
        No* atual = pilha->topo;
        printf("\n > Elementos na pilha:\n\n >");
        while (atual != NULL) {
            printf(" Salário: %.2f - Tipo: %s  - Taxa: %.2f\n",
                   atual->salario,
                   tipoFuncao[atual->tipo],
                   atual->taxa);
            atual = atual->proximo;
        }
    }
 esperarEnter();
    
}
/**
 * @brief Função para liberar toda a memória alocada para a pilha e seus nós.
 * 
 * @param pilha: deve conter o endereço de memória do tipo Pilha já alocado.
 * @return void: sem retorno.
 */
void liberarPilha(Pilha* pilha) 
{
  No* atual = pilha->topo;
  No* proximo;
  while (atual != NULL) 
  {
    proximo = atual->proximo;
    free(atual); // Libera o nó atual
    atual = proximo;
  }
  pilha->topo = NULL;
  printf("\n Pilha liberada \n");
  esperarEnter();
}

/**
 * @brief Função para mostrar o menu e obter a escolha do usuário.
 * 
 * @return int: retorna um inteiro contendo a opção escolhida pelo usuário
 */
int mostrarMenu() {
    int escolha;
    system("clear || cls");
    printf("\n### PILHA ###\n");
    printf("\n### Menu de Opções ###\n\n");
    printf("\t1. Empilhar\n");
    printf("\t2. Desempilhar\n");
    printf("\t3. Visualizar a pilha\n");
    printf("\t4. Liberar a pilha\n");
    printf("\t5. Sair\n\n");
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