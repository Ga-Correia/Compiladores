/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Analisador_sintatico.y"

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

#line 87 "Analisador_sintatico.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "Analisador_sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_VG = 9,                         /* VG  */
  YYSYMBOL_PEV = 10,                       /* PEV  */
  YYSYMBOL_ID = 11,                        /* ID  */
  YYSYMBOL_NUM = 12,                       /* NUM  */
  YYSYMBOL_SOM = 13,                       /* SOM  */
  YYSYMBOL_SUB = 14,                       /* SUB  */
  YYSYMBOL_MULT = 15,                      /* MULT  */
  YYSYMBOL_DIV = 16,                       /* DIV  */
  YYSYMBOL_IGUAL = 17,                     /* IGUAL  */
  YYSYMBOL_MENOR = 18,                     /* MENOR  */
  YYSYMBOL_MENORIGUAL = 19,                /* MENORIGUAL  */
  YYSYMBOL_MAIOR = 20,                     /* MAIOR  */
  YYSYMBOL_MAIORIGUAL = 21,                /* MAIORIGUAL  */
  YYSYMBOL_DIFERENTE = 22,                 /* DIFERENTE  */
  YYSYMBOL_IGUALIGUAL = 23,                /* IGUALIGUAL  */
  YYSYMBOL_ABR_COLCH = 24,                 /* ABR_COLCH  */
  YYSYMBOL_FECH_COLCH = 25,                /* FECH_COLCH  */
  YYSYMBOL_ABR_PAR = 26,                   /* ABR_PAR  */
  YYSYMBOL_FECH_PAR = 27,                  /* FECH_PAR  */
  YYSYMBOL_ABR_CHV = 28,                   /* ABR_CHV  */
  YYSYMBOL_FECH_CHV = 29,                  /* FECH_CHV  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_programa = 31,                  /* programa  */
  YYSYMBOL_declaracaolista = 32,           /* declaracaolista  */
  YYSYMBOL_declaracao = 33,                /* declaracao  */
  YYSYMBOL_vardeclaracao = 34,             /* vardeclaracao  */
  YYSYMBOL_35_1 = 35,                      /* $@1  */
  YYSYMBOL_36_2 = 36,                      /* $@2  */
  YYSYMBOL_tipoespecificador = 37,         /* tipoespecificador  */
  YYSYMBOL_fundeclaracao = 38,             /* fundeclaracao  */
  YYSYMBOL_39_3 = 39,                      /* $@3  */
  YYSYMBOL_params = 40,                    /* params  */
  YYSYMBOL_paramlista = 41,                /* paramlista  */
  YYSYMBOL_param = 42,                     /* param  */
  YYSYMBOL_43_4 = 43,                      /* $@4  */
  YYSYMBOL_compostodecl = 44,              /* compostodecl  */
  YYSYMBOL_localdeclaracoes = 45,          /* localdeclaracoes  */
  YYSYMBOL_statementlista = 46,            /* statementlista  */
  YYSYMBOL_statement = 47,                 /* statement  */
  YYSYMBOL_expressaodecl = 48,             /* expressaodecl  */
  YYSYMBOL_selecaodecl = 49,               /* selecaodecl  */
  YYSYMBOL_iteracaodecl = 50,              /* iteracaodecl  */
  YYSYMBOL_retornodecl = 51,               /* retornodecl  */
  YYSYMBOL_expressao = 52,                 /* expressao  */
  YYSYMBOL_var = 53,                       /* var  */
  YYSYMBOL_54_5 = 54,                      /* $@5  */
  YYSYMBOL_simplesexpressao = 55,          /* simplesexpressao  */
  YYSYMBOL_relacional = 56,                /* relacional  */
  YYSYMBOL_somaexpressao = 57,             /* somaexpressao  */
  YYSYMBOL_soma = 58,                      /* soma  */
  YYSYMBOL_termo = 59,                     /* termo  */
  YYSYMBOL_mult = 60,                      /* mult  */
  YYSYMBOL_fator = 61,                     /* fator  */
  YYSYMBOL_ativacao = 62,                  /* ativacao  */
  YYSYMBOL_63_6 = 63,                      /* $@6  */
  YYSYMBOL_args = 64,                      /* args  */
  YYSYMBOL_arglista = 65                   /* arglista  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   108

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    24,    24,    26,    37,    39,    39,    41,    41,    54,
      54,    75,    78,    83,    83,    98,   100,   106,   117,   119,
     131,   131,   149,   163,   174,   176,   188,   190,   190,   190,
     190,   190,   192,   192,   194,   199,   206,   212,   212,   217,
     223,   225,   234,   234,   246,   251,   253,   254,   255,   256,
     257,   258,   260,   266,   268,   268,   270,   275,   277,   277,
     279,   279,   279,   280,   286,   286,   301,   301,   303,   316,
     317
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "INT",
  "RETURN", "VOID", "WHILE", "VG", "PEV", "ID", "NUM", "SOM", "SUB",
  "MULT", "DIV", "IGUAL", "MENOR", "MENORIGUAL", "MAIOR", "MAIORIGUAL",
  "DIFERENTE", "IGUALIGUAL", "ABR_COLCH", "FECH_COLCH", "ABR_PAR",
  "FECH_PAR", "ABR_CHV", "FECH_CHV", "$accept", "programa",
  "declaracaolista", "declaracao", "vardeclaracao", "$@1", "$@2",
  "tipoespecificador", "fundeclaracao", "$@3", "params", "paramlista",
  "param", "$@4", "compostodecl", "localdeclaracoes", "statementlista",
  "statement", "expressaodecl", "selecaodecl", "iteracaodecl",
  "retornodecl", "expressao", "var", "$@5", "simplesexpressao",
  "relacional", "somaexpressao", "soma", "termo", "mult", "fator",
  "ativacao", "$@6", "args", "arglista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-86)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-65)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,   -86,   -86,     2,     7,   -86,   -86,    15,   -86,   -86,
     -86,    -4,     8,    11,     9,   -86,    38,    20,    23,    32,
      44,    33,    53,   -86,    61,    54,    41,     7,   -86,    56,
     -86,   -86,   -86,    52,     7,   -86,   -86,    72,     5,    57,
      60,    37,    62,   -86,     6,   -86,   -86,    -7,   -86,   -86,
     -86,   -86,   -86,   -86,    77,    73,   -86,    55,    28,   -86,
     -86,    -7,   -86,    79,    -7,    63,    67,    65,   -86,    -7,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,    -7,    -7,
     -86,   -86,    -7,    68,   -86,    69,    -7,    46,   -86,   -86,
     -86,    66,    28,   -86,    30,    30,    70,   -86,   -86,    71,
      85,    93,   -86,   -86,   -86,    -7,    30,   -86,   -86
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,    12,     0,     2,     4,     5,     0,     6,     1,
       3,     7,     0,     0,     0,     8,     0,     0,     0,    12,
       0,     0,    15,    18,     0,    19,     0,     0,    10,     0,
      24,    14,    17,     0,    26,    21,    23,     0,     0,     7,
       0,     0,     0,    33,    41,    63,    22,     0,    28,    25,
      27,    29,    30,    31,     0,    61,    40,    45,    53,    57,
      62,     0,    37,     0,     0,     0,     0,     0,    32,     0,
      54,    55,    47,    46,    48,    49,    51,    50,     0,     0,
      58,    59,     0,     0,    38,     0,     0,    67,    60,    39,
      61,    44,    52,    56,     0,     0,     0,    69,    70,     0,
      66,    34,    36,    43,    65,     0,     0,    68,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -86,   -86,   -86,    96,    74,   -86,   -86,     3,   -86,   -86,
     -86,   -86,   -26,   -86,    75,   -86,   -86,   -85,   -86,   -86,
     -86,   -86,   -41,   -12,   -86,   -86,   -86,    24,   -86,    25,
     -86,    21,   -86,   -86,   -86,   -86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    12,    13,    20,     8,    14,
      21,    22,    23,    29,    48,    34,    38,    49,    50,    51,
      52,    53,    54,    55,    65,    56,    78,    57,    79,    58,
      82,    59,    60,    66,    99,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      63,    32,     9,     7,    44,    45,    67,     7,    40,   101,
     102,    41,     1,    42,     2,    43,    44,    45,    15,    47,
      83,   108,   -13,    85,    -9,     1,    11,    19,    89,    30,
      46,    47,   -64,    40,   -42,    17,    41,    37,    42,    16,
      43,    44,    45,    80,    81,    96,    98,    62,    44,    45,
      18,     1,    24,     2,    30,    25,    47,    44,    45,   -16,
      26,    97,    27,    47,   107,    30,    90,    90,    70,    71,
      90,    28,    47,    72,    73,    74,    75,    76,    77,    70,
      71,    35,   -20,    39,    33,    -9,    61,    68,    64,    84,
      69,    86,    88,    87,   105,    94,    95,   106,   104,   103,
      10,    31,    91,    93,    92,     0,     0,     0,    36
};

static const yytype_int8 yycheck[] =
{
      41,    27,     0,     0,    11,    12,    47,     4,     3,    94,
      95,     6,     5,     8,     7,    10,    11,    12,    10,    26,
      61,   106,    26,    64,    28,     5,    11,     7,    69,    24,
      25,    26,    26,     3,    28,    26,     6,    34,     8,    28,
      10,    11,    12,    15,    16,    86,    87,    10,    11,    12,
      12,     5,    29,     7,    24,    11,    26,    11,    12,    27,
      27,    87,     9,    26,   105,    24,    78,    79,    13,    14,
      82,    10,    26,    18,    19,    20,    21,    22,    23,    13,
      14,    29,    28,    11,    28,    28,    26,    10,    26,    10,
      17,    28,    27,    26,     9,    27,    27,     4,    27,    29,
       4,    26,    78,    82,    79,    -1,    -1,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    31,    32,    33,    34,    37,    38,     0,
      33,    11,    35,    36,    39,    10,    28,    26,    12,     7,
      37,    40,    41,    42,    29,    11,    27,     9,    10,    43,
      24,    44,    42,    28,    45,    29,    34,    37,    46,    11,
       3,     6,     8,    10,    11,    12,    25,    26,    44,    47,
      48,    49,    50,    51,    52,    53,    55,    57,    59,    61,
      62,    26,    10,    52,    26,    54,    63,    52,    10,    17,
      13,    14,    18,    19,    20,    21,    22,    23,    56,    58,
      15,    16,    60,    52,    10,    52,    28,    26,    27,    52,
      53,    57,    59,    61,    27,    27,    52,    42,    52,    64,
      65,    47,    47,    29,    27,     9,     4,    52,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    35,    34,    36,
      34,    37,    37,    39,    38,    40,    40,    41,    41,    42,
      43,    42,    44,    45,    45,    46,    46,    47,    47,    47,
      47,    47,    48,    48,    49,    49,    50,    51,    51,    52,
      52,    53,    54,    53,    55,    55,    56,    56,    56,    56,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    61,    61,    63,    62,    64,    64,    65,    65,
      65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     4,     0,
       7,     1,     1,     0,     7,     1,     1,     3,     1,     2,
       0,     5,     4,     2,     0,     2,     0,     1,     1,     1,
       1,     1,     2,     1,     5,     7,     5,     2,     3,     3,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     0,     5,     1,     0,     3,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: declaracaolista  */
