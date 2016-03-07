#include <stdio.h>

#define SIZE 100
#define INF 99999

/* function to swap array elements */
void swap(int v[SIZE], int i, int j) {
	int t;

	t = v[i];
	v[i] = v[j];
	v[j] = t;
}

/* recursive function to generate permutations */
int brute_force(int c[SIZE][SIZE], int v[SIZE], int n, int s, int i) {
	// this function generates the permutations of the array from element i to element n-1
	int j, sum, k;
	static int optimum = INF;
	//if we are at the end of the array, we have one permutation
	if (i == n) {
		if(v[0] == s){
			for(j=0; j < n; j++)
				printf("%d ", v[j]);

			for(k=0, sum=0; k < n-1; k++)
				sum += c[v[k]][v[k+1]];

			sum += c[v[n-1]][s];
			
			printf("Sum = %d\n", sum);
			
			if(sum < optimum)
				optimum = sum;
		}
	}else {
		// recursively explore the permutations starting at index i going through index n-1*/
		for(j=i; j<n; j++) { /* try the array with i and j switched */
			swap(v, i, j);
			brute_force(c, v, n, s, i+1);
			/* swap them back the way they were */
			swap(v, i, j);
		}
	}
	return optimum;
}

int nearest_neighbour(int c[SIZE][SIZE], int n, int s) {
	int sum, min, p, vi[SIZE]={0}, from;
	int i, j;

	vi[s] = 1;
	from = s;

	for(j=1, sum=0; j < n; j++) {
		for(i=1, min=INF; i < n; i++) {
			if(vi[i] != 1 && c[from][i] < min && c[from][i] != 0 ) {
				min = c[from][i];
				p = i;
			}
		}
		vi[p] = 1;
		from = p;
		sum += min;
	}

	sum += c[from][s];

	return sum;
}

int main() {
	int C[SIZE][SIZE], N, V[SIZE], S;
	float opt, sum;
	int i,j;
	
	//printf("Enter N : ");
	scanf("%d",&N);
	
	for(i=0; i < N; i++)
		V[i] = i+1;
	
	//printf("Enter Cost matrix :\n");
	for(i=0; i < N; i++)
		for(j=1; j < N; j++)
			scanf("%d",&C[i][j]);
	
	//printf("Enter Source : ");
	scanf("%d",&S);
	
	opt = brute_force (C, V, N, S, 0);
	
	printf("Optimum solution with brute force technique is = %f\n", opt);
	
	sum = nearest_neighbour(C, N, S);
	
	printf("Solution with Nearest Neighbour technique is = %f\n", sum);
	printf("The error in approximation is = %f \%", ( (sum/opt)-1 )*100 );
	
	return 0;
}