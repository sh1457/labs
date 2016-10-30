#include<iostream>
#include<cmath>

using namespace std;

class Octal {
	private: int o;
	public:	static int dec2oct(int x) {
			int a = 0;
			while(x != 0 && x > 8) {
				a += (x / 8);
				a *= 10; 
				x %= 8;	
			}
			a += x;
			return a;
		}
		static int oct2dec(int x) {
			int a = 0, d = 0, i = 0;
			for(i = 0; x != 0; i++) {
				d = (x % 10);
				a += d * pow(8,i);
				x /= 10; 
			}
			return a;
		}	
		Octal() {
			o = 0;
		}
		Octal(int x) {
			o = dec2oct(x);
		}
		Octal operator+(int x) {
			Octal temp;
			temp.o = dec2oct(oct2dec(o) + x);
			return temp;
		}
		friend ostream &operator<<(ostream &c, Octal oct) {
			c<<oct.o<<endl;
			return c;
		}
};

int main() {
	int k;
	Octal h;
	cout<<"Enter a Decimal Number :";
	cin>>k;
	h = k;
	cout<<"Enter a Decimal Number :";
	cin>>k;
	cout<<"Sum of Octal num "<<h<<"\tand\n\tDecimal num "<<k<<"\n\tis\n\tOctal num ";
	Octal y = h + k;
	cout<<y; 
	return 0;
}
