/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
 void dobrar(int *n)//espera um ponteiro
   { *n= *n*2;
   }
int main()
{
    int x=10;
    int *px;// ponteiro para int x
    px=&x;
    printf("valor de x: %d\n",x);
    printf("endereço de x: %p\n",&x);
    printf("valor armazenado de x: %p\n",px);
    printf("valor apontado po px : %d\n",*px);
   
    int valor=5;
    printf("Antes: %d",valor);
    dobrar(&valor);//passa o e-comercial na variável porque a função espera um ponteiro
    printf("\nDepois: %d\n", valor);
    return 0;
}
    
   
   
    
    
    
    
    
    

    
    
    
    
    
    
    
    
