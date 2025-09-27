
//entrada por linhas de comando: arg1 arg2 arg3 etc arg0 é o nome do arquivo do programa
//no exercicio: write/append/read    arquivo1.txt    " qualquer coisa"

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

//funcoes
void write_text(const char *filename, const char *text;

void append_text(const char *filename, const char *text;

void read_text(const char *filename);


int main(int argc, char *argv[])
{
    printf("Número de argumento %d\n", argc);
    for (int i=0;i<argc;i++)
    {
        printf("Argumento %d: %s\n", i,argv[i]);
    }

       if(strcmp(argv[1],"write")==0);
    {
       write_text (argv[2], argv[3]);
    }
       else
       {
       append_text (argv[2], argv[3]);//else if para lleitura etc
    }

}  
    
    return 0;
}

//funcoes definidas
void write_text(const char *filename, const char *text) {
    FILE *f = fopen(filename, "w"); // "w" cria ou sobrescreve
    if (!f) {
        perror("Erro ao abrir arquivo para escrita");
        return;
    }
    fprintf(f, "%s\n", text);
    fclose(f);
}

void append_text(const char *filename, const char *text) {
    FILE *f = fopen(filename, "a"); // "a" abre para append
    if (!f) {
        perror("Erro ao abrir arquivo para append");
        return;
    }
    fprintf(f, "%s\n", text);
    fclose(f);
}

void read_text(const char *filename) /* Lê todo o arquivo de texto e imprime na tela */
{

    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("Erro ao abrir arquivo para leitura");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), f)) {
        printf("%s", buffer); // fgets já traz o '\n' se houver
    }

    if (ferror(f)) {
        perror("Erro durante a leitura");
    }

    fclose(f);
}
