#include <iostream>

const int ELIGIBLE_FOR_DISCOUNT = 10;
const double VIP_DICOUNT = 0.15;
const double OTHER_DISCOUNT = 0.05;

bool processTransaction(int& stockQuantity, int quantityChange, bool isSale) {
	if (quantityChange <= 0) {
		return false;
	}
	if (isSale) {
		if (quantityChange > stockQuantity) {
			return false;
		}
		stockQuantity -= quantityChange;
	}
	else {
		stockQuantity += quantityChange;
	}
	return true;
}

double calculatePrice(int quantity, double unitPrice, bool isVIP) {
	if (quantity <= 0 || unitPrice <= 0) {
		return -1;
	}
	if (isVIP) {
		return quantity * unitPrice * (1 - VIP_DICOUNT);
	}
	if (quantity > ELIGIBLE_FOR_DISCOUNT) {
		return quantity * unitPrice * (1 - OTHER_DISCOUNT);
	}
	return quantity * unitPrice;
}

void engine() {
	int stockQuantity = 0;
	double unitPrice = 0;

	std::cout << "Insert stock quantity\n";
	if (!(std::cin >> stockQuantity) || stockQuantity < 0) {
		return;
	}
	std::cout << "Insert unit price\n";
	if (!(std::cin >> unitPrice) || unitPrice <= 0) {
		return;
	}

	bool isSale;
	int quantity;
	bool hasDiscount;
	std::cout << "Insert is sale? quantity discount\n";
	while (std::cin >> isSale >> quantity >> hasDiscount) {
		if (!processTransaction(stockQuantity, quantity, isSale)) {
			std::cout << "Transaction rejected\n";
			continue;
		}
		if (isSale) {
			std::cout << "Price: " << calculatePrice(quantity, unitPrice, hasDiscount) << "\n";
		}
		std::cout << "Stock left: " << stockQuantity << "\n";
	}
}

int main() {
	engine();
}
