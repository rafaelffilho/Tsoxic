%{
	#include <stdio.h>
	#include "common.h"
	int line_num = 1;
	extern int yyline;
%}

upper  [A-Z]
lower  [a-z]
digit  [0-9]
spaces [ \t]+
foo ({upper}|{lower})({upper}|{lower}|{digit}|_({digit}|{lower}|{upper}))*
symbols (\.|,|:|;|\[|\]|\(|\)|\+|\-|\*|\/|=|==|\!=|<|<=|>|>=|!|&&|\|\|)

keyword_list (false|if|input|isFalseDo|isTrueDo|main|output|true|types|while)
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

%%

{symbols} { yyline = line_num; return SYMBOL;}
{keyword_list} { yyline = line_num; return KEYWORD;}
{id_int} { yyline = line_num; return ID_INT;}
{id_float} { yyline = line_num; return ID_FLOAT;}
{id_string} { yyline = line_num; return ID_STR;}
{id_bool} { yyline = line_num; return ID_BOOL;}
{id_comp} { yyline = line_num; return ID_COMP;}
{c_int} { yyline = line_num; return C_INT;}
{c_float} { yyline = line_num; return C_FLOAT;}
{c_string} { yyline = line_num; return C_STR;}
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
int yywrap () { }

int parse () {
	yylex();

	return 0;
}