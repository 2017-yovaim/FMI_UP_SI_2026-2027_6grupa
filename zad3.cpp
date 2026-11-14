#include <iostream>

bool processTransaction(int& stockQuantity, int quantityChange, bool isSale)
{
	if (isSale == true)
	{
		if (stockQuantity < quantityChange)
		{
			return false;
		}
		else
		{
			stockQuantity -= quantityChange;
			std::cout << "Stock is now: " << stockQuantity<<"\n";
		}
	}
	else
	{
		stockQuantity += quantityChange;
		std::cout << "Stock is now: " << stockQuantity<<"\n";
		return true;
	}
}

double calculatePrice(int quantity, double unitPrice, bool isVIP)
{
	double final_price = quantity * unitPrice;
	if (isVIP == true)
	{
		final_price -= (0.15 * final_price);
		if (quantity > 10)
	{
		final_price -= (0.10 * final_price);
	}
	}
	return final_price;
}

int main()
{
	int stock;
	double unitPrice;
	double finalPrice = 0;
	int option;
	std::cout << "Stock: ";
	std::cin >> stock;
	std::cout << "Unit price: ";
	std::cin >> unitPrice;

	int quantity_change;
	bool isSale;
	bool isVip;

	std::cout << "1.Stock loading " << "2.Sell " << "3.Enter Another number to end"<<"\n";
	do
	{
		std::cout << "Choose an option(1-2): ";
		std::cin >> option;
		switch (option)
		{
		case 1:
		{
			isSale = 0;
			std::cout << "Enter quantity: ";
			std::cin >> quantity_change;
			processTransaction(stock, quantity_change, isSale);
		} break;
		case 2:
		{
			isSale = 1;
			std::cout << "Enter quantity: ";
			std::cin >> quantity_change;
			std::cout << "Are they a VIP client: ";
			std::cin >> isVip;
			finalPrice += calculatePrice(quantity_change, unitPrice, isVip);
			std::cout << "Price: " << calculatePrice(quantity_change, unitPrice, isVip) << "\n";
			processTransaction(stock, quantity_change, isSale);
		} break;
		}
	} 
	while (option >= 1 && option<3);

	std::cout << "Final stock now: " << stock<<std::endl;
	std::cout << "Full income: " << finalPrice;
	
}
