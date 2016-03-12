#include <stdio.h>

#define SIZE 12

int head = -1, tail = -1, queue[SIZE] = {0}, sol[SIZE+1] = {0};

int delete() {
	int x = queue[head++];
	
	if(head > tail) {
		head = -1;
		tail = -1;
	}

	sol[x + 1] = 1;
	
	return x; 
}

void insert(int x) {
	if(head == -1)
		++head;
	
	queue[++tail] = x;
}

void BFS(int d[SIZE][SIZE], int n, int start) {
	int vi[SIZE]={0}, curr;
	int j;

	insert(start);
	vi[start]=1;

	while(head != -1 && tail != -1) {
		curr = delete(); 
		for(j=0; j < n; j++) 
			if(d[curr][j] && vi[j] != 1) {
				insert(j);
				vi[j] = 1;
			}		
	}

}

int main() {
	int D[SIZE][SIZE], N, S;
	int i, j;

	//printf("Enter N : ");
	scanf("%d", &N);

	for(i=0; i < N; i++) 
		for(j=0; j < N; j++) 
			scanf("%d", &D[i][j]);

	//printf("Enter Starting Node : ");
	scanf("%d", &S);

	BFS(D, N, S);

	for(i=1; i <= N; i++) 
		if(sol[i]) {
			printf("%d is Reachable\n", i);
		}else {
			printf("%d is Not Reachable\n", i);
		}

	return 0;
}