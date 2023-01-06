%{
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin, *yyout;
int yylex();
int yyparse(void);
void yyerror(char *s);
%}
%name parser

%union{
    int number;
    char *str;
    int opr;
};

%token IF ELSE INT RETURN VOID WHILE LINHA VG PEV
%token ID
%token NUM
%token SOM SUB MULT DIV IGUAL
%token MENOR MENORIGUAL MAIOR MAIORIGUAL DIFERENTE IGUALIGUAL
%token ABR_COLCH FECH_COLCH ABR_PAR FECH_PAR ABR_CHV FECH_CHV

%type <str> ID
%type <number> NUM
%type <opr> SOM SUB MULT DIV IGUAL MENOR MENORIGUAL MAIOR MAIORIGUAL DIFERENTE IGUALIGUAL
%type <str> VG PEV

%%

programa: declaracaolista ;

declaracaolista: declaracaolista declaracao | declaracao ;

declaracao: vardeclaracao | fundeclaracao ;

vardeclaracao: tipoespecificador ID PEV | tipoespecificador ID ABR_CHV NUM FECH_CHV PEV ;

tipoespecificador: INT | VOID ;

fundeclaracao: tipoespecificador ID ABR_PAR params FECH_PAR compostodecl ;

params: paramlista | VOID ;

paramlista: paramlista VG param | param ;

param: tipoespecificador ID | tipoespecificador ID ABR_CHV FECH_CHV ;

compostodecl: ABR_COLCH localdeclaracoes statementlista FECH_COLCH ;

localdeclaracoes: localdeclaracoes vardeclaracao | vazio ;

statementlista: statementlista statement | vazio ;

statement: expressaodecl | compostodecl | selecaodecl | iteracaodecl | retornodecl ;

expressaodecl: expressao PEV | PEV ;

selecaodecl: IF ABR_PAR expressao FECH_PAR statement 
           | IF ABR_PAR expressao FECH_PAR statement ELSE statement ;

iteracaodecl: WHILE ABR_PAR expressao FECH_PAR statement ;

retornodecl: RETURN PEV | RETURN expressao PEV ;

expressao: var IGUAL expressao | simplesexpressao ;

var: ID | ID ABR_CHV expressao FECH_CHV ;

simplesexpressao: somaexpressao relacional somaexpressao | somaexpressao ;

relacional: MENORIGUAL | MENOR | MAIOR | MAIORIGUAL | IGUALIGUAL | DIFERENTE ;

somaexpressao: somaexpressao soma termo | termo ;

soma: SOM | SUB ;

termo: termo mult fator | fator ;

mult: MULT | DIV ;

fator: ABR_PAR expressao FECH_PAR | var | ativacao | NUM ;

ativacao: ID ABR_PAR args FECH_PAR ;

args: arglista | vazio ;

vazio: ;

arglista: arglista VG expressao | expressao ;

%%

int main(int argc, char **argv){
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
    yyparse();
    fclose(yyin);
    return 0;
}
void yyerror(char *msg){
    fprintf(stderr, "Erro: %s\n", msg);
}