#include <iostream>
#include <iostream>
#include <cstdlib>

#define SIZE 100

using namespace std;

class Node {
	public:
		int info;
		class Node *link;
};

class List {
	private: 
		Node *HEAD;
	public:
		List() {
			HEAD = NULL;
		}
		void insert() {
			Node *TMP;
			TMP = new Node();
			cout<<"\nEnter an element to be inserted : ";
			cin>>TMP->info;
			TMP->link = HEAD;
			HEAD = TMP;
		}
		void del() {
			Node *TMP;
			if(HEAD == NULL) {
				cout<<"\nList is Empty!\n";
			}else {
				TMP = HEAD;
				cout<<"The deleted item : "<<TMP->info;
				HEAD = HEAD->link;
				TMP->link = NULL;
				delete(TMP);
			}
		}
		void display() {
			Node *TMP;
			if(HEAD == NULL) {
				cout<<"\nList is Empty!\n";
			}else {
				for(TMP = HEAD; TMP != NULL; TMP = TMP->link) {
					cout<<TMP->info<<"-->";
				}
				cout<<"NULL\n";
			}
		}
};

int main() {
	List l;
	int ch = 0;
	while(1) {
		cout<<"\nEnter the choice of operation,";
		cout<<"\n1) Insert\n2) Delete\n3) Display\n4) Quit\n";
		cin>>ch;
		switch(ch) {
			case 1:
				l.insert();
			break;
			case 2:
				l.del();
			break;
			case 3:
				l.display();
			break;
			case 4:
				exit(0);
			break;
			default:
				cout<<"\nInvalid Input!\n";
			break;
		}
	}
	return 0;
}