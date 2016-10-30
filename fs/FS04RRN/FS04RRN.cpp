#include <iostream>
#include <fstream>
#include <cstring>

#define SIZE 20

using namespace std;

extern int menu(char o[][20], int m);

char buf[SIZE];

class Stud {
	private:
		char usn[4], name[10], marks[3];

		void pack();
		void unpack(); 
	public:
		void add();
		void direct_access();
};

void Stud::pack() {
	strcpy(buf, usn);
	strcat(buf, "|");
	strcat(buf, name);
	strcat(buf, "|");
	strcat(buf, marks);
	strcat(buf, "|");

	while(strlen(buf)<SIZE)
		strcat(buf, "#");
}

void Stud::unpack() {
	strcpy(usn, strtok(buf, "|"));
	strcpy(name, strtok(NULL, "|"));
	strcpy(marks, strtok(NULL, "|"));
}

void Stud::add() {
	ofstream ofile;

	cout<<"\nEnter details:\n\n";
	cout<<"USN >";
	cin>>usn;
	cout<<"Name >";
	cin>>name;
	cout<<"Marks >";
	cin>>marks;

	pack();

	ofile.open("03Stud.dat", ios::out|ios::app);

	ofile<<buf<<endl;

	ofile.close();
}

void Stud::direct_access() {
	ifstream ifile;
	int rrn, offset;

	ifile.open("03Stud.dat", ios::in);

	cout<<"RRN >";
	cin>>rrn;

	offset = rrn * (SIZE+1);

	ifile.seekg(offset, ios::beg);

	ifile.getline(buf, SIZE, '#');

	if(ifile.fail()) {
		cout<<"Error : Record Number exceeded limits of File!\n";
		ifile.close();
		return;
	}

	unpack();

	cout<<"USN : "<<usn<<"\tName : "<<name<<"\tMarks : "<<marks<<"\n\n";

	ifile.close();
}


int main() {
	Stud s;

        int ch;
        char k[4];
        char o[][20] = {"Add Record", "Direct Access", "Exit"};

        while(1) {
                switch(menu(o, 3)) {
                        case 1:
                                cout<<"\t\t>>ADD<<\n\n";
                                s.add();
                        break;
                        case 2:
                                cout<<"\t\t>>DIRECT ACCESS<<\n\n";
                                s.direct_access();
                        break;
                        default:
                                return 0;
                        break;
                }
        }

	return 0;
}
