%{
#include <stdio.h>
#include <stdlib.h>
#include "sintatico.tab.h"
extern YYSTYPE yylval;
int num_linha=0;
int i;
%}
LINHA \n 
DIGITO [0-9]
NUM {DIGITO}+
LETRA [a-zA-Z]
ID {LETRA}+
COMENTARIO \/\*[^\*\/]*\*\/
SOM \+
SUB \-
MULT \*
DIV \/
IGUAL \=
MENOR \<
MENORIGUAL \<\=
MAIOR \>
MAIORIGUAL \>\=
IGUALIGUAL \=\=
DIFERENTE \!\=
ABR_COLCH \{
FECH_COLCH \}
ABR_PAR \(
FECH_PAR \)
ABR_CHV \[
FECH_CHV \]
IF if
ELSE else
INT int
RETURN return
VOID void
WHILE while
VIRGULA ,
PONTOVIRGULA ;
%%
{IF} {
    /*yylval = strdup(yytext);*/
    /*printf("< RVD: %s >", yytext);*/
    /*return IF;*/
}
{ELSE} {
    /*yylval = strdup(yytext);*/
    /*printf("< RVD: %s >", yytext);*/
    /*return ELSE;*/
}
{INT} {
    /*yylval = strdup(yytext);*/
    /*printf("< RVD: %s >", yytext);*/
    /*return INT;*/
}
{RETURN} {
    /*yylval = strdup(yytext);*/
    /*printf("< RVD: %s >", yytext);*/
    /*return RETURN;*/
}
{VOID} {
    /*yylval = strdup(yytext);*/
    /*printf("< RVD: %s >", yytext);*/
    /*return VOID;*/
}
{WHILE} {
    /*yylval = strdup(yytext);*/
    /*printf("< RVD: %s >", yytext);*/
    /*return WHILE;*/
}
{NUM} {
    yylval.number = atoi(yytext);
    printf("< NUM: %s >", yytext); 
    return NUM;
}
{ID} {
    yylval.str = strdup(yytext);
    printf("< ID: %s >", yytext);
    return ID;
}
{SOM} {
    yylval.opr = atoi(yytext);
    printf("< OP_ARTM: %s >", yytext);
    return SOM;
}
{SUB} {
    yylval.opr = atoi(yytext);
    printf("< OP_ARTM: %s >", yytext);
    return SUB;
}
{MULT} {
    yylval.opr = atoi(yytext);
    printf("< OP_ARTM: %s >", yytext);
    return MULT;
}
{DIV} {
    yylval.opr = atoi(yytext);
    printf("< OP_ARTM: %s >", yytext);
    return DIV;
}
{IGUAL} {
    /*yylval = strdup(yytext);*/
    printf("< OP_ARTM: %s >", yytext);
    return IGUAL;
}
{MENOR} {
    yylval.opr = atoi(yytext);
    printf("< OP_REL: %s >", yytext);
    return MENOR;
}
{MENORIGUAL} {
    yylval.opr = atoi(yytext);
    printf("< OP_REL: %s >", yytext);
    return MENORIGUAL;
}
{MAIOR} {
    yylval.opr = atoi(yytext);
    printf("< OP_REL: %s >", yytext);
    return MAIOR;
}
{MAIORIGUAL} {
    yylval.opr = atoi(yytext);
    printf("< OP_REL: %s >", yytext);
    return MAIORIGUAL;
}
{DIFERENTE} {
    yylval.opr = atoi(yytext);
    printf("< OP_REL: %s >", yytext);
    return DIFERENTE;
}
{IGUALIGUAL} {
    yylval.opr = atoi(yytext);
    printf("< OP_REL: %s >", yytext);
    return IGUALIGUAL;
}
{ABR_COLCH} {
    /*yylval = strdup(yytext);*/ 
    printf("< ABR_COLCH: %s >", yytext); 
    return ABR_COLCH;
}
{FECH_COLCH} {
    /*yylval = strdup(yytext);*/ 
    printf("< FECH_COLCH: %s >", yytext); 
    return FECH_COLCH;
}
{ABR_PAR} {
    /*yylval = strdup(yytext);*/
    printf("< ABR_PAR: %s >", yytext);
    return ABR_PAR;    
}
{FECH_PAR} {
    /*yylval = strdup(yytext);*/
    printf("< FECH_PAR: %s >", yytext);
    return FECH_PAR;    
}
{ABR_CHV} {
    /*yylval = strdup(yytext);*/
    printf("< ABR_CHV: %s >", yytext);
    /*return ABR_CHV;*/    
}
{FECH_CHV} {
    /*yylval = strdup(yytext);*/
    printf("< FECH_CHV: %s >", yytext);
    /*return FECH_CHV;*/
}
{PONTOVIRGULA} {
    /*yylval = strdup(yytext);*/
    printf("< PEV: %s >", yytext);
    /*return PEV*/
}
{VIRGULA} {
    /*yylval = strdup(yytext);
    printf("< VG: %s >", yytext);
    return VG;*/
}
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
{LINHA} {
    printf(" Linha %d%s", ++num_linha, yytext);
    return LINHA;   
}
[ \s\t]
<<EOF>> printf(" Linha %d ", ++num_linha); exit(-1); return NULO; 
. printf("Erro: %s Linha: %d", yytext, ++num_linha); fflush(stdout);exit(-1);
%%
/*int main(int argc, char *argv[]){
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
}*/
