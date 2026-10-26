#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0, c = 0;
	cout << "Please enter 3 numbers: I will tell you the biggest one! " << endl;
	cin >> a >> b >> c;

	int max = a;
	if (max < b) {
		max = b;
	}

	if (max < c) {
		max = c;
	}

	cout << "The biggest number of the 3 is " << max << endl;




	return 0;
}