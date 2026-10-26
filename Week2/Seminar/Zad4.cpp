#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0, c = 0;
	cout << "Please enter 3 numbers - I will tell you if they could be the lengths of the sides of a triangle" << endl;
	cin >> a >> b >> c;

	bool firstCheck = (a + b) > c;
	bool secondCheck = (a + c) > b;
	bool thirdCheck = (b + c) > a;

	if (firstCheck && secondCheck && thirdCheck) {
		cout << "Yes, these numbers could be the lengths of the sides of a triangle!" << endl;
	}
	else {
		cout << "No, these numbers could not be the lengths of the sides of a triangle!" << endl;
	}





	return 0;
}