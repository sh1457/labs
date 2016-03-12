#include <stdio.h>
#include <stdlib.h>

void printError(char *err) {
	printf("\n\nERROR : %s\n\n\n", err);
//	exit(1);
}

void getDate(int *d, int *m, int *y) {
	printf("Enter a Date [dd/mm/yyyy] : ");
	scanf("%d %d %d", d, m, y);
}

void checkDate(int d, int m, int y, int month[13]) {
	if(y < 1703 || y > 2016)
		printError("Date has invalid year.");
	if(m < 1 || m > 12)
		printError("Date has invalid month.");
	if(d < 1 || d > month[m])
		printError("Date has invalid date.");
}

int isLeapYear(int y) {
	return ((y % 100 == 0 && y % 400 == 0) || (y % 100 != 0 && y % 4 == 0));
}

void nextDate(int dd, int mm, int yyyy) {
//	int dd, mm, yyyy;	
	int months[13] = {-1, 30, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	getDate(&dd, &mm, &yyyy);
	months[2] = ( isLeapYear(yyyy) ) ? 29 : 28;
	checkDate(dd, mm, yyyy, months);

	if(mm == 12 && dd == months[mm]) {
		dd = mm = 1;
		yyyy++;
	}else if(dd == months[mm]) {
		dd = 1;
		mm++;
	}else
		dd++;

	checkDate(dd, mm, yyyy, months);

	printf("\nNext Date \t %d/%d/%d\n\n", dd, mm, yyyy);

//	return 0;
}
