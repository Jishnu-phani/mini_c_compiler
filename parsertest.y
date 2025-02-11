%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
    #include "lex.yy.c"
	#define YYSTYPE char*

	void yyerror(const char* s);
	int yylex();
	extern int yylineno;

    void add(char);
    void insert_type();
    int search(char *);

    struct dataType{
        char* id_name;
        char* data_type;
        char* type;
        int line_no;
    } symbol_table[40];

    int count=0;
    int scope = 0;
    int q;
    char type[10];
    extern int countn;

%}

%token T_INT T_CHAR T_DOUBLE T_WHILE T_INC T_DEC T_OROR T_ANDAND T_EQCOMP T_NOTEQUAL T_GREATEREQ T_LESSEREQ T_LEFTSHIFT T_RIGHTSHIFT T_PRINTLN T_STRING  T_FLOAT T_BOOLEAN T_IF T_ELSE T_STRLITERAL T_DO T_INCLUDE T_HEADER T_MAIN T_ID T_NUM T_PRINTFF T_SCANFF T_VOID T_RETURN T_FOR T_TRUE T_FALSE T_LOGAND T_LOGOR T_SQBRACK T_BREAK T_CONTINUE T_CASE T_SWITCH T_DEFAULT

%start START


%%
START : PROG { printf("Valid syntax\n"); YYACCEPT; }	
        | T_INCLUDE '<' T_HEADER { add('H') ;}'>' PROG { printf("Valid syntax\n"); YYACCEPT; } 
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
     | T_ID { add('V'); }
     | T_ID {add('V');} '[' EXPR ']' DIMS
     ;

DIMS: '[' EXPR ']' DIMS
    | 
    ;

TYPE : T_INT { insert_type(); add('K'); }
       | T_FLOAT { insert_type();add('K'); }
       | T_DOUBLE { insert_type();add('K'); }
       | T_CHAR { insert_type();add('K'); }
       | T_VOID { insert_type();add('K'); }
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

EXPR : LOGIC_EXPR
    ;

LOGIC_EXPR : LOGIC_EXPR T_LOGOR AND_EXPR
        | AND_EXPR
        ;

AND_EXPR : AND_EXPR T_LOGAND REL_EXPR
        | REL_EXPR
        ;

REL_EXPR : REL_EXPR REL_OP E
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
    | '!' F
    | T_ID {add('V');}
    | T_NUM { add('C'); }
    | T_STRLITERAL { add('C'); }
    ;

REL_OP :   T_LESSEREQ
	   | T_GREATEREQ
	   | '<' 
	   | '>' 
	   | T_EQCOMP
	   | T_NOTEQUAL
	   ;	

MAIN : TYPE T_MAIN { add('F'); } '(' EMPTY_LISTVAR ')' '{' STMT '}'
    ;

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
       | T_FOR { add('K'); } '(' DECLR ';' EXPR ';' UNARYEXPR ')' BLOCK
       | T_DO { add('K'); } BLOCK T_WHILE { add('K'); } '(' EXPR ')' ';'
       | T_IF {add('K');} '(' EXPR ')' BLOCK ELSE
       | T_RETURN { add('K'); } EXPR ';'
       | T_WHILE { add('K'); } '(' EXPR ')' BLOCK
       | T_BREAK { add('K'); } ';'
       | T_CONTINUE { add('K'); } ';'
       ;

ELSE : T_ELSE {add('K');} BLOCK
       |
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
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
    printf("\nSYMBOL    DATATYPE    TYPE    LINE NUMBER \n");
    printf("_____________________________________________\n\n");
    int i=0;
    for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
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

void add(char c){
    q=search(yytext);
    if(c == 'K') {
        symbol_table[count].id_name=strdup(yytext);
        symbol_table[count].data_type=strdup("N/A");
        symbol_table[count].line_no=yylineno;
        symbol_table[count].type=strdup("Keyword\t");
        count++;
    }
    else if(c=='H'){
        symbol_table[count].id_name=strdup(yytext);
        symbol_table[count].data_type=strdup(type);
        symbol_table[count].line_no=yylineno;
        symbol_table[count].type=strdup("Header");
        count++;
    }
    else if(c == 'C') {
        symbol_table[count].id_name=strdup(yytext);
        symbol_table[count].data_type=strdup("CONST");
        symbol_table[count].line_no=yylineno;
        symbol_table[count].type=strdup("Constant");
        count++;
    }
    if (!q){
		if(c == 'V') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Variable");
			count++;
		}
		else if(c == 'F') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Function");
			count++;
        }
    }
}

void insert_type() {
	strcpy(type, yytext);
}