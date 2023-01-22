#include "Biblioteca.h"

/*==========================ANALISE LEXICA E ANALISE SINTATICA==========================*/
void PrintaTokens(char *texto){
    FILE* arq = fopen(texto,"r");
    if(arq==NULL){
        printf("Falhou a leitura do código\n");
        ERROR = 1;
        return;
    }
    int primeira_vez= 1;
    int restante= 0;
    char string[100];
    while(1){
        if(fgets(string, 100, arq)==NULL){
            break;
        }
        if(string[0]=='\n'){
            if(fgets(string, 100, arq)==NULL){
                break;
            }
        }
        int linha;
        TOKEN tok;
        if(primeira_vez==1){
            linha= num_linha + 1;
            primeira_vez = 0;
        }else{
            linha = num_linha;
        }
        printf("\nL: %d: %s", linha, string);
        if(restante){
            switch((tok==ID)||(tok==NUM)){
                case 0:
                printf("\t%d: %s\n",num_linha, NomeTok(tok));
                break;

                case 1:
                printf("\t%d: %s, val= %s\n",num_linha, NomeTok(tok), yytext);
                break;
            }
            restante= 0;
        }
        do{
            tok = PegaTok();
            if(tok == EOF){
                break;
            }
            else if(num_linha != linha){
                restante = 1;
                break;
            }
            switch((tok==ID)||(tok==NUM)){
                case 0:
                printf("\t%d: %s\n",num_linha, NomeTok(tok));
                break;

                case 1:
                printf("\t%d: %s, val= %s\n",num_linha, NomeTok(tok), yytext);
                break;
            }
        }while(1);
    }
    fclose(arq);
}


ArvoreNO *CriaNoDecl(Decla decla){
    ArvoreNO *NO= (ArvoreNO*) malloc(sizeof(ArvoreNO));
    int i;
    if (NO==NULL){
        fprintf(stderr,"Falta de memória%d\n",num_linha);
    }else{
        for (i=0; i<MAXIMOFILHOS; i++){ 
            NO->filho[i]= NULL;
        }
        NO->irmao= NULL;
        NO->nodo= Decla_K;
        NO->Txt_linguagem.declaracao = decla;
        NO->linha= num_linha;
    }
    return NO;
}

ArvoreNO *CriaNoStmt(Statment stmt){
    ArvoreNO *NO= (ArvoreNO*) malloc(sizeof(ArvoreNO));
    int i;
    if (NO==NULL){
        fprintf(stderr,"Falta de memória%d\n",num_linha);
    }else{
        for (i=0; i<MAXIMOFILHOS; i++){ 
            NO->filho[i]= NULL;
        }
        NO->irmao= NULL;
        NO->nodo= Stmt_K;
        NO->Txt_linguagem.statment = stmt;
        NO->linha= num_linha;
    }
    return NO;
}

ArvoreNO *CriaNoExp(Expressao exp){
    ArvoreNO *NO= (ArvoreNO*) malloc(sizeof(ArvoreNO));
    int i;
    if (NO==NULL){
        fprintf(stderr,"Falta de memória%d\n",num_linha);
    }else{
        for (i=0; i<MAXIMOFILHOS; i++){ 
            NO->filho[i]= NULL;
        }
        NO->irmao= NULL;
        NO->nodo= Exp_K;
        NO->Txt_linguagem.expressao= exp;
        NO->linha= num_linha;
    }
    return NO;
}

static int indentno = 0;
#define INDENT indentno+=2
#define UNINDENT indentno-=2

static void PrintaEspacos(void){ 
    int i;
    for (i=0;i<indentno;i++){
        fprintf(stdout," ");
    }
}

