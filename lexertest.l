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
"int" 		{yylval=strdup(yytext); return T_INT;}
"char"		{yylval=strdup(yytext); return T_CHAR;}
"double"	{yylval=strdup(yytext); return T_DOUBLE;}
"float"		{yylval=strdup(yytext); return T_FLOAT;}
"while" 	{yylval=strdup(yytext); return T_WHILE;}
"if"		{yylval=strdup(yytext); return T_IF;}
"else"		{yylval=strdup(yytext); return T_ELSE;}
"do" 		{yylval=strdup(yytext); return T_DO;}
"#include" 	{yylval=strdup(yytext); return T_INCLUDE;}
"main" 		{yylval=strdup(yytext); return T_MAIN;}
"printf"	{yylval=strdup(yytext); return T_PRINTFF;}
"scanf"		{yylval=strdup(yytext); return T_SCANFF;}
"void"		{yylval=strdup(yytext); return T_VOID;}
"return"	{yylval=strdup(yytext); return T_RETURN;}
"for"		{yylval=strdup(yytext); return T_FOR;}
"true"		{yylval=strdup(yytext); return T_TRUE;}
"false"		{yylval=strdup(yytext); return T_FALSE;}
"break"		{yylval=strdup(yytext); return T_BREAK;}
"continue"	{yylval=strdup(yytext); return T_CONTINUE;}
"case"		{yylval=strdup(yytext); return T_CASE;}
"switch"	{yylval=strdup(yytext); return T_SWITCH;}
"default"	{yylval=strdup(yytext); return T_DEFAULT;}
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
{id}\.h	{yylval=strdup(yytext); return T_HEADER;}
{id}        	{
			yylval=strdup(yytext);
			return T_ID;
		}
.		{} // anything else => ignore
%%



