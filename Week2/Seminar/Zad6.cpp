#include <iostream>
using namespace std;

int main6() {
	cout << "Please enter numbers - I will tell you which is the smallest. When you want to stop entering numbers, please enter 0." << endl;

	int temp = 0, min;
	cin >> temp;
	min = temp;

	while (temp != 0) {
		cin >> temp;
		if (min > temp) {
			min = temp;
		}
	}

	cout << "The smallest number is " << min << endl;




	return 0;
}