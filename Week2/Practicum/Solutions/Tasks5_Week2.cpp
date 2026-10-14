#include <iostream>

int main()
{
	int year;
	std::cin >> year;

	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}

	return 0;
}
