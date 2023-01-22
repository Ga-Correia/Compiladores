/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_ANALISADOR_SINTATICO_TAB_H_INCLUDED
# define YY_YY_ANALISADOR_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    INT = 260,                     /* INT  */
    RETURN = 261,                  /* RETURN  */
    VOID = 262,                    /* VOID  */
    WHILE = 263,                   /* WHILE  */
    VG = 264,                      /* VG  */
    PEV = 265,                     /* PEV  */
    ID = 266,                      /* ID  */
    NUM = 267,                     /* NUM  */
    SOM = 268,                     /* SOM  */
    SUB = 269,                     /* SUB  */
    MULT = 270,                    /* MULT  */
    DIV = 271,                     /* DIV  */
    IGUAL = 272,                   /* IGUAL  */
    MENOR = 273,                   /* MENOR  */
    MENORIGUAL = 274,              /* MENORIGUAL  */
    MAIOR = 275,                   /* MAIOR  */
    MAIORIGUAL = 276,              /* MAIORIGUAL  */
    DIFERENTE = 277,               /* DIFERENTE  */
    IGUALIGUAL = 278,              /* IGUALIGUAL  */
    ABR_COLCH = 279,               /* ABR_COLCH  */
    FECH_COLCH = 280,              /* FECH_COLCH  */
    ABR_PAR = 281,                 /* ABR_PAR  */
    FECH_PAR = 282,                /* FECH_PAR  */
    ABR_CHV = 283,                 /* ABR_CHV  */
    FECH_CHV = 284                 /* FECH_CHV  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ANALISADOR_SINTATICO_TAB_H_INCLUDED  */
