#include <iostream>
using namespace std;

int main() {
	unsigned n = 0;
	cout << "Please enter a number - I will tell you its factorial!" << endl;
	cin >> n;

	unsigned factorial = 1;

	for (unsigned i = 1; i <= n; i++) {
		factorial *= i;
	}

	cout << "The factorial of " << n << " is " << factorial << endl;


	return 0;
}