void PrintaArvore(ArvoreNO *arvore){
    int i;
    INDENT;
    while (arvore!=NULL){
        PrintaEspacos();
        if(arvore->nodo==Decla_K){
            switch (arvore->Txt_linguagem.declaracao) {
                case var_K:
                fprintf(stdout,"Variável %s\n",arvore->Atribuicao.nome);
                break;

                case func_K:
                fprintf(stdout,"Função %s\n",arvore->Atribuicao.nome);
                break;

                case tipo_K:
                if (arvore->tipo == Integer){
                    fprintf(stdout,"Tipo int\n");
                }else if(arvore->tipo == Array){ 
                    fprintf(stdout,"Tipo int[]\n");
                }else{
                    fprintf(stdout,"Tipo void\n");
                }
                break;

                default:
                fprintf(stdout,"Tipo desconhecido de Decl\n");
                break;
            }
        }else if(arvore->nodo==Stmt_K){ 
            switch(arvore->Txt_linguagem.statment){
                case if_K:
                fprintf(stdout,"If\n");
                break;

                case while_K:
                fprintf(stdout,"While\n");
                break;

                case atrib_K:
                fprintf(stdout,"Atribuição\n");
                break;

                case return_K:
                fprintf(stdout,"Return\n");
                break;

                case chamada_K:
                fprintf(stdout,"Chamada de Sistema %s\n",arvore->Atribuicao.nome);
                break;

                default:
                fprintf(stdout,"Tipo desconhecido de Stmt\n");
                break;
            }
        }else if(arvore->nodo==Exp_K){ 
            switch (arvore->Txt_linguagem.expressao) {
                case OP_K:
                fprintf(stdout,"OP:%s\n", NomeTok(arvore->Atribuicao.op));
                break;

                case NUM_K:
                fprintf(stdout,"NUM: %d\n",arvore->Atribuicao.valor);
                break;

                case ID_K:
                fprintf(stdout,"ID: %s\n",arvore->Atribuicao.nome);
                break;
                default:
                fprintf(stdout,"Tipo desconhecido de Exp\n");
                break;
            }
        }else{
            fprintf(stdout,"Tipo desconhecido de Nó\n");
        }
        for (i=0;i<MAXIMOFILHOS;i++){
            PrintaArvore(arvore->filho[i]);
        }
        arvore= arvore->irmao;
    }
    UNINDENT;
}



char* NomeTok(TOKEN tok){
    char *nome;
    nome = malloc(100*sizeof(char));
    switch(tok){
        case IF:
        strcpy(nome,"IF");
        break;
        case ELSE:
        strcpy(nome,"ELSE");
        break;
        case INT:
        strcpy(nome,"INT");
        break;
        case RETURN:
        strcpy(nome,"RETURN");
        break;
        case VOID:
        strcpy(nome,"VOID");
        break;
        case WHILE:
        strcpy(nome,"WHILE");
        break;
        case NUM:
        strcpy(nome,"NUM");
        break;
        case ID:
        strcpy(nome,"ID");
        break;
        case SOM:
        strcpy(nome,"SOM");
        break;
        case SUB:
        strcpy(nome,"SUB");
        break;
        case MULT:
        strcpy(nome,"MULT");
        break;
        case DIV:
        strcpy(nome,"DIV");
        break;
        case IGUAL:
        strcpy(nome,"IGUAL");
        break;
        case MENOR:
        strcpy(nome,"MENOR");
        break;
        case MENORIGUAL:
        strcpy(nome,"MENORIGUAL");
        break;
        case MAIOR:
        strcpy(nome,"MAIOR");
        break;
        case MAIORIGUAL:
        strcpy(nome,"MAIORIGUAL");
        break;
        case IGUALIGUAL:
        strcpy(nome,"IGUALIGUAL");
        break;
        case DIFERENTE:
        strcpy(nome,"DIFERENTE");
        break;
        case ABR_PAR:
        strcpy(nome,"ABR_PAR");
        break;
        case FECH_PAR:
        strcpy(nome,"FECH_PAR");
        break;
        case ABR_CHV:
        strcpy(nome,"ABR_CHV");
        break;
        case FECH_CHV:
        strcpy(nome,"FECH_CHV");
        break;
        case ABR_COLCH:
        strcpy(nome,"ABR_COLCH");
        break;
        case FECH_COLCH:
        strcpy(nome,"FECH_COLCH");
        break;
        case PEV:
        strcpy(nome,"PEV");
        break;
        case VG:
        strcpy(nome,"VG");
        break;
        default:
        strcpy(nome, "OUTRO");
        break;
    }
    return nome;
}


