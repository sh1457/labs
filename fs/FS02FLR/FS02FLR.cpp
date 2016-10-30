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
		void display();
		int search();
		void modify();
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

	ofile.open("02Stud.dat", ios::out|ios::app);

	ofile<<buf<<endl;

	ofile.close();
}

void Stud::display() {
	ifstream ifile;
	int i=0;

	ifile.open("02Stud.dat", ios::in);

	while(!ifile.eof()) {
		ifile>>buf;

		if(ifile.fail())
			break;

		i++;
		unpack();

		cout<<"USN : "<<usn<<"\tName : "<<name<<"\tMarks : "<<marks<<"\n\n";
	}

	cout<<i<<" records displayed.\n\n";

	ifile.close();
}

int Stud::search() {
	ifstream ifile;
	int i=0;
	char key[4];

	ifile.open("02Stud.dat", ios::in);

	cout<<"Enter USN to search > ";			
	cin>>key;

	while(!ifile.eof()) {
		ifile>>buf;

		if(ifile.fail())
			break;

		i++;

		unpack();

		if(strcmp(key, usn)==0) {
			cout<<"USN : "<<usn<<"\tName : "<<name<<"\tMarks : "<<marks<<"\n\n";
			ifile.close();			
			return i;
		}
	}

	ifile.close();

	return -1;
}	


void Stud::modify() {
	fstream file;
	char key[4];
	char tmp[21];

	cout<<"Enter USN to search > ";			
	cin>>key;

	file.open("02Stud.dat", ios::in|ios::out);

	while(!file.eof()) {
                file>>buf;

                if(file.fail())
                        break;

                unpack();

                if(strcmp(key, usn)==0) {
                        cout<<"USN : "<<usn<<"\tName : "<<name<<"\tMarks : "<<marks<<"\n\n";

			cout<<"Enter new USN : ";
			cin>>tmp;
			if(strlen(tmp)!=0)
				strcpy(usn, tmp);

			cout<<"Enter new Name : ";
			cin>>tmp;
			if(strlen(tmp)!=0)
				strcpy(name, tmp);

			cout<<"Enter new Marks : ";
			cin>>tmp;
			if(strlen(tmp)!=0)
				strcpy(marks, tmp);

			pack();

			file.seekp((int) file.tellg() - SIZE, ios::beg);

			if(!file.eof() && !file.fail())
				file<<buf;
                }
        }
	file.close();
}


int main() {
	Stud s;

	int ch;
	char k[4];
	char o[][20] = {"Add Record", "Display All", "Search for a Record", "Modify a Record", "Exit"};
		
	while(1) {
		switch(menu(o, 5)) {
			case 1:
				cout<<"\t\t>>ADD<<\n\n";
				s.add();
			break;
			case 2:
				cout<<"\t\t>>DISPLAY<<\n\n";
				s.display();
			break;
			case 3:
				cout<<"\t\t>>SEARCH<<\n\n";				
				( (ch=s.search()) == -1) ? cout<<"Record not found!\n\n": cout<<"Record Found at Line "<<ch<<"!\n\n";
			break;
			case 4:
				s.modify();
			break;
			default:
				return 0;
			break;
		}
	}
}
