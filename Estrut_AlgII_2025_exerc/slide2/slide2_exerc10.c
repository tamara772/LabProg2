//slide2 exercício 10
/*10) A importância de R$ 780.000,00 será dividida entre três ganhadores de um concurso, sendo que:
i. O primeiro ganhador receberá 46% do total.
ii. O segundo receberá 32% do total.
iii. O terceiro receberá o restante.Calcule e imprima a quantia recebida por cada um dos ganhadores.*/

#include <stdio.h>

int main ()
{
float valor=780000;

printf(" ## Valor total do prêmio : 780.000,00 ##\n");
printf("O ganhador 1 recebe 46 por cento do total com um valor de: %.2f\n", 780000*0.46);

printf("O ganhador 2 recebe 32 por cento do total com um valor de: %.2f\n", 780000*0.32);

printf("O ganhador 3 recebe 22 por cento do total com um valor de: %.2f\n", 780000*0.22);

return 0;
}