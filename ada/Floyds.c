#include <stdio.h>
#include <omp.h>
#include <sys/time.h>

#define SIZE 20
#define INF 999

void floyds(int n, int c[SIZE][SIZE], int p[SIZE][SIZE]) {
	int i,j,k;

	for(k=0; k < n; k++) {
		for(i=0; i < n; i++) {
			for(j=0; j < n; j++) {
				if(c[i][j] > (c[i][k] + c[k][j]) ) {	
					c[i][j] = c[i][k] + c[k][j];
					p[i][j] = k;
				}else {
                    	p[i][j] = 0;
                }
			}
		}
	}
}

void floyds_para(int n, int d[SIZE][SIZE], int p[SIZE][SIZE]) {
	int i,j,k;

    for(k=0; k < n; k++) {
        for(i=0; i < n; i++) {
            for(j=0; j < n; j++) {     
            // Parallelize the algorithm using OpenMP
                #pragma omp parallel shared(d,i,j,k) 
                {
                    if( d[i][j] > ( d[i][k] + d[k][j] ) )
                        #pragma omp sections nowait 
                    {
                        d[i][j] = d[i][k] + d[k][j];
                        p[i][j] = k;
                    }else {
                    	p[i][j] = 0;
                    }
                }
            }
        }
    }
}

int main() {
	int N, C[SIZE][SIZE], D[SIZE][SIZE], P[SIZE][SIZE];
	double start, end;
	struct timeval t;

	int i, j;

	int iCPU = omp_get_num_procs();
    omp_set_num_threads(iCPU);

	//printf("Enter n : ");
	scanf("%d", &N);

	//printf("Enter distance matrix :\n");
	for(i=0; i < N; i++) {
		for(j=0; j < N; j++) {
			scanf("%d", &C[i][j]);
			D[i][j]=C[i][j];
			if(C[i][j] == 0) {
				C[i][j]=INF;
				D[i][j]=INF;
			}
			if(i == j) {
				C[i][j]=0;
				D[i][j]=0;
			}
		}
	}

	gettimeofday(&t, NULL);
	start = t.tv_sec + ( t.tv_usec / 1000000.0);

	floyds(N, C, P);

	gettimeofday(&t, NULL);
	end = t.tv_sec + ( t.tv_usec / 1000000.0);

	for(i=0; i < N; i++) {
		for(j=0; j < N; j++) {
			printf("\nPath from %d --> %d  =  %d\t", (i+1), (j+1), D[i][j]);
			if(P[i][j] != 0) {
				printf(" via %d.", (P[i][j] + 1));
			}
		}
		puts("");
	}

	puts("");

	for(i=0; i < N; i++) {
		for(j=0; j < N; j++) {
			printf("%d\t", D[i][j]);
		}
		puts("");
	}
	puts("");

	printf("Floyd's algorithm took %fs to run sequentially\n", (end-start));

	gettimeofday(&t, NULL);
	start = t.tv_sec + ( t.tv_usec / 1000000.0);

	floyds_para(N, C, P);

	gettimeofday(&t, NULL);
	end = t.tv_sec + ( t.tv_usec / 1000000.0);

	for(i=0; i < N; i++) {
		for(j=0; j < N; j++) {
			printf("\nPath from %d --> %d  =  %d\t", (i+1), (j+1), D[i][j]);
			if(P[i][j] != 0) {
				printf(" via %d.", (P[i][j] + 1));
			}
		}
		puts("");
	}

	puts("");

	for(i=0; i < N; i++) {
		for(j=0; j < N; j++) {
			printf("%d\t", D[i][j]);
		}
		puts("");
	}
	puts("");

	printf("Floyd's algorithm took %fs to run in parallel\n", (end-start));

	return 0;
}
