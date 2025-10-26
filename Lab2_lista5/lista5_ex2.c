
/*struct - lista 5 - Exercício 2 – Vetor de struct
Usando a struct Aluno do exercício anterior, armazene os dados de até 100 alunos em um
vetor.
O programa deve permitir:
● Inserir um novo aluno na próxima posição livre
● Listar todos os alunos cadastrados*/


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
     struct  Alunos turma1[100];
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