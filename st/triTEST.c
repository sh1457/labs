#include <stdio.h>

extern int tri(int a, int b, int c);

void best() {
        int i, j, k;
        int VALUES[]= {1, 2, 100, 199, 200};
	int LEN = 5;
	
        for(i=j=LEN/2, k=0; k<LEN; k++) {
                printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
                tri(VALUES[i], VALUES[j], VALUES[k]);
        }
	for(i=k=LEN/2, j=0; j<LEN; j++) {
                printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
                tri(VALUES[i], VALUES[j], VALUES[k]);
        }
	for(j=k=LEN/2, i=0; i<LEN; i++) {
        	printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
                tri(VALUES[i], VALUES[j], VALUES[k]);
        }
}


void worst() {
	int i, j, k;
	int VALUES[]= {1, 2, 100, 199, 200};
	int LEN = 5;

	for(i=0; i<LEN; i++) {
		for(j=0; j<LEN; j++) {
			for(k=0; k<LEN; k++) {
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

	for(i=j=LEN/2, k=0; k<LEN; k++) {
                printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
                tri(VALUES[i], VALUES[j], VALUES[k]);
        }
        for(i=k=LEN/2, j=0; j<LEN; j++) {
                printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
                tri(VALUES[i], VALUES[j], VALUES[k]);
        }
        for(j=k=LEN/2, i=0; i<LEN; i++) {
                printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
                tri(VALUES[i], VALUES[j], VALUES[k]);
        }
}

void worst_robust() {
        int i, j, k;
        int VALUES[] = {-1, 1, 2, 100, 199, 200, 201};
        int LEN = 7;

        for(i=0; i<LEN; i++) {
                for(j=0; j<LEN; j++) {
                        for(k=0; k<LEN; k++) {
                                printf("%d %d %d :\t", VALUES[i], VALUES[j], VALUES[k]);
                                tri(VALUES[i], VALUES[j], VALUES[k]);
                        }
                }
        }
}


int main() {
	int ch;

	while(1) {
		printf("Triangle Problem TESTER\n\n");
		printf("\tEnter 1 for Best Case BVA (Single Fault)\n");
		printf("\tEnter 2 for Robust BVA (Single Fault)\n");
		printf("\tEnter 3 for Worst Case BVA (Multi Fault)\n");
		printf("\tEnter 4 for Worst Case Robust BVA (Multi Fault)\n");
		printf("0 to Exit\n\n");
		printf("-->");
		scanf("%d", &ch);

		switch(ch) {
			case 1:
				printf("BEST CASE BVA (Single Fault)\n\n");
				best();	
			break;
			case 2:
				printf("ROBUST BVA (Single Fault)\n\n");
				robust();
			break;
			case 3:
				printf("WORST CASE BVA (Multi Fault)\n\n");
				worst();
			break;
			case 4:
				printf("WORST CASE ROBUST BVA (Multi Fault)\n\n");
				worst_robust();
			break;
			default:
				return 0;
			break;
		}
	}
}
