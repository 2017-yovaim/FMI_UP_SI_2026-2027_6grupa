#include <iostream>
using namespace std;

const int MAX_ARRAY_SIZE = 50;
const int MAX_ERATOSTENES_ARRAY_SIZE = 5002;

//auxiliary function
void printArray(int arr[], size_t size) {
	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//Zad1
void findBiggestElementOfArray(int arr[], size_t size, int& maxValue, size_t& maxIndex) {
	if (size <= 0) {
		return;
	}

	maxValue = arr[0];
	maxIndex = 0;
	for (size_t i = 1; i < size; i++) {
		if (maxValue < arr[i]) {
			maxValue = arr[i];
			maxIndex = i;
		}
	}
}

//Zad2
int linearSearch(int arr[], size_t size, int toSearch) {
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == toSearch) {
			return i;
		}
	}
	return -1;
}

//Zad3
int binarySearch(int arr[], size_t size, int toSearch) {
	if (size <= 0) {
		return -1;
	}
	size_t left = 0;
	size_t right = size - 1;


	while (left <= right) {
		size_t middle = left + ((right - left) / 2);
		if (arr[middle] == toSearch) {
			return middle;
		}
		else if (arr[middle] < toSearch) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}

	return -1;
}

//Zad4
int calculateScalarProduct(int arr1[], size_t size1, int arr2[], size_t size2) {
	if (size1 != size2 || size1 <= 0) {
		return -1;
	}

	int scalarProduct = 0;
	for (size_t i = 0; i < size1; i++) {
		int currentMonomial = arr1[i] * arr2[i];
		scalarProduct += currentMonomial;
	}

	return scalarProduct;
}

//Zad5
bool isSymmetricalArray(int arr[], size_t size) {
	if (size <= 0) {
		return false;
	}
	for (size_t i = 0; i < size / 2; i++) {
		if (arr[i] != arr[size - i - 1]) {
			return false;
		}
	}
	return true;
}

//Zad6
bool hasRepeatingElements(int arr[], size_t size) {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = i + 1; j < size; j++) {
			if (arr[i] == arr[j]) {
				return true;
			}
		}
	}
	return false;
}

//Zad7
double getAverageOfGrades() {

	cout << "Please enter grades - whole integers in the interval of [2, 6] - then, when done, enter an integer outside of this interval: ";
	int currentGrade = 0;
	cin >> currentGrade;
	int gradesArray[5]{ 0 };
	int gradeCounter = 0;

	while (currentGrade >= 2 && currentGrade <= 6) {
		gradesArray[currentGrade - 2]++;
		gradeCounter++;
		cin >> currentGrade;
	}

	int sum = 0;
	for (size_t i = 0; i < 5; i++) {
		sum += (gradesArray[i] * (i + 2));
	}

	return (double)sum / (double)gradeCounter;

}

//Zad8
void moveArrayElement(int arr[], size_t size, size_t from, size_t to) {
	if (from >= size || to >= size || size <= 0) {
		return;
	}
	if (from == to) {
		return;
	}

	int valueToMove = arr[from];
	if (from < to) {
		for (size_t i = from + 1; i <= to; i++) {
			arr[i - 1] = arr[i];
		}
	}
	else {
		for (size_t i = from - 1; i >= to; i--) {
			arr[i + 1] = arr[i];
		}
	}

	arr[to] = valueToMove;
}

//Zad9
void insertElement(int arr[], size_t size, int newElement, size_t index) {
	if (index > size) { //put element on first available space
		arr[size] = newElement;
		return;
	}
	for (size_t i = size; i >= index; i--) {
		arr[i] = arr[i - 1];
	}
	arr[index] = newElement;
}

