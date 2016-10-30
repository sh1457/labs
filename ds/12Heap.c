#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 15

void swap(int);
void display();

int arr[SIZE];

void init() {
	int i = 0;

	for(i = 0; i < SIZE; i++) {
		arr[i] = -1;
	}
}

void insert() {
	int i = 0, num = 0;
	while(arr[i] != -1) {
		i++;
	}

	printf("Enter an element to be inserted : ");
	scanf("%d", &num);

	arr[i] = num;

	swap(i);
}

void swap(int i) {
	int j = 0;
	static int z = 0;
	while(i > 0) {
		j = i;
		i = floor(i/2);
		if(arr[j] > arr[i]) {
			arr[j] = arr[j] + arr[i];
			arr[i] = arr[j] - arr[i];
			arr[j] = arr[j] - arr[i];
		}
	}
	if (z == 1) {
		return;
	}else {
		z = 1;
	}
	if(i % 2 == 0) {
		swap(i + 1);
	}else {
		swap(i - 1);
	}
}

void display() {
	int i = 0, j = 0, k = 0, l = 0;
	for(i = 0; i < 4; i++) {
		for(k = 4 - i; k > 0; k--) {
				printf("   ");
		}
		printf("|");
		for(j = pow(2, i) - 1; j < pow(2, i+1) - 1; j++) {
			if(arr[j] != -1) {
				printf("%d", arr[j]);
				if(j % 2) {
					printf("    ");
				}else {
					printf("|");
				}
			}
		}
	printf("\n");
	}
}

int main() {
	int n = 0;
	init();
	printf("Enter number of elements in the Heap : ");
	scanf("%d", &n);
	while(n > 0) {
		insert();
		n--;
	}
	display();
	return 0;
}
