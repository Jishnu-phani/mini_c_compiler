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
#line 1 "parsertest.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
    #include "lex.yy.c"
	#define YYSTYPE char*

	void yyerror(const char* s);
	int yylex();
	extern int yylineno;

    void add(char, char *);
    void insert_type();
    int search(char *);

    struct dataType{
        char* id_name;
        char* data_type;
        char* type;
        int line_no;
        int scope;
    } symbol_table[40];

    int count=0;
    int scope = 0;
    int q;
    char type[10];
    extern int countn;


#line 102 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    T_INT = 258,                   /* T_INT  */
    T_CHAR = 259,                  /* T_CHAR  */
    T_DOUBLE = 260,                /* T_DOUBLE  */
    T_WHILE = 261,                 /* T_WHILE  */
    T_INC = 262,                   /* T_INC  */
    T_DEC = 263,                   /* T_DEC  */
    T_OROR = 264,                  /* T_OROR  */
    T_ANDAND = 265,                /* T_ANDAND  */
    T_EQCOMP = 266,                /* T_EQCOMP  */
    T_NOTEQUAL = 267,              /* T_NOTEQUAL  */
    T_GREATEREQ = 268,             /* T_GREATEREQ  */
    T_LESSEREQ = 269,              /* T_LESSEREQ  */
    T_LEFTSHIFT = 270,             /* T_LEFTSHIFT  */
    T_RIGHTSHIFT = 271,            /* T_RIGHTSHIFT  */
    T_PRINTLN = 272,               /* T_PRINTLN  */
    T_STRING = 273,                /* T_STRING  */
    T_FLOAT = 274,                 /* T_FLOAT  */
    T_BOOLEAN = 275,               /* T_BOOLEAN  */
    T_IF = 276,                    /* T_IF  */
    T_ELSE = 277,                  /* T_ELSE  */
    T_STRLITERAL = 278,            /* T_STRLITERAL  */
    T_DO = 279,                    /* T_DO  */
    T_INCLUDE = 280,               /* T_INCLUDE  */
    T_HEADER = 281,                /* T_HEADER  */
    T_MAIN = 282,                  /* T_MAIN  */
    T_ID = 283,                    /* T_ID  */
    T_NUM = 284,                   /* T_NUM  */
    T_PRINTFF = 285,               /* T_PRINTFF  */
    T_SCANFF = 286,                /* T_SCANFF  */
    T_VOID = 287,                  /* T_VOID  */
    T_RETURN = 288,                /* T_RETURN  */
    T_FOR = 289,                   /* T_FOR  */
    T_TRUE = 290,                  /* T_TRUE  */
    T_FALSE = 291,                 /* T_FALSE  */
    T_LOGAND = 292,                /* T_LOGAND  */
    T_LOGOR = 293,                 /* T_LOGOR  */
    T_SQBRACK = 294,               /* T_SQBRACK  */
    T_BREAK = 295,                 /* T_BREAK  */
    T_CONTINUE = 296,              /* T_CONTINUE  */
    T_CASE = 297,                  /* T_CASE  */
    T_SWITCH = 298,                /* T_SWITCH  */
    T_DEFAULT = 299                /* T_DEFAULT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_INT 258
#define T_CHAR 259
#define T_DOUBLE 260
#define T_WHILE 261
#define T_INC 262
#define T_DEC 263
#define T_OROR 264
#define T_ANDAND 265
#define T_EQCOMP 266
#define T_NOTEQUAL 267
#define T_GREATEREQ 268
#define T_LESSEREQ 269
#define T_LEFTSHIFT 270
#define T_RIGHTSHIFT 271
#define T_PRINTLN 272
#define T_STRING 273
#define T_FLOAT 274
#define T_BOOLEAN 275
#define T_IF 276
#define T_ELSE 277
#define T_STRLITERAL 278
#define T_DO 279
#define T_INCLUDE 280
#define T_HEADER 281
#define T_MAIN 282
#define T_ID 283
#define T_NUM 284
#define T_PRINTFF 285
#define T_SCANFF 286
#define T_VOID 287
#define T_RETURN 288
#define T_FOR 289
#define T_TRUE 290
#define T_FALSE 291
#define T_LOGAND 292
#define T_LOGOR 293
#define T_SQBRACK 294
#define T_BREAK 295
#define T_CONTINUE 296
#define T_CASE 297
#define T_SWITCH 298
#define T_DEFAULT 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_INT = 3,                      /* T_INT  */
  YYSYMBOL_T_CHAR = 4,                     /* T_CHAR  */
  YYSYMBOL_T_DOUBLE = 5,                   /* T_DOUBLE  */
  YYSYMBOL_T_WHILE = 6,                    /* T_WHILE  */
  YYSYMBOL_T_INC = 7,                      /* T_INC  */
  YYSYMBOL_T_DEC = 8,                      /* T_DEC  */
  YYSYMBOL_T_OROR = 9,                     /* T_OROR  */
  YYSYMBOL_T_ANDAND = 10,                  /* T_ANDAND  */
  YYSYMBOL_T_EQCOMP = 11,                  /* T_EQCOMP  */
  YYSYMBOL_T_NOTEQUAL = 12,                /* T_NOTEQUAL  */
  YYSYMBOL_T_GREATEREQ = 13,               /* T_GREATEREQ  */
  YYSYMBOL_T_LESSEREQ = 14,                /* T_LESSEREQ  */
  YYSYMBOL_T_LEFTSHIFT = 15,               /* T_LEFTSHIFT  */
  YYSYMBOL_T_RIGHTSHIFT = 16,              /* T_RIGHTSHIFT  */
  YYSYMBOL_T_PRINTLN = 17,                 /* T_PRINTLN  */
  YYSYMBOL_T_STRING = 18,                  /* T_STRING  */
  YYSYMBOL_T_FLOAT = 19,                   /* T_FLOAT  */
  YYSYMBOL_T_BOOLEAN = 20,                 /* T_BOOLEAN  */
  YYSYMBOL_T_IF = 21,                      /* T_IF  */
  YYSYMBOL_T_ELSE = 22,                    /* T_ELSE  */
  YYSYMBOL_T_STRLITERAL = 23,              /* T_STRLITERAL  */
  YYSYMBOL_T_DO = 24,                      /* T_DO  */
  YYSYMBOL_T_INCLUDE = 25,                 /* T_INCLUDE  */
  YYSYMBOL_T_HEADER = 26,                  /* T_HEADER  */
  YYSYMBOL_T_MAIN = 27,                    /* T_MAIN  */
  YYSYMBOL_T_ID = 28,                      /* T_ID  */
  YYSYMBOL_T_NUM = 29,                     /* T_NUM  */
  YYSYMBOL_T_PRINTFF = 30,                 /* T_PRINTFF  */
  YYSYMBOL_T_SCANFF = 31,                  /* T_SCANFF  */
  YYSYMBOL_T_VOID = 32,                    /* T_VOID  */
  YYSYMBOL_T_RETURN = 33,                  /* T_RETURN  */
  YYSYMBOL_T_FOR = 34,                     /* T_FOR  */
  YYSYMBOL_T_TRUE = 35,                    /* T_TRUE  */
  YYSYMBOL_T_FALSE = 36,                   /* T_FALSE  */
  YYSYMBOL_T_LOGAND = 37,                  /* T_LOGAND  */
  YYSYMBOL_T_LOGOR = 38,                   /* T_LOGOR  */
  YYSYMBOL_T_SQBRACK = 39,                 /* T_SQBRACK  */
  YYSYMBOL_T_BREAK = 40,                   /* T_BREAK  */
  YYSYMBOL_T_CONTINUE = 41,                /* T_CONTINUE  */
  YYSYMBOL_T_CASE = 42,                    /* T_CASE  */
  YYSYMBOL_T_SWITCH = 43,                  /* T_SWITCH  */
  YYSYMBOL_T_DEFAULT = 44,                 /* T_DEFAULT  */
  YYSYMBOL_45_ = 45,                       /* '<'  */
  YYSYMBOL_46_ = 46,                       /* '>'  */
  YYSYMBOL_47_ = 47,                       /* ';'  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_49_ = 49,                       /* '['  */
  YYSYMBOL_50_ = 50,                       /* ']'  */
  YYSYMBOL_51_ = 51,                       /* '='  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* '+'  */
  YYSYMBOL_55_ = 55,                       /* '-'  */
  YYSYMBOL_56_ = 56,                       /* '*'  */
  YYSYMBOL_57_ = 57,                       /* '/'  */
  YYSYMBOL_58_ = 58,                       /* '('  */
  YYSYMBOL_59_ = 59,                       /* ')'  */
  YYSYMBOL_60_ = 60,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_START = 62,                     /* START  */
  YYSYMBOL_63_1 = 63,                      /* $@1  */
  YYSYMBOL_PROG = 64,                      /* PROG  */
  YYSYMBOL_DECLR = 65,                     /* DECLR  */
  YYSYMBOL_LISTVAR = 66,                   /* LISTVAR  */
  YYSYMBOL_VAR = 67,                       /* VAR  */
  YYSYMBOL_DIMS = 68,                      /* DIMS  */
  YYSYMBOL_TYPE = 69,                      /* TYPE  */
  YYSYMBOL_ASSGN = 70,                     /* ASSGN  */
  YYSYMBOL_ARRELEM = 71,                   /* ARRELEM  */
  YYSYMBOL_ARRDEF = 72,                    /* ARRDEF  */
  YYSYMBOL_UNARYEXPR = 73,                 /* UNARYEXPR  */
  YYSYMBOL_EXPR = 74,                      /* EXPR  */
  YYSYMBOL_LOGIC_EXPR = 75,                /* LOGIC_EXPR  */
  YYSYMBOL_AND_EXPR = 76,                  /* AND_EXPR  */
  YYSYMBOL_REL_EXPR = 77,                  /* REL_EXPR  */
  YYSYMBOL_E = 78,                         /* E  */
  YYSYMBOL_T = 79,                         /* T  */
  YYSYMBOL_F = 80,                         /* F  */
  YYSYMBOL_REL_OP = 81,                    /* REL_OP  */
  YYSYMBOL_MAIN = 82,                      /* MAIN  */
  YYSYMBOL_83_2 = 83,                      /* $@2  */
  YYSYMBOL_84_3 = 84,                      /* $@3  */
  YYSYMBOL_EMPTY_LISTVAR = 85,             /* EMPTY_LISTVAR  */
  YYSYMBOL_STMT = 86,                      /* STMT  */
  YYSYMBOL_STMT_NO_BLOCK = 87,             /* STMT_NO_BLOCK  */
  YYSYMBOL_ELSE = 88,                      /* ELSE  */
  YYSYMBOL_BLOCK = 89,                     /* BLOCK  */
  YYSYMBOL_90_4 = 90                       /* $@4  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
       2,     2,     2,    60,     2,     2,     2,     2,     2,     2,
      58,    59,    56,    54,    48,    55,     2,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
      45,    51,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    38,    38,    39,    39,    42,    43,    44,    45,    49,
      53,    54,    57,    58,    59,    62,    63,    66,    67,    68,
      69,    70,    73,    74,    75,    76,    77,    78,    81,    82,
      83,    86,    88,    89,    90,    91,    94,    97,    98,   101,
     102,   105,   106,   109,   110,   111,   115,   116,   117,   120,
     121,   122,   123,   124,   127,   128,   129,   130,   131,   132,
     135,   135,   135,   138,   139,   142,   143,   144,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   160,   161,
     164,   164
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
  "\"end of file\"", "error", "\"invalid token\"", "T_INT", "T_CHAR",
  "T_DOUBLE", "T_WHILE", "T_INC", "T_DEC", "T_OROR", "T_ANDAND",
  "T_EQCOMP", "T_NOTEQUAL", "T_GREATEREQ", "T_LESSEREQ", "T_LEFTSHIFT",
  "T_RIGHTSHIFT", "T_PRINTLN", "T_STRING", "T_FLOAT", "T_BOOLEAN", "T_IF",
  "T_ELSE", "T_STRLITERAL", "T_DO", "T_INCLUDE", "T_HEADER", "T_MAIN",
  "T_ID", "T_NUM", "T_PRINTFF", "T_SCANFF", "T_VOID", "T_RETURN", "T_FOR",
  "T_TRUE", "T_FALSE", "T_LOGAND", "T_LOGOR", "T_SQBRACK", "T_BREAK",
  "T_CONTINUE", "T_CASE", "T_SWITCH", "T_DEFAULT", "'<'", "'>'", "';'",
  "','", "'['", "']'", "'='", "'{'", "'}'", "'+'", "'-'", "'*'", "'/'",
  "'('", "')'", "'!'", "$accept", "START", "$@1", "PROG", "DECLR",
  "LISTVAR", "VAR", "DIMS", "TYPE", "ASSGN", "ARRELEM", "ARRDEF",
  "UNARYEXPR", "EXPR", "LOGIC_EXPR", "AND_EXPR", "REL_EXPR", "E", "T", "F",
  "REL_OP", "MAIN", "$@2", "$@3", "EMPTY_LISTVAR", "STMT", "STMT_NO_BLOCK",
  "ELSE", "BLOCK", "$@4", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-106)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      89,  -106,  -106,  -106,  -106,   -36,   -13,  -106,    17,  -106,
      -8,    38,    10,   120,    35,    12,    14,     4,  -106,   120,
    -106,    -4,    11,  -106,  -106,   120,  -106,  -106,    18,  -106,
    -106,  -106,    14,    14,    21,    44,    36,     8,   -41,    29,
    -106,    14,    14,  -106,  -106,    23,  -106,    39,    14,    63,
    -106,    59,    14,  -106,    50,  -106,    61,    14,    14,  -106,
    -106,  -106,  -106,  -106,  -106,    14,    14,    14,    14,    14,
     -41,   -41,  -106,  -106,    63,    70,  -106,   120,    69,    78,
    -106,    14,    77,    36,     8,   -41,    29,    29,  -106,  -106,
      11,    71,    61,  -106,  -106,    14,    79,     0,    80,    77,
    -106,    61,  -106,  -106,  -106,  -106,  -106,   139,    73,    91,
      83,   -13,    14,    92,    90,   104,  -106,   107,    63,   108,
     109,    23,    85,   139,   139,    14,    14,   130,   110,    84,
    -106,  -106,   139,  -106,  -106,  -106,  -106,  -106,  -106,   100,
     102,   106,  -106,   118,   113,    83,    83,    14,    14,  -106,
    -106,   152,   117,   134,    83,  -106,   135,     4,  -106,  -106,
     124,    83,  -106
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       8,    17,    20,    19,    18,     0,     0,    21,     0,     2,
       0,     0,     0,     8,     0,     0,     0,     0,     1,     8,
      60,    13,     9,    11,    12,     8,     5,     3,     0,    53,
      51,    52,     0,     0,     0,    36,    38,    40,    42,    45,
      48,     0,     0,    23,    22,    42,     6,     0,     0,     0,
       7,     0,    30,    27,     0,    50,    16,     0,     0,    58,
      59,    55,    54,    56,    57,     0,     0,     0,     0,     0,
      32,    33,    34,    35,    64,     0,    10,     8,     0,    29,
      49,     0,     0,    37,    39,    41,    43,    44,    46,    47,
      63,     0,    16,     4,    31,    30,     0,     0,     0,    14,
      28,    16,    26,    25,    24,    61,    15,    67,     0,     0,
       0,    51,     0,     0,     0,     0,    80,     0,     0,     0,
       0,     0,     0,    67,    67,     0,     0,     0,     0,     0,
      76,    77,    67,    68,    69,    70,    62,    65,    66,     0,
       0,     0,    74,     0,     0,     0,     0,     0,     0,    81,
      75,    79,     0,     0,     0,    73,     0,     0,    78,    72,
       0,     0,    71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -106,  -106,  -106,    -9,   -28,   103,   136,   -46,    46,    -5,
      93,    87,   -16,   -14,  -106,   129,   131,   -17,    33,   -18,
    -106,  -106,  -106,  -106,  -106,   -48,  -106,  -106,  -105,  -106
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,    51,     9,    10,    22,    23,    82,    11,    12,
      78,    53,   120,    79,    35,    36,    37,    38,    39,    40,
      65,    13,    47,   107,    91,   122,   123,   155,   124,   132
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      45,    43,    34,    44,    26,   127,    24,    41,    42,    14,
      46,    41,    42,    66,    67,    55,    50,    18,    54,    59,
      60,    61,    62,    29,    70,    71,    15,    29,    30,    31,
      72,    73,    30,    31,    75,    15,    16,    29,    17,    19,
     150,   151,    30,    31,    24,    48,    99,    17,    85,   158,
      88,    89,    52,    63,    64,   106,   162,    25,    32,    49,
      33,    27,    32,    28,    33,    20,    21,    96,    93,    24,
      52,    56,    32,    58,    33,   137,   138,    66,    67,   117,
      45,   103,    57,   104,   144,    68,    69,     1,     2,     3,
     121,    21,     1,     2,     3,   117,   117,    74,   128,    86,
      87,   143,   119,     4,   117,    77,   121,   121,     4,    80,
      81,   139,   140,    24,     5,   121,     7,     6,   119,   119,
      92,     7,    94,     1,     2,     3,    95,   119,    97,   101,
      98,   125,   105,   152,   153,   116,   141,   130,   136,     4,
     121,   160,     1,     2,     3,   108,    41,    42,     6,   126,
     129,   131,     7,   118,   133,   134,   135,   142,     4,   145,
     109,   146,    29,   110,   147,   148,   149,   111,    31,   118,
     118,     7,   112,   113,   154,   118,   156,    90,   118,   114,
     115,   157,   159,   161,   102,    76,    83,     0,   100,    84,
       0,   116,     0,     0,     0,     0,     0,    32,     0,    33
};

static const yytype_int16 yycheck[] =
{
      17,    17,    16,    17,    13,   110,    11,     7,     8,    45,
      19,     7,     8,    54,    55,    33,    25,     0,    32,    11,
      12,    13,    14,    23,    41,    42,    39,    23,    28,    29,
       7,     8,    28,    29,    48,    39,    49,    23,    51,    47,
     145,   146,    28,    29,    49,    49,    92,    51,    65,   154,
      68,    69,    52,    45,    46,   101,   161,    47,    58,    48,
      60,    26,    58,    51,    60,    27,    28,    81,    77,    74,
      52,    50,    58,    37,    60,   123,   124,    54,    55,   107,
      97,    97,    38,    97,   132,    56,    57,     3,     4,     5,
     107,    28,     3,     4,     5,   123,   124,    58,   112,    66,
      67,   129,   107,    19,   132,    46,   123,   124,    19,    59,
      49,   125,   126,   118,    25,   132,    32,    28,   123,   124,
      50,    32,    53,     3,     4,     5,    48,   132,    51,    50,
      59,    58,    52,   147,   148,    52,     6,    47,    53,    19,
     157,   157,     3,     4,     5,     6,     7,     8,    28,    58,
      58,    47,    32,   107,    47,    47,    47,    47,    19,    59,
      21,    59,    23,    24,    58,    47,    53,    28,    29,   123,
     124,    32,    33,    34,    22,   129,    59,    74,   132,    40,
      41,    47,    47,    59,    97,    49,    57,    -1,    95,    58,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    19,    25,    28,    32,    62,    64,
      65,    69,    70,    82,    45,    39,    49,    51,     0,    47,
      27,    28,    66,    67,    70,    47,    64,    26,    51,    23,
      28,    29,    58,    60,    74,    75,    76,    77,    78,    79,
      80,     7,     8,    73,    74,    78,    64,    83,    49,    48,
      64,    63,    52,    72,    74,    80,    50,    38,    37,    11,
      12,    13,    14,    45,    46,    81,    54,    55,    56,    57,
      78,    78,     7,     8,    58,    74,    67,    46,    71,    74,
      59,    49,    68,    76,    77,    78,    79,    79,    80,    80,
      66,    85,    50,    64,    53,    48,    74,    51,    59,    68,
      71,    50,    72,    73,    74,    52,    68,    84,     6,    21,
      24,    28,    33,    34,    40,    41,    52,    65,    69,    70,
      73,    78,    86,    87,    89,    58,    58,    89,    74,    58,
      47,    47,    90,    47,    47,    47,    53,    86,    86,    74,
      74,     6,    47,    65,    86,    59,    59,    58,    47,    53,
      89,    89,    74,    74,    22,    88,    59,    47,    89,    47,
      73,    59,    89
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    62,    64,    64,    64,    64,    65,
      66,    66,    67,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    70,    70,    70,    70,    70,    70,    71,    71,
      71,    72,    73,    73,    73,    73,    74,    75,    75,    76,
      76,    77,    77,    78,    78,    78,    79,    79,    79,    80,
      80,    80,    80,    80,    81,    81,    81,    81,    81,    81,
      83,    84,    82,    85,    85,    86,    86,    86,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    88,    88,
      90,    89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     6,     2,     3,     3,     0,     2,
       3,     1,     1,     1,     5,     4,     0,     1,     1,     1,
       1,     1,     3,     3,     7,     7,     7,     4,     3,     1,
       0,     3,     2,     2,     2,     2,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     0,    10,     1,     0,     2,     2,     0,     2,     2,
       2,     9,     7,     6,     3,     5,     2,     2,     2,     0,
       0,     4
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
  case 2: /* START: PROG  */
