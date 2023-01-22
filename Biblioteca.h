#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef YYPARSER
#include "Analisador_sintatico.tab.h"
#endif

/*============================GLOBAIS E ENUMS====================================*/
typedef int TOKEN;
extern int num_linha;
extern FILE *arquivo;
extern char* tokenString;
extern char *buffer;
extern int numero;
extern char* yytext;
extern int ERROR;
static int alocacao = 0;
static int ExisteMain = 0;
static char* escopo = "global";

#define MAXIMOFILHOS 3

typedef enum {Decla_K, Exp_K, Stmt_K} Nodo;
typedef enum {var_K, func_K, tipo_K} Decla;
typedef enum {if_K, while_K, atrib_K, return_K, chamada_K} Statment;
typedef enum {OP_K, NUM_K, ID_K} Expressao;
typedef enum {Void, Integer, Array} Tipagem;


/*===================FUNCOES DE VARREDURA E ARVORE SINTATICA E SUAS FUNCOES==============*/
typedef struct ArvoreNO{
    struct ArvoreNO *filho[MAXIMOFILHOS];
    struct ArvoreNO *irmao;
    int linha;
    Nodo nodo;
    union{
        Decla declaracao;
        Statment statment;
        Expressao expressao;
    }Txt_linguagem;        // basicamente o corpo de um arquivo referente a linguagem
    union{
        TOKEN op;
        int valor;
        char * nome; 
    }Atribuicao;      // variaveis e atributos presentes em expressões
    Tipagem tipo;     //verifica os tipos das expressoes
}ArvoreNO;

/*Funcoes auxiliares presentes no Flex e no Bison*/
TOKEN PegaTok();

ArvoreNO* parse(void);

/*Funcoes referentes a analise lexica*/
void PrintaTokens(char* texto);

char* NomeTok(TOKEN token);

/*Funçoes referentes a arvore sintatica da analise sintatica*/
ArvoreNO *CriaNoDecl(Decla decla); 

ArvoreNO *CriaNoStmt(Statment stmt);

ArvoreNO *CriaNoExp(Expressao exp);

void PrintaArvore(ArvoreNO *arvore);


/*-----------PILHA DE FUNÇOES PARA AUXILIO NA ANALISE SINTATICA------------*/

typedef struct SNome{
    char *nome;
    struct SNome *abaixo;
}TNome;

typedef struct Pilha{
    int numelementos;
    TNome* topo;
}Pilha;

void push(Pilha *P, char* nome);

char *pop(Pilha *P);

void InicializaPilha(Pilha *P);


/*============TABELA HASH E SUAS FUNCOES PARA A TABELA DE SIMBOLOS E ANALISE SEMANTICA=============*/

typedef struct ListaLinhas{ 
    int numlinha;
    struct ListaLinhas* prox;
}*ListaLinhas;   // Struct para o conjunto de linhas em que uma variavel ou funcao pode aparecer

typedef struct TabelaHash{ 
    char* nome;
    char* escopo;
    int funcao; // 0: variável, 1: função
    Tipagem tipo; 
    ListaLinhas linhas;
    int entrada; // referente a alocação das declarações na tabela
    struct TabelaHash* prox;
}*TabelaHash;

static TabelaHash tabela[211];

char *RetornaTipo(Tipagem tipo);

/*Funcao de espalhammento*/
static int Hash (char *chave);

/*Funcao que insere numero das linhas e locais de memoria na tabela hash de simbolos*/
void InsereTabela(char *nome, int linha, int aloc, char *escopo, Tipagem tipo, int funcao);

void PrintaTabela(FILE* listing);

void MontaTabela(ArvoreNO* arvore); 

/*Função que retornará 1 caso haja uma funçao de mesmo nome declarada*/
int FuncDeclarada (char *nome);

/*Função que retornará 1 caso haja uma variável declarada já*/
int VarDeclarada (char *nome);

/*Função retornará 1 caso haja uma variavel decladara no escopo*/
int VarDeclaradaEscopo(char *nome, char *escopo);

/*Função retornará 1 se houver uma variável global declarada já*/
int VarTemGlobal(char *nome);

void RetornaTipoFunc (char *nome, Tipagem *tipo);

void RetornaTipoVar (char *nome, char *escopo, Tipagem *tipo);

/*Funcao que ira inserir nó da arvore na tabela e verificar a já existencia ou nao*/
static void InsereNoTabela(ArvoreNO* arvore);

/*Função que fará o percorrimento em Pre-Ordem sobre a arvore sintática*/
static void PercorrePreOrdem(ArvoreNO* arvore);


