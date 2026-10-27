#include <iostream>
using namespace std;

int main() {
	unsigned dayOfTheWeek = 0;
	cout << "Please enter a number - I will tell you which day of the week if corresponds to!" << endl;
	cin >> dayOfTheWeek;

	switch (dayOfTheWeek) {
	case 1:
		cout << "Monday!" << endl;
		break;
	case 2:
		cout << "Tuesday!" << endl;
		break;
	case 3:
		cout << "Wednesday!" << endl;
		break;
	case 4:
		cout << "Thursday!" << endl;
		break;
	case 5:
		cout << "Friday!" << endl;
		break;
	case 6:
		cout << "Saturday!" << endl;
		break;
	case 7:
		cout << "Sunday!" << endl;
		break;
	default:
		cout << "Not a day of the week!" << endl;
		break;
	}





	return 0;
}