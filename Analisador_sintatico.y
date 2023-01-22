%{
#define YYPARSER
#include "Biblioteca.h"
#define YYSTYPE ArvoreNO*
static ArvoreNO* salvaArvore;
static Pilha Funcao; // para uso em funções
static int pilha_Inicializada = 0; // já inicializada pilha
static char *Func_decl; // para uso em declaracao de funções
static char *Var_salvo; // para uso em atribuições
static char *ID_salvo; // para uso geral em IDs
static int Linha_salva;
static int Linha_salvaF;
static int yylex();
int yyerror(char *msg);
%}

%start programa
%token IF ELSE INT RETURN VOID WHILE VG PEV 
%token ID NUM
%token SOM SUB MULT DIV IGUAL MENOR MENORIGUAL MAIOR MAIORIGUAL DIFERENTE IGUALIGUAL ABR_COLCH FECH_COLCH ABR_PAR FECH_PAR ABR_CHV FECH_CHV

%%

programa: declaracaolista {salvaArvore = $1;};

declaracaolista: declaracaolista declaracao{
    YYSTYPE t = $1;   // adiciona os nos como irmãos por recursividade a esquerda
    if(t!=NULL){
        while(t->filho[0]->irmao != NULL){
            t = t->filho[0]->irmao;
        }
        t->filho[0]->irmao = $2;
        $$ = $1;
    }else{
        $$ = $2;
    }
}               | declaracao {$$ = $1;};

declaracao: vardeclaracao {$$ = $1;} | fundeclaracao {$$ = $1;};

vardeclaracao: tipoespecificador ID {
    ID_salvo = strdup(buffer);
    free(buffer);
    Linha_salva = num_linha;
} PEV {
    $$ = $1;
    YYSTYPE vard;
    vard = CriaNoDecl(var_K);
    vard->Atribuicao.nome = ID_salvo;
    vard->linha = Linha_salva;
    vard->tipo = $1->tipo;
    $$->filho[0] = vard;
}            
            | tipoespecificador ID {
    ID_salvo = strdup(buffer);
    free(buffer);
    Linha_salva = num_linha;
} ABR_CHV NUM FECH_CHV PEV{
    $$ = $1;
    YYSTYPE indice = CriaNoExp(NUM_K);
    indice->Atribuicao.valor = numero;
    indice->tipo = Integer;
    YYSTYPE vard = CriaNoDecl(var_K);
    vard->Atribuicao.nome = ID_salvo;
    vard->linha = Linha_salva;
    vard->filho[0] = indice;
    if($1->tipo == Integer){
        vard->tipo = Array;
    }else{
        vard->tipo = Void;
    }
    $$->filho[0] = vard;
};

tipoespecificador: INT{
    $$ = CriaNoDecl(tipo_K); // cria o nó para o tipo
    $$->tipo = Integer; 
}                | VOID{
    $$ = CriaNoDecl(tipo_K); // cria o nó para o tipo
    $$->tipo = Void; 
};

fundeclaracao: tipoespecificador ID {
    Func_decl = strdup(buffer);
    free(buffer);
    Linha_salvaF = num_linha;
} ABR_PAR params FECH_PAR compostodecl{
    $$ = $1;
    YYSTYPE func = CriaNoDecl(func_K);
    func->filho[0] = $5;
    func->filho[1] = $7;
    func->Atribuicao.nome = Func_decl;
    func->linha = Linha_salvaF;
    func->tipo = $1->tipo;
    $$->filho[0] = func;
};

params: paramlista{
    $$ = $1;  //$$->filho[0] = $1;
}     | VOID{
    $$ = CriaNoExp(ID_K); 
    $$->Atribuicao.nome = "void"; 
    $$->tipo = Void;
};

paramlista: paramlista VG param{
    YYSTYPE t = $1;   // adiciona os nos como irmãos
    if(t!=NULL){
        while(t->irmao!=NULL){
            t = t->irmao;
        }
        t->irmao = $3;
        $$ = $1;
    }else{
        $$ = $3;
    }
}         | param {$$ = $1;};

