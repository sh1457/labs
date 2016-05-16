#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>

#define LEN 40
#define MAX 10

using namespace std;

class Student {
	private:
		int fd;
		char name[21], usn[11], marks[4], buf[LEN];

		void pack();
		void unpack();
		unsigned int hash(char *);
	public:
		Student();
		void add();
		void search();
		void display();
};

Student::Student() {
	int i;
	char hash_table[(LEN + 1) * MAX];

	if( (fd = open("Stud11", O_RDWR)) == -1) {
		for(i=0; i < (LEN + 1) * MAX; i++)
			hash_table[i] = '/';

		fd = open("Stud11", O_RDWR|O_CREAT|O_EXCL, 0666);
		write(fd, hash_table, (LEN + 1) * MAX);
	}
}

void Student::pack() {
	int i;

	strcpy(buf, usn);
	strcat(buf, "|");
	strcat(buf, name);
	strcat(buf, "|");
	strcat(buf, marks);
	strcat(buf, "|");
	for(i = strlen(buf); i < LEN-1; i++)
		strcat(buf, "*");
}

void Student::unpack() {
	strcpy(usn, strtok(buf, "|"));
	strcpy(name, strtok(NULL, "|"));
	strcpy(marks, strtok(NULL, "|"));
}

unsigned int Student::hash(char *key) {
	unsigned int hash = 0;
	int c;

	while(c = *key++)
		hash = hash + c;

	return hash % MAX;
}

void Student::add() {
	int home_address;
	int i=0;
	char test;
	
	cout << "Enter USN : ";
	cin  >> usn;
	cout << "Enter Name : ";
	cin  >> name;
	cout << "Enter Marks : ";
	cin  >> marks;

	pack();

	home_address = hash(name);
	cout << "HA" << home_address << "\n";

	while(1) {
		if(i==MAX) {
			cout << "Error : Overflow!\n";
			return;
		}

		lseek(fd, (LEN + 1) * home_address, SEEK_SET);
		read(fd, &test, sizeof(test));

		cout << test << endl;

		if(test == '/')
			break;

		home_address = (home_address + 1) % MAX;
		i++;
	}

	lseek(fd, (LEN + 1) * home_address, SEEK_SET);
	write(fd, buf, LEN);
	write(fd, "\n", 1);
}

void Student::search() {
	char key[25];
	int home_address;
	int i=0;

	cout << "Enter key: ";
	cin  >> key;

	home_address = hash(key);
	cout << "HA" << home_address << "\n";

	do {
		lseek(fd, (LEN+1) * home_address, SEEK_SET);
		read(fd, buf, LEN);
		if(buf[0] != '/')
			unpack();
		home_address = (home_address + 1) % MAX;
		i++;
	}while(strcmp(name, key) && i < MAX);

	if(strcmp(name, key) == 0)
		cout << "Record found!\n" << "USN = " << usn << " Name = " << name << " Marks = " << marks << "\n";
	else
		cout << "Record not found!\n";
}

void Student::display() {
	int i;

	for(i=0; i < MAX; i++) {
		lseek(fd, (LEN+1) * i, SEEK_SET);
		read(fd, buf, LEN);
		if(buf[0] != '/') {
			unpack();
			cout << "HA" << i << " USN = " << usn << " Name = " << name << " Marks = " << marks << "\n";
		}
	}
}

int main() {
	int ch;
	Student s;

	do {
		cout<<"FS11 Hash\n\n1) Add\n2) Search\n3) Display\n4) Exit\n\n>>> ";
		cin>>ch;

		switch(ch) {
			case 1:  
				s.add();
			break;
			case 2:  
				s.search();
			break;
			case 3:
				s.display();
			break;
			case 4:
			break;
			default:
				cout << "Invalid Input!\n\n";
		}
	}while(ch != 4);

	return 0;
}