#line 24 "Analisador_sintatico.y"
                          {salvaArvore = yyvsp[0];}
#line 1215 "Analisador_sintatico.tab.c"
    break;

  case 3: /* declaracaolista: declaracaolista declaracao  */
#line 26 "Analisador_sintatico.y"
                                           {
    YYSTYPE t = yyvsp[-1];   // adiciona os nos como irmãos por recursividade a esquerda
    if(t!=NULL){
        while(t->filho[0]->irmao != NULL){
            t = t->filho[0]->irmao;
        }
        t->filho[0]->irmao = yyvsp[0];
        yyval = yyvsp[-1];
    }else{
        yyval = yyvsp[0];
    }
}
#line 1232 "Analisador_sintatico.tab.c"
    break;

  case 4: /* declaracaolista: declaracao  */
#line 37 "Analisador_sintatico.y"
                             {yyval = yyvsp[0];}
#line 1238 "Analisador_sintatico.tab.c"
    break;

  case 5: /* declaracao: vardeclaracao  */
#line 39 "Analisador_sintatico.y"
                          {yyval = yyvsp[0];}
#line 1244 "Analisador_sintatico.tab.c"
    break;

  case 6: /* declaracao: fundeclaracao  */
#line 39 "Analisador_sintatico.y"
                                                     {yyval = yyvsp[0];}
