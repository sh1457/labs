#include <stdio.h>

#define SIZE 10
#define INF 999

void dijkistra(int c[SIZE][SIZE], int n, int src) {
	int i,a;
	int vi[SIZE]={0}, di[SIZE]={0}, min=0, count=1; 
		
	for(i=0; i < n; i++) {
		vi[i] = 0;
		di[i] = c[src][i];
	}

	vi[src]=1; 

	while(count < n) {
		min = INF;
		for(i=0; i < n; i++) {
			if(di[i] < min && vi[i] != 1) {
				min = di[i];
				a = i;
			}
		}

		vi[a] = 1;
		count++;
	
		for(i=0; i < n; i++) {
			min = di[i];
			if(di[a] + c[a][i] < min && vi[i] != 1)
				di[i] = di[a] + c[a][i];
		}
	}

	for(i = 0; i < n; i++)
		printf("Cost of ( %d, %d ) = %d\n", (src + 1), (i + 1), di[i]);
}

int main() {
	int i, j;
	int C[SIZE][SIZE], N, S;

	//printf("Enter n : ");
	scanf("%d", &N);

	for(i=0; i < N; i++) 
		for(j=0; j < N; j++) {
			scanf("%d", &C[i][j]);

			if(C[i][j] == 0)
				C[i][j]=INF;
			if(i == j)
				C[i][j]=0;
		}


	//printf("Enter Source Vertex : ");
	scanf("%d", &S);

	dijkistra(C, N, S);

	return 0;
}