//Zad10
void mergeSortedArrays(int arr1[], size_t size1, int arr2[], size_t size2, int resultArray[], size_t& resultSize) {
	resultSize = size1 + size2;
	size_t resultIndex = 0, arr1Index = 0, arr2Index = 0;

	while (arr1Index < size1 && arr2Index <size2) {
		if (arr1[arr1Index] <= arr2[arr2Index]) {
			resultArray[resultIndex++] = arr1[arr1Index++];
		}
		else {
			resultArray[resultIndex++] = arr2[arr2Index++];
		}
	}

	while (arr1Index < size1) {
		resultArray[resultIndex++] = arr1[arr1Index++];
	}

	while (arr2Index < size2) {
		resultArray[resultIndex++] = arr2[arr2Index++];
	}
}

//Zad11
void sieveOfEratostenes() {
	static bool sieve[MAX_ERATOSTENES_ARRAY_SIZE];
	//ignoring indexes 0 and 1 - we know they are not prime
	sieve[0] = sieve[1] = false;

	//initializing array - all other values are true first
	for (size_t i = 2; i < MAX_ERATOSTENES_ARRAY_SIZE; i++) {
		sieve[i] = true;
	}

	//sieve algorithm
	int sqrtOfMax = sqrt(MAX_ERATOSTENES_ARRAY_SIZE);
	for (size_t i = 2; i < sqrtOfMax; i++) {
		if (sieve[i]) {
			//cross out any numbers that are divisible by this number
			for (size_t j = i + i; j < MAX_ERATOSTENES_ARRAY_SIZE; j += i) {
				sieve[j] = false;
			}
		}
	}

	for (size_t i = 0; i < MAX_ERATOSTENES_ARRAY_SIZE; i++) {
		cout << i << " ";
		if (sieve[i]) {
			cout << "PRIME!";
		}
		else {
			cout << "NOT PRIME!";
		}
		cout << endl;
	}

}


















//for testing
int main() {
	int testArray[] = { 4, 2, 7, 10, -50, 100, 3 };
	int testArraySize = 7;
	int maxValue = 0;
	size_t maxIndex = 0;
	findBiggestElementOfArray(testArray, testArraySize, maxValue, maxIndex);
	cout << "The biggest element of the array is " << maxValue << " and it is located at index " << maxIndex << endl;
	
	cout << linearSearch(testArray, testArraySize, 7) << " " << linearSearch(testArray, testArraySize, 0) << endl;
	int sortedTestArray[] = { -20, -10, 0, 15, 27, 31, 65 };
	size_t sortedTestArraySize = 7;
	cout << binarySearch(sortedTestArray, sortedTestArraySize, 31) << " " << 
		binarySearch(sortedTestArray, sortedTestArraySize, 1) << endl;

	int arr1[] = { 2, 4, 6, 1, 7 };
	int arr2[MAX_ARRAY_SIZE] = { 3, 6, 1, 2, 0 };
	cout << calculateScalarProduct(arr1, 5, arr2, 5) << endl;

	int arr3[] = { 2, 4, 3, 4, 2 };
	cout << isSymmetricalArray(arr3, 5) << " " << isSymmetricalArray(arr1, 5) << endl;
	cout << hasRepeatingElements(arr3, 5) << " " << hasRepeatingElements(arr1, 5) << endl;
	cout << getAverageOfGrades();

	printArray(arr2, 5);
	moveArrayElement(arr2, 5, 4, 1);
	printArray(arr2, 5);

	printArray(arr2, 5);
	insertElement(arr2, 5, 10, 1);
	printArray(arr2, 6);
	int sortedArray2[] = {1, 2, 4, 15, 22, 30, 65, 66, 70};
	size_t sortedArray2Size = 9;
	int resultArray[MAX_ARRAY_SIZE]{ 0 };
	size_t resultSize = 0;
	mergeSortedArrays(sortedTestArray, sortedTestArraySize, sortedArray2, sortedArray2Size, resultArray, resultSize);
	printArray(sortedTestArray, sortedTestArraySize);
	printArray(sortedArray2, sortedArray2Size);
	printArray(resultArray, resultSize);
	

	sieveOfEratostenes();
	




	return 0;
}