#line 1250 "Analisador_sintatico.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 41 "Analisador_sintatico.y"
                                    {
    ID_salvo = strdup(buffer);
    free(buffer);
    Linha_salva = num_linha;
}
#line 1260 "Analisador_sintatico.tab.c"
    break;

  case 8: /* vardeclaracao: tipoespecificador ID $@1 PEV  */
#line 45 "Analisador_sintatico.y"
      {
    yyval = yyvsp[-3];
    YYSTYPE vard;
    vard = CriaNoDecl(var_K);
    vard->Atribuicao.nome = ID_salvo;
    vard->linha = Linha_salva;
    vard->tipo = yyvsp[-3]->tipo;
    yyval->filho[0] = vard;
}
#line 1274 "Analisador_sintatico.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 54 "Analisador_sintatico.y"
                                   {
    ID_salvo = strdup(buffer);
    free(buffer);
    Linha_salva = num_linha;
}
#line 1284 "Analisador_sintatico.tab.c"
    break;

  case 10: /* vardeclaracao: tipoespecificador ID $@2 ABR_CHV NUM FECH_CHV PEV  */
#line 58 "Analisador_sintatico.y"
                          {
    yyval = yyvsp[-6];
    YYSTYPE indice = CriaNoExp(NUM_K);
    indice->Atribuicao.valor = numero;
    indice->tipo = Integer;
    YYSTYPE vard = CriaNoDecl(var_K);
    vard->Atribuicao.nome = ID_salvo;
    vard->linha = Linha_salva;
    vard->filho[0] = indice;
    if(yyvsp[-6]->tipo == Integer){
        vard->tipo = Array;
    }else{
        vard->tipo = Void;
    }
    yyval->filho[0] = vard;
}
#line 1305 "Analisador_sintatico.tab.c"
    break;

  case 11: /* tipoespecificador: INT  */
