#include <iostream>

void reverseRange(int a[], int l, int r)
{
	for (int i = l; i<r; i++, r--)
	{
		int temp = a[i];
		a[i] = a[r];
		a[r] = temp;
	}
}

int main()
{
	int l;
	int r;
	int n;
	std::cout << "Enter array lenght: ";
	std::cin >> n;
	if (n < 0 || n>50)
	{
		std::cout << "Invalid Input!";
		return 1;
	}
	int arr[50];
	std::cout << "Enter array's elements: ";
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	std::cout << "Enter l and r: ";
	std::cin >> l >> r;
	if (l<0 || l>r || r >= n)
	{
		std::cout << "Invalid Input!";
		return 1;
	}
	reverseRange(arr, l, r);
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i]<< " ";
	}
	
}