#include <stdio.h>

extern int tri(int a, int b, int c);

void best() {
        int i, j, k;
        int VALUES[]= {1, 2, 100, 199, 200};
	int LEN = 5;
	
        for(i=j=LEN/2, k=0; k<=LEN; k++) {
                printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
                tri(VALUES[i], VALUES[j], VALUES[k]);
        }
	for(i=k=LEN/2, j=0; j<=LEN; j++) {
                printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
                tri(VALUES[i], VALUES[j], VALUES[k]);
        }
	for(j=k=LEN/2, i=0; i<=LEN; i++) {
        	printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
                tri(VALUES[i], VALUES[j], VALUES[k]);
        }
}


void worst() {
	int i, j, k;
	int VALUES[]= {1, 2, 100, 199, 200};
	int LEN = 5;

	for(i=0; i<=LEN; i++) {
		for(j=0; j<=LEN; j++) {
			for(k=0; k<=LEN; k++) {
				printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
				tri(VALUES[i], VALUES[j], VALUES[k]);
			}
		}
	}
}

void robust() {
        int i, j, k;
        int VALUES[] = {-1, 1, 2, 100, 199, 200, 201};
	int LEN = 7;

	for(i=j=LEN/2, k=0; k<=LEN; k++) {
                printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
                tri(VALUES[i], VALUES[j], VALUES[k]);
        }
        for(i=k=LEN/2, j=0; j<=LEN; j++) {
                printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
                tri(VALUES[i], VALUES[j], VALUES[k]);
        }
        for(j=k=LEN/2, i=0; i<=LEN; i++) {
                printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
                tri(VALUES[i], VALUES[j], VALUES[k]);
        }
}

void worst_robust() {
        int i, j, k;
        int VALUES[] = {-1, 1, 2, 100, 199, 200, 201};
        int LEN = 7;

        for(i=0; i<=LEN; i++) {
                for(j=0; j<=LEN; j++) {
                        for(k=0; k<=LEN; k++) {
                                printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
                                tri(VALUES[i], VALUES[j], VALUES[k]);
                        }
                }
        }
}


int main() {
	printf("BEST CASE BVA (Single Fault)\n\n");
	best();	

	printf("ROBUST BVA (Single Fault)\n\n");
	robust();

	printf("WORST CASE BVA (Multi Fault)\n\n");
	worst();

	printf("WORST CASE ROBUST BVA (Multi Fault)\n\n");
	worst_robust();

	return 0;
}
