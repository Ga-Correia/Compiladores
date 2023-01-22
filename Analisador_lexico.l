%{
#include "Biblioteca.h"
char *buffer;
int numero;
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
{IF} {return IF;}
{ELSE} {return ELSE;}
{INT} {return INT;}
{RETURN} {return RETURN;}
{VOID} {return VOID;}
{WHILE} {return WHILE;}
{NUM} {
    numero = atoi(yytext); 
    return NUM;
}
{ID} { 
    buffer = strdup(yytext);   
    return ID;
}
{SOM} {return SOM;}
{SUB} {return SUB;}
{MULT} {return MULT;}
{DIV} {return DIV;}
{IGUAL} {return IGUAL;}
{MENOR} {return MENOR;}
{MENORIGUAL} {return MENORIGUAL;}
{MAIOR} {return MAIOR;}
{MAIORIGUAL} {return MAIORIGUAL;}
{DIFERENTE} {return DIFERENTE;}
{IGUALIGUAL} {return IGUALIGUAL;}
{ABR_COLCH} {return ABR_COLCH;}
{FECH_COLCH} {return FECH_COLCH;}
{ABR_PAR} {return ABR_PAR;}
{FECH_PAR} {return FECH_PAR;}
{ABR_CHV} {return ABR_CHV;}
{FECH_CHV} {return FECH_CHV;}
{PONTOVIRGULA} {return PEV;}
{VIRGULA} {return VG;}
{COMENTARIO} {
    for(i=0; i<strlen(yytext); i++){
        if(yytext[i]=='\n'){
            num_linha++;
        }
    }
}
{LINHA} {num_linha++;}
[ \s\t]
<<EOF>> {return EOF;} 
. printf("ERRO LÉXICO: %s LINHA: %d", yytext, num_linha); exit(-1);
%%

TOKEN PegaTok(void){
    static int primeira_vez= 1;
    TOKEN tok;
    if(primeira_vez==1){
        yyin= arquivo;
        yyout= stdout;
        num_linha++;
        primeira_vez= 0;
    }
    tok = yylex();
    return tok;
}