#line 38 "parsertest.y"
             { printf("Valid syntax\n"); YYACCEPT; }
#line 1423 "y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 39 "parsertest.y"
                                 { add('H', yyvsp[0]); }
#line 1429 "y.tab.c"
    break;

  case 4: /* START: T_INCLUDE '<' T_HEADER $@1 '>' PROG  */
#line 39 "parsertest.y"
                                                            { printf("Valid syntax\n"); YYACCEPT;  }
#line 1435 "y.tab.c"
    break;

  case 13: /* VAR: T_ID  */
#line 58 "parsertest.y"
            { add('V', yyvsp[0]); }
#line 1441 "y.tab.c"
    break;

  case 14: /* VAR: T_ID '[' EXPR ']' DIMS  */
#line 59 "parsertest.y"
                              { add('V', yyvsp[-4]); }
#line 1447 "y.tab.c"
    break;

  case 17: /* TYPE: T_INT  */
#line 66 "parsertest.y"
             { insert_type(); add('K', yyvsp[0]); }
#line 1453 "y.tab.c"
    break;

  case 18: /* TYPE: T_FLOAT  */
#line 67 "parsertest.y"
                 { insert_type(); add('K', yyvsp[0]); }
#line 1459 "y.tab.c"
    break;

  case 19: /* TYPE: T_DOUBLE  */
