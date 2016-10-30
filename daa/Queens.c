#include <stdio.h>
#include <math.h>

#define SIZE 10

int isSafe(int pos[SIZE], int row, int col) {
    int i;
 
    for(i=0; i < row; i++) {
        if(pos[i] == col) {
            return 0;
        }
    }

    for(i=0; i < row; i++) {
	    if(abs(pos[i]-col) == abs(i-row) ) {
	    	return 0;
	    }
	} 

    return 1;
}

void nqueens(int n) {
	int pos[SIZE]={0}, flag;
	int i, j;

	for(i=0; i < n; i++) {
		for(j=0, flag=0; j < n; j++) { 
			if( isSafe(pos, i, j) ) {
				pos[i] = j;
				flag = 1;
				break;
			}
		}

		while(flag == 0) {
			if(i < 0){
				printf("No Solution\n");
				return;
			}

			if(pos[i-1] < n-1) {
				pos[i-1]++;
				flag = 1;
			}else {
				pos[i-1] = 0;
			}
			i--;
		}
	}

	for(i=0; i < n; i++) {
		printf("%d\t", pos[i]);
		for(j=0; j < n; j++) { 
			if(j == pos[i]) {
				printf("Q ");
			}else {
				printf("* ");
			}	
		}
		puts("");	
	}
}

int main() {
	int N;

	//printf("Enter N : ");
	scanf("%d", &N);

	nqueens(N);

	return 0;
}