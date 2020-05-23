%{
#include <iostream>
using namespace std;
extern "C"
{
	#include "header.h"
	#include <stdio.h>
	#include "y.tab.h"
	#include<string.h>

	//#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;

	extern void yyerror(const char *);  /* prints grammar violation message */

	extern int sym_type(const char *);  /* returns type from symbol table */

	#define sym_type(identifier) IDENTIFIER /* with no symbol table, fake it */

	//static void comment(void);
	int yyparse(void);
	int yylex(void);
	//void yyerror(char *);
	static int check_type(void);
	
	int line = 1;
}
%}

%option yylineno

D   		[0-9]
L   		[a-zA-Z_]
A   		[a-zA-Z_0-9]
WS  		[ \t\v\n\f]


%%
"\n" line++;
"/*"		{ yyerror("unterminated comment"); }
"//"[^\n]*	{ /* Consume Comment */ }

	/* Data Types */
var			{ strcpy(yylval.string,yytext); return(VAR); }
break			{ strcpy(yylval.string,yytext); return(BREAK); }

	/* Control Structures */
for		{ return(FOR); 	}
do		{ return(DO);  	}
while		{ return(WHILE);}
switch		{ return(SWITCH);}
case		{ return(CASE); }
default		{ return(DEFAULT);}

alert		{ strcpy(yylval.string,yytext); return(ALERT);}
function	{ strcpy(yylval.string,yytext); return(FUNCTION); }


	/* User Defined Data Types, Identifiers */
{L}{A}*							{ strcpy(yylval.string,yytext); return IDENTIFIER;}
{D}+							{ strcpy(yylval.string,yytext); return INTEGER_LITERAL;}
{D}+\.{D}+						{ strcpy(yylval.string,yytext); return FLOAT_LITERAL;}
L?\"(\\.|[^\\"])*\"	{ return(STRING_LITERAL); }

	/* Assignment Operators */
"+="		{return(ADD_ASSIGN); }
"-="		{return(SUB_ASSIGN); }


	/* Relational Operators */
"++"		{return(INC_OP); }
"--"		{return(DEC_OP); }
"<="		{ strcpy(yylval.string,yytext); return(LE_OP); }
">="		{ strcpy(yylval.string,yytext); return(GE_OP); }
"=="		{ strcpy(yylval.string,yytext); return(EQ_OP); }
"!="		{ strcpy(yylval.string,yytext); return(NE_OP); }

	/* Basic Syntax */
";"		{return(';'); }
"{"	{return('{'); }
"}"	{return('}'); }
","		{return(','); }
":"		{return(':'); }
"="		{return('='); }
"("		{return('('); }
")"		{return(')'); }
("["|"<:")	{return('['); }
("]"|":>")	{return(']'); }
"."		{return('.'); }
"&"		{return('&'); }
"!"		{return('!'); }
"~"		{return('~'); }
"-"		{ strcpy(yylval.string,yytext);return('-'); }
"+"		{ strcpy(yylval.string,yytext);return('+'); }
"*"		{ strcpy(yylval.string,yytext);return('*'); }
"/"		{ strcpy(yylval.string,yytext);return('/'); }
"%"		{ strcpy(yylval.string,yytext);return('%'); }
"<"		{ strcpy(yylval.string,yytext);return('<'); }
">"		{ strcpy(yylval.string,yytext);return('>'); }
"^"		{return('^'); }
"|"		{return('|'); }
"?"		{return('?'); }


{WS}+		{ /* whitespace separates tokens */}
	
.		{ printf("No Match, Invalid Expression %s\n", yytext); }
%%

int yywrap(void)
{
	return 1;
}



