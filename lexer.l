%{
	#include <stdio.h>
	int line_num = 1;
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

{symbols} { printf("found symbols (%s) in line %d\n", yytext, line_num); }
{keyword_list} { printf("found keyword (%s) in line %d\n", yytext, line_num); }
{id_int} { printf("found id_int (%s) in line %d\n", yytext, line_num); }
{id_float} { printf("found id_float (%s) in line %d\n", yytext, line_num); }
{id_string} { printf("found id_string (%s) in line %d\n", yytext, line_num); }
{id_bool} { printf("found id_bool (%s) in line %d\n", yytext, line_num); }
{id_comp} { printf("found id_comp (%s) in line %d\n", yytext, line_num); }
{c_int} { printf("found c_int (%s) in line %d\n", yytext, line_num); }
{c_float} { printf("found c_float (%s) in line %d\n", yytext, line_num); }
{c_string} { printf("found c_string (%s) in line %d\n", yytext, line_num); }
{line_comment} { /* do nothing */ }
{block_comment} { 
	int i = 0;
	while(yytext[i] != '\0')
		if (yytext[i++] == '\n')
			line_num++;
}
{spaces} { /* do nothing */ }

\n {line_num++;}
(I|F|S|B|C) { printf("ERROR line %d - Invalid id %s_\n", line_num, yytext); return -1; }
\" { printf("ERROR line %d - Invalid string\n", line_num); return -1; }
{invalid_block_comment} { printf("ERROR line %d - Invalid block comment\n", line_num); return -1; }
. { printf("ERROR: unrecognized (%s) line %d\n", yytext, line_num); return -1; }

%%
int yywrap () {}

int parse () {
	yylex();
}