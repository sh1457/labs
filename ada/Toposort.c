#include <stdio.h>
#include <math.h>

#define SIZE 20

void topo(int a[SIZE][SIZE], int n) {
	int in[SIZE], out[SIZE], stack[SIZE];
	int TOS = -1;
	int i, j, k = 0;

	for(j=0; j < n; j++) 
		for(i=0, in[j]=0; i < n; i++)
			if(a[i][j] != 0)
				in[j]++;

	TOS = -1;
	while(1) {
		for(i=0; i < n; i++)
			if(in[i] == 0) {
				stack[++TOS] = i;
				in[i] = -1;
			}
		if(TOS == -1) {
			for(i=0; i < k; i++)
				printf("%d\t", (out[i] + 1));
			return;
		}
		while(TOS != -1) {
			out[k] = stack[TOS--];

			for(i=0; i < n; i++) 
				if(a[out[k]][i] != 0) 
					in[i]--;
			k++;
		}
	}
}

int main() {
	int A[SIZE][SIZE], N;
	int i, j;

	//printf("Enter n : ");
	scanf("%d", &N);

	//printf("Enter Cost Matrix :\n");
	for(i=0; i < N; i++) 
		for(j=0; j < N; j++) 
			scanf("%d", &A[i][j]);

	topo(A, N);

	return 0;
}