#include <stdio.h>

#define SIZE 12

int top = -1, stack[SIZE] = {0};

int pop() {
	int x = stack[top--];
	return x; 
}

void push(int x) {
	stack[++top] = x;
}

void DFS(int d[SIZE][SIZE], int n) {
	int vi[SIZE]={0}, curr;
	int i;

	push(0);
	vi[0]=1;

	while(top != -1) {
		curr = pop();

		for(i=0; i < n; i++)
			if(d[curr][i] == 1 && vi[i] != 1) {
				push(i);
				vi[i]=1;
			}	
	}

	for(i=0; i < n; i++)
		if(vi[i] == 0) {
			printf("Graph is Disconnected\n");
			return;
		}

	printf("Graph is Connected\n");	
}

int main() {
	int D[SIZE][SIZE], N;
	int i, j;

	//printf("Enter N : ");
	scanf("%d", &N);
	
	//printf("Enter Adjacency Matrix :\n");
	for(i=0; i < N; i++) 
		for(j=0; j < N; j++) 
			scanf("%d", &D[i][j]);

	DFS(D, N);

	return 0;
}