%{
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
        int column_no;
        int scope;
    } symbol_table[100];

    int count=0;
    int scope = 0;
    int q;
    char type[10];
    extern int countn;
    extern int colcount;

%}

%token T_INT T_CHAR T_DOUBLE T_WHILE T_INC T_DEC T_OROR T_ANDAND T_EQCOMP T_NOTEQUAL T_GREATEREQ T_LESSEREQ T_LEFTSHIFT T_RIGHTSHIFT T_PRINTLN T_STRING  T_FLOAT T_BOOLEAN T_IF T_ELSE T_STRLITERAL T_DO T_INCLUDE T_HEADER T_MAIN T_ID T_NUM T_PRINTFF T_SCANFF T_VOID T_RETURN T_FOR T_TRUE T_FALSE T_LOGAND T_LOGOR T_SQBRACK T_BREAK T_CONTINUE T_CASE T_SWITCH T_DEFAULT

%start START


%%
START : PROG { printf("Valid syntax\n"); YYACCEPT; }	
        | T_INCLUDE '<' T_HEADER { add('H', $3); } '>' PROG { printf("Valid syntax\n"); YYACCEPT;  } 
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
     | T_ID { add('V', $1); }
     | T_ID '[' EXPR ']' DIMS { add('V', $1); }
     ;

DIMS: '[' EXPR ']' DIMS
    | 
    ;

TYPE : T_INT { insert_type(); add('K', $1); }
       | T_FLOAT { insert_type(); add('K', $1); }
       | T_DOUBLE { insert_type(); add('K', $1); }
       | T_CHAR { insert_type(); add('K', $1); }
       | T_VOID { insert_type(); add('K', $1); }
       ;

ASSGN : T_ID '=' EXPR { add('V', $1); }
      | T_ID '=' UNARYEXPR { add('V', $1); }
      | T_ID '[' EXPR ']' DIMS '=' EXPR { add('V', $1); }
      | T_ID '[' EXPR ']' DIMS '=' UNARYEXPR { add('V', $1); }
      | T_ID '[' EXPR ']' DIMS '=' ARRDEF { add('V', $1); }
      | T_ID T_SQBRACK '=' ARRDEF { add('V', $1); }
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
    | T_ID {add('V', $1);}
    | T_NUM { add('C', $1); }
    | T_STRLITERAL { add('C', $1); }
    ;

REL_OP :   T_LESSEREQ
	   | T_GREATEREQ
	   | '<' 
	   | '>' 
	   | T_EQCOMP
	   | T_NOTEQUAL
	   ;	

MAIN : TYPE T_MAIN { add('F',$2); } '(' EMPTY_LISTVAR ')' '{'{++scope;} STMT '}' {--scope;} 
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
       | T_FOR { add('K', $1); }  '(' DECLR ';' EXPR ';' UNARYEXPR ')' HANDLER
       | T_DO { add('K', $1); }  BLOCK T_WHILE { add('K', $4); } '(' EXPR ')' ';'
       | T_IF { add('K', $1); } '(' EXPR ')' BLOCK ELSE
       | T_RETURN { add('K', $1); }  EXPR ';' 
       | T_WHILE { add('K', $1); }  '(' EXPR ')' HANDLER
       | T_BREAK { add('K', $1); }  ';'
       | T_CONTINUE { add('K', $1); } ';' 
       ;

HANDLER : BLOCK 
        | STMT_NO_BLOCK
        ;

ELSE : T_ELSE BLOCK {add('K', $1);}
       |
       ;

BLOCK : '{'{++scope;} STMT '}'{--scope;};
%%


void yyerror(const char* s)
{
	printf("Error :%s at %d, %d \n",s,yylineno, colcount);
    exit(1);
}


int main(int argc, char* argv[])
{
	yyparse();
    printf("\n\n");
    printf("\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
    printf("\nSYMBOL\tDATATYPE\tTYPE\tLINE NO\tCOL NO\tSCOPE\n");
    printf("_____________________________________________\n\n");
    int i=0;
    for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t%d\t%d\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no,symbol_table[i].column_no, symbol_table[i].scope);
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
        symbol_table[count].column_no=colcount - yyleng;
        count++;
    }
    else if(c=='H'){
        symbol_table[count].id_name=strdup(s);
        symbol_table[count].data_type=strdup("N/A");
        symbol_table[count].line_no=yylineno;
        symbol_table[count].type=strdup("Header\t");
        symbol_table[count].scope=scope;
        symbol_table[count].column_no=colcount - yyleng;
        count++;
    }
    else if(c == 'C') {
        symbol_table[count].id_name=strdup(s);
        symbol_table[count].data_type=strdup("CONST");
        symbol_table[count].line_no=yylineno;
        symbol_table[count].type=strdup("Constant");
        symbol_table[count].scope=scope;
        symbol_table[count].column_no=colcount - yyleng;
        count++;
    }
    if (!q){
		if(c == 'V') {
			symbol_table[count].id_name=strdup(s);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Variable");
            symbol_table[count].scope=scope;
            symbol_table[count].column_no=colcount - yyleng;
			count++;
		}
		else if(c == 'F') {
			symbol_table[count].id_name=strdup(s);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Function");
            symbol_table[count].scope=scope;
            symbol_table[count].column_no=colcount - yyleng;
			count++;
        }
    }
}

void insert_type() {
	strcpy(type, yytext);
}