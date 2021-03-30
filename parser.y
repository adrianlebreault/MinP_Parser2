%{
#include <bits/stdc++.h>

using namespace std;

enum TipoEnum{
	Integer,
	Real,
	String,
	Procedure
};

struct registro{

	TipoEnum tipo;
	int nivel;
};

extern int yylineno;
int yylex();
int yyerror(char *s);
int error(char *s);
short setType(short xtype, short ytype);
int nivel;
bool declaration = false;


stringstream ss;
multimap<string,registro> SymTab, BUSymTab;
multimap<string,registro>::iterator oit;
map<string,registro> ProcTab;
vector<string> declares, uses, declerrors, typerrors;

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

%type <sval> _ID
%type <tipo> expr term fac val ids it _RCONST _ICONST _ECONST _INTEGER _STRING _LITERAL

%union {

	short tipo;
	char *sval;
	
}

%start program

%%

program:
	title _SEMI block { printf("Regla program\n"); }
;

title:
	_PROGRAM _ID {nivel = 0;}
;

block:
	vars { nivel++; } _ENDVARS procs _ENDPROCS code {oit = SymTab.begin();
														while(oit != SymTab.end())
														{
															if(oit->second.nivel == nivel) SymTab.erase(oit);

															oit++;
														}
														nivel--; 
													}
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
	_ID _COLON _INTEGER		{ if(declaration){
									registro newreg;
									newreg.tipo = Integer;
									newreg.nivel = nivel;
									SymTab.insert(pair<string,registro>(yyval.sval,newreg));
									oit = SymTab.upper_bound(yyval.sval);
									oit--;
									ss <<  "En linea: " << yylineno << " se declaro Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl;
									declares.push_back(ss.str());
									cout << ss.str();
									ss.str(string());
								} 
							}
|
	_ID _COLON _REAL		{if(declaration){
									registro newreg;
									newreg.tipo = Real;
									newreg.nivel = nivel;
									SymTab.insert(pair<string,registro>(yyval.sval,newreg));
									oit = SymTab.upper_bound(yyval.sval);
									oit--;
									ss <<  "En linea: " << yylineno << " se declaro Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl;
									declares.push_back(ss.str());
									cout << ss.str();
									ss.str(string());}
							}
|
	_ID _COLON _INTEGER bnl {if(declaration){
									registro newreg;
									newreg.tipo = Integer;
									newreg.nivel = nivel;
									SymTab.insert(pair<string,registro>(yyval.sval,newreg));
									oit = SymTab.upper_bound(yyval.sval);
									oit--;
									ss <<  "En linea: " << yylineno << " se declaro Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl;
									declares.push_back(ss.str());
									cout << ss.str();
									ss.str(string());}
							}
|
	_ID _COLON _STRING {
								if(declaration){
									registro newreg;
									newreg.tipo = String;
									newreg.nivel = nivel;
									SymTab.insert(pair<string,registro>(yyval.sval,newreg));
									oit = SymTab.upper_bound(yyval.sval);
									oit--;
									ss <<  "En linea: " << yylineno << " se declaro Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl;
									declares.push_back(ss.str());
									cout << ss.str();
									ss.str(string());}
						}
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
	_PROC _ID _LPAREN 	{ declaration = true; }
	varlist _RPAREN	{ registro newreg;
						newreg.tipo = Procedure;
						newreg.nivel = nivel;
						ProcTab.insert(pair<string,registro>($2,newreg));
						oit = ProcTab.upper_bound($2);
						oit--;
						ss <<  "En linea: " << yylineno << " se declaro Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl;
						declares.push_back(ss.str());
						cout << ss.str();
						ss.str(string()); 
					}
|
	_PROC _ID _LPAREN _RPAREN {
								registro newreg;
								newreg.tipo = Procedure;
								newreg.nivel = nivel;
								ProcTab.insert(pair<string,registro>($2,newreg));
								oit = ProcTab.upper_bound($2);
								oit--;
								ss <<  "En linea: " << yylineno << " se declaro Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl;
								declares.push_back(ss.str());
								cout << ss.str();
								ss.str(string());
							  }
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
	expr _PLUS term				{ $$ = setType($1,$3); }
|
	expr _MINUS term			{$$ = setType($1,$3);}
|
	term		{$$ = $1;}
;

term:
	term _MULT fac				{ $$ = setType($1, $3); }
|
	term _DIVIDE fac			{ $$ = setType($1,$3); }
|
	fac			{ $$=$1; }
;

fac:
	val							{ $$ = $1; }
|
	_LPAREN expr _RPAREN		{ $$ = $2; }
;

val:
	ids							{ $$ = $1; }
|
	_ID _LPAREN vallist _RPAREN {oit = SymTab.upper_bound(yyval.sval);
									oit--;
									if(oit->first != yyval.sval) { error(yyval.sval); }
									else { 	$$ = oit->second.tipo;
											ss <<  "En linea:" << yylineno << " se uso Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl;
											uses.push_back(ss.str());
											cout << ss.str();
											ss.str(string());
										 }
								}
|
	_RCONST 	{ $$ = $1; }
|
	_ICONST		{ $$ = $1; }
;

ids:
	_ID			{ 	oit = SymTab.upper_bound(yyval.sval);
					oit--;
					if(oit->first != yyval.sval) { error(yyval.sval); }
					else { 	$$ = oit->second.tipo;
							ss <<  "En linea:" << yylineno << " se uso Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl;
					 		uses.push_back(ss.str());
							cout << ss.str();
							ss.str(string());
					 } 
				}
|
	_ID _LBRACK vallist _RBRACK {	oit = SymTab.upper_bound(yyval.sval);
									oit--;
									if(oit->first != yyval.sval) { error(yyval.sval); }
									else { 	$$ = oit->second.tipo;
											ss <<  "En linea:" << yylineno << " se uso Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl;
					 						uses.push_back(ss.str());
											cout << ss.str();
											ss.str(string());
					 }
					 }
;

vallist:
	vallist _COMMA  it			{ printf("Regla vallist\n"); }
|
	it
;

it:
	_ID							{ 	oit = SymTab.upper_bound(yyval.sval);
									oit--;
									if(oit->first != yyval.sval) { error(yyval.sval); }
									else { 	$$ = oit->second.tipo;
											ss <<  "En linea:" << yylineno << " se uso Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl;
					 						uses.push_back(ss.str());
											cout << ss.str();
											ss.str(string());
					 					} 
					 			}
|
	_ICONST { $$=$1; }
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
	_READ _LPAREN _ID _RPAREN	{ oit = SymTab.find($3);
								if(oit->first != $3) { error($3); }
								else {	cout <<  "En linea:" << yylineno << " se uso Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl; 
										uses.push_back(ss.str());
										cout << ss.str();
										ss.str(string());
									 } 
								}
;

output:
	_WRITE  _LPAREN _ID _RPAREN	{ 				oit = SymTab.find($3);
												if(oit->first != $3) { error($3); }
												else {	ss <<  "En linea:" << yylineno << " se uso Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl; 
														uses.push_back(ss.str());
														cout << ss.str();
														ss.str(string());	
									 				} 
								}
|
	_WRITE  _LPAREN _LITERAL  _RPAREN
;

%%

int yyerror(char *s)
{
	cout << "Syntax Error on line " << yylineno << endl;
	
	return 0;
}

int error(char *s)
{

	ss << "Error semantico, variable " << s << " no declarada en la linea " << yylineno << endl;
	declerrors.push_back(ss.str());
	cout << ss.str();
	ss.str(string());
	
	return 0;
}

string getType(short x)
{
	switch(x)
	{
		case Integer: 
				return strdup("Integer");
				break;
		case Real: 
				return strdup("Real");
				break;
		case String: 
				return strdup("String");
				break;
		case Procedure: 
				return strdup("Procedure");
				break;
		default: return strdup("Undefined");
					break;

	}
}

void typeError(short xtype, short ytype){

	string tipo1 = getType(xtype);
	string tipo2 = getType(ytype);

	ss << "Type error line " << yylineno << " type " << tipo1 << " missmatch " << tipo2 << endl;
	typerrors.push_back(ss.str());
	cout << ss.str();
	ss.str(string());

}

short setType(short xtype, short ytype)
{
	if(xtype <= 2) 
	switch(xtype)
	{
		case Integer:	if(ytype == 0) return 0;
				else if(ytype == 1) return 1;
				else typeError(xtype, ytype);
				break;

		case Real:	if(ytype == 0) return 1;
				else if(ytype == 1) return 1;
				else typeError(xtype, ytype);
				break;
		case String:	if(ytype == 2) return 2;
				else typeError(xtype, ytype);
				break;
	}

	else{typeError(xtype, ytype);}
}