#line 75 "Analisador_sintatico.y"
                      {
    yyval = CriaNoDecl(tipo_K); // cria o nó para o tipo
    yyval->tipo = Integer; 
}
#line 1314 "Analisador_sintatico.tab.c"
    break;

  case 12: /* tipoespecificador: VOID  */
#line 78 "Analisador_sintatico.y"
                       {
    yyval = CriaNoDecl(tipo_K); // cria o nó para o tipo
    yyval->tipo = Void; 
}
#line 1323 "Analisador_sintatico.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 83 "Analisador_sintatico.y"
                                    {
    Func_decl = strdup(buffer);
    free(buffer);
    Linha_salvaF = num_linha;
}
#line 1333 "Analisador_sintatico.tab.c"
    break;

  case 14: /* fundeclaracao: tipoespecificador ID $@3 ABR_PAR params FECH_PAR compostodecl  */
#line 87 "Analisador_sintatico.y"
                                      {
    yyval = yyvsp[-6];
    YYSTYPE func = CriaNoDecl(func_K);
    func->filho[0] = yyvsp[-2];
    func->filho[1] = yyvsp[0];
    func->Atribuicao.nome = Func_decl;
    func->linha = Linha_salvaF;
    func->tipo = yyvsp[-6]->tipo;
    yyval->filho[0] = func;
}
#line 1348 "Analisador_sintatico.tab.c"
    break;

  case 15: /* params: paramlista  */
#line 98 "Analisador_sintatico.y"
                  {
    yyval = yyvsp[0];  //$$->filho[0] = $1;
}
#line 1356 "Analisador_sintatico.tab.c"
    break;

  case 16: /* params: VOID  */
#line 100 "Analisador_sintatico.y"
            {
    yyval = CriaNoExp(ID_K); 
    yyval->Atribuicao.nome = "void"; 
    yyval->tipo = Void;
}
#line 1366 "Analisador_sintatico.tab.c"
    break;

  case 17: /* paramlista: paramlista VG param  */