#line 68 "parsertest.y"
                  { insert_type(); add('K', yyvsp[0]); }
#line 1465 "y.tab.c"
    break;

  case 20: /* TYPE: T_CHAR  */
#line 69 "parsertest.y"
                { insert_type(); add('K', yyvsp[0]); }
#line 1471 "y.tab.c"
    break;

  case 21: /* TYPE: T_VOID  */
#line 70 "parsertest.y"
                { insert_type(); add('K', yyvsp[0]); }
#line 1477 "y.tab.c"
    break;

  case 22: /* ASSGN: T_ID '=' EXPR  */
#line 73 "parsertest.y"
                      { add('V', yyvsp[-2]); }
#line 1483 "y.tab.c"
    break;

  case 23: /* ASSGN: T_ID '=' UNARYEXPR  */
#line 74 "parsertest.y"
                           { add('V', yyvsp[-2]); }
#line 1489 "y.tab.c"
    break;

  case 24: /* ASSGN: T_ID '[' EXPR ']' DIMS '=' EXPR  */
#line 75 "parsertest.y"
                                        { add('V', yyvsp[-6]); }
#line 1495 "y.tab.c"
    break;

  case 25: /* ASSGN: T_ID '[' EXPR ']' DIMS '=' UNARYEXPR  */
#line 76 "parsertest.y"
                                             { add('V', yyvsp[-6]); }
