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
// vector<string> declares, uses, declerrors, typerrors;




%}

%token ID
%token ICONST
%token RCONST
%token ECONST
%token LITERAL
%token LBRACK
%token RBRACK
%token LPAREN
%token RPAREN
%token SEMI
%token COLON
%token COMMA
%token ASSIGN
%token PLUS
%token MINUS
%token MULT
%token DIVIDE
%token EQL
%token LESS
%token GTR
%token LEQ
%token GEQ
%token NEQ
%token PROGRAM
%token ENDVARS
%token ENDPROCS
%token VARS
%token NOVARS
%token INTEGER
%token REAL
%token STRING
%token PROCS
%token NOPROCS
%token PROC
%token _BEGIN
%token END
%token FOR
%token TO
%token DO
%token IF
%token THEN
%token ELSE
%token READ
%token WRITE
%token ERROR

%type <sval> ID
%type <tipo> expr term fac val ids it RCONST ICONST ECONST INTEGER STRING LITERAL


%union {

	short tipo;
	char *sval;
	
}

%start program

%%

program:
	title SEMI block 
;

title:
	PROGRAM ID { nivel = 0; }
;

block:
	vars { nivel++; }  ENDVARS procs ENDPROCS code  {  oit = SymTab.begin();
														while(oit != SymTab.end())
														{
															if(oit->second.nivel == nivel) SymTab.erase(oit);

															oit++;
														}
														nivel--; 
													 }
;

vars:
	VARS {  declaration = true; } varlist SEMI	
|
	NOVARS			
;

varlist:
	varlist SEMI vardef 
|
	vardef				
;

vardef:
	ID COLON INTEGER		{  
								if(declaration){
									registro newreg;
									newreg.tipo = Integer;
									newreg.nivel = nivel;
									SymTab.insert(pair<string,registro>(yyval.sval,newreg));
									// oit = SymTab.upper_bound(yyval.sval);
									// oit--;
									auto ouit = SymTab.find(yyval.sval);
							
									ss <<  "En linea: " << yylineno << " se declaro Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
									//declares.push_back(ss.str());
									cout << ss.str();
									ss.str(string());
								}
							}
|
	ID COLON REAL			{
								if(declaration){
									registro newreg;
									newreg.tipo = Real;
									newreg.nivel = nivel;
									SymTab.insert(pair<string,registro>(yyval.sval,newreg));
									// oit = SymTab.upper_bound(yyval.sval);
									// oit--;
									auto ouit = SymTab.find(yyval.sval);
									ss <<  "En linea: " << yylineno << " se declaro Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
									// declares.push_back(ss.str());
									cout << ss.str();
									ss.str(string());}
							}
|
	ID COLON INTEGER bnl	{   
								if(declaration){
									registro newreg;
									newreg.tipo = Integer;
									newreg.nivel = nivel;
									SymTab.insert(pair<string,registro>(yyval.sval,newreg));
									// oit = SymTab.upper_bound(yyval.sval);
									// oit--;
									auto ouit = SymTab.find(yyval.sval);
									ss <<  "En linea: " << yylineno << " se declaro Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
									// declares.push_back(ss.str());
									cout << ss.str();
									ss.str(string());}
							}
|
	ID COLON STRING			 {  
								if(declaration){
									registro newreg;
									newreg.tipo = String;
									newreg.nivel = nivel;
									SymTab.insert(pair<string,registro>(yyval.sval,newreg));
									// oit = SymTab.upper_bound(yyval.sval);
									// oit--;
									auto ouit = SymTab.find(yyval.sval);
									ss <<  "En linea: " << yylineno << " se declaro Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
									// declares.push_back(ss.str());
									cout << ss.str();
									ss.str(string());}
							} 
;

bnl:
	LBRACK nlist RBRACK		
;

nlist:
	nlist COMMA ICONST		
|
	ICONST					
;

procs:
	PROCS  proclist			
|
	NOPROCS					
;

proclist:
	proclist SEMI procdef	
|
	procdef					
;

procdef:
	ptittle SEMI block 	
;

ptittle:
	PROC ID LPAREN { declaration = true; }
	varlist RPAREN	{
						registro newreg;
						newreg.tipo = Procedure;
						newreg.nivel = nivel;
						ProcTab.insert(pair<string,registro>($2,newreg));
						// oit = ProcTab.upper_bound($2);
						// oit--;
						auto ouit = ProcTab.find($2);
						ss <<  "En linea: " << yylineno << " se declaro Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
						// declares.push_back(ss.str());
						cout << ss.str();
						ss.str(string());
					}
