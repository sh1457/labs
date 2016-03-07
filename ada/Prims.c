#include <stdio.h>
#include <math.h>

#define SIZE 10
#define INF 999

int prims(int c[SIZE][SIZE], int n) {
	int i, j;
	int vi[SIZE]={0}, count, min, a, b, min_cost = 0;

	vi[0] = 1;

	for(count=1; count < n; count++) {
		for(i=0, min=INF; i < n; i++) {
			if(vi[i]) {
				for(j=0; j < n; j++) {
					if( (c[i][j] < min) && (vi[j] != 1) ) {
						min = c[i][j];
						a = i;
						b = j;
					}
				}
			}	
		}

		if(vi[a] == 0 || vi[b] == 0) {
			min_cost += min;
			vi[b] = 1;
			printf("EDGE %d : %d --> %d\tCost = %d\n", count, (a+1), (b+1), min);
		}

		c[a][b] = c[b][a] = INF;
	}
	
	return min_cost;	
}

int main() {
	int i, j;
	int C[SIZE][SIZE], N;
	int cost;

	//printf("Enter N : ");
	scanf("%d", &N);

	//printf("Enter the Adjacency Matrix :\n");
	for(i=0; i < N; i++)
		for(j=0; j < N; j++) {
			scanf("%d", &C[i][j]);
			if(C[i][j] == 0)
				C[i][j] = INF;
			if(i == j)
				C[i][j] = 0;
		}

	cost = prims(C, N);
	
	printf("Min Cost = %d\n", cost);

	return 0;
}