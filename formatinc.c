#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>


#if ((defined _WIN32) || (defined _WIN64))
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif


void limpar_nome (char original[], char formatado[]){
    // O objetivo é tirar as seguintes letras do nome
}


void formatarNome (char original[], char formatado[]){
    int ult_esp, i, j;

    // Etapa1: Colocar o último sobrenome
    for (ult_esp = strlen(original); original[ult_esp] != ' '; ult_esp--);

    for (i = ult_esp, j = 0; i <= strlen(original); i++, j++)
        formatado[j] = original[i];

    // Etapa2: Pegando a primeira letra
    formatado[j-1] = ',';
    formatado[j] = ' ';
    formatado[++j] = original[0];
    formatado[++j] = '.';
    j++;

    // Etapa3: Pegar os nomes do meio
    for (i = 1; i < ult_esp; i++) {
        if (original[i-1] == ' ' && original[i] != ' ') {
            formatado[j] = ' ';
            formatado[++j] = original[i];
            formatado[++j] = '.';
            j++;
        }
    }
    formatado[++j] = '\0';
}


int main(){
    system (CLEAR);

    char original[255], formatado [255]; // declarando os dois vetores de char
    int i, j; // variáveis auxiliares

    // coletando a string original
    printf ("--> Digite o nome a ser formatado: ");
    scanf ("%[^\n]", original);


    printf ("\t>>> Original: %s", original);

    formatarNome (original, formatado);

    printf ("\n\t>>> Formatado: %s", formatado);

    printf ("\n\n");

    return 0;
}