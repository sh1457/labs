#include <stdio.h>
#include <math.h>
#include <sys/time.h>

#define SIZE 2000

int part(int *a, int l, int r) {
	int p=0, i=0, j=0;
	
	i = l;
	j = r;
	p = i;

	while(i < j) {
		while( (a[j] >= a[p]) && (j > l) ) {
			j--;
		}
		while( (a[i] <= a[p]) && (i < r) ) {
			i++;
		}
		if(i < j) {
			a[i] += a[j];
			a[j] = a[i]-a[j];
			a[i] = a[i]-a[j];
		}
	}
	if(p != j) {
		a[p] += a[j];
		a[j] = a[p]-a[j];
		a[p] = a[p]-a[j];
	}

	p = j;
	return p;
}

void quicksort(int *a, int l, int r) {
	int s = 0;

	if(r <= l) {
		return;
	}

	s = part(a, l, r);

	quicksort(a, l, s);
	quicksort(a, (s + 1), r);
}

int main() {
	double s=0, e=0;
	struct timeval t;

	//FILE *fp;
	//fp = fopen("Quick.time", "w");

	int a[SIZE];
	int L, R, N, i;

	//printf("Enter N : ");
	scanf("%d", &N);

	L=0;
	R=N-1;

	srand(time(NULL));
	for(i=0; i < N ; i++) {
		a[i] = rand() % 1000;
		//printf("%d\t", a[i]);
	}

	gettimeofday(&t, NULL);
	s = t.tv_sec + ( t.tv_usec / 1000000.0);

	quicksort(a, L, R);

	gettimeofday(&t, NULL);
	e = t.tv_sec + ( t.tv_usec / 1000000.0);

	printf("Quicksort took %fs for Input Size %d\n", (e - s), N);

	//fprintf(fp, "Quicksort took %fs for Input Size %d\n", (e - s), N);

	//fclose(fp);
	printf("The Sorted Array is\n");
	for(i=0; i < N ; i++)
		printf("%03d\t", a[i]);

	return 0;
}