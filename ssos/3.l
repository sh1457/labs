%{
#include<stdio.h>
#include<stdlib.h>
int c=0;
%}
DT      "int"|"float"|"char"|"long"|"double"|"short"
ID      [a-zA-Z][a-zA-Z0-9]*
%S STR

%%

{DT}            {ECHO; BEGIN(STR);}
<STR>{ID}/,     {ECHO; c++;}
<STR>{ID}/;     {ECHO; c++; BEGIN(INITIAL);}

%%

int main(int argc, char *argv[]) {
        if(argc==2) {
                yyin=fopen(argv[1], "r");
        }else {
                printf("Error!\n\n");
                exit(0);
        }
        yylex();
        printf("Number of Identifiers = %d\n", c);
	return 0;
}
