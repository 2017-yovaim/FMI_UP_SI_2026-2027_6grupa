#include <iostream>
using namespace std;

int main() {
	int number = 0;
	cout << "Please enter a number - I will tell you the sum of its digits!" << endl;
	cin >> number;

	int numberCopy = number;
	int sum = 0;
	while (numberCopy != 0) {
		sum += (numberCopy % 10);
		numberCopy /= 10;
	}

	cout << "The sum of the digits of the number " << number << " is " << sum << endl;




	return 0;
}