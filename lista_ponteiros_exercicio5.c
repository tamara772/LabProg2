/*Lista ponteiros. Exercício 5. Ponteiros para ponteiros
Crie um programa que:
● Declare uma variável inteira x = 99
● Crie um ponteiro p para x
● Crie um ponteiro pp que aponte para p
● Altere o valor de x para 123 usando pp (não use x nem p)
● Imprima o novo valor de x*/

#include <stdio.h>
#include <string.h>

int main() 
{
    int x = 99;      
    int *p = &x;    
    int **pp = &p; //ponteiro para ponteiro **ponteiro

    **pp = 123;      

    printf("Novo valor de x = %d\n", x);

    return 0;
}

/*    **pp = 123;
Primeiro, *pp desreferencia pp → acessa p

Depois, outro * → **pp desreferencia p → acessa x

Por fim, o = 123 altera o valor de x

✅ Então sim, você está desreferenciando *pp para chegar em x.*/