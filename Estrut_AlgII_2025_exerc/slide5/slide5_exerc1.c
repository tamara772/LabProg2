//Slide 05:  Exercício 01 - struct carro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char modelo[51];
    char marca[51];
    int ano;
    int transfer;
} carro;


int main(void) {
    carro car[5];
    int tamVetor = sizeof(car) / sizeof(car[0]);

    for (int i = 0; i < tamVetor; i++) 
    {   
        for (int j = 0; j < sizeof(car[i].marca); j++) 
        {
            car[i].marca[j] = '\0';
            car[i].modelo[j] = '\0';
        }
        car[i].ano = 0;
        car[i].transfer = 0;
    }

    int i = 0;
    while (i < tamVetor) 
    {
        printf("\nInforme o modelo: ");
        fgets(car[i].modelo, sizeof(car[i].modelo), stdin);
        printf("Informe a marca: ");
        fgets(car[i].marca, sizeof(car[i].marca), stdin);
        printf("Informe o ano: ");
        scanf("%i", &car[i].ano);
        printf("É transferido? Sim=1 Não=0: ");
        scanf("%i", &car[i].transfer);
        getchar();
        i++;
    }

    printf("\n ---- Carros cadastrados ----\n");
    for (i = 0; i < tamVetor; i++)
    {   
        printf("\n### Carro %d ###\n", i + 1);
        printf(" Modelo: %s\r Marca: %s\r Ano: %i \r É transferido?: %s", 
                car[i].modelo, 
                car[i].marca, 
                car[i].ano,
                //car[i].transfer);
                (car[i].transfer==0)?"Não é transferido":"É transferido");
        printf("\n###############\n");
    }

    return 0;
}