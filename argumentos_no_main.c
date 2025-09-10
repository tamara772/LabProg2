
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("Número de argumento %d\n", argc);
    for (int i=0;i<argc;i++)
    {
        printf("Argumento %d: %s\n", i,argv[i]);
    }

if (argc>2)
{
    int a=atoi(argv[1]);
    int b=atoi(argv[2]);
    printf("Soma de %d+%d=%d\n", a,b, a+b);
}
    if(argc>1)
    {
        if(strcmp(argv[2],"20")==0)//10 pode ser qq cte -p, por exemplo, 
                                 //para encontrar um elemento/limitar o código a uma criptografia
        {
            printf("Entrou");
        }
    }
    
    
    return 0;
}