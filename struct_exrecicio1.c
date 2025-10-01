/*Exercício 1 – Struct simples e acesso a campos
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
     struct  Alunos turma1;//= {"Joao Silva",1521, 70.5};
      //strcpy (turma1.nome,"Joao Silva");
      //turma1.matricula=2345;
      //turma1.nota=75;
      printf("Digite o nome do aluno\n");
      scanf("%s", turma1.nome);
      printf("Número de matrícula\n");
      scanf ("%d", &turma1.matricula);
      printf(" Nota final: \n");
      scanf("%f", &turma1.nota);
      
      printf("%s,%d,%.2f\n", turma1.nome, turma1.matricula,turma1.nota);
      
      
      
      return 0;
  }