#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0, c = 0;
	cout << "Please enter 3 numbers - I will sort them!" << endl;
	cin >> a >> b >> c;

	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}

	if (a > c) {
		int temp = a;
		a = c;
		c = temp;
	}

	if (b > c) {
		int temp = b;
		b = c;
		c = temp;
	}

	cout << "The sorted numbers are " << a << " " << b << " and " << c << endl;



	return 0;
}