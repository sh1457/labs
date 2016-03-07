#include <stdio.h>
#include <stdlib.h>

int sales(int l, int s, int b) {
	if(l<1 || l>70 || s<1 || s>80 || b<1 || b>90) {
		printf("ERROR : No. of parts is not in limits!\n");
//		exit(1);
	}
	return ( l*45 + s*30 + b*25 );
}

float comms(int s) {
	float c=0;

	while(s!=0) {
		if(s>1800) {
			c+=(s-1800) * 0.2;
			s=1800;
		}else if(s>1000) {
			c+=(s-1000) * 0.15;
			s=1000;
		}else {
			c+=s * 0.1;
			s=0;
		}
	}

	return c;
}

int main() {
	int lock, stock, barrel;
	int sale;
	float comm;

	//printf("Enter L, S, B : ");
	while(1) {
	scanf("%d %d %d", &lock, &stock, &barrel);

	sale = sales(lock, stock, barrel);
	comm = comms(sale);

	printf("Sales : %d\n\nCommissions : %.2f\n\n", sale, comm);
	}

	return 0;
}
