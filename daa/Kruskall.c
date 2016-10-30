#include <stdio.h>
#include <math.h>

#define SIZE 10
#define INF 999

int parent[SIZE]={0};

int find(int i) {
	while(parent[i])
		i = parent[i];
	return i;
}

int uni(int i, int j) {
	if(i != j) {
		parent[j] = i;
		return 1;
	}
	return 0;
}

int kruskall(int c[SIZE][SIZE], int n) {
	int i, j, k;
	int min, a, b, u, v, min_cost = 0;

	for(i=0; i < n-1; i++) {
		for(j=0, min = INF; j < n; j++)
			for(k=0; k < n; k++) {
				if(c[j][k] < min) {
					a = j;
					u = j;
					b = k;
					v = k;
					min = c[j][k];
				}
			}	

		u = find(u);
		v = find(v);
		
		if(uni(u, v)) {
			printf("EDGE (%d, %d)\tCost = %d\n", (a + 1), (b + 1), c[a][b]);
			min_cost += c[a][b];
		}

		c[a][b] = c[b][a] = INF;
	}

	return min_cost;	
}

int main() {
	int i, j;
	int C[SIZE][SIZE], N, cost=0;
	
	//printf("Enter n : ");
	scanf("%d", &N);

	//printf("Enter the Adjacency Matrix :\n");
	for(i=0; i < N; i++)
		for(j=0; j < N; j++) {
			scanf("%d", &C[i][j]);

			if(C[i][j] == 0)
				C[i][j]=INF;
			if(i == j)
				C[i][j]=INF;
		}

	cost = kruskall(C, N);
	
	printf("Min Cost = %d\n", cost);

	return 0;
}