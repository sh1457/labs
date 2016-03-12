#include <stdio.h>
#include <math.h>

#define SIZE 20

void warshall(int a[SIZE][SIZE], int n) {
	int i, j, k;

	for(k=0; k < n; k++) 
		for(i=0; i < n; i++) 
			for(j=0; j < n; j++) 
				a[i][j] = ( a[i][j] || ( a[i][k] && a[k][j] ) );
}

int main() {
	int n;
	int i, j;
	int a[SIZE][SIZE];

	//printf("Enter n : ");
	scanf("%d", &n);

	//printf("Enter Cost Matrix :\n");
	for(i=0; i < n; i++) {
		for(j=0; j < n; j++) {
			scanf("%d", &a[i][j]);
			printf("%d ", a[i][j]);
		}
		puts("");
	}
	puts("");

	warshall(a, n);

	for(i=0; i < n; i++) {
		for(j=0; j < n; j++) 
			printf("%d ", a[i][j]);
		puts("");
	}

	return 0;
}