|
	PROC ID LPAREN RPAREN	{
								registro newreg;
								newreg.tipo = Procedure;
								newreg.nivel = nivel;
								ProcTab.insert(pair<string,registro>($2,newreg));
								// oit = ProcTab.upper_bound($2);
								// oit--;
								auto ouit = ProcTab.find($2);
								ss <<  "En linea: " << yylineno << " se declaro Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
								// declares.push_back(ss.str());
								cout << ss.str();
								ss.str(string());
							}
;

code:
	_BEGIN para END			
|
	SEMI						
;

para:
	para SEMI stmt				
|
	stmt						
;

stmt:
	assign						
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
	ids ASSIGN expr				
;

expr:
	expr PLUS term		{	$$ = setType($1, $3); }		
|
	expr MINUS term		{	$$ = setType($1, $3); }		
|
	term		{ $$ = $1;}				
;

term:
	term MULT fac		{	$$ = setType($1, $3); }			
|
	term DIVIDE fac		{	$$ = setType($1, $3); }		
|
	fac		{ $$ = $1;}				
;

fac:
	val			{ $$ = $1; }
|
	LPAREN expr RPAREN		{ $$ = $2; }	
;

val:
	ids							{ $$ = $1; }
|
	ID LPAREN vallist RPAREN	{	//Se busca en la tabla de simbolo para encontrar el uso de la variable cuyo lexema de identificador proviene de ID
									// oit = SymTab.upper_bound(yyval.sval);
									// oit--;
									auto ouit = SymTab.find(yyval.sval);
									if(ouit->first != yyval.sval) { error(yyval.sval); }
									else { 	$$ = ouit->second.tipo;
											ss <<  "En linea:" << yylineno << " se uso Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
											// uses.push_back(ss.str());
											cout << ss.str();
											ss.str(string());
										 }
								}	
|
	RCONST			{ 	$$ = $1;	}	
|		
	ICONST			{ 	$$ = $1;	}			
;

ids:
	ID		{	//Se busca en la tabla de simbolo para encontrar el uso de la variable cuyo lexema de identificador proviene de ID
				// oit = SymTab.upper_bound(yyval.sval);
				// oit--;
				auto ouit = SymTab.find(yyval.sval);
				if(ouit->first != yyval.sval) { error(yyval.sval); }
				else { 	$$ = ouit->second.tipo;
						ss <<  "En linea:" << yylineno << " se uso Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
					 	// uses.push_back(ss.str());
						cout << ss.str();
						ss.str(string());
					 }
			}					
|
	ID LBRACK vallist RBRACK	{	//Se busca en la tabla de simbolo para encontrar el uso de la variable cuyo lexema de identificador proviene de ID
									// oit = SymTab.upper_bound(yyval.sval);
									// oit--;
									auto ouit = SymTab.find(yyval.sval);
									if(ouit->first != yyval.sval) { error(yyval.sval); }
									else { 	$$ = ouit->second.tipo;
											ss <<  "En linea:" << yylineno << " se uso Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
											// uses.push_back(ss.str());
											cout << ss.str();
											ss.str(string());
										 }
								}
;

vallist:
	vallist COMMA it			
|
	it							
;

it:
	ID							{	//Se busca en la tabla de simbolo para encontrar el uso de la variable cuyo lexema de identificador proviene de ID
									// oit = SymTab.upper_bound(yyval.sval);
									// oit--;
									auto ouit = SymTab.find(yyval.sval);
									if(ouit->first != yyval.sval) { error(yyval.sval); }
									else { 	$$ = ouit->second.tipo;
											ss <<  "En linea:" << yylineno << " se uso Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
											// uses.push_back(ss.str());
											cout << ss.str();
											ss.str(string());
										 }
								}
|
	ICONST						{ 	$$ = $1;
								}
;

cond:
	IF expr bop expr THEN stmt ELSE stmt 	
;

bop:
	EQL		
|
	LESS	
|
	GTR		
|
	LEQ		
|
	GEQ		
|
	NEQ		
;

loop:
	FOR assign TO expr DO stmt	
;

input:
	READ LPAREN ID RPAREN	{
								oit = SymTab.find($3);
								if(oit->first != $3) { error($3); }
								else {	cout <<  "En linea:" << yylineno << " se uso Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl; 
										// uses.push_back(ss.str());
										cout << ss.str();
										ss.str(string());
									 }
							}
;

output:
	WRITE LPAREN ID RPAREN	{
								oit = SymTab.find($3);
								if(oit->first != $3) { error($3); }
								else {	ss <<  "En linea:" << yylineno << " se uso Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl; 
										// uses.push_back(ss.str());
										cout << ss.str();
										ss.str(string());	
									 }
							}
|
	WRITE LPAREN LITERAL RPAREN
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
	// declerrors.push_back(ss.str());
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
	// typerrors.push_back(ss.str());
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

