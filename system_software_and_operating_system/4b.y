%{
#include<stdio.h>
#include<ctype.h>
%}
%token LETTER DIGIT
%%

VAR:
	  LETTER st '\n' {printf("Valid Variable name!\n"); exit(0);}
	;
st:
	  LETTER st
	| DIGIT st
	| DIGIT
	| LETTER
	;
%%

int yylex() {
	int c;
	while((c=getchar())==' ');
	if(isdigit(c)) {
		yylval=c-'0';
		return DIGIT;
	}
	if(isalpha(c)) {
		if(islower(c))
			yylval=c-'a';
		else
			yylval=c-'A';
		return LETTER;
	}
	return c;
}

int main() {
	printf("Enter Variable name : ");
	yyparse();
	return 0;
}

int yyerror() {
        printf("Invalid Variable name!\n");
        return 0;
}