param: tipoespecificador ID {
    $$ = $1;
    ID_salvo = strdup(buffer);
    free(buffer);
    Linha_salva = num_linha;
    YYSTYPE par;
    par = CriaNoDecl(var_K);
    par->Atribuicao.nome = ID_salvo;
    par->linha = Linha_salva;
    par->tipo = $1->tipo;
    $$->filho[0] = par;
}    
    | tipoespecificador ID{
    ID_salvo = strdup(buffer);
    free(buffer);
    Linha_salva = num_linha;
} ABR_CHV FECH_CHV{
    $$ = $1;
    YYSTYPE par;
    par = CriaNoDecl(var_K);
    par->Atribuicao.nome = ID_salvo;
    par->linha = Linha_salva;
    if($1->tipo == Integer){
        par->tipo = Array;
    }else{
        par->tipo = $1->tipo;
    }
    $$->filho[0] = par;
};

compostodecl: ABR_COLCH localdeclaracoes statementlista FECH_COLCH{
    { YYSTYPE t = $2;  // adiciona os nós como irmãos
      if(t!=NULL){
        while(t->irmao!=NULL){
            t = t->irmao;
        }
        t->irmao = $3;
        $$ = $2;
       }else{
        $$ = $3;
       }
    }      
};

localdeclaracoes: localdeclaracoes vardeclaracao{
    YYSTYPE t = $1;    // adiciona os nos como irmãos
    if(t!=NULL && t->Atribuicao.nome!="sem_local_decl"){
        while(t->irmao != NULL){
            t = t->irmao;
        }
        t->irmao = $2;
        $$ = $1;
    }else{
        $$ = $2;
    }
}               | %empty {$$ = NULL;};

statementlista: statementlista statement{
    YYSTYPE t = $1;
    // adiciona os nós como irmãos
    if(t!=NULL){
        while(t->irmao!=NULL){
            t = t->irmao;
        }
        t->irmao = $2;
        $$ = $1;
    }else{
        $$ = $2;
    }
}             | %empty {$$ = NULL;};

statement: expressaodecl{$$ = $1;} | compostodecl{$$ = $1;} | selecaodecl{$$ = $1;} | iteracaodecl{$$ = $1;} | retornodecl{$$ = $1;};

expressaodecl: expressao PEV {$$ = $1;} | PEV{$$ = NULL;};

selecaodecl: IF ABR_PAR expressao FECH_PAR statement{
    $$ = CriaNoStmt(if_K);
    $$->filho[0] = $3;
    $$->filho[1] = $5;
} 
           | IF ABR_PAR expressao FECH_PAR statement ELSE statement{
    $$ = CriaNoStmt(if_K);
    $$->filho[0] = $3;
    $$->filho[1] = $5;
    $$->filho[2] = $7;
};

iteracaodecl: WHILE ABR_PAR expressao FECH_PAR statement{
    $$ = CriaNoStmt(while_K);
    $$->filho[0] = $3;
    $$->filho[1] = $5;
};

retornodecl: RETURN PEV{$$ = CriaNoStmt(return_K);} | RETURN expressao PEV{
    $$ = CriaNoStmt(return_K);
    $$->filho[0] = $2;
};

expressao: var IGUAL expressao{
    $$ = CriaNoStmt(atrib_K);
    $$->filho[0] = $1;
    $$->filho[1] = $3;
    $$->tipo = Integer;
    $$->Atribuicao.op = IGUAL;
}        | simplesexpressao {$$ = $1;};

var: ID{
    ID_salvo = strdup(buffer);
    free(buffer);
    Linha_salva = num_linha;
    $$ = CriaNoExp(ID_K);
    $$->Atribuicao.nome = ID_salvo;
    $$->linha = Linha_salva;
    $$->tipo = Void;
}  
    | ID{
    Var_salvo = strdup(buffer);
    free(buffer);
    Linha_salva = num_linha;
} ABR_CHV expressao FECH_CHV{
    $$ = CriaNoExp(ID_K);
    $$->Atribuicao.nome = Var_salvo;
    $$->linha = Linha_salva;
    $$->filho[0] = $4;
    $$->tipo = Integer; //certeza. v[]
};

