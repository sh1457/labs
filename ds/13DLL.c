#include <stdio.h>
#include <stdlib.h>

typedef struct ad{
	int info;
	struct ad *linkl;
	struct ad *linkr;
}NODE;

NODE *HEAD = NULL;

NODE *getNode() {
	return (NODE *) malloc(sizeof(NODE));
}

void add() {
	NODE *TMP = NULL;
	if((TMP = getNode()) == NULL) {
		printf("\nInsufficient Memory!\n");
	}else {
		printf("Enter an element : ");
		scanf("%d", &(TMP->info));
		if(HEAD == NULL) {
			HEAD = TMP;
		}else {
			TMP->linkr = HEAD;
			HEAD->linkl = TMP;
			HEAD = TMP;
		}
	}
}

void insert(int key) {
	NODE *TMP = HEAD;
	NODE *PREV = NULL;
	NODE *NEXT = NULL;
	int found = 0;
	
	if(HEAD == NULL) {
		printf("\nList is Empty!\n");
		return;
	}
	
	while(TMP != NULL) {
		if(TMP->info == key) {
			found = 1;
			break;
		}
		TMP = TMP->linkr;
	}
	
	if(found) {
		PREV = TMP->linkl;
		NEXT = TMP;
		if(PREV == NULL) {
			add();
			return;
		}
		if((TMP = getNode()) == NULL) {
			printf("\nInsufficient Memory!\n");
		}else {
			printf("Enter an element : ");
			scanf("%d", &(TMP->info));
		}
		PREV->linkr = TMP;
		NEXT->linkl = TMP;
		TMP->linkl = PREV;
		TMP->linkr = NEXT;
		printf("\nThe given value has been inserted into List!\n");
	}else {
		printf("\nThe given value is not in the List!\n");
	}
}

void del(int key) {
	NODE *TMP = HEAD;
	NODE *PREV = NULL;
	NODE *NEXT = NULL;
	int found = 0;
	
	if(HEAD == NULL) {
		printf("\nList is Empty!\n");
		return;
	}
	
	while(TMP != NULL) {
		if(TMP->info == key) {
			found = 1;
			break;
		}
		TMP = TMP->linkr;
	}
	
	if(found) {
		PREV = TMP->linkl;
		NEXT = TMP->linkr;
		if(PREV == NULL && NEXT == NULL) {
			HEAD = NULL;
		}else if(NEXT == NULL) {
			PREV->linkr = NULL;
		}else if(PREV == NULL) {
			HEAD = NEXT;
			NEXT->linkl = NULL;
		}else {
			PREV->linkr = NEXT;
			NEXT->linkl = PREV;
		}
		TMP->linkl = NULL;
		TMP->linkr = NULL;
		free(TMP);
		printf("\nThe given value has been deleted from the List!\n");
	}else {
		printf("\nThe given value is not in the List!\n");
	}
}

void display() {
	NODE *TMP = HEAD;
	while(TMP != NULL) {
		printf("%d <--> ", TMP->info);
		TMP = TMP->linkr;
	}
	printf("NULL");
}

int main() {
	int ch = 0, key = 0;
	
	while(1) {
		printf("\nEnter the choice of Operation,\n");
		printf("\n1) Add to Left\n2) Insert left to Key\n3) Delete a Key\n4) Display List\n5) Quit\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				add();
			break;
			case 2:
				printf("Enter Key : ");
				scanf("%d", &key);
				insert(key);
			break;
			case 3:
				printf("Enter Key : ");
				scanf("%d", &key);
				del(key);
			break;
			case 4:
				display();
			break;
			case 5:
				exit(0);
			break;
			default:
				printf("\nInvalid Input!\n");
			break;
		}
	}
	return 0;
}
