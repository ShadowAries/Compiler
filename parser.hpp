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

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    T_ARROW = 258,
    T_PLUS = 259,
    T_MINUS = 260,
    T_MULT = 261,
    T_DIVIDE = 262,
    T_AND = 263,
    T_OR = 264,
    T_NOT = 265,
    T_OPAREN = 266,
    T_CPAREN = 267,
    T_OBRACET = 268,
    T_CBRACET = 269,
    T_SEMICOLON = 270,
    T_COMMA = 271,
    T_DOT = 272,
    T_ASSIGNMENT = 273,
    T_LESSEQ = 274,
    T_LESS = 275,
    T_EQUALS = 276,
    T_IFSTMNT = 277,
    T_ELSESTMNT = 278,
    T_WHILESTMNT = 279,
    T_REPEATSTMNT = 280,
    T_UNTILSTMNT = 281,
    T_PRINTSTMNT = 282,
    T_LITERAL = 283,
    T_TRUE = 284,
    T_FALSE = 285,
    T_BOOLEAN = 286,
    T_INTEGER = 287,
    T_NONE = 288,
    T_NEW = 289,
    T_EXTENDS = 290,
    T_EOF = 291,
    T_COLON = 292,
    T_RETURN = 293,
    T_CLASS = 294,
    T_IDENTIFIER = 295,
    NOT = 296,
    UNARYMINUS = 297
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
