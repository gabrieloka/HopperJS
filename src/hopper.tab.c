/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "hopper.y"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila/fila.c"
#include "var/var.c"
#include "hash/hash.h"

#define YYSTYPE char*
#define GLOBAL "__GLOBAL__"

fila_var fila_variavel;
filaError fila_erros;
filaTraducao fila_traducao;
int tab = 0;
int cont_caso = 0;
int erros;
char variavel_escolha[50];
char variavel_escolha1[50];
char variavel_escolha2[50];
extern int yylineno;
extern char *yytext;

char *var_nome;
char *var_escopo;
char *var_tipo;
char *c;
char *tipo;
char leiaTipos[256];
char leiaVariaveis[256];

item *temp;

void tabear(){
	int i;
	for(i=0;i<tab;i++)
		push_traducao(&fila_traducao, "    ");
}

void tabear_especial(){ //serve para tabear o palavras como o "else" por exemplo
	int i;
        for(i=0;i<tab-1;i++)
                push_traducao(&fila_traducao, "    ");
}

void cadastrar_variavel(char var_tipo[50])
{
	elementofila_var *elemento_fila_var;
	//push_traducao(&fila_traducao,"var ");
	while(pop_var(&fila_variavel, &elemento_fila_var) == 1)
	{
		if(hash_consultar(elemento_fila_var->token, var_escopo) == 0)
		{
			hash_inserir(elemento_fila_var->token, var_escopo, var_tipo);
		}
		else
		{
			erros++;
			strcat(elemento_fila_var->token, " ");
			strcat(elemento_fila_var->token, var_escopo);		
			yyerror("Variável já declarada: ", yylineno, elemento_fila_var->token);		
		}
	}
}

void verificar_variavel(char variavel[50])
{
	if (hash_consultar(variavel, var_escopo) == 0)
	{
		if (hash_consultar(variavel, GLOBAL) == 0)
		{
			erros++;
			strcat(variavel, " ");
			strcat(variavel, var_escopo);				
			yyerror("Variável não declarada: ", yylineno, variavel);
		}
	}	
}


