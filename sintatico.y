%{
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin, *yyout;
int yylex();
int yyparse(void);
void yyerror(char *);
%}

%name parse
%start entrada
%token ID NUM LINHA NULO
%left SOM
%left SUB
%left MULT
%left DIV
%left IGUAL
%left MENOR MENORIGUAL MAIOR MAIORIGUAL DIFERENTE IGUALIGUAL
%token ABR_PAR FECH_PAR ABR_COLCH FECH_COLCH

%union{
    int number;
    char *str;
    int opr;
};
%type <number> expressao simplesexpressao somaexpressao termo fator NUM 
%type <identificador> ID
%type <opr> relacional soma mult SOM SUB MULT DIV MENOR MENORIGUAL MAIOR MAIORIGUAL IGUALIGUAL DIFERENTE 

%%
entrada: | entrada expressao;

expressao: LINHA |simplesexpressao LINHA {printf("Resultado: %d\n", $1);} | error LINHA{yyerrok;};

/*var: ID 
   | ID ABR_CHV expressao FECH_CHV */

simplesexpressao: somaexpressao relacional somaexpressao {
    if($2 == 0){
        $$ = $1 <= $3;
    }else if($2 == 1){
        $$ = $1 < $3;
    }else if($2 == 2){
        $$ = $1 > $3;
    }else if($2 == 3){
        $$ = $1 >= $3;
    }else if($2 == 4){
        $$ = $1 == $3;
    }else if($2 == 5){
        $$ = $1 != $3;
    }
}
         | somaexpressao {$$ = $1;};

relacional: MENORIGUAL {$$ = $1;} | MENOR {$$ = $1+1;}| MAIOR {$$ = $1+2;}
          | MAIORIGUAL {$$ = $1+3;}| IGUALIGUAL {$$ = $1+4;}| DIFERENTE {$$ = $1+5;};

somaexpressao: somaexpressao soma termo {
    if($2 == 0){
        $$ = $1 + $3;
    }else if($2 == 1){
        $$ = $1 - $3;
    }
}
             | termo {$$ = $1;};

soma: SOM {$$ = $1;}
    | SUB {$$ = $1+1;};

termo: termo mult fator {
    if($2 == 0){
        $$ = $1 * $3;
    }else if($2 == 1){
        $$ = $1 / $3;
    }
}
     | fator {$$ = $1;};

mult: MULT {$$ = $1;}
    | DIV {$$ = $1+1;}; 

fator: ABR_PAR somaexpressao FECH_PAR {$$ = $2;}
     | NUM {$$ = $1;};

/*ativação: ID ABR_PAR args FECH_PAR;

args: arg-lista 
    |  vazio;

arg-lista: arg-listaVGexpressão 
         | expressão;*/

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
    return yyparse();
}
void yyerror(char *msg){
    fprintf(stderr, "Erro: %s\n", msg);
}