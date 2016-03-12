#include <stdio.h>

#define SIZE 10
#define NUM 10

int main() {
	int AVAIL[SIZE], ALLOC[NUM][SIZE], REQ[NUM][SIZE], FIN[NUM]={0};
	int N, M;
	int ca, ex;
	int i, j, k, l=0;

	scanf("%d %d", &N, &M);

	for(j=0; j<M; j++)
		scanf("%d", &AVAIL[j]);

	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
			scanf("%d", &ALLOC[i][j]);

	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
			scanf("%d", &REQ[i][j]);

	puts("\n\nAvailable Resources :");
	for(j=0; j<M; j++)
		printf("%d\t", AVAIL[j]);

	puts("\n\nAllocated Resources :");
	for(i=0; i<N; i++) {
		printf("\nP%d\t:\t", i);
		for(j=0; j<M; j++)
			printf("%d\t", ALLOC[i][j]);
	}

	puts("\n\nRequested Resources :");
	for(i=0; i<N; i++) {
		printf("\nP%d\t:\t", i);
		for(j=0; j<M; j++)
			printf("%d\t", REQ[i][j]);
	}

	puts("");

	k=1;
	while(k>0) {
		for(i=0, k=0; i<N; i++) {
			if(FIN[i]==0) {
				for(j=0, ex=1; j<M; j++) {
					if(ALLOC[i][j] + AVAIL[j] < REQ[i][j]) {
						ex=0;
						break;
					}
				}
				if(ex==1) {
					FIN[i] = ++l;
					k++;
					for(j=0; j<M; j++) {
						AVAIL[j] += ALLOC[i][j];
						ALLOC[i][j] = 0;
						REQ[i][j] = 0;
					}
				}
			}
		}
	}

	if(l == N) {
		puts("SAFE\n");
		printf("|");
		for(i=1; i<=N; i++)
			for(j=0; j<N; j++)
				if(FIN[j] == i)
					printf(" P%d |", j);
	}else {
		puts("UNSAFE\n");
	}

	puts("");

	return 0;
}
