#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 10

//STRUCTURES

typedef struct {
	int TOS;	
	char ch[SIZE];	
}STACK;

//GLOBALS

STACK s;

//FUNCTIONS

int precede(char);
void push(char);
char pop();

int precede(char c) {
	if(c=='/' || c=='*') {
		return 2;
	}else if(c=='+' || c=='-') {
		return 1;
	}
	return 0;
}

void push(char c) {
	if(s.TOS>SIZE) {
		fprintf(stderr, "Stack Overflow Error\n");
	}
	s.ch[++(s.TOS)]=c;
}

char pop() {
	if(s.TOS==-1) {
		fprintf(stderr, "Stack Underflow Error\n");
	}
	return s.ch[(s.TOS)--];
}

int main() {
	int i=0,j=0;
	char infix[SIZE], pf[SIZE];
	printf("Enter a valid infix expression: ");
	fgets(infix, SIZE, stdin);
	push('#');
	while(infix[i]!='\0') {
		if(isdigit(infix[i]) || isalpha(infix[i])) {
			pf[j++]=infix[i];
		}else if(infix[i]=='(') {
			push(infix[i]);
		}else if(infix[i]==')') {
			while(s.ch[s.TOS]!='(') {
				pf[j++]=pop();
			}
			pop();
		}else if (infix[i]=='/' || infix[i]=='*' || infix[i]=='+' || infix[i]=='-') {
			if(precede(infix[i])>precede(s.ch[s.TOS])) {
				push(infix[i]);
			} else {
				do {
					pf[j++]=pop();
				}while(precede(infix[i])<precede(s.ch[s.TOS]));
			}
		}else {
			while(s.ch[s.TOS]!='#') {
				pf[j++]=pop();
			}
		}
		i++;
	} 
	pf[j]='\0';
	printf("The Postfix expression is %s\n",pf);
	return 0;
}
