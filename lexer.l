%{
	#include <stdio.h>
	#include "sem.tab.h"
	int line_num = 1;
	int yyline;
%}

upper  [A-Z]
lower  [a-z]
digit  [0-9]
spaces [ \t]+
foo ({upper}|{lower})({upper}|{lower}|{digit}|_({digit}|{lower}|{upper}))*
id_int I_{foo}
id_float F_{foo}
id_string S_{foo}
id_bool B_{foo}
id_comp C_{foo}
c_int {digit}+
c_float {digit}+,{digit}+
c_string \"[^\"\n]*\"
line_comment \/\/.*
block_comment \/\*([^\*\/]*\n*)*\*\/
invalid_block_comment \/\*([^(\*\/)]*\n*)*
open_parantheses \(
close_parantheses \)
open_brackets \[
close_brackets \]
open_braces \{
close_braces \}
semi_colon ;
main main
input input
false false
if if
isFalseDo isFalseDo
isTrueDo isTrueDo
output output
true true
types types
while while
dot \.
comma ,
colon :
plus \+
minus \-
asterisk \*
slash \/
equals =
double_equals ==
not_equal !=
less_than <
less_equal <=
greater_than >
greater_equal >=
not !
and &&
or \|\|

%%

{dot} { yyline = line_num; return DOT; }
{comma} { yyline = line_num; return COMMA; }
{colon} { yyline = line_num; return COLON; }
{plus} { yyline = line_num; return PLUS; }
{minus} { yyline = line_num; return MINUS; }
{asterisk} { yyline = line_num; return ASTERISK; }
{slash} { yyline = line_num; return SLASH; }
{equals} { yyline = line_num; return EQUALS; }
{double_equals} { yyline = line_num; return DOUBLE_EQUALS; }
{not_equal} { yyline = line_num; return NOT_EQUAL; }
{less_than} { yyline = line_num; return LESS_THAN; }
{less_equal} { yyline = line_num; return LESS_EQUAL; }
{greater_than} { yyline = line_num; return GREATER_THAN; }
{greater_equal} { yyline = line_num; return GREATER_EQUAL; }
{not} { yyline = line_num; return NOT; }
{and} { yyline = line_num; return AND; }
{or} { yyline = line_num; return OR; }
{false} { yyline = line_num; return T_FALSE; }
{if} { yyline = line_num; return IF; }
{isFalseDo} { yyline = line_num; return ISFALSEDO; }
{isTrueDo} { yyline = line_num; return ISTRUEDO; }
{output} { yyline = line_num; return OUTPUT; }
{true} { yyline = line_num; return T_TRUE; }
{types} { yyline = line_num; return TYPES; }
{while} { yyline = line_num; return WHILE; }
{main} { yyline = line_num; return MAIN; }
{semi_colon} { yyline = line_num; return SEMI_COLON; }
{open_parantheses} { yyline = line_num; return OPEN_PARANTHESES ; }
{close_parantheses} { yyline = line_num; return CLOSE_PARANTHESES ; }
{open_brackets} { yyline = line_num; return OPEN_BRACKETS ; }
{close_brackets} { yyline = line_num; return CLOSE_BRACKETS ; }
{open_braces} { yyline = line_num; return OPEN_BRACES ; }
{close_braces} { yyline = line_num; return CLOSE_BRACES ; }
{input} { yyline = line_num; return INPUT; }
{id_int} { yyline = line_num; return ID_INT;}
{id_float} { yyline = line_num; return ID_FLOAT;}
{id_string} { yyline = line_num; return ID_STRING;}
{id_bool} { yyline = line_num; return ID_BOOL;}
{id_comp} { yyline = line_num; return ID_COMP;}
{c_int} { yyline = line_num; return C_INT;}
{c_float} { yyline = line_num; return C_FLOAT;}
{c_string} { yyline = line_num; return C_STRING;}
{line_comment} { /* do nothing */ }
{block_comment} { 
	int i = 0;
	while(yytext[i] != '\0')
		if (yytext[i++] == '\n')
			line_num++;
}
{spaces} { /* do nothing */ }

\n {line_num++;}
(I|F|S|B|C) { yyline = line_num; return ERR_ID; }
\" { yyline = line_num; return ERR_STR; }
{invalid_block_comment} { yyline = line_num; return ERR_BLK; }
. { yyline = line_num; return ERR_UNK; }

%%