#line 1501 "y.tab.c"
    break;

  case 26: /* ASSGN: T_ID '[' EXPR ']' DIMS '=' ARRDEF  */
#line 77 "parsertest.y"
                                          { add('V', yyvsp[-6]); }
#line 1507 "y.tab.c"
    break;

  case 27: /* ASSGN: T_ID T_SQBRACK '=' ARRDEF  */
#line 78 "parsertest.y"
                                  { add('V', yyvsp[-3]); }
#line 1513 "y.tab.c"
    break;

  case 51: /* F: T_ID  */
#line 122 "parsertest.y"
           {add('V', yyvsp[0]);}
#line 1519 "y.tab.c"
    break;

  case 52: /* F: T_NUM  */
#line 123 "parsertest.y"
            { add('C', yyvsp[0]); }
#line 1525 "y.tab.c"
    break;

  case 53: /* F: T_STRLITERAL  */
#line 124 "parsertest.y"
                   { add('C', yyvsp[0]); }
#line 1531 "y.tab.c"
    break;

  case 60: /* $@2: %empty  */
#line 135 "parsertest.y"
                   { add('F',yyvsp[0]); }
#line 1537 "y.tab.c"
    break;

  case 61: /* $@3: %empty  */
#line 135 "parsertest.y"
                                                             {++scope;}
