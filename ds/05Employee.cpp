#include<iostream>

using namespace std;

class Employee {
	private:
		int id, b_sal; 
		float allw, i_tax, net_sal;
		char name[30];
	public:
		int getID() {
			return id;
		}
		void getEmployee() {
			cout<<"Enter the following Employee Details :\n\n";
			cout<<"Name : ";
			cin>>name;
			cout<<"ID : ";
			cin>>id;
			cout<<"Basic Salary : ";
			cin>>b_sal;
		}
		void calcNSalary() {
			allw = (float) 1.23 * b_sal;
			i_tax = (float) 0.1 * (b_sal + allw);
			net_sal = (b_sal + allw) - i_tax;
		}
		void putEmployee() {
			cout.setf(ios::right);
			cout<<endl;
			cout<<id;
			cout.width(12);
			cout<<name;
			cout.width(10);
			cout<<b_sal;
			cout.width(15);
			cout<<i_tax;
			cout.width(15);
			cout<<net_sal;
		}
};

int main() {
	int i, j, num, flag = 0;
	cout<<"Enter the Number of Employees : ";
	cin>>num;
	Employee e[30];
	for(i = 0; i < num; i++) {
		e[i].getEmployee();
		for(j = 0; j < i; j++) {
			if(e[i].getID() == e[j].getID()) {
				cout<<"\n\nDuplicate ID "<<e[i].getID()<<" Detected!\n\n";
				flag = 1;
				cout<<"Please correctly enter your Employee Credetials!\n";
			}
		}
		if(flag){
			flag = 0;
			i--;
			continue;
		}
		e[i].calcNSalary();
	}
	cout<<"\nNumber \tName\tBasic Salary\tIncome Tax\tNet Salary\n";	
	for(i = 0; i < num; i++) {
		e[i].putEmployee();
	}
	cout<<endl;
	return 0;
}
