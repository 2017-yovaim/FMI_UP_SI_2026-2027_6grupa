#include<iostream>
using namespace std;

void reverseRange(int arr[], int l, int r)
{
	while (l <= r)
	{
		int a;
		a = arr[l];
		arr[l] = arr[r];
		arr[r] = a;
		l++;
		r--;
	}
}

int main()
{
	int n;
	cin >> n;

	int arr[100];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int l, r;
	cin >> l >> r;
	reverseRange(arr, l, r);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i]<<" ";
	}
}