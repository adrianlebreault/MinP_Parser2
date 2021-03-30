

D [0-9]
A [a-zA-Z]
Sign ("+"|"-")
INT {Sign}?{D}+

%{
#include "y.tab.h"
#include <iostream>

void showError();
int tokenCount;
%}

%option yylineno

%% 
{INT}																			{   tokenCount++; 
                                                                                    yylval.tipo = 0;
                                                                                    return (_ICONST);
                                                                                }
{Sign}?({D}+)?"."{D}+?																	{ tokenCount++;
                                                                                           yylval.tipo = 1;
                                                                                           return (_RCONST);}			
{Sign}?({D}+)?("."{D}+)?("E"{INT})														{ tokenCount++; 
                                                                                           yylval.tipo = 1; 
                                                                                           return (_ECONST);
                                                                                        }
["](.)*["]																		{tokenCount++; 
                                                                                   yylval.tipo = 2; 
                                                                                    return (_LITERAL);
                                                                                }
"[" 																			{tokenCount++; return (_LBRACK);}
"]"																				{tokenCount++; return (_RBRACK);}
"("																				{tokenCount++; return (_LPAREN);}
")"																				{tokenCount++; return (_RPAREN);}
";"																				{tokenCount++; return (_SEMI);}
":"																				{tokenCount++; return (_COLON);}
","																				{tokenCount++; return (_COMMA);}
":="																			{tokenCount++; return (_ASSIGN);}
"+"																				{tokenCount++; return (_PLUS);}
"-"																				{tokenCount++; return (_MINUS);}
"*"																				{tokenCount++; return (_MULT);}
"/"																				{tokenCount++; return (_DIVIDE);}
"="																				{tokenCount++; return (_EQL);}
"<"																				{tokenCount++; return (_LESS);}
">"																				{tokenCount++; return (_GTR);}
"<="																			{tokenCount++; return (_LEQ);}
">="																			{tokenCount++; return (_GEQ);}
"<>"																			{tokenCount++; return (_NEQ);}
[P|p][R|r][O|o][G|g][R|r][A|a][M|m]												{tokenCount++; return (_PROGRAM);}
[E|e][N|n][D|d][V|v][A|a][R|r][S|s]												{tokenCount++; return (_ENDVARS);}
[E|e][N|n][D|d][P|p][R|r][O|o][C|c][S|s] 										{tokenCount++; return (_ENDPROCS);}
[V|v][A|a][R|r][I|i][A|a][B|b][L|l][E|e][S|s]									{tokenCount++; return (_VARS);}
[N|n][O|o][V|v][A|a][R|r][I|i][A|a][B|b][L|l][E|e][S|s]							{tokenCount++; return (_NOVARS);}
[I|i][N|n][T|t][E|e][G|g][E|e][R|r]												{tokenCount++;
                                                                                 yylval.tipo = 0; 
                                                                                 return (_INTEGER);
                                                                                }
[R|r][E|e][A|a][L|l]															{tokenCount++; 
                                                                                  yylval.tipo = 1; 
                                                                                 return (_REAL);
                                                                                }
[S|s][T|t][R|r][I|i][N|n][G|g]													{tokenCount++; 
                                                                                 yylval.tipo = 2; 
                                                                                  return (_STRING);
                                                                                }
[P|p][R|r][O|o][C|c][E|e][D|d][U|u][R|r][E|e][S|s]								{tokenCount++; return (_PROCS);}
[N|n][O|o][P|p][R|r][O|o][C|c][E|e][D|d][U|u][R|r][E|e][S|s]					{tokenCount++; return (_NOPROCS);}
[P|p][R|r][O|o][C|c][E|e][D|d][U|u][R|r][E|e]									{tokenCount++;
                                                                                  yylval.tipo = 3; 
                                                                                  return (_PROC);
                                                                                }
[B|b][E|e][G|g][I|i][N|n]														{tokenCount++; return (_BEGIN);}
[E|e][N|n][D|d]																	{tokenCount++; return (_END);}
[F|f][O|o][R|r]																	{tokenCount++; return (_FOR);}
[T|t][O|o]																		{tokenCount++; return (_TO);}
[D|d][O|o]																		{tokenCount++; return (_DO);}
[I|i][F|f]																		{tokenCount++; return (_IF);}
[T|t][H|h][E|e][N|n]															{tokenCount++; return (_THEN);}
[E|e][L|l][S|s][E|e]															{tokenCount++; return (_ELSE);}
[R|r][E|e][A|a][D|d]															{tokenCount++; return (_READ);}
[W|w][R|r][I|i][T|t][E|e]														{tokenCount++; return (_WRITE);}
[{](.)*[}]																		
({A}|"_")(({A}|{D}|"_")+)?														{tokenCount++;
                                                                                 char *res = new char[strlen(yytext) + 1];
                                                                                strcpy(res,yytext);
                                                                                yylval.sval = res;
                                                                                 return (_ID);
                                                                                }
(" "|"")
\t
(\r\n|\r|\n)
[{][^}]* 																		{tokenCount++; return(_ERROR);}
["][^"]*																		{tokenCount++; return(_ERROR);}
.																				{tokenCount++; return (_ERROR);}

%%

void showError(){
    printf("Error Lexico:\n");
}

int yywrap (void) {return 1; }
