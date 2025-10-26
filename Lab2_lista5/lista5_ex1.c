/*Lista 05 - Exercício 1 – Struct simples e acesso a campos
Crie uma struct chamada Aluno com os campos:
● nome (string de até 50 caracteres)
● matrícula (inteiro)
● nota (float)
Peça ao usuário para preencher os dados de 3 alunos e depois exiba os dados na tela.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Alunos
  {
  char nome [51];
  int matricula;
  float nota;
  };
  
 int  main (void)
  {
     struct  Alunos turma1[3];
    int tamVetor = sizeof(turma1) / sizeof(turma1[0]);

    for (int i = 0; i < tamVetor; i++) 
    {   
        for (int j = 0; j < sizeof(turma1[i].nome); j++) 
        {
            turma1[i].nome[j] = '\0';
            
        }
        turma1[i].matricula = 0;
        turma1[i].nota = 0;
    }

    int i = 0;
    while (i < tamVetor) 
    {
        printf("\nInforme o nome do aluno: ");
        fgets(turma1[i].nome, sizeof(turma1[i].nome), stdin);
        
        printf("Informe a matrícula: ");
        scanf("%d", &turma1[i].matricula);
        
        printf("Informe a nota: ");
        scanf("%f", &turma1[i].nota);
        
        getchar();
        i++;
    }
     
    printf("\n ---- Lista de alunos ----\n");
    for (i = 0; i < tamVetor; i++)
    {   
        printf("\n### aluno %d ###\n", i + 1);
        printf(" Nome do aluno: %s\r Matrícula: %d \n Nota: %.2f ", 
                turma1[i].nome, 
                turma1[i].matricula, 
                turma1[i].nota);
            
        printf("\n###############\n");
    }
      
      
      return 0;
  }