simplesexpressao: somaexpressao relacional somaexpressao{
    $$ = CriaNoExp(OP_K);
    $$->filho[0] = $1;
    $$->filho[1] = $3;
    $$->Atribuicao.op = $2->Atribuicao.op; //token recebido pelo relacional
}               | somaexpressao {$$ = $1;};

relacional: MENORIGUAL{$$ = CriaNoExp(ID_K); $$->Atribuicao.op = MENORIGUAL;} 
          | MENOR{$$ = CriaNoExp(ID_K); $$->Atribuicao.op = MENOR;} 
          | MAIOR{$$ = CriaNoExp(ID_K); $$->Atribuicao.op = MAIOR;} 
          | MAIORIGUAL{$$ = CriaNoExp(ID_K); $$->Atribuicao.op = MAIORIGUAL;} 
          | IGUALIGUAL{$$ = CriaNoExp(ID_K); $$->Atribuicao.op = IGUALIGUAL;} 
          | DIFERENTE{$$ = CriaNoExp(ID_K); $$->Atribuicao.op = DIFERENTE;};

somaexpressao: somaexpressao soma termo{
    $$ = CriaNoExp(OP_K);
    $$->filho[0] = $1;
    $$->filho[1] = $3;
    $$->Atribuicao.op = $2->Atribuicao.op; //token recebido pela soma
} 
             | termo {$$ = $1;};

soma: SOM{$$ = CriaNoExp(ID_K); $$->Atribuicao.op = SOM;} | SUB{$$ = CriaNoExp(ID_K); $$->Atribuicao.op = SUB;};

termo: termo mult fator{
    $$ = CriaNoExp(OP_K);
    $$->filho[0] = $1;
    $$->filho[1] = $3;
    $$->Atribuicao.op = $2->Atribuicao.op; //token recebido pelo mult
}    | fator {$$ = $1;};

mult: MULT{$$ = CriaNoExp(ID_K); $$->Atribuicao.op = MULT;} | DIV{$$ = CriaNoExp(ID_K); $$->Atribuicao.op = DIV;};

fator: ABR_PAR expressao FECH_PAR {$$ = $1;} | var {$$ = $1;} | ativacao {$$ = $1;} 
     | NUM {
        $$ = CriaNoExp(NUM_K);
        $$->Atribuicao.valor = numero;
        $$->tipo = Integer;
     };

ativacao: ID{
    if(pilha_Inicializada == 0){
        InicializaPilha(&Funcao);
        pilha_Inicializada = 1;
    }
    push(&Funcao, strdup(buffer));
    free(buffer);
    Linha_salva = num_linha;
} ABR_PAR args FECH_PAR{
    $$ = CriaNoStmt(chamada_K);
    $$->filho[1] = $4; // filho direito
    $$->Atribuicao.nome = pop(&Funcao);
    $$->linha = Linha_salva;
};

args: arglista {$$ = $1;} | %empty {$$ = NULL;};

arglista: arglista VG expressao{
    YYSTYPE t = $1;
    // adiciona os nós como irmãos
    if(t!=NULL){
        while(t->irmao != NULL){
            t = t->irmao;
        }
        t->irmao = $3;
        $$ = $1;
    }else{
        $$ = $3;
    }

}       | param {$$ = $1;}
        | expressao {$$ = $1;};

%%

int yyerror(char * msg){
    if(yychar == ID || yychar == NUM){
        fprintf(stdout,"\nERRO SINTATICO: %s LINHA: %d\n", NomeTok(yychar), num_linha);
    }else{
        fprintf(stdout,"\nERRO SINTATICO: %s (%s) LINHA: %d\n", NomeTok(yychar), yytext, num_linha);
    }
    ERROR = 1;
    return 0;
}

static int yylex(void){ 
    return PegaTok();
}

ArvoreNO* parse(void){
    yyparse();
    return salvaArvore;
}
