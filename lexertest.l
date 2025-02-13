%{
    #define YYSTYPE char*
    #include "y.tab.h"
    #include <stdio.h>
    extern void yyerror(const char *);
    extern char* strdup(const char*);
	int countn = 0;
    int colcount = 0;
%}

digit	[0-9]
letter	[a-zA-Z]
id	{letter}({letter}|{digit})*
digits	{digit}+
opFraction	(\.{digits})?
opExponent	([Ee][+-]?{digits})?
number	{digits}{opFraction}{opExponent}
%option yylineno
%option noyywrap
%x COMMENT

%%
\/\/(.*) {colcount += yyleng;} 
[\t]* {colcount += 4;} 
[\n]		{countn++; colcount=0;}
"/*"    { BEGIN(COMMENT); }
"*/"    { yyerror("Unmatched comment termination"); }
<COMMENT>{
    "*/"    { BEGIN(INITIAL); }
    .|\n    ; // consume everything inside the comment
    <<EOF>> { yyerror("Unterminated comment"); }
}
"int" 		{colcount += yyleng;yylval=strdup(yytext); return T_INT;}
"char"		{colcount += yyleng;yylval=strdup(yytext); return T_CHAR;}
"double"	{colcount += yyleng;yylval=strdup(yytext); return T_DOUBLE;}
"float"		{colcount += yyleng;yylval=strdup(yytext); return T_FLOAT;}
"while" 	{colcount += yyleng;yylval=strdup(yytext); return T_WHILE;}
"if"		{colcount += yyleng;yylval=strdup(yytext); return T_IF;}
"else"		{colcount += yyleng;yylval=strdup(yytext); return T_ELSE;}
"do" 		{colcount += yyleng;yylval=strdup(yytext); return T_DO;}
"#include" 	{colcount += yyleng;yylval=strdup(yytext); return T_INCLUDE;}
"main" 		{colcount += yyleng;yylval=strdup(yytext); return T_MAIN;}
"printf"	{colcount += yyleng;yylval=strdup(yytext); return T_PRINTFF;}
"scanf"		{colcount += yyleng;yylval=strdup(yytext); return T_SCANFF;}
"void"		{colcount += yyleng;yylval=strdup(yytext); return T_VOID;}
"return"	{colcount += yyleng;yylval=strdup(yytext); return T_RETURN;}
"for"		{colcount += yyleng;yylval=strdup(yytext); return T_FOR;}
"true"		{colcount += yyleng;yylval=strdup(yytext); return T_TRUE;}
"false"		{colcount += yyleng;yylval=strdup(yytext); return T_FALSE;}
"break"		{colcount += yyleng;yylval=strdup(yytext); return T_BREAK;}
"continue"	{colcount += yyleng;yylval=strdup(yytext); return T_CONTINUE;}
"case"		{colcount += yyleng;yylval=strdup(yytext); return T_CASE;}
"switch"	{colcount += yyleng;yylval=strdup(yytext); return T_SWITCH;}
"default"	{colcount += yyleng;yylval=strdup(yytext); return T_DEFAULT;}
\".*\"		{colcount += yyleng;yylval=strdup(yytext); return T_STRLITERAL; }
"=="		{colcount += yyleng;return T_EQCOMP;}
"!="		{colcount += yyleng;return T_NOTEQUAL;}
">="        	{colcount += yyleng; return T_GREATEREQ;}
"<="        	{colcount += yyleng; return T_LESSEREQ;}
"&&"			{colcount += yyleng; return T_LOGAND;}
"||"			{colcount += yyleng; return T_LOGOR;}
"[]"			{colcount += yyleng; return T_SQBRACK;}
"++"			{colcount += yyleng; return T_INC;}
"--"			{colcount += yyleng; return T_DEC;}
"!"				{colcount += yyleng; return *yytext;}
"("		{colcount += yyleng; return *yytext;}
")"		{colcount += yyleng; return *yytext;}
"."         	{colcount += yyleng; return *yytext;}
","         	{colcount += yyleng; return *yytext;}
"{"         	{colcount += yyleng; return *yytext;}
"}"         	{colcount += yyleng; return *yytext;}
"*"         	{colcount += yyleng; return *yytext;}
"+"         	{colcount += yyleng; return *yytext;}
";"         	{colcount += yyleng; return *yytext;}
"-"         	{colcount += yyleng; return *yytext;}
"/"         	{colcount += yyleng; return *yytext;}
"%"				{colcount += yyleng; return *yytext;}
"="         	{colcount += yyleng; return *yytext;}
">"         	{colcount += yyleng; return *yytext;}
"<"         	{colcount += yyleng; return *yytext;}
"["				{colcount += yyleng; return *yytext;}
"]"				{colcount += yyleng; return *yytext;}
":"             {yyerror("Unexpected colon at"); exit(1);}
{number}	{
			yylval=strdup(yytext); 
			return T_NUM;
            colcount += yyleng;
		}
{id}\.h	{yylval=strdup(yytext); colcount += yyleng; return T_HEADER;}
{id}        	{
			yylval=strdup(yytext);
            colcount += yyleng;
			return T_ID;
		}
.		{colcount += yyleng;} 
%%