/* ----------PILHA DE FUNCOES------------*/

void InicializaPilha(Pilha *P){
    P = malloc(sizeof(Pilha*));
    P->numelementos = 0;
    P->topo = NULL;
}

void push(Pilha *P, char* nome){
    TNome *NomeStr = malloc(sizeof(TNome*));
    NomeStr->nome = strdup(nome);
    free(nome);
    NomeStr->abaixo = P->topo;
    P->topo = NomeStr;
    P->numelementos ++;
}

char *pop(Pilha *P){
    char *nome = NULL;
    if (P->numelementos != 0){// pilha não vazia
        nome = strdup(P->topo->nome);
        TNome *topoAntigo;
        topoAntigo = P->topo;
        P->topo = topoAntigo->abaixo;
        P->numelementos --;
        nome = strdup(topoAntigo->nome);
        free(topoAntigo);
    }
    return nome;
}



/*=================ANALISE SEMANTICA POR TABELA DE SIMBOLOS (HASH)========================*/

static int Hash(char *chave){ 
    int temp= 0;
    int i= 0;
    while(chave[i]!='\0'){ 
        temp= ((temp << 4) + chave[i]) % 211;
        ++i;
    }
    return temp;
}

void InsereTabela(char *nome, int linha, int aloc, char *escopo, Tipagem tipo, int funcao){
    int hash= Hash(nome);
    TabelaHash tab= tabela[hash];
    while ((tab!=NULL) && ((strcmp(nome, tab->nome) != 0) || strcmp(tab->escopo, escopo)!=0)){
        tab= tab->prox;
    }
    if (tab==NULL){ // variavel ainda nao esta na tabela
        tab= (TabelaHash) malloc(sizeof(struct TabelaHash));
        tab->nome= nome;
        tab->linhas= (ListaLinhas) malloc(sizeof(struct ListaLinhas));
        tab->linhas->numlinha= linha;
        tab->entrada= aloc;
        if(strcmp(escopo,"global")==0){
            char *global = malloc(7*sizeof(char));
            if(global == NULL){
                printf("Erro de alocação de memória!\n");
                return;
            }
            global[0] ='g';
            global[1]='l';
            global[2]='o';
            global[3]='b';
            global[4]='a';
            global[5]='l';
            global[6]='\0';
            tab->escopo= global;
        }else{
            tab->escopo= escopo;
        }
        tab->tipo= tipo;
        tab->funcao= funcao;
        tab->linhas->prox= NULL;
        tab->prox= tabela[hash];
        tabela[hash]= tab; 
    }else{    //encontrado na tabela, logo, apenas adicionar o numero da linha
        ListaLinhas lin = tab->linhas;
        while(lin->prox != NULL){
            lin= lin->prox;
        }
        lin->prox = (ListaLinhas) malloc(sizeof(struct ListaLinhas));
        lin->prox->numlinha = linha;
        lin->prox->prox = NULL;
    }
}

int FuncDeclarada(char *nome){
    int hash= Hash(nome);
    TabelaHash tab= tabela[hash];
    while((tab!=NULL) && ((strcmp(nome, tab->nome) != 0)||(tab->funcao == 0))){
        tab= tab->prox;
    }
    if(tab==NULL){
        return 0;
    }else{
        return 1;
    }
}

int VarDeclarada(char *nome){
    int hash= Hash(nome);
    TabelaHash tab= tabela[hash];
    while ((tab!=NULL) && ((strcmp(nome, tab->nome)!=0)||(tab->funcao==1))){
        tab= tab->prox;
    }
    if(tab==NULL){
        return 0;
    }else{
        return 1;
    }
}

int VarDeclaradaEscopo(char *nome, char *escopo){
    int hash= Hash(nome);
    TabelaHash tab= tabela[hash];
    while(tab!=NULL){
        if((tab->funcao==0 && strcmp(nome, tab->nome)==0)&&(strcmp(escopo,tab->escopo)==0)){
            break;
        }
        tab= tab->prox;
    }
    if(tab==NULL){
        return 0;
    }else{
        return 1;
    }
}