#line 1543 "y.tab.c"
    break;

  case 62: /* MAIN: TYPE T_MAIN $@2 '(' EMPTY_LISTVAR ')' '{' $@3 STMT '}'  */
#line 135 "parsertest.y"
                                                                                 {--scope;}
#line 1549 "y.tab.c"
    break;

  case 71: /* STMT_NO_BLOCK: T_FOR '(' DECLR ';' EXPR ';' UNARYEXPR ')' BLOCK  */
#line 151 "parsertest.y"
                                                           { add('K', yyvsp[-8]); }
#line 1555 "y.tab.c"
    break;

  case 72: /* STMT_NO_BLOCK: T_DO BLOCK T_WHILE '(' EXPR ')' ';'  */
#line 152 "parsertest.y"
                                              { add('K', yyvsp[-6]); add('K', yyvsp[-4]); }
#line 1561 "y.tab.c"
    break;

  case 73: /* STMT_NO_BLOCK: T_IF '(' EXPR ')' BLOCK ELSE  */
#line 153 "parsertest.y"
                                      {add('K', yyvsp[-5]);}
#line 1567 "y.tab.c"
    break;

  case 74: /* STMT_NO_BLOCK: T_RETURN EXPR ';'  */
#line 154 "parsertest.y"
                            { add('K', yyvsp[-2]); }
