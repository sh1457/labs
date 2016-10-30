#include<iostream>
#include<cstring>

using namespace std;

class String {
	private:
		char str[50];
	public:
		String() {
			strcpy(str, "");
		}
		String(char p[20]) {
			strcpy(str, p);
		}
		String operator+(String s) {
			String tmp;
			strcat(tmp.str, str);
			strcat(tmp.str, " ");
			strcat(tmp.str, s.str);
			return tmp;
		}
		friend ostream &operator<<(ostream &st, String s) {
			st<<s.str<<" "<<endl;
			return st;
		}
};

int main() {
	char c1[20] = "VTU";
	char c2[20] = "BELGAUM";
	String s1 = c1;
	String s2 = c2;
	String s3 = s1 + s2;
	cout<<s1;
	cout<<s2;
	cout<<s3;
	return 0;
}
