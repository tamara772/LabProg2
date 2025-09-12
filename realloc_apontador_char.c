/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str=NULL; //cria um ponteiro cujo valor inicial (nulo)funciona como endereço para a string str
    int c, len=0;
    printf("Digite uma string (ENTER para terminar): "); //enter=\n
    while ((c=getchar())!='\n' && c!=EOF)
   {
      str=realloc (str,(len+2)*sizeof(char)); //1 char +1 \0

        if (str==NULL)
            {return 1;}
    str[len]=c;
    len ++;
    str[len]='\0'; //manter finalizador, obrigatório para string
} 
   printf("Você digitou: %s", str);
   free (str);
   return 0;

}