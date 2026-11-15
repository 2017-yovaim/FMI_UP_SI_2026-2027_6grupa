#include<iostream>
using namespace std;

bool contains(int arr1[], int length_arr1, int arr2[], int length_arr2)
{
	bool isItTrue = 0;
	for (int i = 0; i < length_arr1; i++)
	{
		int brOfPepetitions = i;
		for (int j = 0; j < length_arr2; j++)
		{

			if (arr1[brOfPepetitions] == arr2[j])
			{
				brOfPepetitions++;
			}
			else
			{
				break;
			}
		}
		if (brOfPepetitions==i+length_arr2)
		{
			isItTrue = 1;
			break;
		}
	}
	return isItTrue;
}

int main()
{
	int a, b;
	cin >> a;
	int arr1[100];
	for (int i = 0; i < a; i++)
	{
		cin >> arr1[i];
	}

	cin >> b;
	int arr2[100];
	for (int i = 0; i < b; i++)
	{
		cin >> arr2[i];
	}

	cout << contains(arr1, a, arr2, b);
}