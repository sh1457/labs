#include <stdio.h>
#include <math.h>
#include <sys/time.h>

#define SIZE 2000

void merge(int a[SIZE], int low, int mid, int high) {
	int i, j ,k;
	int c[SIZE];

	i = low;
	j = (mid + 1);
	k = i;

	while(i <= mid && j <= high) {
		if(a[i] < a[j]) {
			c[k++] = a[i];
			i++;
		}else {
			c[k++] = a[j];
			j++;
		}
	}

	while(i <= mid) {
		c[k++] = a[i];
		i++;
	}

	while(j <= high) {
		c[k++] = a[j];
		j++;
	}

	for(i=low; i <= high; i++)
		a[i] = c[i];
}

void mergesort(int a[SIZE], int low, int high) {
	int mid;

	if(low >= high) {
		return;
	}else {
		mid = (low + high) / 2;
		mergesort(a, low, mid);
		mergesort(a, (mid + 1), high);
		merge(a, low, mid, high);
	}
}

int main() {
	double s=0, e=0;
	struct timeval t;

	int A[SIZE], LO, HI, N; 
	int i;

	//FILE *fp;
	//fp = fopen("Merge.time", "a");

	//printf("Enter N : ");
	scanf("%d", &N);

	LO=0;
	HI=N-1;

	srand(time(NULL));
	for(i=0; i < N; i++)
		A[i] = rand() % 1000;
	//	printf("%d\n", a[i]);

	gettimeofday(&t, NULL);
	s = t.tv_sec + ( t.tv_usec / 1000000.0);

	mergesort(A, LO, HI);

	gettimeofday(&t, NULL);
	e = t.tv_sec + ( t.tv_usec / 1000000.0);

	printf("Mergesort took %fs for Input Size %d\n",(e - s), N);

	//fprintf(fp, "Mergesort took %fs for Input Size %d\n",(e - s), N);

	//fclose(fp);
	//printf("The Sorted Array is, \n\n");
	//for(i=0; i < N; i++)
	//	printf("%d\n", A[i]);

	return 0;
}
