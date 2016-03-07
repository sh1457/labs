#include <stdio.h>
#include <omp.h>

#define SIZE 100

int main() {
	int N;
	unsigned long long C[SIZE];
	int i;

	scanf("%d", &N);

	omp_set_num_threads(2);

	C[0] = 0;
	C[1] = 1;

	printf("%llu\n%llu\n", C[0], C[1]);

	#pragma omp parallel
	{
	#pragma omp single nowait
	{
		for(i=2; i<N; i++) {
			printf("Computation F[%d] (%d)\n", i, omp_get_thread_num());
			C[i] = C[i-2] + C[i-1];
		}
	}
	#pragma omp barrier
	#pragma omp single nowait
	{
		for(i=2; i<N; i++) {
			printf("Display F[%d] (%d)\n", i, omp_get_thread_num());
			printf("%llu\n", C[i]);
		}
	}

	}

	puts("");

	return 0;
}