int VarTemGlobal(char *nome){
    int hash= Hash(nome);
    TabelaHash tab= tabela[hash];
    while (tab!=NULL){
        if((tab->funcao==0&&strcmp(nome, tab->nome)==0)&&(strcmp(tab->escopo,"global")==0)){
            break;
        }
        tab= tab->prox;
    }
    if(tab==NULL){
        return 0;
    }else{
        return 1;
    }
}

void RetornaTipoFunc(char *nome, Tipagem *tipo){
    int hash= Hash(nome);
    TabelaHash tab= tabela[hash];
    while ((tab!=NULL) && ((strcmp(nome,tab->nome) != 0)||(tab->funcao == 0))){
        tab = tab->prox;
    }
    if (tab!=NULL){
        *tipo = tab->tipo;
    }
}

void RetornaTipoVar(char *nome, char *escopo, Tipagem *tipo){
    int hash= Hash(nome);
    TabelaHash tab=  tabela[hash];
    while((tab!=NULL) && ((strcmp(nome,tab->nome)!=0) || (strcmp(escopo,tab->escopo)!=0) || (tab->funcao == 1))){
        tab= tab->prox;
    }
    if(tab!=NULL){
        *tipo= tab->tipo;
    }
}


char *RetornaTipo(Tipagem tipo){
    switch(tipo){
        case Void:
        return "void";
        break;
    
        case Integer:
        return "int";
        break;

        case Array:
        return "int[]";
        break;

        default:
        break;
    }
}

void PrintaTabela(FILE* listing){ 
    int i;
    fprintf(listing,"  Entrada:    ID:      Tipo:     Escopo:      N. Linhas:\n");
    fprintf(listing," _______________________________________________________________\n");
    for (i=0; i<211; ++i){ 
        if(tabela[i]!=NULL){ 
            TabelaHash tab= tabela[i];
            while (tab!=NULL){         
                ListaLinhas lin= tab->linhas;
                fprintf(listing,"   %-2d ",tab->entrada);
                fprintf(listing,"    |  %-6s ",tab->nome);
                fprintf(listing," |  %-5s ",RetornaTipo(tab->tipo));
                fprintf(listing,"|  %-11s|",tab->escopo);
                while(lin!=NULL){ 
                    fprintf(listing,"%4d ",lin->numlinha);
                    lin= lin->prox;
                }
                fprintf(listing,"\n");
                tab= tab->prox;
            }
        }
    }
}


