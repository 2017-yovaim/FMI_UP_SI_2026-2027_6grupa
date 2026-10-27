#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0, c = 0;
	cout << "Please enter 3 numbers - I will tell you the biggest of them!" << endl;
	cin >> a >> b >> c;

	int max = a >= b ? (a >= c ? a : (b >= c ? b : c)) : (b >= c ? b : (c >= a ? c : a));
	cout << "The max of " << a << ", " << b << " and " << c << " is " << max << endl;



	return 0;
}