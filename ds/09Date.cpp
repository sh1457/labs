#include<iostream>

using namespace std;

class Date
{
	private:
		int dd,mm,yyyy;
		int a[12];
		bool ly;
		long int nod;
	public:
		Date()
		{
			a[0]=a[2]=a[4]=a[6]=a[7]=a[9]=a[11] = 31;
			a[3]=a[5]=a[8]=a[10] = 30;
			a[1] = 28;
			dd=mm=yyyy = 1;
		}
		void getNo()
		{
			long int num = 0;
			int m = mm;
			num += ((366 * (yyyy / 4)) + (365 * (3 * yyyy / 4)));
			while(m > 0) {
				num += a[m-1];
			}
			num += dd;
			nod = num; 
		}
		void getDate()
		{
			cout<<"Enter a Date (dd/mm/yyyy)\n"<<endl;
			cin>>dd>>mm>>yyyy;
			if((yyyy % 4) == 0) {
				ly = 1;
				a[1] = 29;
			}
			while((dd > a[mm - 1]) || (dd <= 0) || (mm > 12) || (mm <= 0)) {
				cout<<"Invalid Date!\nTry Again\n"<<endl;
				this->getDate();
			}
			getNo();
		}
		friend ostream &operator<<(ostream &c, Date d) {
			c<<d.dd<<"/"<<d.mm<<"/"<<d.yyyy;
			return c; 		
		}
		long int operator-(Date d) { 
			return (nod - d.nod);
		}
		Date operator+(int no_of_days) { 
			Date d2 = *this;
			while(no_of_days > 0) {
                                if(no_of_days > 365) {
                                        no_of_days -= 365;
                                        d2.yyyy++;
                                        continue;
                                }else if(no_of_days > 31) {
                                        no_of_days -= 31;
                                        d2.mm++;
                                        continue;
                                }else {
                                        d2.dd += no_of_days;
                                        no_of_days = 0;
                                }
                        }
                        return d2;
		}
};

int main() {
	Date d1, d2, d3, d4;
	long int nod1, nod2;
	d1.getDate();
	d2.getDate();
	nod1 = d1 - d2;
	cout<<"The difference between "<<d1<<" and "<<d2<<" is "<<nod1<<endl;	

	d3.getDate();
	cout<<"Enter Number of days to add : ";
	cin>>nod2;
	d4 = d3 + nod2;
	cout<<"The sum of "<<d3<<" and "<<nod2<<" is "<<d4<<endl;
	
	return 0;
}