#line 106 "Analisador_sintatico.y"
                               {
    YYSTYPE t = yyvsp[-2];   // adiciona os nos como irmãos
    if(t!=NULL){
        while(t->irmao!=NULL){
            t = t->irmao;
        }
        t->irmao = yyvsp[0];
        yyval = yyvsp[-2];
    }else{
        yyval = yyvsp[0];
    }
}
#line 1383 "Analisador_sintatico.tab.c"
    break;

  case 18: /* paramlista: param  */
#line 117 "Analisador_sintatico.y"
                  {yyval = yyvsp[0];}
#line 1389 "Analisador_sintatico.tab.c"
    break;

  case 19: /* param: tipoespecificador ID  */
#line 119 "Analisador_sintatico.y"
                            {
    yyval = yyvsp[-1];
    ID_salvo = strdup(buffer);
    free(buffer);
    Linha_salva = num_linha;
    YYSTYPE par;
    par = CriaNoDecl(var_K);
    par->Atribuicao.nome = ID_salvo;
    par->linha = Linha_salva;
    par->tipo = yyvsp[-1]->tipo;
    yyval->filho[0] = par;
}
#line 1406 "Analisador_sintatico.tab.c"
    break;

  case 20: /* $@4: %empty  */
#line 131 "Analisador_sintatico.y"
                          {
    ID_salvo = strdup(buffer);
    free(buffer);
    Linha_salva = num_linha;
}
#line 1416 "Analisador_sintatico.tab.c"
    break;

  case 21: /* param: tipoespecificador ID $@4 ABR_CHV FECH_CHV  */
#line 135 "Analisador_sintatico.y"
                  {
    yyval = yyvsp[-4];
    YYSTYPE par;
    par = CriaNoDecl(var_K);
    par->Atribuicao.nome = ID_salvo;
    par->linha = Linha_salva;
    if(yyvsp[-4]->tipo == Integer){
        par->tipo = Array;
    }else{
        par->tipo = yyvsp[-4]->tipo;
    }
    yyval->filho[0] = par;
}
#line 1434 "Analisador_sintatico.tab.c"
    break;

  case 22: /* compostodecl: ABR_COLCH localdeclaracoes statementlista FECH_COLCH  */
#line 149 "Analisador_sintatico.y"
                                                                  {
    { YYSTYPE t = yyvsp[-2];  // adiciona os nós como irmãos
      if(t!=NULL){
        while(t->irmao!=NULL){
            t = t->irmao;
        }
        t->irmao = yyvsp[-1];
        yyval = yyvsp[-2];
       }else{
        yyval = yyvsp[-1];
       }
    }      
}
#line 1452 "Analisador_sintatico.tab.c"
    break;

  case 23: /* localdeclaracoes: localdeclaracoes vardeclaracao  */
#line 163 "Analisador_sintatico.y"
                                                {
    YYSTYPE t = yyvsp[-1];    // adiciona os nos como irmãos
    if(t!=NULL && t->Atribuicao.nome!="sem_local_decl"){
        while(t->irmao != NULL){
            t = t->irmao;
        }
        t->irmao = yyvsp[0];
        yyval = yyvsp[-1];
    }else{
        yyval = yyvsp[0];
    }
}
#line 1469 "Analisador_sintatico.tab.c"
    break;

  case 24: /* localdeclaracoes: %empty  */
#line 174 "Analisador_sintatico.y"
                         {yyval = NULL;}
#line 1475 "Analisador_sintatico.tab.c"
    break;

  case 25: /* statementlista: statementlista statement  */
#line 176 "Analisador_sintatico.y"
                                        {
    YYSTYPE t = yyvsp[-1];
    // adiciona os nós como irmãos
    if(t!=NULL){
        while(t->irmao!=NULL){
            t = t->irmao;
        }
        t->irmao = yyvsp[0];
        yyval = yyvsp[-1];
    }else{
        yyval = yyvsp[0];
    }
}
#line 1493 "Analisador_sintatico.tab.c"
    break;

  case 26: /* statementlista: %empty  */
#line 188 "Analisador_sintatico.y"
                       {yyval = NULL;}
#line 1499 "Analisador_sintatico.tab.c"
    break;

  case 27: /* statement: expressaodecl  */
#line 190 "Analisador_sintatico.y"
                        {yyval = yyvsp[0];}
#line 1505 "Analisador_sintatico.tab.c"
    break;

  case 28: /* statement: compostodecl  */
