#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 20

typedef struct {
	int TOS;
	int ch[SIZE];
}STACK;

STACK s;

void push(int c) {
	if(s.TOS >= SIZE) {
		fprintf(stderr, "Stack Overflow Error!\n");
		exit(1);
	}else {
		s.ch[++(s.TOS)] = c;
	}
}

int pop() {
	if(s.TOS == -1) {
		fprintf(stderr, "Stack Underflow Error!\n;");
		exit(1);
	}else {
		return s.ch[(s.TOS)--];
	}
}

int main() {
	int i = 0; 
	int op1 = 0, op2 = 0;
	char pf[SIZE];
	s.TOS = -1;
	puts("Enter a valid Postfix Expression : ");
	fgets(pf, SIZE, stdin);
	while(pf[i] != '\n') {
		if(isdigit(pf[i])) {
			push((int) pf[i]-'0');
		}else {
			op1 = pop();
			op2 = pop();
			switch(pf[i]) {
				case '+':
					push(op2+op1);
				break;
				case '-':
					push(op2-op1);
				break;
				case '*':
					push(op2*op1);
				break;
				case '/':
					push(op2/op1);
				break;
				default:
					fprintf(stderr, "Invalid Operator!\n");
					exit(1);
			}
		}
	i++;
	}
	if(s.TOS != 0) {
		fprintf(stderr, "Invalid Expression!\n");
		exit(1);
	}
	printf("The Value of this Postfix Expression is %d\n", pop());
	return 0;	
}
