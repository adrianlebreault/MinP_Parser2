/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    ICONST = 259,
    RCONST = 260,
    ECONST = 261,
    LITERAL = 262,
    LBRACK = 263,
    RBRACK = 264,
    LPAREN = 265,
    RPAREN = 266,
    SEMI = 267,
    COLON = 268,
    COMMA = 269,
    ASSIGN = 270,
    PLUS = 271,
    MINUS = 272,
    MULT = 273,
    DIVIDE = 274,
    EQL = 275,
    LESS = 276,
    GTR = 277,
    LEQ = 278,
    GEQ = 279,
    NEQ = 280,
    PROGRAM = 281,
    ENDVARS = 282,
    ENDPROCS = 283,
    VARS = 284,
    NOVARS = 285,
    INTEGER = 286,
    REAL = 287,
    STRING = 288,
    PROCS = 289,
    NOPROCS = 290,
    PROC = 291,
    _BEGIN = 292,
    END = 293,
    FOR = 294,
    TO = 295,
    DO = 296,
    IF = 297,
    THEN = 298,
    ELSE = 299,
    READ = 300,
    WRITE = 301,
    ERROR = 302
  };
#endif
/* Tokens.  */
#define ID 258
#define ICONST 259
#define RCONST 260
#define ECONST 261
#define LITERAL 262
#define LBRACK 263
#define RBRACK 264
#define LPAREN 265
#define RPAREN 266
#define SEMI 267
#define COLON 268
#define COMMA 269
#define ASSIGN 270
#define PLUS 271
#define MINUS 272
#define MULT 273
#define DIVIDE 274
#define EQL 275
#define LESS 276
#define GTR 277
#define LEQ 278
#define GEQ 279
#define NEQ 280
#define PROGRAM 281
#define ENDVARS 282
#define ENDPROCS 283
#define VARS 284
#define NOVARS 285
#define INTEGER 286
#define REAL 287
#define STRING 288
#define PROCS 289
#define NOPROCS 290
#define PROC 291
#define _BEGIN 292
#define END 293
#define FOR 294
#define TO 295
#define DO 296
#define IF 297
#define THEN 298
#define ELSE 299
#define READ 300
#define WRITE 301
#define ERROR 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 89 "parse.y" /* yacc.c:1909  */


	short tipo;
	char *sval;
	

#line 155 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
