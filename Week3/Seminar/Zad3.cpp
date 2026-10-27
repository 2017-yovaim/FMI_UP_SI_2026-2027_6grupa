#include <iostream>
using namespace std;

int main() {
	unsigned number = 0;
	cout << "Please enter a number: I will tell you if it is prime!" << endl;
	cin >> number;

	if (number < 2) {
		cout << "Not prime!" << endl;
		return 0;
	}

	bool isDivisible = false;
	int squareRootOfNumber = std::sqrt(number);

	for (unsigned i = 2; i < squareRootOfNumber; i++) { //optimization - if any number is not divisible by anything until its square root, it is prime (proof - ask a mathematician)
		if (number % i == 0) {
			isDivisible = true;
			break;
		}
	}

	if (isDivisible) {
		cout << "Not prime!" << endl;
	}
	else {
		cout << "Prime!" << endl;
	}




}