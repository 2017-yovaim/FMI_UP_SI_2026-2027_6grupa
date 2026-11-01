#include <iostream>
using namespace std;
//Zad1 - count digits of number
int countDigitsOfNumber(int number) {
	if (number == 0) {
		return 1;
	}
	if (number < 0) {
		number *= -1; //working with positive integers for ease
	}

	int counterOfDigits = 0;
	while (number != 0) {
		counterOfDigits++;
		number /= 10;
	}

	return counterOfDigits;
}

//Zad2 - sum digits of number
int sumDigitsOfNumber(int number) {
	if (number < 0) {
		number *= -1; //working with positive integers for ease
	}

	int sumOfDigits = 0;
	while (number != 0) {
		sumOfDigits += number % 10;
		number /= 10;
	}
	return sumOfDigits;
}

//Zad3 - reverse a positive number that does not end in 0
unsigned int reverseNumber(unsigned int number) {
	if (number % 10 == 0) { //validation
		return -1; //error code
	}
	if (number >= 0 && number <= 9) { //the reverse of a single-digit number is itself
		return number;
	}

	int reversedNumber = 0;
	while (number != 0) {
		(reversedNumber *= 10) += (number % 10);
		number /= 10;
	}
	return reversedNumber;
}

//Zad4 - check if a number is a palindrom
bool isPalindrom(unsigned int number) {
	return number == reverseNumber(number);
}

//Zad5 - raise n to the power of k
unsigned int calculatePower(unsigned int n, unsigned int k) {
	if (n == 0) {
		return 1; //0 raised to any power is 1; we ignore the case of 0 to the power of 0
	}
	unsigned int power = 1;
	for (int i = 0; i < k; i++) {
		power *= n;
	}
	return power;
}

//Zad6 - check if k is suffix of n
bool isSuffix(unsigned int n, unsigned int k) {
	while (k != 0) {
		int lastDigitOfK = k % 10;
		int lastDigitOfN = n % 10;
		if (lastDigitOfK != lastDigitOfN) {
			return false;
		}
		k /= 10;
		n /= 10;
	}
	return true;
}

//Zad7 - check if k is a prefix of n; n and k must contain no 0s for this to be a valid solution
bool isPrefix(unsigned int n, unsigned int k) {
	while (n >= k) {
		if (n == k) {
			return true;
		}
		n /= 10;
	}
	return false;
}

//Zad8 - check if k is an infix of n
bool isInfix(unsigned int n, unsigned int k) {
	while (n >= k) {
		if (isSuffix(n, k)) {
			return true;
		}
		n /= 10;
	}
	return false;
}

//Zad9 - swap two integer variables
void mySwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//auxiliary function defined for unsigned ints for Zad10
void mySwap(unsigned int& a, unsigned int& b) {
	unsigned int temp = a;
	a = b;
	b = temp;
}

//auxiliary function for Zad10
double calculateAverageOfDigits(unsigned int number) {
	if (number >= 0 && number <= 9) { //average of digits of a single-digit number is the number
		return number; //a double can accept an unsigned int
	}
	int digitCounter = 0;
	double sum = 0;

	while (number != 0) {
		digitCounter++;
		sum += number % 10;
		number /= 10;
	}

	return double(sum) / double(digitCounter);
}

//Zad10
void printSuitableDigits(unsigned int n, unsigned int m, unsigned int k) {
	//validation - if wrong arguments, print an error message and return
	if (n == 0 || m == 0 || k == 0) {
		cout << "None of the arguments can be 0!" << endl;
		return; //program stops
	}
	if (n > 10000 || m > 10000 || k > 10) {
		cout << "Argument is too big!" << endl;
		return;
	}
	if (n > m) {
		mySwap(n, m);
	}

	for (unsigned int i = n; i <= m; i++) {
		if (calculateAverageOfDigits(i) > k) {
			cout << i << " ";
		}
	}
}








//for testing
int main() {
	cout << countDigitsOfNumber(0) << " " << countDigitsOfNumber(120) << " " << countDigitsOfNumber(1234) << " " << countDigitsOfNumber(-12345);
	cout << sumDigitsOfNumber(0) << " " << sumDigitsOfNumber(120) << " " << sumDigitsOfNumber(123) << " " << sumDigitsOfNumber(-1234);
	cout << reverseNumber(1234);
	cout << isPalindrom(121) << " " << isPalindrom(122) << endl;
	cout << calculatePower(2, 3) << " " << calculatePower(3, 5);
	cout << isSuffix(1234, 34) << " " << isSuffix(1234, 12);
	cout << isPrefix(12, 12) << " " << isPrefix(1234, 12) << " " << isPrefix(1234, 15);
	cout << isInfix(1234, 12) << " " << isInfix(1234, 23) << " " << isInfix(1234, 34) << " " << isInfix(1234, 5);
	printSuitableDigits(10, 100, 3);
 

	return 0;
}