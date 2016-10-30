#include<stdio.h>
#include<stdlib.h>

#define SIZE 3

typedef struct {
	int queue[SIZE];
	int HEAD, TAIL;
}QUEUE;

QUEUE q;

void insert(int x) {
	if(q.HEAD == -1) {
		q.HEAD++;
	}
	if(q.TAIL == (SIZE - 1)) {
		fprintf(stderr, "\nQUEUE is FULL!\n");
		exit(1);
	}
	q.queue[++(q.TAIL)] = x;
}

int delete() {
	int x = -999; //Sentinel Value
	if(q.HEAD == -1) {
		fprintf(stderr, "\nQUEUE is EMPTY!\n");
		exit(1);
	}
	x = q.queue[(q.HEAD)++];
	if(q.HEAD > q.TAIL) {
		q.HEAD = -1;
		q.TAIL = -1;
	}
	return x;
}

int main() {
	int i;
	int ch;
	q.HEAD = -1;
	q.TAIL = -1;
	while(1) {
		puts("\n\nEnter your Choice :\n");
		puts("1)\tTo Insert an Element to the QUEUE");
		puts("2)\tTo Delete an Element from the QUEUE");
		puts("3)\tTo Print the QUEUE");
		puts("*)\tTo Quit\n");
		printf("-->");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				printf("Enter Element to be inserted : ");
				scanf("%d", &ch);
//printf("DEBUG : B4\n\tHEAD = %d\n\tTAIL = %d\n", q.HEAD, q.TAIL);
				insert(ch);
//printf("DEBUG : After\n\tHEAD = %d\n\tTAIL = %d\n", q.HEAD, q.TAIL);
			break;
			case 2:
//printf("DEBUG : B4\n\tHEAD = %d\n\tTAIL = %d\n", q.HEAD, q.TAIL);
				ch = delete();
//printf("DEBUG : After\n\tHEAD = %d\n\tTAIL = %d\n", q.HEAD, q.TAIL);
				printf("Element '%d' was deleted.", ch);
			break;
			case 3:
				printf("Queue:");
				if(q.HEAD != -1) {
					for(i = q.HEAD; i <= q.TAIL; i++) {
						printf("\t%d", q.queue[i]);
					}
				}
				puts("\n");
			break;
			default:
				exit(0);
			break;
			
		}
	}
	return 0;
}
