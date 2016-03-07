%{
#include <stdio.h>
#include <stdlib.h>
int wc=0, cc=0, lc=0, sc=0;
%}
%%
[^ \t\n]+	{wc++; cc += yyleng;}
\n		{lc++; cc++;}
" "		{sc++; cc++;}
\t		{sc += 4; cc++;}
.		{cc++;}
%%
int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("ERROR : INSUFFIECIENT ARGUMENTS!!\n");
		exit(1);
	}

	yyin = fopen(argv[1], "r");

	yylex();

	printf("Word Count = %d\nLine Count = %d\nCharacter Count = %d\nSpace Count = %d\n", wc, lc, cc, sc);

	return 0;
}
