%{
#include<stdio.h>
#include<ctype.h>
%}

%token A B
%%

list:
	| list s '\n' {printf("Valid!\n"); exit(0);}
	;
s:
	A s B
	|
	;
%%

int yylex() {
	int c;
	while((c=getchar())==' ');
	if(c=='a')
		return A;
	if(c=='b')
		return B;
	return c;
}

int main() {
	printf("Enter String : ");
	yyparse();
	return 0;
}

int yyerror() {
	printf("Invalid!\n");
	return 0;
}

