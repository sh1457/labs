#include <iostream>
#include <fstream>

using namespace std;

void rev(char *a) {
	int i=0, j=0, ind=0;
	char tmp;

	while(a[ind]!='\0')
		ind++;

	for(i = 0, j = ind - 1; i < j; i++, j--) {
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}

int main() {
	int ch;

	int n;
	char name[40];

	ifstream fin;
	ofstream fout;

	cout<<"Choose\n\t'1' for IO Redirection\n\t'2' for File IO\n\n>>> ";
	cin>>ch;

	switch(ch) {
		case 1:
			cout<<"Enter N : ";
			cin>>n;

			cout<<"Enter Names : \n";
			do {
				cin.getline(name, 40, '\n');
				rev(name);
				cout<<name<<endl;
			}while(n--);
		break;
		case 2:
			fin.open("fin1.txt", ios::in);
			fout.open("fout1.txt" , ios::out);

			do {
				fin.getline(name, 40, '\n');
				rev(name);
				fout<<name<<endl;
			}while(!fin.eof());

			fin.close();
			fout.close();
		break;
		default:
			cout<<"Incorrect Choice!!!\n";
		break;
	}

	return 0;
}
