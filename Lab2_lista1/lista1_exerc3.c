/* Lista 1 exercício 3
7.	Receba um número e diga se é positivo, negativo ou zero.
8.	Receba dois números e diga qual é o maior.
9.	Verifique se um aluno foi aprovado:
- Média >= 7 → Aprovado
- Média >= 5 → Recuperação
- Senão → Reprovado*/

#include <stdio.h>
int main (void)
{
    
    int n3= -30;
    if (n3==0)
    { printf("\nO valor do número é zero");
    }
    else 
        {
        if  (n3<0)
          {
          printf("\n%d é negativo", n3);
          }
       else 
        {
        printf("\n%d é positivo", n3);
        }
        }
     int n4=30, n5=12;
     if ((n4-n5)==0)
     {
         printf("\n%d é igual a %d", n4,n5);
     }
     if ((n4-n5)>0)
     {
         printf("\n%d é maior que %d", n4,n5);
     }
       if ((n4-n5)<0)
       {printf("\n%d é menor que %d", n4,n5);
     }
     
   float p1=7.0, p2=8.0, p3=4.0;
   float media;
   media=(p1+p2+p3)/3;
   if (media>=7)
      {
      printf("\nA média é %.2f e o aluno está aprovado.", media);
      }
    else if (media>5 && media<7)
      {
      printf("\nA média é %.2f e o aluno está em recuperação.", media);
      }
       else
      {
       printf("\nA média é %.2f e o aluno está reprovado.", media);
      }
}