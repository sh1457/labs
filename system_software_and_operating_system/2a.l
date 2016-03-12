%{
#include<stdio.h>
int op[4]={0};
int ops=0, b=0, l=0, f=0;
%}
%%
[a-zA-Z0-9]+	{l++;}
[+]		{op[0]++; if(l==0) f=1;}
[-]		{op[1]++; if(l==0) f=1;}
[*]		{op[2]++;}
[/]		{op[3]++;}
[(]		{b++;}
[)]		{b--;}
.|\n		{ext();}
%%
void ext() {
	ops = op[0]+op[1]+op[2]+op[3];
        if( (ops>=1 && l==ops+1 && b==0) || (f==1 && l==ops) ) {
                printf("Valid Expression!\n");
                printf("Identifiers = %d\n", l);
                printf("Operators ( +, -, *, / ) = ( %d, %d, %d, %d )\n", op[0], op[1], op[2], op[3]);
        }else {
                printf("Invalid expression!\n");
        }
	exit(0);
}
int main() {
	printf("Enter arithematic expression : ");
	yylex();
	return 0;
}
