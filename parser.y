%{
#include <stdio.h>
//#include "Tokens.h"

int yylex();
int yyerror(char *s);

%}

%token _ID 1
%token _ICONST 2
%token _RCONST 3
%token _ECONST 4
%token _LITERAL 5
%token _LBRACK 10
%token _RBRACK 11
%token _LPAREN 12
%token _RPAREN 13
%token _SEMI 14
%token _COLON 15
%token _COMMA 16
%token _ASSIGN 17
%token _PLUS 20
%token _MINUS 21
%token _MULT 22
%token _DIVIDE 23
%token _EQL 40
%token _LESS 41
%token _GTR 42
%token _LEQ 43
%token _GEQ 44
%token _NEQ 45
%token _PROGRAM 51
%token _ENDVARS 52
%token _ENDPROCS 53
%token _VARS 54
%token _NOVARS 55
%token _INTEGER 56
%token _REAL 57
%token _STRING 58
%token _PROCS 59
%token _NOPROCS 60
%token _PROC 61
%token _BEGIN 62
%token _END 63
%token _FOR 64
%token _TO 65
%token _DO 66
%token _IF 67
%token _THEN 68
%token _ELSE 69
%token _READ 70
%token _WRITE 71
%token _COMMENT 79
%token _ERROR 80 

%start program

%%

program:
	title _SEMI block { printf("Regla program\n"); }
;

title:
	_PROGRAM _ID { printf("Regla title\n"); }
;

block:
	vars _ENDVARS procs _ENDPROCS code { printf("Regla block\n"); }
;

vars:
	_VARS varlist _SEMI	{ printf("Regla vars\n"); }
|
	_NOVARS 
;

varlist:
	varlist _SEMI vardef { printf("Regla varlist\n"); }
|
	vardef
;

vardef:
	_ID _COLON _INTEGER		{ printf("Regla vardef\n"); }
|
	_ID _COLON _REAL
|
	_ID _COLON _INTEGER bnl
|
	_ID _COLON _STRING
;

bnl:
	_LBRACK nlist _RBRACK		{ printf("Regla bnl \n"); }
;

nlist:
	nlist _COMMA  _ICONST		{ printf("Regla nlist \n"); }
|
	_ICONST
;

procs:
	_PROCS proclist			{ printf("Regla procs \n"); }
|
	_NOPROCS
;

proclist:
	proclist _SEMI procdef	{ printf("Regla proclist\n"); }
|
	procdef
;

procdef:
	ptittle _SEMI block		{ printf("Regla procdef\n"); }
;

ptittle:
	_PROC _ID _LPAREN varlist _RPAREN	{ printf("Regla ptittle \n"); }
|
	_PROC _ID _LPAREN _RPAREN
;

code:
	_BEGIN para _END				{ printf("Regla code \n"); }
|
	_SEMI
;

para:
	para _SEMI stmt				{ printf("Regla para\n"); }
|
	stmt
;

stmt:
	assign						{ printf("Regla stmt\n"); }
|
	cond
|
	loop
|
	input
|
	output
|
	code
;

assign:
	ids _ASSIGN expr				{ printf("Regla assign\n"); }
;

expr:
	expr _PLUS term				{ printf("Regla expr\n"); }
|
	expr _MINUS term
|
	term
;

term:
	term _MULT fac				{ printf("Regla term\n"); }
|
	term _DIVIDE fac
|
	fac
;

fac:
	val							{ printf("Regla fac\n"); }
|
	_LPAREN expr _RPAREN
;

val:
	ids							{ printf("Regla val\n"); }
|
	_ID _LPAREN vallist _RPAREN
|
	_RCONST
|
	_ICONST
;

ids:
	_ID							{ printf("Regla ids\n"); }
|
	_ID _LBRACK vallist _RBRACK
;

vallist:
	vallist _COMMA  it			{ printf("Regla vallist\n"); }
|
	it
;

it:
	_ID							{ printf("Regla it\n"); }
|
	_ICONST
;

cond:
	_IF expr bop expr _THEN stmt _ELSE stmt	{ printf("Regla cond\n"); }
;

bop:
	_EQL		{ printf("Regla bop\n"); }
|
	_LESS
|
	_GTR
|
	_LEQ
|
	_GEQ
|
	_NEQ
;

loop:
	_FOR assign _TO expr _DO stmt	{ printf("Regla loop\n"); }
;

input:
	_READ _LPAREN _ID _RPAREN	{ printf("Regla input\n"); }
;

output:
	_WRITE  _LPAREN _ID _RPAREN	{ printf("Regla output\n"); }
|
	_WRITE  _LPAREN _LITERAL  _RPAREN
;

%%

int yyerror(char *s)
{
	printf("Syntax Error on line:%s\n",s);
	return 0;
}

