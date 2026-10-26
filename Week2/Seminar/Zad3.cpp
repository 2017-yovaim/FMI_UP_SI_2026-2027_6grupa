#include <iostream>
using namespace std;

int main() {
	int number = 0;
	cout << "Please enter a 3-digit number - I will tell you if at least 2 of the digits are the same" << endl;
	cin >> number;

	int firstDigit = number / 100;
	int secondDigit = (number / 10) % 10;
	int thirdDigit = number % 10;

	if ((firstDigit == secondDigit) || (firstDigit == thirdDigit) || (secondDigit == thirdDigit)) {
		cout << "Yes, the number has at least 2 equal digits!" << endl;
	}
	else {
		cout << "No, the number does not have repeating digits!" << endl;
	}





	return 0;
}