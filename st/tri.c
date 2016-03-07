#include <stdio.h>
#include <stdlib.h>

int tri(int a, int b, int c) {
//	int a, b, c;
	sleep(1/2);
//	printf("Enter 3 sides of a triangle : ");
//	scanf("%d %d %d", &a, &b, &c);

	if(a<1 || a>200 || b<1 || b>200 || c<1 || c>200) {
		printf("ERROR : Side cannot be less than 1!\n\n");
		return 1;
	}

	if( a+b<=c || b+c<=a || a+c<=b ) {
		printf("Not a triangle\n\n");
		return 0;
	}

	if(a==b && b==c)
		printf("EQUILATERAL\n\n");
	else if((a==b && b!=c) || (b==c && a!=b) || (a==c && b!=c))
		printf("ISOCELES\n\n");
	else
		printf("SCALENE\n\n");

	return 0;
}
