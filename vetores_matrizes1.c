#include <stdio.h>
int main (void)
{
int vetor1[10];
int i=0;
for (i=0;i<10;i++)
{
    vetor1[i]=i+3;
    printf("%d", vetor1[i]);
}
for (int i=0;i<10;i++)
{
printf("\n vetor1= %d", vetor1[i]);
}
printf("%s", &vetor1);

//vetor recebe string

char vet_str[5];
printf("Digite uma palavra com 5 caracteres: ");
scanf("%s", vet_str); 
printf("Frase lida (scanf): %s\n", vet_str);

for (i=4;i>=0;i--)
{
printf("%c", vet_str[i]);
}
printf("\n)");
//printf("\n %s\n", vet_str);
return 0;
}