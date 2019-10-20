/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

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

#ifndef YY_YY_SEM_TAB_H_INCLUDED
# define YY_YY_SEM_TAB_H_INCLUDED
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
    KEYWORD = 258,
    ID_INT = 259,
    ID_FLOAT = 260,
    ID_STRING = 261,
    ID_BOOL = 262,
    ID_COMP = 263,
    C_INT = 264,
    C_FLOAT = 265,
    C_STRING = 266,
    END = 267,
    SYMBOL = 268,
    ERR_ID = 269,
    ERR_STR = 270,
    ERR_BLK = 271,
    ERR_UNK = 272,
    MAIN = 273,
    INPUT = 274,
    OPEN_PARANTHESES = 275,
    CLOSE_PARANTHESES = 276,
    OPEN_BRACKETS = 277,
    CLOSE_BRACKETS = 278,
    OPEN_BRACES = 279,
    CLOSE_BRACES = 280,
    SEMI_COLON = 281,
    T_FALSE = 282,
    IF = 283,
    ISFALSEDO = 284,
    ISTRUEDO = 285,
    OUTPUT = 286,
    T_TRUE = 287,
    TYPES = 288,
    WHILE = 289,
    DOT = 290,
    COMMA = 291,
    COLON = 292,
    PLUS = 293,
    MINUS = 294,
    ASTERISK = 295,
    SLASH = 296,
    EQUALS = 297,
    DOUBLE_EQUALS = 298,
    NOT_EQUAL = 299,
    LESS_THAN = 300,
    LESS_EQUAL = 301,
    GREATER_THAN = 302,
    GREATER_EQUAL = 303,
    NOT = 304,
    AND = 305,
    OR = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SEM_TAB_H_INCLUDED  */
