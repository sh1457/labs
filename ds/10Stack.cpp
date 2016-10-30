#include <iostream>
#include <iostream>
#include <cstdlib>

#define SIZE 100

using namespace std;

class Stack {
	private: 
		int a[SIZE];
		int TOP;
	public:
		Stack() {
			TOP = -1;
		}
		Stack operator +(int ele) {
			if(TOP == SIZE - 1) {
				cout<<"\nStack Full!\n";
			}else {
				a[++TOP] = ele;
			}
			return (*this);
		}
		Stack operator --(int i) {
			if(TOP == -1) {
				cout<<"\nStack Empty!\n";
			}else {
				cout<<"Deleted item : "<<a[TOP--]<<endl;
			}
			return (*this);
		}
		friend ostream &operator <<(ostream &c, Stack &s) {
			if(s.TOP == -1) {
				c<<"\nStack Empty!\n";
			}else {
				for(int j = s.TOP; j >= 0; j--) {
					c<<"\n\t\t|";
					c.width(4);
					c<<s.a[j]<<"|\n";
				}
			}
			return c;
		}
};

int main() {
	Stack st;
	int ch = 0, ele = 0;
	while(1) {
		cout<<"\nEnter the choice of operation,";
		cout<<"\n1) Push\n2) Pop\n3) Display\n4) Quit\n";
		cin>>ch;
		switch(ch) {
			case 1:
				cout<<"Enter an element to Push : ";
				cin>>ele;
				st = st + ele;
			break;
			case 2:
				st = st--;
			break;
			case 3:
				cout<<st;
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