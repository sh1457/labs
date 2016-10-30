#include <stdio.h>
#define R 2
#define C 2

typedef struct Lists {
	int rowData;
	int colData;
	int elmData;
}List;

List a[R*C/2];

void disp();

void main() {
	int M = 0, N = 0;
	int i = 0, j = 0, k = 0;
	int data[R][C], key = 0;

	printf("Enter number of Rows and Cols: ");
	scanf("%d %d", &M, &N);

	for(i = 0; i < M; i++) {
		printf("Row %d\n",(i+1));
		for(j = 0; j < N; j++) {
			printf("\tCol %d\n",(j+1));
			scanf("%d",&data[i][j]);
		}
	}
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			if(data[i][j] != 0) {
				a[k].rowData = i;
				a[k].colData = j;
				a[k].elmData = data[i][j];
				k++;
			}
		}
	}
	for(i = 0; i < k; i++) {
		disp(a[i]);
	}
	printf("Enter a value to be searched : ");
	scanf("%d",&key);
	for(i = 0 ; i < k; i++) {
		if(key == a[i].elmData) {
			printf("\nKey Found at Row %d Col %d\n",(a[i].rowData+1), (a[i].colData+1));
		}else {
			printf("\nKey not Found!\n");
		}
	}
}

void disp(List d) {
	printf("Row : %d\n", (d.rowData + 1));
	printf("Col : %d\n", (d.colData + 1));
	printf("Value : %d\n\n", (d.elmData + 1));
}