/* Line 371 of yacc.c  */
#line 150 "hopper.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "hopper.tab.h".  */
#ifndef YY_YY_HOPPER_TAB_H_INCLUDED
# define YY_YY_HOPPER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_ALGORITMO = 258,
     T_STRING = 259,
     T_FIM_COMANDO = 260,
     T_VAR = 261,
     T_IDENTIFICADOR = 262,
     T_TIPO_ATRIBUIDOR = 263,
     T_IDENT_SEPARADOR = 264,
     T_REAL = 265,
     T_INTEIRO = 266,
     T_INICIO = 267,
     T_ESCREVA = 268,
     T_ESCREVAL = 269,
     T_PARENTESE_DIR = 270,
     T_PARENTESE_ESQ = 271,
     T_LEIA = 272,
     T_OPERADOR_ATRIBUICAO = 273,
     T_OPERADOR_SOMA = 274,
     T_OPERADOR_SUBTRACAO = 275,
     T_OPERADOR_MULTIPLICACAO = 276,
     T_OPERADOR_DIVISAO = 277,
     T_OPERADOR_EXPONENCIACAO = 278,
     T_RAIZQ = 279,
     T_FIMALGORITMO = 280,
     T_ABS = 281,
     T_ALEATORIO = 282,
     T_ARCCOS = 283,
     T_ARCSEN = 284,
     T_ARCTAN = 285,
     T_ATE = 286,
     T_ASC = 287,
     T_ARQUIVO = 288,
     T_CARAC = 289,
     T_CARACPNUM = 290,
     T_CARACTERE = 291,
     T_CASO = 292,
     T_COMPR = 293,
     T_COPIA = 294,
     T_COS = 295,
     T_COTAN = 296,
     T_CRONOMETRO = 297,
     T_DE = 298,
     T_DEBUG = 299,
     T_DECLARE = 300,
     T_ECO = 301,
     T_ENQUANTO = 302,
     T_ENTAO = 303,
     T_ESCOLHA = 304,
     T_EXP = 305,
     T_FACA = 306,
     T_FALSO = 307,
     T_FIMENQUANTO = 308,
     T_FIMESCOLHA = 309,
     T_FIMFUNCAO = 310,
     T_FIMPARA = 311,
     T_FIMPROCEDIMENTO = 312,
     T_FIMREPITA = 313,
     T_FIMSE = 314,
     T_FUNCAO = 315,
     T_GRAUPRAD = 316,
     T_INT = 317,
     T_INTERROMPA = 318,
     T_LIMPATELA = 319,
     T_LITERAL = 320,
     T_LOG = 321,
     T_LOGICO = 322,
     T_MAIUSC = 323,
     T_MENSAGEM = 324,
     T_MINUSC = 325,
     T_NUMPCARAC = 326,
     T_NUMERICO = 327,
     T_OUTROCASO = 328,
     T_PARA = 329,
     T_PASSO = 330,
     T_PAUSA = 331,
     T_PI = 332,
     T_POS = 333,
     T_PROCEDIMENTO = 334,
     T_QUAD = 335,
     T_RADPGRAU = 336,
     T_RAND = 337,
     T_RANDI = 338,
     T_REPITA = 339,
     T_RETORNE = 340,
     T_SE = 341,
     T_SEN = 342,
     T_SENAO = 343,
     T_TAN = 344,
     T_TIMER = 345,
     T_VETOR = 346,
     T_VERDADEIRO = 347,
     T_OPERADOR_DIVISAO_INT = 348,
     T_OPERADOR_DIVISAO_RESTO = 349,
     T_OPERADOR_IGUAL = 350,
     T_OPERADOR_DIFERENTE = 351,
     T_OPERADOR_MENOR = 352,
     T_OPERADOR_MAIOR = 353,
     T_OPERADOR_MENOR_IGUAL = 354,
     T_OPERADOR_MAIOR_IGUAL = 355,
     T_COLCHETE_ESQ = 356,
     T_COLCHETE_DIR = 357,
     T_VETOR_INTERVALO = 358,
     T_NUMERO_INTEIRO = 359,
     T_NUMERO_REAL = 360,
     T_OP_LOGICO_E = 361,
     T_OP_LOGICO_XOU = 362,
     T_OP_LOGICO_NAO = 363,
     T_OP_LOGICO_OU = 364,
     T_INVALIDO = 365,
     NEG = 366
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_HOPPER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 340 "hopper.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1045

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  112
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  90
/* YYNRULES -- Number of rules.  */
#define YYNRULES  160
/* YYNRULES -- Number of states.  */
#define YYNSTATES  310

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   366

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    12,    16,    21,
      25,    29,    31,    33,    34,    38,    40,    41,    45,    50,
      56,    58,    60,    62,    66,    68,    70,    72,    74,    76,
      78,    80,    82,    85,    88,    89,   105,   106,   120,   124,
     130,   136,   138,   141,   144,   147,   150,   153,   156,   159,
     162,   165,   171,   175,   178,   180,   185,   187,   191,   192,
     198,   201,   202,   208,   209,   211,   215,   217,   223,   232,
     233,   237,   239,   241,   243,   245,   247,   248,   256,   258,
     261,   262,   263,   270,   271,   276,   277,   278,   291,   293,
     294,   299,   301,   303,   305,   307,   309,   311,   313,   314,
     315,   316,   326,   327,   328,   336,   337,   338,   344,   346,
     348,   350,   352,   354,   355,   360,   361,   366,   367,   372,
     373,   378,   379,   384,   385,   390,   391,   396,   397,   402,
     406,   407,   412,   413,   418,   419,   424,   425,   430,   431,
     436,   437,   442,   445,   448,   449,   450,   456,   457,   458,
     467,   472,   477,   482,   487,   488,   493,   495,   499,   501,
     503
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     115,     0,    -1,    -1,   114,    -1,     5,    -1,   114,     5,
      -1,    -1,   113,   116,   117,    -1,   118,   120,   128,   134,
      -1,   118,   120,   134,    -1,   119,     4,   114,    -1,     3,
      -1,     1,    -1,    -1,   121,   113,   123,    -1,     6,    -1,
      -1,     1,   122,     5,    -1,   125,   124,   127,   114,    -1,
     123,   125,     8,   127,   114,    -1,     8,    -1,     1,    -1,
     200,    -1,   125,   126,   200,    -1,     9,    -1,     1,    -1,
      10,    -1,    11,    -1,    36,    -1,     1,    -1,   129,    -1,
     131,    -1,   128,   129,    -1,   128,   131,    -1,    -1,    60,
     200,   130,    16,   133,    15,   124,   127,   114,   120,    12,
     114,   135,    55,   114,    -1,    -1,    79,   200,   132,    16,
     133,    15,   114,   120,    12,   114,   135,    57,   114,    -1,
     125,   124,   127,    -1,   133,   126,   125,   124,   127,    -1,
      12,   114,   135,    25,   113,    -1,   136,    -1,   135,   136,
      -1,   137,   114,    -1,   139,   114,    -1,   176,   114,    -1,
     144,   114,    -1,   150,   114,    -1,   158,   114,    -1,   169,
     114,    -1,   173,   114,    -1,   200,    16,   199,    15,   114,
      -1,    85,   179,   114,    -1,    63,   114,    -1,     1,    -1,
      17,    16,   138,    15,    -1,   200,    -1,   138,   126,   200,
      -1,    -1,   201,    16,   140,   141,    15,    -1,   179,   143,
      -1,    -1,   179,     9,   142,   179,   143,    -1,    -1,   104,
      -1,   104,   124,   104,    -1,     1,    -1,   145,   148,   114,
     135,   147,    -1,   145,   148,   114,   135,   149,   114,   135,
     147,    -1,    -1,    86,   146,   179,    -1,    59,    -1,     1,
      -1,    48,    -1,     1,    -1,    88,    -1,    -1,    49,   200,
     151,   114,   152,   156,    54,    -1,   153,    -1,   152,   153,
      -1,    -1,    -1,    37,   154,   179,   155,   114,   135,    -1,
      -1,    73,   157,   114,   135,    -1,    -1,    -1,   163,   200,
     159,   165,   179,   166,   160,   161,   164,   114,   135,   167,
      -1,   179,    -1,    -1,   179,   162,   168,   179,    -1,    74,
      -1,    51,    -1,    43,    -1,    31,    -1,    56,    -1,     1,
      -1,    75,    -1,    -1,    -1,    -1,    47,   170,   179,   171,
      51,   172,   114,   135,    53,    -1,    -1,    -1,    84,   174,
     114,   135,    31,   175,   179,    -1,    -1,    -1,   200,   177,
      18,   178,   179,    -1,   200,    -1,   104,    -1,   105,    -1,
      77,    -1,     4,    -1,    -1,    16,   180,   179,    15,    -1,
      -1,   179,    94,   181,   179,    -1,    -1,   179,    19,   182,
     179,    -1,    -1,   179,    20,   183,   179,    -1,    -1,   179,
      21,   184,   179,    -1,    -1,   179,    22,   185,   179,    -1,
      -1,   179,   106,   186,   179,    -1,    -1,   179,   109,   187,
     179,    -1,   179,   107,   179,    -1,    -1,   179,    95,   188,
     179,    -1,    -1,   179,    96,   189,   179,    -1,    -1,   179,
      97,   190,   179,    -1,    -1,   179,    98,   191,   179,    -1,
      -1,   179,    99,   192,   179,    -1,    -1,   179,   100,   193,
     179,    -1,    20,   179,    -1,   179,   108,    -1,    -1,    -1,
      23,   194,   179,   195,   179,    -1,    -1,    -1,    24,    16,
     179,    15,   196,   179,   197,   179,    -1,    68,    16,   179,
      15,    -1,    38,    16,   179,    15,    -1,   200,    16,   199,
      15,    -1,    39,    16,   199,    15,    -1,    -1,    16,     1,
     198,    15,    -1,   179,    -1,   199,     9,   179,    -1,     7,
      -1,    13,    -1,    14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   135,   135,   137,   141,   142,   149,   149,   153,   154,
     158,   162,   163,   166,   168,   172,   173,   173,   178,   179,
     183,   184,   188,   189,   193,   194,   199,   200,   201,   202,
     206,   207,   208,   209,   213,   213,   219,   219,   224,   225,
     229,   233,   234,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   253,   258,   273,   293,   293,
     297,   298,   298,   301,   303,   304,   305,   310,   311,   317,
     317,   322,   323,   327,   328,   332,   336,   336,   340,   341,
     345,   345,   345,   350,   350,   355,   355,   355,   361,   362,
     362,   367,   372,   376,   380,   384,   385,   389,   393,   393,
     393,   393,   397,   397,   397,   401,   401,   401,   405,   406,
     407,   408,   409,   410,   410,   411,   411,   412,   412,   413,
     413,   414,   414,   415,   415,   416,   416,   417,   417,   418,
     419,   419,   420,   420,   421,   421,   422,   422,   423,   423,
     424,   424,   425,   427,   429,   429,   429,   430,   430,   430,
     431,   432,   433,   434,   435,   435,   439,   440,   444,   448,
     449
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ALGORITMO", "T_STRING",
  "T_FIM_COMANDO", "T_VAR", "T_IDENTIFICADOR", "T_TIPO_ATRIBUIDOR",
  "T_IDENT_SEPARADOR", "T_REAL", "T_INTEIRO", "T_INICIO", "T_ESCREVA",
  "T_ESCREVAL", "T_PARENTESE_DIR", "T_PARENTESE_ESQ", "T_LEIA",
  "T_OPERADOR_ATRIBUICAO", "T_OPERADOR_SOMA", "T_OPERADOR_SUBTRACAO",
  "T_OPERADOR_MULTIPLICACAO", "T_OPERADOR_DIVISAO",
  "T_OPERADOR_EXPONENCIACAO", "T_RAIZQ", "T_FIMALGORITMO", "T_ABS",
  "T_ALEATORIO", "T_ARCCOS", "T_ARCSEN", "T_ARCTAN", "T_ATE", "T_ASC",
  "T_ARQUIVO", "T_CARAC", "T_CARACPNUM", "T_CARACTERE", "T_CASO",
  "T_COMPR", "T_COPIA", "T_COS", "T_COTAN", "T_CRONOMETRO", "T_DE",
  "T_DEBUG", "T_DECLARE", "T_ECO", "T_ENQUANTO", "T_ENTAO", "T_ESCOLHA",
  "T_EXP", "T_FACA", "T_FALSO", "T_FIMENQUANTO", "T_FIMESCOLHA",
  "T_FIMFUNCAO", "T_FIMPARA", "T_FIMPROCEDIMENTO", "T_FIMREPITA",
  "T_FIMSE", "T_FUNCAO", "T_GRAUPRAD", "T_INT", "T_INTERROMPA",
  "T_LIMPATELA", "T_LITERAL", "T_LOG", "T_LOGICO", "T_MAIUSC",
  "T_MENSAGEM", "T_MINUSC", "T_NUMPCARAC", "T_NUMERICO", "T_OUTROCASO",
  "T_PARA", "T_PASSO", "T_PAUSA", "T_PI", "T_POS", "T_PROCEDIMENTO",
  "T_QUAD", "T_RADPGRAU", "T_RAND", "T_RANDI", "T_REPITA", "T_RETORNE",
  "T_SE", "T_SEN", "T_SENAO", "T_TAN", "T_TIMER", "T_VETOR",
  "T_VERDADEIRO", "T_OPERADOR_DIVISAO_INT", "T_OPERADOR_DIVISAO_RESTO",
  "T_OPERADOR_IGUAL", "T_OPERADOR_DIFERENTE", "T_OPERADOR_MENOR",
  "T_OPERADOR_MAIOR", "T_OPERADOR_MENOR_IGUAL", "T_OPERADOR_MAIOR_IGUAL",
  "T_COLCHETE_ESQ", "T_COLCHETE_DIR", "T_VETOR_INTERVALO",
  "T_NUMERO_INTEIRO", "T_NUMERO_REAL", "T_OP_LOGICO_E", "T_OP_LOGICO_XOU",
  "T_OP_LOGICO_NAO", "T_OP_LOGICO_OU", "T_INVALIDO", "NEG", "$accept",
  "QuebraComando", "FimComando", "Input", "$@1", "Algoritmo",
  "BlocoCabecalho", "T_Algoritmo", "BlocoDeclaracoes", "T_Var", "$@2",
  "ListaDeclaracoes", "T_Tipo_Atribuidor", "ListaVariaveis",
  "T_Ident_Separador", "TipoVariavel", "BlocoFuncoes", "BlocoFuncao",
  "$@3", "BlocoProcedimento", "$@4", "ListaParametros", "BlocoComando",
  "Comandos", "Comando", "Leia", "ListaLeia", "Escreva", "$@5",
  "ConteudoEscreva", "$@6", "OpcaoCasasDecimais", "BlocoSe", "T_Se", "$@7",
  "T_FimSe", "T_Entao", "T_Senao", "BlocoEscolha", "$@8", "ListaCasos",
  "Caso", "$@9", "$@10", "OutroCaso", "$@11", "BlocoPara", "$@12", "$@13",
  "T_MeioPara", "$@14", "T_Para", "T_Faca", "T_De", "T_Ate", "T_FimPara",
  "T_Passo", "BlocoEnquanto", "$@15", "$@16", "$@17", "BlocoRepita",
  "$@18", "$@19", "Atribuicao", "$@20", "$@21", "Expr", "$@22", "$@23",
  "$@24", "$@25", "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32",
  "$@33", "$@34", "$@35", "$@36", "$@37", "$@38", "$@39", "$@40",
  "List_Expr", "T_Identificador", "T_Escreva", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   112,   113,   113,   114,   114,   116,   115,   117,   117,
     118,   119,   119,   120,   120,   121,   122,   121,   123,   123,
     124,   124,   125,   125,   126,   126,   127,   127,   127,   127,
     128,   128,   128,   128,   130,   129,   132,   131,   133,   133,
     134,   135,   135,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   137,   138,   138,   140,   139,
     141,   142,   141,   143,   143,   143,   143,   144,   144,   146,
     145,   147,   147,   148,   148,   149,   151,   150,   152,   152,
     154,   155,   153,   157,   156,   159,   160,   158,   161,   162,
     161,   163,   164,   165,   166,   167,   167,   168,   170,   171,
     172,   169,   174,   175,   173,   177,   178,   176,   179,   179,
     179,   179,   179,   180,   179,   181,   179,   182,   179,   183,
     179,   184,   179,   185,   179,   186,   179,   187,   179,   179,
     188,   179,   189,   179,   190,   179,   191,   179,   192,   179,
     193,   179,   179,   179,   194,   195,   179,   196,   197,   179,
     179,   179,   179,   179,   198,   179,   199,   199,   200,   201,
     201
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     0,     3,     4,     3,
       3,     1,     1,     0,     3,     1,     0,     3,     4,     5,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     0,    15,     0,    13,     3,     5,
       5,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     5,     3,     2,     1,     4,     1,     3,     0,     5,
       2,     0,     5,     0,     1,     3,     1,     5,     8,     0,
       3,     1,     1,     1,     1,     1,     0,     7,     1,     2,
       0,     0,     6,     0,     4,     0,     0,    12,     1,     0,
       4,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       0,     9,     0,     0,     7,     0,     0,     5,     1,     1,
       1,     1,     1,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     3,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     2,     2,     0,     0,     5,     0,     0,     8,
       4,     4,     4,     4,     0,     4,     1,     3,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     4,     6,     3,     0,     0,     5,     1,    12,    11,
       7,     0,     0,    16,    15,     0,     2,     0,     0,     0,
       0,     0,     0,    30,    31,     9,     0,    10,    17,     0,
     158,    34,    36,    32,    33,     8,    14,     0,    22,    54,
     159,   160,     0,    98,     0,     0,    91,   102,     0,    69,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,     0,     0,     0,     0,    21,    20,    24,
       0,     0,     0,     0,    76,    53,     0,   112,     0,     0,
     144,     0,     0,     0,     0,   111,   109,   110,     0,   108,
       0,     2,    42,    43,    44,    46,    74,    73,     0,    47,
      48,    85,    49,    50,    45,     0,     0,    58,     0,     0,
      25,     0,    29,    26,    27,    28,     0,    23,     0,    56,
      99,     0,     0,   154,     0,   142,     0,     0,     0,     0,
       0,   117,   119,   121,   123,   115,   130,   132,   134,   136,
     138,   140,   125,     0,   143,   127,    52,     0,    70,    40,
       0,     0,   156,     0,   106,     0,     0,     0,     0,     0,
      18,    55,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,     0,     0,     0,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    57,   100,    80,     0,    78,   103,   155,   114,     0,
     147,   151,   153,   150,   118,   120,   122,   124,   116,   131,
     133,   135,   137,   139,   141,   126,   128,   152,    54,    71,
      75,    67,     0,     0,   157,    51,   107,    59,    66,    61,
       0,    60,    38,    21,     0,     0,     0,     0,     0,    83,
      79,     0,     0,   146,     0,     0,    94,    86,     0,     0,
       0,     0,     0,     0,    81,     0,    77,   104,   148,     0,
       0,     0,    65,     0,    39,     0,     0,     0,     0,     0,
      68,     0,    88,    62,     0,     0,   101,     0,     0,   149,
      92,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,    90,     0,    37,    54,    95,    87,     0,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    10,    11,    12,    15,    16,
      18,    36,    70,   156,    71,   116,    22,    23,    64,    24,
      65,   157,    25,    50,    51,    52,   118,    53,   155,   194,
     258,   241,    54,    55,    90,   231,    98,   232,    56,   121,
     204,   205,   248,   277,   251,   265,    57,   151,   270,   281,
     292,    58,   291,   190,   257,   307,   298,    59,    73,   163,
     247,    60,    76,   252,    61,   106,   193,   152,   124,   177,
     173,   174,   175,   176,   184,   186,   178,   179,   180,   181,
     182,   183,   126,   209,   254,   279,   166,   153,    89,    63
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -228
static const yytype_int16 yypact[] =
{
       0,  -228,  -228,     5,    21,   145,  -228,  -228,  -228,  -228,
    -228,     6,    23,  -228,  -228,    -6,     0,     0,    26,     0,
      61,    61,    -6,  -228,  -228,  -228,    61,     5,  -228,   118,
    -228,  -228,  -228,  -228,  -228,  -228,    61,    81,  -228,  -228,
    -228,  -228,    62,  -228,    61,     0,  -228,  -228,    89,  -228,
     337,  -228,     0,     0,     0,    16,     0,     0,    61,     0,
       0,     0,    71,    75,    86,    90,   121,    70,  -228,  -228,
      19,    61,    61,    89,  -228,     5,     0,  -228,    56,    89,
    -228,    94,   110,   122,   133,  -228,  -228,  -228,   430,   134,
      89,     0,  -228,     5,     5,     5,  -228,  -228,     0,     5,
       5,  -228,     5,     5,     5,    89,    97,  -228,    61,    61,
    -228,    19,  -228,  -228,  -228,  -228,     0,  -228,    60,  -228,
     601,     0,   118,  -228,    89,  -228,    89,    89,    89,    89,
      89,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,    89,  -228,  -228,     5,    89,   601,  -228,
     118,   109,   601,    92,  -228,    89,    81,    99,   102,     0,
       5,  -228,    61,    67,    10,   784,   141,   446,   601,   471,
     487,   128,   541,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,   651,    89,   132,   725,  -228,
      89,    89,     0,    89,   157,   320,    19,    66,    61,     0,
       5,  -228,  -228,  -228,   -28,  -228,  -228,  -228,  -228,    89,
    -228,  -228,  -228,  -228,   137,   137,  -228,  -228,   149,     4,
       4,     4,     4,     4,     4,   667,   623,  -228,   159,  -228,
    -228,  -228,     0,   569,   601,     5,   601,  -228,  -228,  -228,
      50,  -228,  -228,  -228,    19,    81,   139,     0,    89,  -228,
    -228,   100,    89,  -228,    89,   118,  -228,  -228,    89,    69,
       0,    19,   167,   118,   601,     0,  -228,   601,   601,   813,
      89,   376,  -228,   139,  -228,     0,   860,     0,   118,    89,
    -228,   129,   585,  -228,   171,   118,  -228,   118,   877,   601,
    -228,     0,   111,     0,   901,   769,   118,  -228,    89,   118,
       0,   942,   601,   959,     5,   179,  -228,  -228,     0,     5
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -228,    -5,   -17,  -228,  -228,  -228,  -228,  -228,  -227,  -228,
    -228,  -228,  -148,   -22,  -105,  -108,  -228,   166,  -228,   168,
    -228,    80,   169,  -100,   -49,  -228,  -228,  -228,  -228,  -228,
    -228,   -76,  -228,  -228,  -228,   -72,  -228,  -228,  -228,  -228,
    -228,    -3,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,   190,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -113,    12,  -228
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -114
static const yytype_int16 yytable[] =
{
      27,    92,    29,   159,    37,     1,    19,    13,   196,   203,
       6,    26,    14,   162,    66,     6,   171,    96,   -13,   262,
     112,     7,   165,   131,   132,   133,   134,    17,    75,   113,
     114,    28,    31,    32,   187,    93,    94,    95,    38,    99,
     100,    62,   102,   103,   104,   249,   284,   203,    38,   244,
     188,   243,   198,   198,    20,   115,    74,   123,    68,   122,
    -113,   110,    62,  -113,    97,   -64,   -13,   243,    30,    69,
     101,   146,  -113,    21,    68,   161,  -113,   -25,    72,  -113,
    -113,   150,    67,   117,   119,   -13,   149,   105,   242,    68,
      69,   107,   259,    77,  -113,  -113,    30,   261,   135,   160,
     110,   191,   108,   110,   164,    78,   109,   192,    69,    79,
     127,    69,    80,    81,   197,   154,    92,   199,   202,    39,
      38,    38,   110,     6,  -113,    30,   128,    82,    83,   111,
      69,    40,    41,  -113,    62,    42,   260,   191,   129,    92,
      13,   191,   200,   212,     6,    14,     8,   227,     9,   130,
     147,   -13,   189,   274,   266,   269,   207,    84,   133,   134,
    -113,  -113,    62,   276,   -72,    43,    85,    44,   131,   132,
     133,   134,   237,   272,   201,   235,   245,    62,   288,   275,
     290,    45,   246,   293,   -96,   294,   297,   295,    33,   158,
      34,    35,    46,    86,    87,   283,   301,   280,     0,   303,
      62,   250,    47,    48,    49,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,   255,     0,     0,     0,     0,
      92,     0,     0,     0,     0,     0,     0,    92,     0,     0,
     263,     0,     0,     0,     0,     0,     0,     0,    88,    92,
       0,     0,     0,   273,     0,    92,    92,     0,   278,     0,
       0,     0,    92,     0,    92,     0,     0,     0,   285,     0,
     287,     0,     0,   120,     0,     0,     0,    62,     0,   125,
       0,     0,     0,     0,   296,    62,   299,     0,     0,     0,
     148,    62,     0,   304,     0,     0,     0,     0,    62,     0,
      62,   309,     0,     0,     0,     0,     0,    62,     0,    62,
      62,     0,     0,     0,     0,     0,    62,    62,    62,     0,
       0,    62,     0,    62,   167,    62,   168,   169,   170,     0,
     172,   238,     0,     0,     0,     0,     0,     0,     0,   239,
       0,     0,     0,   185,     0,   -63,     0,     0,    39,   131,
     132,   133,   134,     0,    30,   195,     0,     0,     0,     0,
      40,    41,     0,     0,    42,     0,     0,     0,     0,     0,
       0,     0,    91,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,     0,   226,   238,     0,     0,
     233,   234,     0,   236,    43,     0,    44,     0,     0,     0,
       0,   -63,     0,     0,     0,   131,   132,   133,   134,   253,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,   135,   136,   137,   138,   139,   140,
     141,    47,    48,    49,   240,     0,   142,   143,   144,   145,
       0,     0,     0,     0,     0,     1,     0,     0,   264,     0,
       0,     0,   267,     0,   268,     0,     0,     0,   271,   131,
     132,   133,   134,     0,     0,     0,     0,     0,     0,     0,
     282,   208,     0,     0,     0,   131,   132,   133,   134,   289,
     135,   136,   137,   138,   139,   140,   141,     0,     0,     0,
     240,     0,   142,   143,   144,   145,   210,     0,   302,     0,
     131,   132,   133,   134,     0,     0,     0,     0,     0,     0,
       0,     0,   211,     0,     0,     0,   131,   132,   133,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   136,   137,   138,   139,   140,
     141,     0,     0,     0,     0,     0,   142,   143,   144,   145,
     135,   136,   137,   138,   139,   140,   141,     0,     0,     0,
       0,     0,   142,   143,   144,   145,   213,     0,     0,     0,
     131,   132,   133,   134,     0,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,     0,     0,   142,   143,   144,
     145,   135,   136,   137,   138,   139,   140,   141,   131,   132,
     133,   134,     0,   142,   143,   144,   145,     0,     0,     0,
     256,     0,     0,     0,   131,   132,   133,   134,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,   132,   133,   134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   135,   136,   137,   138,   139,
     140,   141,   131,   132,   133,   134,     0,   142,   143,   144,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -89,     0,     0,   135,   136,   137,   138,   139,   140,   141,
     131,   132,   133,   134,     0,   142,   143,   144,   145,   135,
     136,   137,   138,   139,   140,   141,   131,   132,   133,   134,
       0,   142,   143,   144,   145,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,     0,     0,   142,   143,   144,
     145,     0,     0,     0,     0,     0,     0,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   228,     0,     0,   142,
     143,   144,    30,     0,     0,     0,     0,     0,    40,    41,
       0,     0,    42,     0,     0,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,     0,     0,   142,     0,   144,
       0,   135,   136,   137,   138,   139,   140,   141,     0,     0,
      39,     0,    43,     0,    44,   144,    30,     0,     0,     0,
       0,     0,    40,    41,   229,    39,    42,     0,    45,     0,
       0,    30,     0,     0,     0,     0,     0,    40,    41,    46,
       0,    42,     0,     0,     0,     0,   -82,     0,     0,    47,
      48,    49,     0,   230,   228,   206,    43,     0,    44,     0,
      30,     0,     0,     0,     0,     0,    40,    41,     0,     0,
      42,    43,    45,    44,     0,     0,     0,     0,     0,     0,
       0,     0,   -82,    46,     0,     0,     0,    45,     0,     0,
       0,     0,     0,    47,    48,    49,     0,     0,    46,     0,
      43,    39,    44,     0,     0,     0,     0,    30,    47,    48,
      49,     0,   229,    40,    41,     0,    45,    42,    39,     0,
       0,     0,     0,     0,    30,     0,     0,    46,     0,     0,
      40,    41,     0,     0,    42,     0,     0,    47,    48,    49,
       0,     0,    39,     0,     0,     0,     0,    43,    30,    44,
       0,     0,     0,   286,    40,    41,     0,     0,    42,     0,
       0,     0,     0,    45,    43,     0,    44,     0,     0,     0,
       0,   -84,     0,     0,    46,     0,     0,     0,     0,     0,
      45,     0,     0,   305,    47,    48,    49,     0,    43,    30,
      44,    46,     0,     0,     0,    40,    41,     0,   300,    42,
      39,    47,    48,    49,    45,     0,    30,     0,     0,     0,
       0,     0,    40,    41,     0,    46,    42,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    48,    49,     0,    43,
       0,    44,     0,     0,     0,     0,     0,     0,   306,     0,
       0,     0,     0,     0,     0,    45,    43,     0,    44,     0,
       0,     0,     0,     0,   308,     0,    46,     0,     0,     0,
       0,     0,    45,     0,     0,     0,    47,    48,    49,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,    48,    49
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-228)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      17,    50,    19,   111,    26,     5,    12,     1,   156,    37,
       5,    16,     6,   118,    36,     5,   129,     1,    12,   246,
       1,     0,   122,    19,    20,    21,    22,     4,    45,    10,
      11,     5,    20,    21,   147,    52,    53,    54,    26,    56,
      57,    29,    59,    60,    61,    73,   273,    37,    36,   197,
     150,     1,   157,   158,    60,    36,    44,     1,     8,    76,
       4,     1,    50,     7,    48,    15,    60,     1,     7,     9,
      58,    88,    16,    79,     8,    15,    20,     7,    16,    23,
      24,    98,     1,    71,    72,    79,    91,    16,   196,     8,
       9,    16,   240,     4,    38,    39,     7,   245,    94,   116,
       1,     9,    16,     1,   121,    16,    16,    15,     9,    20,
      16,     9,    23,    24,    15,    18,   165,    15,    51,     1,
     108,   109,     1,     5,    68,     7,    16,    38,    39,     8,
       9,    13,    14,    77,   122,    17,   244,     9,    16,   188,
       1,     9,   159,    15,     5,     6,     1,    15,     3,    16,
      16,    12,    43,   261,    54,   255,    15,    68,    21,    22,
     104,   105,   150,   263,     5,    47,    77,    49,    19,    20,
      21,    22,    15,   104,   162,   192,   198,   165,   278,    12,
      51,    63,   199,    12,     5,   285,    75,   287,    22,   109,
      22,    22,    74,   104,   105,   271,   296,   269,    -1,   299,
     188,   204,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,    -1,    -1,    -1,   276,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,   288,
      -1,    -1,    -1,   260,    -1,   294,   295,    -1,   265,    -1,
      -1,    -1,   301,    -1,   303,    -1,    -1,    -1,   275,    -1,
     277,    -1,    -1,    73,    -1,    -1,    -1,   255,    -1,    79,
      -1,    -1,    -1,    -1,   291,   263,   293,    -1,    -1,    -1,
      90,   269,    -1,   300,    -1,    -1,    -1,    -1,   276,    -1,
     278,   308,    -1,    -1,    -1,    -1,    -1,   285,    -1,   287,
     288,    -1,    -1,    -1,    -1,    -1,   294,   295,   296,    -1,
      -1,   299,    -1,   301,   124,   303,   126,   127,   128,    -1,
     130,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    -1,   143,    -1,    15,    -1,    -1,     1,    19,
      20,    21,    22,    -1,     7,   155,    -1,    -1,    -1,    -1,
      13,    14,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,    -1,   186,     1,    -1,    -1,
     190,   191,    -1,   193,    47,    -1,    49,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    19,    20,    21,    22,   209,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,    84,    85,    86,   104,    -1,   106,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,   248,    -1,
      -1,    -1,   252,    -1,   254,    -1,    -1,    -1,   258,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     270,    15,    -1,    -1,    -1,    19,    20,    21,    22,   279,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
     104,    -1,   106,   107,   108,   109,    15,    -1,   298,    -1,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,   109,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,    -1,   106,   107,   108,   109,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,
     109,    94,    95,    96,    97,    98,    99,   100,    19,    20,
      21,    22,    -1,   106,   107,   108,   109,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,    19,    20,    21,    22,    -1,   106,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
      19,    20,    21,    22,    -1,   106,   107,   108,   109,    94,
      95,    96,    97,    98,    99,   100,    19,    20,    21,    22,
      -1,   106,   107,   108,   109,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,     1,    -1,    -1,   106,
     107,   108,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    17,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    -1,   106,    -1,   108,
      -1,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
       1,    -1,    47,    -1,    49,   108,     7,    -1,    -1,    -1,
      -1,    -1,    13,    14,    59,     1,    17,    -1,    63,    -1,
      -1,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,    74,
      -1,    17,    -1,    -1,    -1,    -1,    37,    -1,    -1,    84,
      85,    86,    -1,    88,     1,    31,    47,    -1,    49,    -1,
       7,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,
      17,    47,    63,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    -1,    -1,    74,    -1,
      47,     1,    49,    -1,    -1,    -1,    -1,     7,    84,    85,
      86,    -1,    59,    13,    14,    -1,    63,    17,     1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    -1,    74,    -1,    -1,
      13,    14,    -1,    -1,    17,    -1,    -1,    84,    85,    86,
      -1,    -1,     1,    -1,    -1,    -1,    -1,    47,     7,    49,
      -1,    -1,    -1,    53,    13,    14,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    63,    47,    -1,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,     1,    84,    85,    86,    -1,    47,     7,
      49,    74,    -1,    -1,    -1,    13,    14,    -1,    57,    17,
       1,    84,    85,    86,    63,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    74,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    -1,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    84,    85,    86,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,   113,   114,   115,   116,     5,     0,     1,     3,
     117,   118,   119,     1,     6,   120,   121,     4,   122,    12,
      60,    79,   128,   129,   131,   134,   113,   114,     5,   114,
       7,   200,   200,   129,   131,   134,   123,   125,   200,     1,
      13,    14,    17,    47,    49,    63,    74,    84,    85,    86,
     135,   136,   137,   139,   144,   145,   150,   158,   163,   169,
     173,   176,   200,   201,   130,   132,   125,     1,     8,     9,
     124,   126,    16,   170,   200,   114,   174,     4,    16,    20,
      23,    24,    38,    39,    68,    77,   104,   105,   179,   200,
     146,    25,   136,   114,   114,   114,     1,    48,   148,   114,
     114,   200,   114,   114,   114,    16,   177,    16,    16,    16,
       1,     8,     1,    10,    11,    36,   127,   200,   138,   200,
     179,   151,   114,     1,   180,   179,   194,    16,    16,    16,
      16,    19,    20,    21,    22,    94,    95,    96,    97,    98,
      99,   100,   106,   107,   108,   109,   114,    16,   179,   113,
     114,   159,   179,   199,    18,   140,   125,   133,   133,   127,
     114,    15,   126,   171,   114,   135,   198,   179,   179,   179,
     179,   199,   179,   182,   183,   184,   185,   181,   188,   189,
     190,   191,   192,   193,   186,   179,   187,   199,   135,    43,
     165,     9,    15,   178,   141,   179,   124,    15,   126,    15,
     114,   200,    51,    37,   152,   153,    31,    15,    15,   195,
      15,    15,    15,    15,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,    15,     1,    59,
      88,   147,   149,   179,   179,   114,   179,    15,     1,     9,
     104,   143,   127,     1,   124,   125,   114,   172,   154,    73,
     153,   156,   175,   179,   196,   114,    31,   166,   142,   124,
     127,   124,   120,   114,   179,   157,    54,   179,   179,   135,
     160,   179,   104,   114,   127,    12,   135,   155,   114,   197,
     147,   161,   179,   143,   120,   114,    53,   114,   135,   179,
      51,   164,   162,    12,   135,   135,   114,    75,   168,   114,
      57,   135,   179,   135,   114,     1,    56,   167,    55,   114
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
/* Line 1787 of yacc.c  */
#line 149 "hopper.y"
    {var_escopo = GLOBAL;}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 163 "hopper.y"
    {erros++; yyerror("Esperava ALGORITMO, encontrado: ", yylineno, yytext);}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 173 "hopper.y"
    {erros++; yyerror("Esperava VAR, encontrado: ", yylineno, yytext);}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 184 "hopper.y"
    {erros++; yyerror("Esperava '=', encontrado: ", yylineno, yytext);}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 188 "hopper.y"
    {push_var(&fila_variavel,(yyvsp[(1) - (1)]));}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 189 "hopper.y"
    {push_var(&fila_variavel, (yyvsp[(3) - (3)]));}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 194 "hopper.y"
    {erros++; yyerror("Esperava VIRGULA, encontrado: ", yylineno, yytext);}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 199 "hopper.y"
    {cadastrar_variavel("Float");}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 200 "hopper.y"
    {cadastrar_variavel("Int");}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 201 "hopper.y"
    {cadastrar_variavel("string");}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 202 "hopper.y"
    {erros++; yyerror("Tipo de variavel desconhecido: ", yylineno, yytext);}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 213 "hopper.y"
    {var_escopo = (yyvsp[(2) - (2)]);}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 214 "hopper.y"
    {var_escopo = GLOBAL;}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 219 "hopper.y"
    {var_escopo = (yyvsp[(2) - (2)]);}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 220 "hopper.y"
    {var_escopo = GLOBAL;}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 238 "hopper.y"
    {push_traducao(&fila_traducao,";\n");}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 239 "hopper.y"
    {push_traducao(&fila_traducao,";\n");}
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 246 "hopper.y"
    {push_traducao(&fila_traducao,";\n");}
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 247 "hopper.y"
    {push_traducao(&fila_traducao,";\n");}
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 249 "hopper.y"
    {erros++; yyerror("Comando inválido: ", yylineno, yytext);}
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 258 "hopper.y"
    {
		verificar_variavel(strdup((yyvsp[(1) - (1)])));
		hash_consultar2(strdup((yyvsp[(1) - (1)])),var_escopo,&temp);
		char *tipo_string;
		char s[250];
		tipo_string = temp->tipo;
		printf(": %s %s %s\n",temp->key.nome, temp->key.escopo, tipo_string);
		if(strcmp(tipo_string,"string")==0){
			sprintf(s,"%s = window.prompt(\" \")",strdup((yyvsp[(1) - (1)])));
		}else{
			sprintf(s,"%s = parse%s(window.prompt(\" \"))",strdup((yyvsp[(1) - (1)])),tipo_string);
		}
		tabear();
		push_traducao(&fila_traducao,s);
	}
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 273 "hopper.y"
    {
		verificar_variavel(strdup((yyvsp[(3) - (3)])));
		hash_consultar2(strdup((yyvsp[(3) - (3)])),var_escopo,&temp);
		char *tipo_string;
		char s[250];
		tipo_string = temp->tipo;
		printf(": %s %s %s\n",temp->key.nome, temp->key.escopo, tipo_string);
		if(strcmp(tipo_string,"string")==0){
			sprintf(s,"%s = window.prompt(\" \")",strdup((yyvsp[(3) - (3)])));
		}else{
			sprintf(s,"%s = parse%s(window.prompt(\" \"))",strdup((yyvsp[(3) - (3)])),tipo_string);
		}
		tabear();
		push_traducao(&fila_traducao,s);
	}
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 293 "hopper.y"
    {push_traducao(&fila_traducao,"(");}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 293 "hopper.y"
    {push_traducao(&fila_traducao,")");}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 297 "hopper.y"
    {char s[50] = "+\"<br>\"";push_traducao(&fila_traducao,s);}
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 298 "hopper.y"
    {push_traducao(&fila_traducao,", ");}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 298 "hopper.y"
    {char s[50] = ",\"<br>\"";push_traducao(&fila_traducao,s);}
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 305 "hopper.y"
    {erros++; yyerror("Formatacao de casas decimais inválidas", yylineno, yytext);}
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 310 "hopper.y"
    {tabear();push_traducao(&fila_traducao, "}\n");}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 311 "hopper.y"
    {tabear();push_traducao(&fila_traducao, "}\n");}
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 317 "hopper.y"
    {tabear();push_traducao(&fila_traducao,"if (");}
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 317 "hopper.y"
    {push_traducao(&fila_traducao, ") ");}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 322 "hopper.y"
    {tab--;}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 323 "hopper.y"
    {erros++; yyerror("Esperava } encontrado: ", yylineno, yytext);}
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 327 "hopper.y"
    {push_traducao(&fila_traducao," {\n");tab++;}
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 328 "hopper.y"
    {erros++; yyerror("Esperava {, encontrado: ", yylineno, yytext);}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 332 "hopper.y"
    {tabear_especial();push_traducao(&fila_traducao, "}\n");tabear_especial();push_traducao(&fila_traducao, "else { \n");}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 336 "hopper.y"
    {verificar_variavel(strdup((yyvsp[(2) - (2)])));sprintf(variavel_escolha, "switch ( %s ){\n",(yyvsp[(2) - (2)]));tab++;push_traducao(&fila_traducao, variavel_escolha);}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 336 "hopper.y"
    {tab--;cont_caso = 0;push_traducao(&fila_traducao,"}\n");}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 345 "hopper.y"
    {cont_caso++;tabear_especial();if(cont_caso>0);push_traducao(&fila_traducao, "case ");}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 345 "hopper.y"
    {push_traducao(&fila_traducao, ":\n");}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 345 "hopper.y"
    {tabear();push_traducao(&fila_traducao, "break;\n");}
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 350 "hopper.y"
    {tabear_especial();push_traducao(&fila_traducao, "default:\n");}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 355 "hopper.y"
    {verificar_variavel(strdup((yyvsp[(2) - (2)])));sprintf(variavel_escolha, "%s",(yyvsp[(2) - (2)])); push_traducao(&fila_traducao,variavel_escolha);}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 355 "hopper.y"
    {push_traducao(&fila_traducao,variavel_escolha);push_traducao(&fila_traducao,"<=");}
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 361 "hopper.y"
    {push_traducao(&fila_traducao,";");push_traducao(&fila_traducao,variavel_escolha);push_traducao(&fila_traducao,"++");}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 362 "hopper.y"
    {push_traducao(&fila_traducao,";");push_traducao(&fila_traducao,variavel_escolha);push_traducao(&fila_traducao,"=");push_traducao(&fila_traducao,variavel_escolha);push_traducao(&fila_traducao,"+");}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 367 "hopper.y"
    {tabear();push_traducao(&fila_traducao, "for (");tab++;}
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 372 "hopper.y"
    {push_traducao(&fila_traducao, "){\n");}
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 376 "hopper.y"
    {push_traducao(&fila_traducao, "=");}
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 380 "hopper.y"
    {push_traducao(&fila_traducao, ";");}
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 384 "hopper.y"
    {push_traducao(&fila_traducao,"}\n");tab--;}
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 385 "hopper.y"
    {erros++; yyerror("Esperava } encontrado: ", yylineno, yytext);}
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 393 "hopper.y"
    {tabear();push_traducao(&fila_traducao, "while(");tab++;}
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 393 "hopper.y"
    {push_traducao(&fila_traducao, ")");}
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 393 "hopper.y"
    {push_traducao(&fila_traducao, "{\n");}
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 393 "hopper.y"
    {push_traducao(&fila_traducao, "}\n");tab--;}
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 397 "hopper.y"
    {tabear();push_traducao(&fila_traducao, "do{\n");tab++;}
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 397 "hopper.y"
    {tabear_especial();push_traducao(&fila_traducao, "}while ");}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 397 "hopper.y"
    {push_traducao(&fila_traducao, ";\n");tab--;}
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 401 "hopper.y"
    {verificar_variavel(strdup((yyvsp[(1) - (1)])));tabear();push_traducao(&fila_traducao, (yyvsp[(1) - (1)]));}
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 401 "hopper.y"
    {push_traducao(&fila_traducao, " = ");}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 401 "hopper.y"
    {push_traducao(&fila_traducao, ";\n");}
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 405 "hopper.y"
    {verificar_variavel(strdup((yyvsp[(1) - (1)])));char s[50];sprintf(s,"%s", (yyvsp[(1) - (1)]));push_traducao(&fila_traducao, s);}
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 406 "hopper.y"
    {char s[50];sprintf(s,"%i", atoi(yylval));push_traducao(&fila_traducao, s);}
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 407 "hopper.y"
    {char s[50];sprintf(s,"%f", atof(yylval));push_traducao(&fila_traducao, s);}
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 408 "hopper.y"
    {push_traducao(&fila_traducao, "Math.PI");}
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 409 "hopper.y"
    {(yyval) = strdup(yytext); push_traducao(&fila_traducao,(yyval));}
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 410 "hopper.y"
    {push_traducao(&fila_traducao,"(");}
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 410 "hopper.y"
    {push_traducao(&fila_traducao,")"); }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 411 "hopper.y"
    {push_traducao(&fila_traducao, " % ");}
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 412 "hopper.y"
    {push_traducao(&fila_traducao, " + ");}
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 413 "hopper.y"
    {push_traducao(&fila_traducao, " - ");}
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 414 "hopper.y"
    {push_traducao(&fila_traducao, " * ");}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 415 "hopper.y"
    {push_traducao(&fila_traducao, " / ");}
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 416 "hopper.y"
    {push_traducao(&fila_traducao, " && ");}
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 417 "hopper.y"
    {push_traducao(&fila_traducao, " || ");}
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 419 "hopper.y"
    {push_traducao(&fila_traducao, " == ");}
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 420 "hopper.y"
    {push_traducao(&fila_traducao, " != ");}
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 421 "hopper.y"
    {push_traducao(&fila_traducao, " < ");}
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 422 "hopper.y"
    {push_traducao(&fila_traducao, " > ");}
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 423 "hopper.y"
    {push_traducao(&fila_traducao, " <= ");}
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 424 "hopper.y"
    {push_traducao(&fila_traducao, " >= ");}
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 429 "hopper.y"
    {push_traducao(&fila_traducao, "Math.pow(");}
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 429 "hopper.y"
    {push_traducao(&fila_traducao, " , ");}
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 429 "hopper.y"
    {push_traducao(&fila_traducao, ")");}
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 430 "hopper.y"
    {push_traducao(&fila_traducao, "Math.sqrt(");}
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 430 "hopper.y"
    {push_traducao(&fila_traducao, " , ");}
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 430 "hopper.y"
    {push_traducao(&fila_traducao, ")");}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 435 "hopper.y"
    {erros++; yyerror("Expressao inválida", yylineno, yytext);}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 444 "hopper.y"
    { (yyval) = strdup(yytext);}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 448 "hopper.y"
    {tabear();push_traducao(&fila_traducao,"document.write");}
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 449 "hopper.y"
    {tabear();push_traducao(&fila_traducao,"document.write");}
    break;


/* Line 1787 of yacc.c  */
#line 2698 "hopper.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 452 "hopper.y"


int main(int ac, char **av) {
	FILE *file_traducao;
	extern FILE *yyin;



	cria_fila_var(&fila_variavel);
	cria_fila_error(&fila_erros);
	cria_fila_traducao(&fila_traducao);	


	if(ac > 1 && (yyin = fopen(av[1], "r")) == NULL) {
		perror(av[1]);
		exit(1);
	}


	yyparse();

	if(!erros){
		printf("\n\nO algoritmo é valido!\n");
		file_traducao= fopen ("traducao.js", "w+");
		cria_arquivo(&fila_traducao,file_traducao);	
	}
	else
	{
		printf("\n\nExistem erros no algoritmo.\n");
	}
}

int yyerror(char *msg, int line, char *token )
{
	printf ("ERRO -> Linha: %d. %s %s \n", yylineno, msg, token);
	return 0;
}

int yywrap(void)
{
	return 1;
}

