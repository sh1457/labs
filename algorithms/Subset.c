#include <stdio.h>

#define SIZE 100

int getPrev(int x[SIZE], int c) {
	int i;

	for(i=c-1; i >= 0; i--)
		if(x[i] == 1) 
			break;

	return i;	
}

void subset(int s[SIZE], int n, int d) {
	int sum=0, prev, curr=0, sol[SIZE]={0}, x=0;
	int i;

    sum += s[0];

	while(curr < n) {
		prev = getPrev(sol, curr);
		sol[curr]=1;
		
		if(sum > d) {
			if(prev == -1)
				break;
			sum -= s[prev];
			sol[prev]=0; 
			continue;
		}else if(sum == d) {
			x++;
			printf("S%d = {", x);
			for(i=0; i < n; i++) {
				if(sol[i]) {
					if(i == curr){
						printf("%d", s[i]);
					}else{
						printf("%d, ", s[i]);
					}
				}
			}
			printf("}\n");
		}else {}
		
		curr++;
		sum += s[curr];
	}
	if(x == 0) {
		printf("No Possible Subset Found\n");
	}
}

int main() {
	int S[SIZE], N, D;
	int i;

	//printf("Enter N : ");
	scanf("%d", &N);

	//printf("Enter Set : ");
	for(i=0; i < N; i++)
		scanf("%d", &S[i]);

	//printf("Enter D : ");
	scanf("%d", &D);

	subset(S, N, D);

	return 0;
}