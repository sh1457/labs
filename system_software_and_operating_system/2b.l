%{
#include <stdio.h>
#include <stdlib.h>
int flag=0;
%}
ID [a-zA-Z0-9]+
%%
{ID}" ""but"|"although"|"because"|"but"|"and"|"nor"|"else"|"therefore"" "{ID}	{flag=1; puts(""); printf("%s", yytext);}
%%
int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("ERROR : INSUFFIECIENT ARGUMENTS!!\n");
		exit(1);
	}

	yyin = fopen(argv[1], "r");

	yylex();

	if(flag)
		printf("Compound!\n");
	else
		printf("Simple!\n");

	return 0;
}
