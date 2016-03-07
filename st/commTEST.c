#include <stdio.h>

int main() {
	int a, b, c;
	
	for(a=0; a<72; a++)
		for(b=0; b<82; b++)
			for(c=0; c<92; c++)
				printf("%d %d %d\n", a, b, c);

	return 0;
}
