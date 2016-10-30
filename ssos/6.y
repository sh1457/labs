%{
#include<stdio.h>
#include<ctype.h>
int bc=0;
%}
%token A B
%%
list:
	| list start '\n' {if(bc==1) {printf("Valid String!\n");}else {printf("Invalid String!\n");} exit(0);}
	;
start: 
	A A A A A A A A A A s B
	;
s: 
	| A s
	;
%%
int yylex() {
        int c;
	while( (c=getchar())==' ');
	if(c=='a')
		return (A);
	if(c=='b') {
		bc++;
		return (B);
	}
	return c;
}

int main() {
	printf("Enter String : ");
	yyparse();
	return 0;
}
int yyerror() {
	printf("Invalid String!\n");
	return 0;
}
