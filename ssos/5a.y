%{
#include<stdio.h>
#include<ctype.h>
#include<math.h>
%}

%token DIGIT
%left '+''-'
%left '*''/'
%%

list:
	| list s '\n' {exit(0);}
	;
s:
	exp	{printf("Result = %d\n", $$);}
	;
exp:
	  exp '+' exp {$$=$1+$3;}
	| exp '-' exp {$$=$1-$3;}
	| exp '*' exp {$$=$1*$3;}
	| exp '/' exp {if($3==0) printf("Division Error!\n"); $$=$1/$3;}
	| num %prec "*"
	;
num:
	  DIGIT
	| num DIGIT
	;
%%

int yylex() {
	int c;
	while((c=getchar())==' ');
	if( isdigit(c) ) {
		yylval=c-'0';
		return DIGIT;
	}
	return c;
}

int main() {
	printf("Enter Expression : ");
	yyparse();
	return 0;
}

int yyerror() {
	printf("Invalid Expression!\n");
	return 0;
}
