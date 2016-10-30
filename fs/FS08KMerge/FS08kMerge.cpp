#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

#define N 8

using namespace std;

void kmerge() {
	char filename[20];
	ifstream file[N];
	int isEOF[N] = {0};
	int begin=0, chosen;
	char buf[N][30], cstr[30];
	int i, sum;

	for (i=1; i<=N; i++) {
		sprintf(filename, "merge%d.txt", i);
		file[i-1].open(filename, ios::in);
	}
	while (1) {
		sum = 0;
		for (i=0; i<N; i++) {
			sum += isEOF[i];
			if (isEOF[i]) {
				continue;
			}
			if (begin == 0) {
				file[i]>>buf[i];
	                        if (file[i].fail() || file[i].eof()) {
                                	isEOF[i] = 1;
                                	break;
                        	}
				chosen = 0;
			}
			if (begin == 1 && i != chosen && strcmp(buf[chosen], buf[i]) > 0) {
				chosen = i;
			}
		}
		if (sum == N) {
			break;
		}
		if (begin == 0) {
			begin = 1;
			continue;
		}
		strcpy(cstr, buf[chosen]);
		if (strcmp(cstr, buf[chosen]) != 0)
			cout<<buf[chosen]<<endl;
		file[chosen]>>buf[chosen];
                if (file[chosen].fail() || file[chosen].eof()) {
                	isEOF[chosen] = 1;
			for (i=0; i<N; i++) {
				if(isEOF[i]==0) {
					chosen = i;
					break;
				}
			}
                }
	}
  	for (i=0; i<N; i++) {
                file[i].close();
        }
}

int main() {
	kmerge();
	return 0; 
}

