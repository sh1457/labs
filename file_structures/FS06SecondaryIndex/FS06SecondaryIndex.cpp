#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

#define LEN 10

using namespace std;

char buf[50], keys[10][10];
int recAddr[10], numKeys;

class Student {
	private:
        	char name[25], usn[11], marks[4];
        	//char buf[100][LEN];
        	void pack();
		void unpack();
        public:
        	Student();
        	void add();
        	void del();
		void search();
		void remove(char key[10]);
		int find(char key[10], int i);
		void insert(char key[10], int pos);
		void display();
        	void unload();
};

Student::Student() {	
	int i=0;
        ifstream fin;
        fin.open("index", ios::in);

        while(!fin.eof()) {
		fin >> keys[i] >> recAddr[i];
		if(fin.fail())
			break;
		i++;
	}
	numKeys=i;
	fin.close();
}

void Student::pack() {
	strcpy(buf,usn);
	strcat(buf,"|");
	strcat(buf,name);
        strcat(buf,"|");
	strcat(buf,marks);
        strcat(buf,"#");
}

void Student::unpack() {
	strcpy(usn,strtok(buf, "|"));
	strcpy(name,strtok(NULL, "|"));
	strcpy(marks,strtok(NULL, "#"));
}

void Student::add() {
	int pos;
	ofstream fout;	
	
	fout.open("Stud06", ios::app);
	cout << "Enter the USN\nName\nMarks: ";
	cin  >> usn >> name >> marks;
	
	pos = (int)fout.tellp();
	pack();
	fout << buf << endl;
	insert(name, pos);
	cout << "Record added!\n";

	fout.close();
}

void Student::remove(char key[10]) {
	int index = find(key, 0);
	for(int i=index; i < numKeys; i++) {
		strcpy(keys[i], keys[i+1]);
		recAddr[i] = recAddr[i+1];
	}
	numKeys--;
}

void Student::insert(char key[10], int pos) {
	int i;
	int index = find(key, 0);

	if(numKeys == LEN) {
		cout << "Index is FULL!\n";
		return;
	}
	for(i=numKeys-1; i >= 0; i--) {
		if(strcmp(key, keys[i]) < 0) {
			strcpy(keys[i+1], keys[i]);
			recAddr[i+1] = recAddr[i];
		}else {
			break;
		}
	}
	strcpy(keys[i+1], key);
        recAddr[i+1]=pos;
        numKeys++;
}

int Student::find(char key[10], int i) {
	for(; i < numKeys; i++) {
		if(strcmp(keys[i], key)==0)
			return i;
	}
	return -1;
}

void Student::search() {
	int index=-1;
	char key[10];
	fstream fin;
	
	cout << "Enter key: ";
	cin  >> key;
	
	fin.open("Stud06", ios::in);
	
	while((index = find(key, index+1)) != -1) {
		fin.seekg(recAddr[index], ios::beg);
	
		fin  >> buf;
		cout << buf << endl;
	}

	fin.close();
}

void Student::del() {
	int index;
	char key[10];
	fstream f;
	
	f.open("Stud06", ios::in|ios::out);
	cout << "Enter the key: ";
	cin  >> key;
	
	while((index = find(key, 0)) != -1) {
		f.seekp(recAddr[index], ios::beg);
		f << '*';
		remove(key);
	
		cout << "Record deleted\n";
	}

	f.close();
}

void Student::display() {
	ifstream fin;

	fin.open("Stud06", ios::in);

	cout << "Record File : Stud06\n\n";

	while(!fin.eof()) {
		fin  >> buf;
                if(fin.fail())
                        break;
		cout << buf << endl;
	}

	fin.close();

        fin.open("index", ios::in);

        cout << "Index File : index\n\n";

        while(!fin.eof()) {
                fin >> buf;
                if(fin.fail())
                        break;
                cout << buf << "\t";
                fin >> buf;
                if(fin.fail())
                        break;
                cout << buf << "\n";
        }

        fin.close();
}

void Student::unload() {
	ofstream fout;

	fout.open("index");
	for(int i=0; i < numKeys; i++)
		fout << keys[i] << "\t" << recAddr[i] << endl;

	fout.close();
}

int main() {
	int ch;
	Student s;
	
	while(1) {
		cout << "FS - Secondary Index\n\n1) Add\n2) Search\n3) Delete\n4) Display\n5) Exit\n\n>>> ";
		cin  >> ch;
		switch(ch) {
			case 1: s.add();
			break;
			case 2: s.search();
			break;
			case 3: s.del();	
			break;
			case 4: s.display();
			break;
			case 5:  s.unload();
			exit(0);
			default: cout<<"Invalid choice\n";
			break;
		}
	}
}
