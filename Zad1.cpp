#include <iostream>

bool contains(const int a[], int n, const int b[], int m)
{
	int lenght = 0;
	int j = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[j])
		{
			j++;
			lenght++;
		}
		else
		{
			j = 0;
			lenght = 0;
		}
		if (lenght == m)
		{
			return true; break;
		}
	}
	if (lenght != m)
	{
		return false;
	}
}
void readArray(int arr[], int size)
{
	std::cout << "Enter " << size << " numbers: ";
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

int main()
{
	int n, m;
	std::cout << "Enter a number: ";
	std::cin >> n;

	std::cout << "Enter a number: ";
	std::cin >> m;

	if (m < 1 || m>100 || n < 1 || n>100 || m > n)
	{
		std::cout << "Invalid input!";
		return 1;
	}
	if (m > n)
	{
		std::cout << "Invalid Input!";
		return 1;
	}
	int arr1[100];
	int arr2[100];

	readArray(arr1, n);
	readArray(arr2, m);
	std::cout << contains(arr1, n, arr2, m);

}