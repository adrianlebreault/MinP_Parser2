%{
#include "y.tab.h"
#include <iostream>

void showError();
int tokenCount;
%}

D [0-9]
AM [A-Z]
Am [a-z]
A [a-zA-Z]
COD [A-Z][A-Z][A-Z]

%option caseless yylineno

%%




"["			                    {tokenCount++; return (LBRACK);}
"]"			                    {tokenCount++; return (RBRACK);}
"("			                    {tokenCount++; return (LPAREN);}
")"			                    {tokenCount++; return (RPAREN);}
";"			                    {tokenCount++; return (SEMI);}
":"			                    {tokenCount++; return (COLON);}
","			                    {tokenCount++; return (COMMA);}

"+"			                    {tokenCount++; return (PLUS);}
"-"			                    {tokenCount++; return (MINUS);}
"*"			                    {tokenCount++; return (MULT);}
"/"			                    {tokenCount++; return (DIVIDE);}

"="			                    {tokenCount++; return (EQL);}
"<"			                    {tokenCount++; return (LESS);}
">"			                    {tokenCount++; return (GTR);}
"<="		                    {tokenCount++; return (LEQ);}
">="		                    {tokenCount++; return (GEQ);}
"<>"		                    {tokenCount++; return (NEQ);} 

":="		                    {tokenCount++; return (ASSIGN);}


"program"                        {tokenCount++; return (PROGRAM);}
"endvars"                        {tokenCount++; return (ENDVARS);}
"endprocs"                        {tokenCount++; return (ENDPROCS);}
"variables"                        {tokenCount++; return (VARS);}
"novariables"                    {tokenCount++; return (NOVARS);}

"integer"                       {  tokenCount++;
                                    yylval.tipo = 0;
                                    return (INTEGER);}

"real"                          {  tokenCount++;
                                    yylval.tipo = 1;
                                    return (REAL);}

"string"                        {  tokenCount++;
                                    yylval.tipo = 2;
                                    return (STRING);}

"procedure"                     {  tokenCount++;
                                    yylval.tipo = 3;
                                    return (PROC);}

"procedures"                    {tokenCount++; return (PROCS);}
"noprocedures"                    {tokenCount++; return (NOPROCS);}
"begin"                            {tokenCount++; return (_BEGIN);}
"end"                            {tokenCount++; return (END);}
"for"                            {tokenCount++; return (FOR);}
"to"                            {tokenCount++; return (TO);}
"do"                            {tokenCount++; return (DO);}
"if"                            {tokenCount++; return (IF);}
"then"                            {tokenCount++; return (THEN);}
"else"                            {tokenCount++; return (ELSE);}
"read"                            {tokenCount++; return (READ);}
"write"                            {tokenCount++; return (WRITE);}

"-"?({D}+)?"."({D})+		    {   tokenCount++; 
                                    yylval.tipo = 1;
                                    return (RCONST);}

"_"?{A}+"_"?({A}|{D})*		    {   tokenCount++;
                                    char *res = new char[strlen(yytext) + 1];
                                    strcpy(res,yytext);
                                    yylval.sval = res;
                                    return (ID);}

"-"?{D}{D}*			            {   tokenCount++; 
                                    yylval.tipo = 0;
                                    return (ICONST);}

{D}("."{D}+)?"E"("-")?{D}+	    {   tokenCount++;
                                    yylval.tipo = 1;
                                    return (ECONST);}
\"(\\.|[^"\\])*\"		        {   tokenCount++;
                                    yylval.tipo = 2;
                                    return (LITERAL);}
\{(\\.|.)*\}       	 /*Comment */
\n                              {}
.                               

%%

void showError(){
    printf("Lexico Error\n");
}

int yywrap (void) {return 1; }
