
/*4. Ponteiros e strings.Faça um programa que:
● Leia uma string (até 50 caracteres)
● Conte o número de vogais usando ponteiros para percorrer a string
● Mostre o resultado*/

#include <stdio.h>
#include <string.h>

int main ()
{
char str [50];
printf(" Insira uma string de no máximo 50 caracteres: ");
fgets(str, sizeof(str), stdin);
str[strcspn(str, "\n")] = '\0';//enter finaliza a string então atribuo o '\0' para a str
printf("String:  %s\n", str);
char *point = str; 

int cont=0;


char vogais[]="aeiouAEIOU";

 while (*point != '\0') 
       {  
        for (int i = 0; vogais[i] != '\0'; i++) 
           {
            if (*point == vogais[i]) 
              {
                cont++;
                break;  //para sair do laço e não ficar comparando com todas as vogais toda vez
              }
            }
        point++;  
       }

 
printf("O número de vogais é %d:  ", cont);
  

return 0;
}