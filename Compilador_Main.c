#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

/*Globais necessarias alocadas*/
int num_linha= 0;
FILE *arquivo;
int ERROR;


int main(int argc, char **argv){
    arquivo= fopen(argv[1], "r");
    if(arquivo==NULL){
        printf("Arquivo nao encontrado");
    }

    printf("\n-----Compilacao do Codigo------\n");
    printf("-------------------------------ANALISE LEXICA--------------------------------------\n\n");
    PrintaTokens(argv[1]);
    fclose(arquivo);
    arquivo= fopen(argv[1], "r");
    num_linha= 1;

    ArvoreNO* arvoreSintat;
    arvoreSintat = parse();
    printf("\n\n-----------------------------ANALISE SINTATICA---------------------------------\n\n");
    if(!ERROR){
        PrintaArvore(arvoreSintat);
    }
    printf("\n\n-------------------------------ANALISE SEMANTICA-------------------------------\n\n");
    MontaTabela(arvoreSintat);
    fclose(arquivo);
    return 0;
}
