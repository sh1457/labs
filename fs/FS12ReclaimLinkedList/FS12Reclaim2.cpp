#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

#define SIZE 37

using namespace std;

class Record {
	private:
		char buf[SIZE];
		char usn[11], name[21], marks[4];

		void pack() {
			strcpy(buf, usn);
			strcat(buf, "|");
			strcat(buf, name);
			strcat(buf, "|");
			strcat(buf, marks);
			strcat(buf, "|");
			while (strlen(buf) < SIZE-1) {
				strcat(buf, "*");
			}
		}

		void unpack() {
			strcpy(usn, strtok(buf, "|"));
			strcpy(name, strtok(NULL, "|"));
			strcpy(marks, strtok(NULL, "|"));
		}
	public:
		int add();
		void disp();
		int del();
};

void Record::disp() {
	int i, j, head;
	char num[SIZE];
`	ifstream fin;

	cout<<"\tDISP\n\n";

	fin.open("rec.dat", ios::in);

	while (!fin.eof()) {
		fin>>buf;

		if (fin.fail())
			break;

		switch (buf[0]) {
			case '#':
				for (i=1, j=0; i<SIZE; i++) {
					if (buf[i] != '#')
						num[j++] = buf[i];
					else
						break;
				}
				num[j] = '\0';
				head = atoi(num);
#ifdef DEBUG
	cout<<"\nNUM = "<<num<<"\nHEAD = "<<head<<endl;
#endif
				continue;
			break;
			case '?':
#ifdef DEBUG
	cout<<buf<<endl;
#endif
				continue;
			break;
			default:
				unpack();

				cout<<"\nUSN> "<<usn<<"\tName> "<<name<<"\tMarks> "<<marks<<endl;
			break;
		}
	}
	fin.close();
}

int Record::add() {
	int i, j, head, tmp, offset;
	char num[SIZE];
	fstream file;

	cout<<"\tADD\n\n";

	file.open("rec.dat", ios::in|ios::out);

	file>>buf;

	if (!file.fail()) {
		if (file.eof()) {
			head = -1;
			strcpy(num, "-1");

			buf[0] = '#';
			for (i=1, j=0; i<SIZE-1; i++) {
				if(j < strlen(NUM))
					buf[i] = num[j++];
				else
					buf[i] = '#';
			}

			file.seekp(0, ios::beg);

			file<<buf<<endl;;
		}else {
			for (i=1, j=0; i<SIZE; i++) {
                        	if (buf[i] != '#')
                                	num[j++] = buf[i];
                                else
                                        break;
                      	}
			num[j] = '\0';
                        head = atoi(num);
#ifdef DEBUG
        cout<<"\nNUM = "<<num<<"\nHEAD = "<<head<<endl;
#endif

		}
	}else {

	}
	
}

int Record::del() {

}

int menu() {
                        int choice;

                        cout<<"PRG 12 - Reclaim Space using Linked List\n";
                        cout<<"________________________________________\n\n";
                        cout<<"Press\n";
                        cout<<"\t1) Add Record\n";
                        cout<<"\t2) Display Record\n";
                        cout<<"\t3) Delete Record\n";
                        cout<<"\t4) Exit\n\n";
                        cout<<"--> ";
                        cin>>choice;

                        switch (choice) {
                                case 1:
                                        add();
                                break;
                                case 2:
                                        disp();
                                break;
                                case 3:
                                        del();
                                break;
                                case 4:
                                        return 0;
                                break;
                        }
                        return 1;
}

int main() {
	Record r;
	for (;;)
        	if (!s.menu())
                        break;
	return 0;
}
