#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define SIZE 35

class Student {
	private:
		char usn[11], name[21], marks[4], buf[SIZE];
		char temp[5];
		int head, tmp;

		void pack() {
			strcpy(buf, usn);
			strcat(buf, "|");
			strcat(buf, name);
			strcat(buf, "|");
			strcat(buf, marks);
			strcat(buf, "|");
			while(strlen(buf) < SIZE)
				strcat(buf, "*");
		}
		
		void unpack() {
			strcpy(usn, strtok(buf, "|"));
			strcpy(name, strtok(NULL, "|"));
			strcpy(marks, strtok(NULL, "|"));
		}

		int getHead(fstream &fin) {
			fin.seekg(0, ios::beg);

			fin>>buf;
			if(fin.fail()) {
				return -1;
			}

			if(buf[0] == '#') {
				for(i=1, j=0; i<SIZE; i++, j++) {
					if(buf[i] == '#') {
						break;
					}
					temp[j] = buf[i];
				}
				temp[j] = '\0';
				head = atoi(temp);
				return 0;
			}else {
				return -1;
			}
		}

		int setHead(fstream &fout) {
			seekp(0, ios::beg);

			sprintf(temp, "%d", head);

			buf[0] = '#';
			for (i=1; j=0; i<SIZE; i++, j++) {
				if(j<strlen(temp))
					buf[i] = temp[j];
				else
					buf[i] = '#';
			}
#ifdef DEBUG
	printf("BUF = %s\n", buf);
#endif
			fout<<buf<<endl;
			return 0
		}

	public:
		void add() {
			fstream file;
			cout<<"\tADD\n";

		        cout<<"\nEnter details:\n\n";
		        cout<<"USN >";
		       	cin>>usn;
       			cout<<"Name >";
      	 	 	cin>>name;
	        	cout<<"Marks >";
      		  	cin>>marks;

			file.open("12Stud.dat", ios::in|ios::out);
			while(!file.eof()) {
				file>>buf;
				if(file.fail()) {
cout<<"FAIL";
					file.seekp(0, ios::end);
					break;
				}
				if(buf[0] == '?') {
cout<<"RECLAIM";
					file.seekp((int)file.tellg()-SIZE, ios::beg);
					break;
				}
			}
			pack();
        		file<<buf<<endl;
			file.close();
		}

		void disp() {
                        int i=0;
			ifstream file;

			cout<<"\tDISP\n";

			file.open("12Stud.dat", ios::in);
                        
                        while(!file.eof()) {
				file>>buf;
				if(file.fail())
                                	break;
					
                                if(buf[0] == '?')
                                        continue;

				unpack();
                                
				cout<<"\nRecord "<<++i<<" >\t";
                                cout<<"USN > "<<usn<<"\tName >"<<name<<"\tMarks"<<marks<<endl;        
                	}
                        
			file.close();
		}

		void del() {
			char key[11];
			fstream file;
			cout<<"\tDEL\n";

			cout<<"Enter USN of Record to be deleted> ";
			cin>>key;

			file.open("12Stud.dat", ios::in|ios::out);

			while(!file.eof()) {
				file>>buf;
				if(file.fail())
					break;
				unpack();
				if(strcmp(usn, key) == 0) {
					cout<<"Record Found\n";
					pack();
					buf[0] =  '?';
					
					file.seekp((int)file.tellg()-SIZE, ios::beg);
					file<<buf<<endl;
					cout<<"Record Deleted\n";

					file.close();					
					return;
				}
			}
			cout<<"Record Not Found\n";
			file.close();
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

			switch(choice) {
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
};

int main() {
	Student s;
	for(;;)
		if(!s.menu())
			break;
	return 0;
}
