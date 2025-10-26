/* Lista 3 - exercício 2. Passagem por referência
Implemente uma função chamada trocar que receba dois inteiros por referência (via
ponteiro) e troque seus valores.
No main, peça ao usuário para digitar dois números, chame a função e mostre os valores
trocados.*/

#include <stdio.h>

   void  trocar(int*point1,int*point2)
  {
     
    int point=*point1;
     *point1=*point2;
     *point2=point;
     
  }
    
 int main ()
    {
    int n1;
    int n2;
        
            printf("insira um número: ");
            scanf("%d", &n1);
       
        
            printf("insira uoutro número: ");
            scanf("%d", &n2);
       
       
            int *point1=&n1;
            int *point2=&n2; 
        
            printf("Valores antes: %d e %d", n1, n2);
       
        
           trocar(&n1, &n2);//passagem por referência (endereços)
        
       
           printf("\nValores depois: %d e %d", n1, n2);
    
    return 0;
    
}