#line 190 "Analisador_sintatico.y"
                                                 {yyval = yyvsp[0];}
#line 1511 "Analisador_sintatico.tab.c"
    break;

  case 29: /* statement: selecaodecl  */
#line 190 "Analisador_sintatico.y"
                                                                         {yyval = yyvsp[0];}
#line 1517 "Analisador_sintatico.tab.c"
    break;

  case 30: /* statement: iteracaodecl  */
#line 190 "Analisador_sintatico.y"
                                                                                                  {yyval = yyvsp[0];}
#line 1523 "Analisador_sintatico.tab.c"
    break;

  case 31: /* statement: retornodecl  */
#line 190 "Analisador_sintatico.y"
                                                                                                                          {yyval = yyvsp[0];}
#line 1529 "Analisador_sintatico.tab.c"
    break;

  case 32: /* expressaodecl: expressao PEV  */
#line 192 "Analisador_sintatico.y"
                             {yyval = yyvsp[-1];}
#line 1535 "Analisador_sintatico.tab.c"
    break;

  case 33: /* expressaodecl: PEV  */
#line 192 "Analisador_sintatico.y"
                                             {yyval = NULL;}
#line 1541 "Analisador_sintatico.tab.c"
    break;

  case 34: /* selecaodecl: IF ABR_PAR expressao FECH_PAR statement  */
#line 194 "Analisador_sintatico.y"
                                                    {
    yyval = CriaNoStmt(if_K);
    yyval->filho[0] = yyvsp[-2];
    yyval->filho[1] = yyvsp[0];
}
#line 1551 "Analisador_sintatico.tab.c"
    break;

  case 35: /* selecaodecl: IF ABR_PAR expressao FECH_PAR statement ELSE statement  */
#line 199 "Analisador_sintatico.y"
                                                                   {
    yyval = CriaNoStmt(if_K);
    yyval->filho[0] = yyvsp[-4];
    yyval->filho[1] = yyvsp[-2];
    yyval->filho[2] = yyvsp[0];
}
#line 1562 "Analisador_sintatico.tab.c"
    break;

  case 36: /* iteracaodecl: WHILE ABR_PAR expressao FECH_PAR statement  */
#line 206 "Analisador_sintatico.y"
                                                        {
    yyval = CriaNoStmt(while_K);
    yyval->filho[0] = yyvsp[-2];
    yyval->filho[1] = yyvsp[0];
}
#line 1572 "Analisador_sintatico.tab.c"
    break;

  case 37: /* retornodecl: RETURN PEV  */
#line 212 "Analisador_sintatico.y"
                       {yyval = CriaNoStmt(return_K);}
#line 1578 "Analisador_sintatico.tab.c"
    break;

  case 38: /* retornodecl: RETURN expressao PEV  */
#line 212 "Analisador_sintatico.y"
                                                                          {
    yyval = CriaNoStmt(return_K);
    yyval->filho[0] = yyvsp[-1];
}
#line 1587 "Analisador_sintatico.tab.c"
    break;

  case 39: /* expressao: var IGUAL expressao  */
#line 217 "Analisador_sintatico.y"
                              {
    yyval = CriaNoStmt(atrib_K);
    yyval->filho[0] = yyvsp[-2];
    yyval->filho[1] = yyvsp[0];
    yyval->tipo = Integer;
    yyval->Atribuicao.op = IGUAL;
}
#line 1599 "Analisador_sintatico.tab.c"
    break;

  case 40: /* expressao: simplesexpressao  */
#line 223 "Analisador_sintatico.y"
                            {yyval = yyvsp[0];}
#line 1605 "Analisador_sintatico.tab.c"
    break;

  case 41: /* var: ID  */
#line 225 "Analisador_sintatico.y"
       {
    ID_salvo = strdup(buffer);
    free(buffer);
    Linha_salva = num_linha;
    yyval = CriaNoExp(ID_K);
    yyval->Atribuicao.nome = ID_salvo;
    yyval->linha = Linha_salva;
    yyval->tipo = Void;
}
#line 1619 "Analisador_sintatico.tab.c"
    break;

  case 42: /* $@5: %empty  */
