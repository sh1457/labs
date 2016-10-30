#include <iostream>
#include <fstream>
#include <cstring>

#define MAX 20
#define SIZE 20

using namespace std;

int main() {
	char list1[MAX][SIZE];
	char list2[MAX][SIZE];
	char buf1[SIZE];
	char buf2[SIZE];
	ifstream file1, file2;
	ofstream file3;
	int scv, mat=0;
	int next1=1, next2=1;

	file1.open("07List1.dat", ios::in);
	file2.open("07List2.dat", ios::in);
	file3.open("07ListComm.dat", ios::out);

	if(file1.fail() || file2.fail())
		printf("Error : File is empty.\n");

	while(!file1.eof() || !file2.eof()) {
		if(next1) {
			file1>>buf1;
			if(file1.fail())
				break;
		}

		if(next2) {
			file2>>buf2;	
			if(file2.fail())
				break;
		}


		if((scv = strcmp(buf1, buf2)) == 0) {
			file3<<buf1<<endl;
			next1=1;
			next2=1;
			mat++;
		}else if(scv < 0) {
			next1=1;
			next2=0;
		}else {
			next1=0;
			next2=1;
		}
		//DEBUG
		//printf("\n\t\t%s\t\t%s\t\t%d\n\n", buf1, buf2, scv);
	}

	file1.close();
	file2.close();
	file3.close();

	if(!mat)
		printf("No matching names.\n");

	return 0;
}
