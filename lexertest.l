%{
    #define YYSTYPE char*
    #include "y.tab.h"
    #include <stdio.h>
    extern void yyerror(const char *);
    extern char* strdup(const char*);
	int countn = 0;
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
\/\/(.*) ; 
[\t]* ; 
[\n]		{countn++;}
"/*"    { BEGIN(COMMENT); }
"*/"    { yyerror("Unmatched comment termination"); }
<COMMENT>{
    "*/"    { BEGIN(INITIAL); }
    .|\n    ; // consume everything inside the comment
    <<EOF>> { yyerror("Unterminated comment"); }
}
"int" 		{return T_INT;}
"char"		{return T_CHAR;}
"double"	{return T_DOUBLE;}
"float"		{return T_FLOAT;}
"while" 	{return T_WHILE;}
"if"		{return T_IF;}
"else"		{return T_ELSE;}
"do" 		{return T_DO;}
"#include" 	{return T_INCLUDE;}
"main" 		{return T_MAIN;}
"printf"	{return T_PRINTFF;}
"scanf"		{return T_SCANFF;}
"void"		{return T_VOID;}
"return"	{return T_RETURN;}
"for"		{return T_FOR;}
"true"		{return T_TRUE;}
"false"		{return T_FALSE;}
\".*\"		{yylval=strdup(yytext); return T_STRLITERAL; }
"=="		{return T_EQCOMP;}
"!="		{return T_NOTEQUAL;}
">="        	{return T_GREATEREQ;}
"<="        	{return T_LESSEREQ;}
"&&"			{return T_LOGAND;}
"||"			{return T_LOGOR;}
"[]"			{return T_SQBRACK;}
"++"			{return T_INC;}
"--"			{return T_DEC;}
"!"				{return *yytext;}
"("		{return *yytext;}
")"		{return *yytext;}
"."         	{return *yytext;}
","         	{return *yytext;}
"{"         	{return *yytext;}
"}"         	{return *yytext;}
"*"         	{return *yytext;}
"+"         	{return *yytext;}
";"         	{return *yytext;}
"-"         	{return *yytext;}
"/"         	{return *yytext;}
"%"				{return *yytext;}
"="         	{return *yytext;}
">"         	{return *yytext;}
"<"         	{return *yytext;}
"["				{return *yytext;}
"]"				{return *yytext;}
{number}	{
			yylval=strdup(yytext); 
			return T_NUM;
		}
{id}\.h	{return T_HEADER;}
{id}        	{
			yylval=strdup(yytext);
			return T_ID;
		}
.		{} // anything else => ignore
%%