#line 234 "Analisador_sintatico.y"
        {
    Var_salvo = strdup(buffer);
    free(buffer);
    Linha_salva = num_linha;
}
#line 1629 "Analisador_sintatico.tab.c"
    break;

  case 43: /* var: ID $@5 ABR_CHV expressao FECH_CHV  */
#line 238 "Analisador_sintatico.y"
                            {
    yyval = CriaNoExp(ID_K);
    yyval->Atribuicao.nome = Var_salvo;
    yyval->linha = Linha_salva;
    yyval->filho[0] = yyvsp[-1];
    yyval->tipo = Integer; //certeza. v[]
}
#line 1641 "Analisador_sintatico.tab.c"
    break;

  case 44: /* simplesexpressao: somaexpressao relacional somaexpressao  */
#line 246 "Analisador_sintatico.y"
                                                        {
    yyval = CriaNoExp(OP_K);
    yyval->filho[0] = yyvsp[-2];
    yyval->filho[1] = yyvsp[0];
    yyval->Atribuicao.op = yyvsp[-1]->Atribuicao.op; //token recebido pelo relacional
}
#line 1652 "Analisador_sintatico.tab.c"
    break;

  case 45: /* simplesexpressao: somaexpressao  */
#line 251 "Analisador_sintatico.y"
                                {yyval = yyvsp[0];}
#line 1658 "Analisador_sintatico.tab.c"
    break;

  case 46: /* relacional: MENORIGUAL  */
#line 253 "Analisador_sintatico.y"
                      {yyval = CriaNoExp(ID_K); yyval->Atribuicao.op = MENORIGUAL;}
#line 1664 "Analisador_sintatico.tab.c"
    break;

  case 47: /* relacional: MENOR  */
#line 254 "Analisador_sintatico.y"
                 {yyval = CriaNoExp(ID_K); yyval->Atribuicao.op = MENOR;}
#line 1670 "Analisador_sintatico.tab.c"
    break;

  case 48: /* relacional: MAIOR  */
#line 255 "Analisador_sintatico.y"
                 {yyval = CriaNoExp(ID_K); yyval->Atribuicao.op = MAIOR;}
#line 1676 "Analisador_sintatico.tab.c"
    break;

  case 49: /* relacional: MAIORIGUAL  */
#line 256 "Analisador_sintatico.y"
                      {yyval = CriaNoExp(ID_K); yyval->Atribuicao.op = MAIORIGUAL;}
#line 1682 "Analisador_sintatico.tab.c"
    break;

  case 50: /* relacional: IGUALIGUAL  */
#line 257 "Analisador_sintatico.y"
                      {yyval = CriaNoExp(ID_K); yyval->Atribuicao.op = IGUALIGUAL;}
#line 1688 "Analisador_sintatico.tab.c"
    break;

  case 51: /* relacional: DIFERENTE  */
#line 258 "Analisador_sintatico.y"
                     {yyval = CriaNoExp(ID_K); yyval->Atribuicao.op = DIFERENTE;}
#line 1694 "Analisador_sintatico.tab.c"
    break;

  case 52: /* somaexpressao: somaexpressao soma termo  */
#line 260 "Analisador_sintatico.y"
                                       {
    yyval = CriaNoExp(OP_K);
    yyval->filho[0] = yyvsp[-2];
    yyval->filho[1] = yyvsp[0];
    yyval->Atribuicao.op = yyvsp[-1]->Atribuicao.op; //token recebido pela soma
}
#line 1705 "Analisador_sintatico.tab.c"
    break;

  case 53: /* somaexpressao: termo  */
#line 266 "Analisador_sintatico.y"
                     {yyval = yyvsp[0];}
#line 1711 "Analisador_sintatico.tab.c"
    break;

  case 54: /* soma: SOM  */
#line 268 "Analisador_sintatico.y"
         {yyval = CriaNoExp(ID_K); yyval->Atribuicao.op = SOM;}
#line 1717 "Analisador_sintatico.tab.c"
    break;

  case 55: /* soma: SUB  */
#line 268 "Analisador_sintatico.y"
                                                               {yyval = CriaNoExp(ID_K); yyval->Atribuicao.op = SUB;}
#line 1723 "Analisador_sintatico.tab.c"
    break;

  case 56: /* termo: termo mult fator  */
