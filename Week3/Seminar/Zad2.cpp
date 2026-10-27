#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0;
	cout << "Please enter 2 numbers - I'll tell you their GCD!" << endl;
	cin >> a >> b;

	int aCopy = a, bCopy = b;

	if (bCopy > aCopy) { //swap
		int temp = aCopy;
		aCopy = bCopy;
		bCopy = temp;
	}

	while (bCopy != 0) {
		int temp = aCopy % bCopy;
		aCopy = bCopy;
		bCopy = temp;
	}

	cout << "The GCD of " << a << " and " << b << " is " << aCopy << endl;




	return 0;
}