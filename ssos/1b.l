%{
#include <stdio.h>
#include <stdlib.h>
int mc=0, sc=0, flag=0;
%}
%%
.*"//".*	{sc++;}
"/*".*	{flag=1; mc++;}
"*/".*	{flag=0;}
.*	{if(!flag) fprintf(yyout, "%s", yytext);}
%%
int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("ERROR : INSUFFICIENT ARGUMENTS!!\n");
		exit(1);
	}

	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");

	yylex();

	printf("Single Comments = %d\nMulti-line Comments = %d\n", sc, mc);

	return 0;
}
