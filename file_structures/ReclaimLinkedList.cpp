#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

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
			while(strlen(buf) < SIZE-1)
				strcat(buf, "*");
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

int Record::add() {
	cout<<"ADD\n\n";
	int i, j, head, tmp, offset;
	char num[SIZE];
	fstream file;

	file.open("rec.dat", ios::in | ios::out);

	file>>buf;

	if(file.fail()) {
		if(!file.eof()) {
			strcpy(num, "-1");
			buf[0] = '#';
			for(i=1, j=0; i<SIZE-1; i++)
				if(j < strlen(num))
					buf[i] = num[j++];
				else
					buf[i] = '#';

			file.seekp(0, ios::beg);

			file<<buf<<endl;
		}else {
			return -1;
		}
	}

	if(buf[0] == '#')
		for(i=1, j=0; i<SIZE; i++)
			if(buf[i] != '#')
				num[j++] = buf[i];
			else
				break;

	num[j] = '\0';

	head = atoi(num);

	cout<<"USN> ";
	cin>>usn;
	cout<<"Name> ";
	cin>>name;
	cout<<"Marks> ";
	cin>>marks;

	if(head == -1) {
		file.seekp(0, ios::end);
		pack();
		file<<buf<<endl;
	}else {
		offset = head * SIZE;

		file.seekg(offset, ios::beg);

		file>>buf;

		if(file.fail())
			return -1;

		if(buf[0] == '?') {
			for(i=1, j=0; i<SIZE; i++)
				if(buf[i] != '?')
					num[j++] = buf[i];
				else
					break;

			num[j] = '\0';
			tmp = atoi(num);
		}else {
			return -2;
		}

		file.seekp(offset, ios::beg);
		pack();
		file<<buf<<endl;

		head = head + tmp;
		tmp = head - tmp;
		head = head - tmp;

		sprintf(num, "%d", head);

		buf[0] = '#';
		for(i=1, j=0; i<SIZE-1; i++)
			if(j < strlen(num))
				buf[i] = num[j++];
			else
				buf[i] = '#';

		file.seekp(0, ios::beg);

		file<<buf<<endl;
	}

	file.close();
	return 0;
}

void Record::disp() {
	cout<<"DISP\n\n";
	int i, j, head;
	char num[SIZE];
	ifstream fin;

	fin.open("rec.dat", ios::in);

	while(!fin.eof()) {
		fin>>buf;

		if(fin.fail())
			break;

		if(buf[0] == '?') {
#ifdef DEBUG
			cout<<buf<<endl;
#endif
			continue;
		}

		if(buf[0] == '#') {
			for(i=1, j=0; i<SIZE; i++)
				if(buf[i] != '#')
					num[j++] = buf[i];
				else
					break;

			num[j] = '\0';

			head = atoi(num);
#ifdef DEBUG
			cout<<head<<endl;
#endif
			continue;
		}

		unpack();

		cout<<"USN> "<<usn<<"\tName> "<<name<<"\tMarks> "<<marks<<endl;
	}

	fin.close();
}

int Record::del() {
	cout<<"DEL\n\n";
	int i, j, head, tmp = 0, offset;
	char num[SIZE], key[11];
	fstream file;

	cout<<"Key> ";
	cin>>key;

	file.open("rec.dat", ios::in | ios::out);

	while(!file.eof()) {
		file>>buf;

		if(file.fail())
			return -1;

		if(buf[0] == '#') {
			for(i=1, j=0; i<SIZE; i++)
				if(buf[i] != '#')
					num[j++] = buf[i];
				else
					break;

			num[j] = '\0';
			head = atoi(num);
		}else if(buf[0] == '?') {
			tmp++;
			continue;
		}else {
			unpack();

			if(strcmp(key, usn) == 0) {
				head = head + tmp;
				tmp = head - tmp;
				head = head - tmp;

				offset = head * SIZE;

				file.seekg(offset, ios::beg);
				file>>buf;
				file.seekp(offset, ios::beg);

				if(file.fail())
					return -1;

				sprintf(num, "%d", tmp);

				buf[0] = '?';
				for(i=1, j=0; i < SIZE-1; i++)
					if(j < strlen(num))
						buf[i] = num[j++];
					else
						break;

				buf[i] = '?';

				file<<buf<<endl;
				file.seekp(0, ios::beg);

				if(file.fail())
					return -2;

				sprintf(num, "%d", head);

				buf[0] = '#';
				for(i=1, j=0; i < SIZE-1; i++)
					if(j < strlen(num))
						buf[i] = num[j++];
					else
						buf[i] = '#';

				file<<buf<<endl;
				return 0;
			}
		}
		tmp++;
	}
	return -1;
}

int main() {
	int choice;
	Record r;

	while(1) {
		cout<<"\n\nReclaim space inplace method using Linked List\n\n";
		cout<<"1)\tAdd\n2)\tDel\n3)\tDisp\n4)\tExit\n\n";
		cout<<"--> ";
		cin>>choice;

		switch(choice) {
			case 1:
				if((choice = r.add()) < 0)
					cout<<"ERR::ADD::"<<choice<<endl;
				r.disp();
			break;
			case 2:
				if((choice = r.del()) < 0)
					cout<<"ERR::DEL::"<<choice<<endl;
				r.disp();
			break;
			case 3:
				r.disp();
			break;
			default:
				exit(0);
		}
	}

	return 0;
}