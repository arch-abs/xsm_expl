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
    NUM = 258,
    END = 259,
    _BEGIN = 260,
    READ = 261,
    WRITE = 262,
    ID = 263,
    IF = 264,
    then = 265,
    Else = 266,
    ENDIF = 267,
    WHILE = 268,
    DO = 269,
    ENDWHILE = 270,
    RETURN = 271,
    LT = 272,
    GT = 273,
    LE = 274,
    GE = 275,
    EQ = 276,
    NE = 277,
    BREAK = 278,
    CONT = 279,
    DECL = 280,
    ENDDECL = 281,
    INTEGER = 282,
    STRING = 283,
    STRING_LITERAL = 284,
    MAIN = 285
  };
#endif
/* Tokens.  */
#define NUM 258
#define END 259
#define _BEGIN 260
#define READ 261
#define WRITE 262
#define ID 263
#define IF 264
#define then 265
#define Else 266
#define ENDIF 267
#define WHILE 268
#define DO 269
#define ENDWHILE 270
#define RETURN 271
#define LT 272
#define GT 273
#define LE 274
#define GE 275
#define EQ 276
#define NE 277
#define BREAK 278
#define CONT 279
#define DECL 280
#define ENDDECL 281
#define INTEGER 282
#define STRING 283
#define STRING_LITERAL 284
#define MAIN 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "stage5_yacc.y" /* yacc.c:1909  */

     struct tnode* root;

#line 118 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
