#include <stdio.h>
int main (void)
{
 float somanotas=0;
     int cont=0;
     float nota=1;
     while (nota!=0)
     {
         printf("\n Nota do aluno: ");
       scanf ("%f", &nota);
       somanotas=somanotas+nota;
       cont=cont+1;
     }
     
     //float p1=70.0, p2=80.0, p3=50.0; 
   float media=0;
   media=somanotas/(cont-1);
   if (media>=70)
   {
      printf("\n A média é %.2f e o aluno está aprovado.", media);
   }
   if (40<=media && media<70)
   {
       printf("\n A média é %.2f e o aluno está em exame.", media);
   }
   else 
   { 
       printf("\n A média é %.2f e o aluno está aprovado.", media);
       
   }
   return 0;

}


