%{
#include<stdio.h>
#include<ctype.h>
%}

%token LETTER DIGIT
%left '+''-'
%left '*''/'
%%
list:
	|list exp '\n' {printf("Valid Expression!\n"); exit(0);}
	;
exp:
	  exp '+' exp
	| exp '-' exp
	| exp '*' exp
	| exp '/' exp
	| num
	| var;
num:
	  DIGIT
	| num DIGIT
var:
	  LETTER
	| var LETTER
%%

int yylex() {
	int c;
	while((c=getchar())==' ');
	if( isalpha(c) )
		return LETTER;
	if( isdigit(c) )
		return DIGIT;
	return c;
}

int main() {
	printf("Enter the expression : ");
	yyparse();
	return 0;
}

int yyerror() {
	printf("Invalid Expression!\n");
	return 0;
}
