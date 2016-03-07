#include <stdio.h>

#define SIZE 100

typedef struct {
	int at, bt, rt, wt;
}Proc;

int main() {
	int N, TQ, ch; 
	Proc p[SIZE];
	int i, j;

	printf("Simulation of Process Scheduling Algorithms\n\n");
	printf("1) Shortest Remaining Time\n");
	printf("2) Round Robin\n");
	printf(">>> ");
	scanf("%d", &ch);

	if(ch<1 || ch>2)
		exit(1);

	scanf("%d", &N);
	if(ch==2)
		scanf("%d", &TQ);

	for(i=0; i<N; i++) {
		if(ch==1) {
			scanf("%d %d", &p[i].at, &p[i].bt);
		}else {
			scanf("%d", &p[i].bt);
		}
		p[i].rt = p[i].bt;
		p[i].wt = 0;
	}

	ch==1?srt(N, TQ, p):rr(N, TQ, p);	

	return 0;
}

void srt(int N, int TQ, Proc p[SIZE]) {
	int i, j, cnt=0, sum, small, now=0, prv=-1;

	printf("|");
	
	do {
		for(i=0, sum=0, small=999; i<N; i++) {
			if(p[i].at <= cnt && p[i].rt != 0) {
				if(p[i].rt < small) {
					now = i;
					small = p[i].rt;
				}
				sum += p[i].rt;
			}
		}

		if(small==999) {
			cnt++;
			continue;
		}
		if(prv!=now)
			printf(" P%d |", now);

		cnt++;
		p[now].rt--;

		for(i=0; i<N; i++)
			if(i!=now && p[i].rt !=0)
				p[i].wt++;

		prv = now;

	}while(sum);

	puts("");

	sum = 0;
	for(i=0; i<N; i++) {
		printf("Turnaround for P%d : %d\n", i, (p[i].bt + p[i].wt));
		sum += (p[i].bt + p[i].wt);
	}

	printf("Average Turnaround Time = %.4f\n", ((float)sum/N));
}

void rr(int N, int TQ, Proc p[SIZE]) {
	int i, j, cnt=0, sum, buf=0;
	printf("|");

	do {
		for(i=0; i<N; i++) {
			if(p[i].rt > 0) {
				p[i].wt += cnt;
				if(p[i].rt >= TQ) {
					p[i].rt -= TQ;
					cnt += TQ;
				}else {
					buf += (TQ - p[i].rt);
					cnt += p[i].rt;
					p[i].rt = 0;
				}
				printf(" P%d |", i);
				if(p[i].rt)
					p[i].wt -= (cnt+buf);
			}
		}
		sum = 0;
		for(i=0; i<N; i++)
			sum += p[i].rt;

	}while(sum > 0);

	puts("");

	sum = 0;
	for(i=0; i<N; i++) {
		printf("Turnaround for P%d : %d\n", i, (p[i].bt + p[i].wt));
		sum += (p[i].bt + p[i].wt);
	}

	printf("Average Turnaround Time = %.4f\n", ((float)sum/N));
}
