%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
    #include "lex.yy.c"
	#define YYSTYPE char*

	void yyerror(const char* s);
	int yylex();
	extern int yylineno;

%}

%token T_INT T_CHAR T_DOUBLE T_WHILE T_INC T_DEC T_OROR T_ANDAND T_EQCOMP T_NOTEQUAL T_GREATEREQ T_LESSEREQ T_LEFTSHIFT T_RIGHTSHIFT T_PRINTLN T_STRING  T_FLOAT T_BOOLEAN T_IF T_ELSE T_STRLITERAL T_DO T_INCLUDE T_HEADER T_MAIN T_ID T_NUM T_PRINTFF T_SCANFF T_VOID T_RETURN T_FOR T_TRUE T_FALSE T_LOGAND T_LOGOR T_SQBRACK

%start START


%%
START : PROG { printf("Valid syntax\n"); YYACCEPT; }	
        | T_INCLUDE '<' T_HEADER '>' PROG { printf("Valid syntax\n"); YYACCEPT; }
        ;	
	  
PROG :  MAIN PROG				
	| DECLR ';' PROG 				
	| ASSGN ';' PROG 			
	| 					
	;
	 

DECLR : TYPE LISTVAR 
	;	


LISTVAR : LISTVAR ',' VAR 
	  | VAR
	  ;

VAR: ASSGN
     | T_ID
     | T_ID '[' EXPR ']' DIMS
     ;

DIMS: '[' EXPR ']' DIMS
    | 
    ;

TYPE : T_INT
       | T_FLOAT
       | T_DOUBLE
       | T_CHAR
       | T_VOID
       ;

ASSGN : T_ID '=' EXPR
      | T_ID '=' UNARYEXPR
      | T_ID '[' EXPR ']' DIMS '=' EXPR
      | T_ID '[' EXPR ']' DIMS '=' UNARYEXPR
      | T_ID '[' EXPR ']' DIMS '=' ARRDEF
      | T_ID T_SQBRACK '=' ARRDEF
	;

ARRELEM: EXPR ',' ARRELEM
        | EXPR
        |
        ;

ARRDEF : '{' ARRELEM '}' 

UNARYEXPR : T_INC E
        | T_DEC E
        | E T_INC
        | E T_DEC
        ;

EXPR : EXPR REL_OP E
       | E 
       ;
	   
E : E '+' T
    | E '-' T
    | T 
    ;
	
	
T : T '*' F
    | T '/' F
    | F
    ;

F : '(' EXPR ')'
    | T_ID
    | T_NUM
    | T_STRLITERAL
    ;

REL_OP :   T_LESSEREQ
	   | T_GREATEREQ
	   | '<' 
	   | '>' 
	   | T_EQCOMP
	   | T_NOTEQUAL
	   ;	

MAIN : TYPE T_MAIN '(' EMPTY_LISTVAR ')' '{' STMT '}';

EMPTY_LISTVAR : LISTVAR
		|	
		;

STMT : STMT_NO_BLOCK STMT
       | BLOCK STMT
       |
       ;


STMT_NO_BLOCK : DECLR ';'
       | ASSGN ';' 
       | UNARYEXPR ';'
       | T_FOR '(' DECLR ';' EXPR ';' UNARYEXPR ')' BLOCK
       | T_DO BLOCK T_WHILE '(' EXPR ')' ';'
       | T_IF '(' EXPR ')' BLOCK
       | T_IF '(' EXPR ')' BLOCK T_ELSE BLOCK
       | T_RETURN EXPR ';'
       ;

BLOCK : '{' STMT '}';
%%


void yyerror(const char* s)
{
	printf("Error :%s at %d \n",s,yylineno);
}


int main(int argc, char* argv[])
{
	yyparse();
}