static void InsereNoTabela(ArvoreNO* arvore){
    Tipagem *Tipo;
    Tipo = (Tipagem*) malloc(sizeof(Tipagem));
    switch (arvore->nodo){
        case Decla_K:
        if(arvore->Txt_linguagem.declaracao==func_K){ 
            if(strcmp(arvore->Atribuicao.nome, "main")==0){
                ExisteMain = 1;
            }
            if(strcmp(arvore->Atribuicao.nome, "input")==0 || strcmp(arvore->Atribuicao.nome, "output")==0){
                ERROR = 1;
                printf("ERRO SEMANTICO: %s LINHA: %d\tFunção reservada!\n",arvore->Atribuicao.nome, arvore->linha);
            }else{
                if (FuncDeclarada(arvore->Atribuicao.nome)==0){
                    InsereTabela(arvore->Atribuicao.nome, arvore->linha, alocacao++,"global", arvore->tipo, 1);
                    escopo = arvore->Atribuicao.nome;// escopo da função
                }else{
                    ERROR = 1;
                    printf("ERRO SEMANTICO: %s LINHA: %d\tFunção reservada!\n",arvore->Atribuicao.nome, arvore->linha);
                }
            }
        }else if(arvore->Txt_linguagem.declaracao==var_K){ //verificar escopo
            if(arvore->tipo == Void){
                ERROR = 1;
                printf("ERRO SEMANTICO: Declaração de variável não inteira LINHA: %d\n", arvore->linha);
            }
            if (VarDeclarada(arvore->Atribuicao.nome) == 0){    //variável ainda não declarada
                InsereTabela(arvore->Atribuicao.nome, arvore->linha, alocacao++, escopo, arvore->tipo, 0);
            }else{    //variável já declarada
                if(strcmp(escopo, "global")!=0){
                    if(VarDeclaradaEscopo(arvore->Atribuicao.nome, escopo) == 0){  //variavel pode ser declarar
                        InsereTabela(arvore->Atribuicao.nome, arvore->linha, alocacao++, escopo, arvore->tipo, 0);
                    }else{
                        ERROR = 1;
                        printf("ERRO SEMANTICO: %s LINHA: %d\tVariável já declarada!\n", arvore->Atribuicao.nome, arvore->linha);
                    }
                }else{
                    ERROR = 1;
                    printf("ERRO SEMANTICO: %s LINHA: %d\tVariável global já declarada!\n", arvore->Atribuicao.nome, arvore->linha);
                }
            }
        }
        break;

        case Stmt_K:
        if(arvore->Txt_linguagem.statment==chamada_K){ 
            case chamada_K:
            if(strcmp(arvore->Atribuicao.nome, "input")==0){
                arvore->tipo = Integer;
            }else if(strcmp(arvore->Atribuicao.nome, "output")==0){
                arvore->tipo = Integer;
            }else if (FuncDeclarada(arvore->Atribuicao.nome) == 0){
                ERROR = 1;
                printf("ERRO SEMANTICO: %s LINHA: %d\tFunção não declarada!\n", arvore->Atribuicao.nome, arvore->linha);
            }else{  //atualiza linhas
                RetornaTipoFunc(arvore->Atribuicao.nome, Tipo);
                arvore->tipo = *Tipo;
                InsereTabela(arvore->Atribuicao.nome, arvore->linha, 0, "global", arvore->tipo, 1);
            }
        }
        break;

        case Exp_K:
        if(arvore->Txt_linguagem.expressao==ID_K){  // verificar escopo
            if(strcmp(arvore->Atribuicao.nome, "void")!=0){
                if (VarDeclarada(arvore->Atribuicao.nome) == 0){
                    ERROR = 1;
                    printf("ERRO SEMANTICO: %s LINHA: %d\tVariável não declarada\n", arvore->Atribuicao.nome, arvore->linha);
                }else if (VarDeclaradaEscopo(arvore->Atribuicao.nome, escopo) == 1){   //está  declarada no mesmo escopo
                    RetornaTipoVar(arvore->Atribuicao.nome, escopo, Tipo);
                    if(arvore->tipo == Void){
                        arvore->tipo = *Tipo;
                    }
                    InsereTabela(arvore->Atribuicao.nome, arvore->linha, 0, escopo, arvore->tipo, 0);
                }else{    //não está declarada no escopo
                    if(VarTemGlobal(arvore->Atribuicao.nome)==0){
                        ERROR = 1;
                        printf("ERRO SEMANTICO: %s LINHA: %d\tVariável não declarada\n", arvore->Atribuicao.nome, arvore->linha);
                    }else{
                        RetornaTipoVar(arvore->Atribuicao.nome, "global", Tipo);
                        if(arvore->tipo == Void){
                            arvore->tipo = *Tipo;
                        }
                        InsereTabela(arvore->Atribuicao.nome, arvore->linha, 0, "global", arvore->tipo, 0);
                    }
                }
            }
        }
        break;

        default:
        break;
    }
    free(Tipo);
}


static void PercorrePreOrdem(ArvoreNO* arvore){
    if (arvore!=NULL){ 
        InsereNoTabela(arvore); //processa nó pai antes dos filhos
        int i;
        for (i=0; i<MAXIMOFILHOS; i++){
            PercorrePreOrdem(arvore->filho[i]);
        }
        PercorrePreOrdem(arvore->irmao);
    }
}


void MontaTabela(ArvoreNO* arvore){
    PercorrePreOrdem(arvore);
    if(!ExisteMain){
        fprintf(stdout,"\nERRO SEMANTICO: Função Main não declarada ou ERRO SINTATICO impediu a construçao da arvore sintatica para a tabela de simbolos\n");
        ERROR = 1;
    }else{
        fprintf(stdout,"\n============================Tabela de Símbolos=========================\n\n");
        PrintaTabela(stdout);
    }
} 

