%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num_linha=0;
int i;
%}
LINHA \n
DIGITO [0-9]
NUM {DIGITO}+
LETRA [a-zA-Z]
ID {LETRA}+
COMENTARIO \/\*[^\*\/]*\*\/
OP_ARTM \+|\-|\*|\/|\=
OP_REL \<|\<\=|\>|\>\=|\=\=|\!\=
COLCHETE_P \{
COLCHETE_F \}
PARENTESE_P \(
PARENTESE_F \)
CHAVE_P \[
CHAVE_F \]
RESERVADA else|if|int|return|void|while
VIRGULA ,
PONTOVIRGULA ;
%%
{NUM} printf("< NUM: %s >", yytext);
{RESERVADA} printf("< RVD: %s >", yytext);
{ID} printf("< ID: %s >", yytext);
{OP_ARTM} printf("< OP_ARTM: %s >", yytext);
{OP_REL} printf("< OP_REL: %s >", yytext);
{COLCHETE_P} printf("< COLCH_P: %s >", yytext);
{COLCHETE_F} printf("< COLCH_F: %s >", yytext);
{PARENTESE_P} printf("< PARENT_P: %s >", yytext);
{PARENTESE_F} printf("< PARENT_F: %s >", yytext);
{CHAVE_P} printf("< CHV_P: %s >", yytext);
{CHAVE_F} printf("< CHV_F: %s >", yytext);
{PONTOVIRGULA} printf("< PEV: %s >", yytext);
{VIRGULA} printf("< VG: %s >", yytext);
{COMENTARIO} {
    for(i=0; i<strlen(yytext); i++){
        if(yytext[i]=='\n'){
            ++num_linha;
            printf(" Linha %d%c", num_linha, yytext[i]);
        }else{
            printf("%c", yytext[i]);
        }
    }
}
{LINHA} printf(" Linha %d%s", ++num_linha, yytext); 
[ \s\t]
<<EOF>> return printf(" Linha %d ", ++num_linha);
. printf("Erro: %s Linha: %d", yytext, ++num_linha); fflush(stdout);exit(-1);
%%
int main(int argc, char *argv[]){
    FILE *arquivo;

    if(argc==2){
        if(arquivo = fopen(argv[1],"r")){
            yyin = arquivo;
        }else{
            perror(argv[0]);
        }
    }else{
        yyin = stdin;
    }
    yylex();
    return 0;
}
