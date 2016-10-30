#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int exp;
	float cf;
	struct node *link;
}Node;

Node *HEAD1, *HEAD2, *HEAD3;

Node *getNode() {
	return (Node *)malloc(sizeof(Node));
}

Node *createPoly(Node *head) {
	Node *tmp, *cur;
	printf("Enter the terms in descending order of the exponent!\n");
	printf("Input -1 -1 to stop.\n");
	while(1) {
		if((tmp = getNode()) == NULL) {
			printf("\nInsufficient Memory!\n");
		}else {
			printf("Enter the CF and EXP of the term : ");
			scanf("%f %d", &(tmp->cf), &(tmp->exp));
			if(tmp->cf == -1.0 && tmp->exp == -1) {
				break;
			}
			if(head == NULL) {
				head = tmp;
			}else {
				cur = head;
				while(cur->link != NULL) {
					cur = cur->link;
				}
				cur->link = tmp;
			}
		}
	}
	return head;
}

Node *addPoly(Node *head1, Node *head2) {
	Node *head = NULL, *cur = head, *tmp, *tmp1 = head1 , *tmp2 = head2;
	while(tmp1 != NULL || tmp2 != NULL) {
		if((tmp = getNode()) == NULL) {
			printf("\nInsufficient Memory!\n");		
		}else {
			if(tmp1->exp == tmp2->exp) {
				tmp->exp = tmp1->exp;
				tmp->cf = tmp1->cf + tmp2->cf;
				tmp1 = tmp1->link;
				tmp2 = tmp2->link;
			}else if(tmp1->exp > tmp2->exp) {
				tmp = tmp1;	
				tmp1 = tmp1->link;
			}else {
				tmp = tmp2;
				tmp2 = tmp2->link;
			}
			if(head == NULL) {
				head = tmp;
				cur = head;
			}else {	
				cur->link = tmp;
				cur = cur->link;
			}
		}
	}
	if(tmp1 == NULL) {
		while(tmp2 != NULL) {
			tmp = tmp2;
			tmp2 = tmp2->link;
			cur->link = tmp;
			cur = cur->link;
		}
	}else {
		while(tmp1 != NULL) {
			tmp = tmp1;
			tmp1 = tmp1->link;
			cur->link = tmp;
			cur = cur->link;
		}
	}
	return head;
}

void display(Node *head) {
	Node *tmp = head;
	while(tmp != NULL) {
		if(tmp->cf != 0 || tmp->exp > 0) {
			printf(" %.2f X ^ %d ", tmp->cf, tmp->exp);
			if(tmp->link != NULL) {
				printf("+");
			}else {
				break;
			}
		}
		tmp = tmp->link;
	}
	puts("\n");
}

int main() {
	puts("Poly 1 :\n");	
	HEAD1 = createPoly(HEAD1);

	puts("Poly 2 :\n");	
	HEAD2 = createPoly(HEAD2);

	puts("Poly 1 + Poly 2\n");
	HEAD3 = addPoly(HEAD1, HEAD2);	
	
	puts("Poly 1 :\n");
	display(HEAD1);

	puts("Poly 2 :\n");
	display(HEAD2);

	puts("Result Poly :\n");
	display(HEAD3);

	return 0;
}