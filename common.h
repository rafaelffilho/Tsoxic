#ifndef COMMON_H
#define COMMON_H

char *s;

int yyerror(char *s);
int yywrap() {
	return 1;
}

/*enum foo {
	SYMBOL = 1,
	KEYWORD = 2,
	ID_INT = 3,
	ID_FLOAT,
	ID_STR,
	ID_BOOL,
	ID_COMP,
	C_INT,
	C_FLOAT,
	C_STR,
	ERR_ID,
	ERR_STR,
	ERR_BLK,
	ERR_UNK,
	END
};*/

#endif