#line 1573 "y.tab.c"
    break;

  case 75: /* STMT_NO_BLOCK: T_WHILE '(' EXPR ')' BLOCK  */
#line 155 "parsertest.y"
                                     { add('K', yyvsp[-4]); }
#line 1579 "y.tab.c"
    break;

  case 76: /* STMT_NO_BLOCK: T_BREAK ';'  */
#line 156 "parsertest.y"
                      { add('K', yyvsp[-1]); }
#line 1585 "y.tab.c"
    break;

  case 77: /* STMT_NO_BLOCK: T_CONTINUE ';'  */
#line 157 "parsertest.y"
                         { add('K', yyvsp[-1]); }
#line 1591 "y.tab.c"
    break;

  case 78: /* ELSE: T_ELSE BLOCK  */
#line 160 "parsertest.y"
                    {add('K', yyvsp[-1]);}
#line 1597 "y.tab.c"
    break;

  case 80: /* $@4: %empty  */
#line 164 "parsertest.y"
           {++scope;}
#line 1603 "y.tab.c"
    break;

  case 81: /* BLOCK: '{' $@4 STMT '}'  */
#line 164 "parsertest.y"
                              {--scope;}
#line 1609 "y.tab.c"
    break;


#line 1613 "y.tab.c"

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

#line 165 "parsertest.y"



