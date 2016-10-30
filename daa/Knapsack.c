#include <stdio.h>
#define SIZE 100

int max(int, int);
int knapsack(int, int, int[], int[]);

int max(int a, int b) { 
    return (a > b)? a : b; 
}

int knapsack(int n, int w, int wt[SIZE], int val[SIZE]) {
   int i, j;
   int K[SIZE][SIZE], sol[SIZE]={0};

    for (i=0; i <= n; i++) {
        for (j=0; j <= w; j++) {
            if (i == 0 || j == 0) {
                K[i][j]=0;
            }else if(wt[i-1] <= j) {
                K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]], K[i-1][j]);
            }else {
                K[i][j] = K[i-1][j];
            }
        }
    }

    for(i=0; i <= n; i++) {
        for(j=0; j <= w; j++)
            printf("%d ", K[i][j]);
        puts("");    
    }

    for(i=n, j=w; i > 0 && j >= 0; i--) {
        if(K[i][j] > K[i-1][j]) {
            sol[i] = 1;
            j -= wt[i-1];
        }
    }

    for(i=1; i <= n; i++)
        printf("%d\t", sol[i]);
    puts("");

    return K[n][w];
}

int main() {
    int N, W, Val[SIZE]={0}, Wt[SIZE]={0};
    int i;
    int cap;

    scanf("%d", &N);
    scanf("%d", &W);

    for(i=0; i < N; i++)
        scanf("%d %d", &Val[i], &Wt[i]);

    cap = knapsack(N, W, Wt, Val); 

    printf("Max Capacity = %d\n", cap);

    return 0;
}