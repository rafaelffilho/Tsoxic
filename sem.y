%{
	#include <stdio.h>
%}

%token KEYWORD ID_INT ID_FLOAT ID_STRING ID_BOOL ID_COMP C_INT C_FLOAT C_STRING END SYMBOL ERR_ID ERR_STR ERR_BLK ERR_UNK MAIN INPUT OPEN_PARANTHESES CLOSE_PARANTHESES OPEN_BRACKETS CLOSE_BRACKETS OPEN_BRACES CLOSE_BRACES SEMI_COLON T_FALSE IF ISFALSEDO ISTRUEDO OUTPUT T_TRUE TYPES WHILE DOT COMMA COLON PLUS MINUS ASTERISK SLASH EQUALS DOUBLE_EQUALS NOT_EQUAL LESS_THAN LESS_EQUAL GREATER_THAN GREATER_EQUAL NOT AND OR

%start program

%glr-parser

%%

program: types MAIN OPEN_BRACKETS var_dec com_list CLOSE_BRACKETS ;

types: %empty | TYPES OPEN_BRACKETS f CLOSE_BRACKETS ;

f: ID_COMP COLON OPEN_BRACKETS field_list CLOSE_BRACKETS SEMI_COLON | ID_COMP COLON OPEN_BRACKETS field_list CLOSE_BRACKETS SEMI_COLON f ;

field_list: field | field COMMA field_list ;

field: ID_INT | ID_FLOAT | ID_STRING | ID_BOOL ;

var_dec: %empty | COLON var_list SEMI_COLON ;

var_list: var | var COMMA var_list ;

var: simple_type | complex_type ;

simple_type: field | field OPEN_BRACKETS C_INT CLOSE_BRACKETS ;

complex_type: ID_COMP OPEN_BRACKETS ID_COMP CLOSE_BRACKETS | ID_COMP OPEN_BRACKETS C_INT COMMA ID_COMP CLOSE_BRACKETS ;

atribuition: use_var EQUALS expr ;

use_var: id opt_expr opt_field ;

id: ID_BOOL | ID_COMP | ID_FLOAT | ID_INT | ID_STRING ;

opt_expr: %empty | OPEN_BRACKETS expr CLOSE_BRACKETS ;

opt_field: %empty | DOT field ;

input: INPUT OPEN_PARANTHESES id_list CLOSE_PARANTHESES ;

output: OUTPUT OPEN_PARANTHESES expr_list CLOSE_PARANTHESES ;

id_list: use_var | use_var COMMA id_list ;

expr_list: expr | expr COMMA expr_list ;

selection: IF OPEN_PARANTHESES expr CLOSE_PARANTHESES ISTRUEDO OPEN_BRACKETS com_list CLOSE_BRACKETS sel_false ;

sel_false: %empty | ISFALSEDO OPEN_BRACKETS com_list CLOSE_BRACKETS ;

loop: WHILE OPEN_PARANTHESES expr CLOSE_PARANTHESES loop_do ;

loop_do: ISTRUEDO OPEN_BRACKETS com_list CLOSE_BRACKETS | ISFALSEDO OPEN_BRACKETS com_list CLOSE_BRACKETS ;

com_list: command SEMI_COLON | command SEMI_COLON com_list ;

command: input | output | selection | loop | atribuition ;

expr: element expr_ ;

expr_: %empty | OR element expr_ | AND element expr_ ;

element: relational | T_TRUE | T_FALSE | NOT element ;

relational: arithmetic realtional_op arithmetic | arithmetic ;

realtional_op: DOUBLE_EQUALS | NOT_EQUAL | LESS_THAN | LESS_EQUAL | GREATER_EQUAL | GREATER_THAN ;

arithmetic: term arithmetic_ ;

arithmetic_: %empty | PLUS term arithmetic_ | MINUS term arithmetic_ ;

term: factor term_ ;

term_: %empty | ASTERISK factor term_ | SLASH factor term_ ;

factor: use_var | C_INT | C_FLOAT | C_STRING | OPEN_PARANTHESES expr CLOSE_PARANTHESES | PLUS factor | MINUS factor ;

%%
main()
{
 return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}

yywrap()
{
  return(1);
}