void yyerror(const char* s)
{
	printf("Error :%s at %d \n",s,yylineno);
}


int main(int argc, char* argv[])
{
	yyparse();
    printf("\n\n");
    printf("\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
    printf("\nSYMBOL\tDATATYPE\tTYPE\tLINE\tNUMBER\tSCOPE\n");
    printf("_____________________________________________\n\n");
    int i=0;
    for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t%d\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no, symbol_table[i].scope);
	}
    for (i=0; i< count; i++){
        free(symbol_table[i].id_name);
        free(symbol_table[i].type);
    }
    printf("\n\n");
}

int search(char* type){
    int i;
    for(i=count-1; i>=0; i--){
        if (strcmp(symbol_table[i].id_name, type) == 0){
            return -1;
            break;
        }
    }
    return 0;
}

void add(char c, char* s){
    q=search(s);
    if(c == 'K') {
        symbol_table[count].id_name=strdup(s);
        symbol_table[count].data_type=strdup("N/A");
        symbol_table[count].line_no=yylineno;
        symbol_table[count].type=strdup("Keyword\t");
        symbol_table[count].scope=scope;
        count++;
    }
    else if(c=='H'){
        symbol_table[count].id_name=strdup(s);
        symbol_table[count].data_type=strdup("N/A");
        symbol_table[count].line_no=yylineno;
        symbol_table[count].type=strdup("Header\t");
        symbol_table[count].scope=scope;
        count++;
    }
    else if(c == 'C') {
        symbol_table[count].id_name=strdup(s);
        symbol_table[count].data_type=strdup("CONST");
        symbol_table[count].line_no=yylineno;
        symbol_table[count].type=strdup("Constant");
        symbol_table[count].scope=scope;
        count++;
    }
    if (!q){
		if(c == 'V') {
			symbol_table[count].id_name=strdup(s);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Variable");
            symbol_table[count].scope=scope;
			count++;
		}
		else if(c == 'F') {
			symbol_table[count].id_name=strdup(s);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Function");
            symbol_table[count].scope=scope;
			count++;
        }
    }
}

void insert_type() {
	strcpy(type, yytext);
}