#line 270 "Analisador_sintatico.y"
                       {
    yyval = CriaNoExp(OP_K);
    yyval->filho[0] = yyvsp[-2];
    yyval->filho[1] = yyvsp[0];
    yyval->Atribuicao.op = yyvsp[-1]->Atribuicao.op; //token recebido pelo mult
}
#line 1734 "Analisador_sintatico.tab.c"
    break;

  case 57: /* termo: fator  */
#line 275 "Analisador_sintatico.y"
             {yyval = yyvsp[0];}
#line 1740 "Analisador_sintatico.tab.c"
    break;

  case 58: /* mult: MULT  */
#line 277 "Analisador_sintatico.y"
          {yyval = CriaNoExp(ID_K); yyval->Atribuicao.op = MULT;}
#line 1746 "Analisador_sintatico.tab.c"
    break;

  case 59: /* mult: DIV  */
#line 277 "Analisador_sintatico.y"
                                                                 {yyval = CriaNoExp(ID_K); yyval->Atribuicao.op = DIV;}
#line 1752 "Analisador_sintatico.tab.c"
    break;

  case 60: /* fator: ABR_PAR expressao FECH_PAR  */
#line 279 "Analisador_sintatico.y"
                                  {yyval = yyvsp[-2];}
#line 1758 "Analisador_sintatico.tab.c"
    break;

  case 61: /* fator: var  */
#line 279 "Analisador_sintatico.y"
                                                   {yyval = yyvsp[0];}
#line 1764 "Analisador_sintatico.tab.c"
    break;

  case 62: /* fator: ativacao  */
#line 279 "Analisador_sintatico.y"
                                                                         {yyval = yyvsp[0];}
#line 1770 "Analisador_sintatico.tab.c"
    break;

  case 63: /* fator: NUM  */
#line 280 "Analisador_sintatico.y"
           {
        yyval = CriaNoExp(NUM_K);
        yyval->Atribuicao.valor = numero;
        yyval->tipo = Integer;
     }
#line 1780 "Analisador_sintatico.tab.c"
    break;

  case 64: /* $@6: %empty  */
#line 286 "Analisador_sintatico.y"
            {
    if(pilha_Inicializada == 0){
        InicializaPilha(&Funcao);
        pilha_Inicializada = 1;
    }
    push(&Funcao, strdup(buffer));
    free(buffer);
    Linha_salva = num_linha;
}
#line 1794 "Analisador_sintatico.tab.c"
    break;

  case 65: /* ativacao: ID $@6 ABR_PAR args FECH_PAR  */
#line 294 "Analisador_sintatico.y"
                       {
    yyval = CriaNoStmt(chamada_K);
    yyval->filho[1] = yyvsp[-1]; // filho direito
    yyval->Atribuicao.nome = pop(&Funcao);
    yyval->linha = Linha_salva;
}
#line 1805 "Analisador_sintatico.tab.c"
    break;

  case 66: /* args: arglista  */
#line 301 "Analisador_sintatico.y"
               {yyval = yyvsp[0];}
#line 1811 "Analisador_sintatico.tab.c"
    break;

  case 67: /* args: %empty  */
#line 301 "Analisador_sintatico.y"
                                   {yyval = NULL;}
#line 1817 "Analisador_sintatico.tab.c"
    break;

  case 68: /* arglista: arglista VG expressao  */
#line 303 "Analisador_sintatico.y"
                               {
    YYSTYPE t = yyvsp[-2];
    // adiciona os nós como irmãos
    if(t!=NULL){
        while(t->irmao != NULL){
            t = t->irmao;
        }
        t->irmao = yyvsp[0];
        yyval = yyvsp[-2];
    }else{
        yyval = yyvsp[0];
    }

}
#line 1836 "Analisador_sintatico.tab.c"
    break;

  case 69: /* arglista: param  */
#line 316 "Analisador_sintatico.y"
                {yyval = yyvsp[0];}
#line 1842 "Analisador_sintatico.tab.c"
    break;

  case 70: /* arglista: expressao  */
#line 317 "Analisador_sintatico.y"
                    {yyval = yyvsp[0];}
#line 1848 "Analisador_sintatico.tab.c"
    break;


#line 1852 "Analisador_sintatico.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 319 "Analisador_sintatico.y"


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
