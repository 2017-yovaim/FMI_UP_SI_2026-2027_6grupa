#include <iostream>

// Не успях да реша задачата. Питах и  gemini, но не му разбрах отоговора. Пращам, защото съм написал нещо.

bool processTransaction(int& stockQuantity, int quantityChange, bool isSale) 
{

    if (isSale) {
        if (stockQuantity < quantityChange) {

            return false;
        }
        else {
            stockQuantity -= quantityChange;

            return true;
        }
    }
    else {
        stockQuantity += quantityChange;

        return true;
    }

}

double calculatePrice(int quantity, double unitPrice, bool isVIP) 
{

    double totalPrice = quantity * unitPrice;
    int discountVIP = 0.85;
    int quantityDiscount = 0.95;

    if (isVIP) {
        totalPrice *= discountVIP;
    }

    if (quantity > 10) {
        totalPrice *= quantityDiscount;
    }

    return totalPrice;
    
}

int main()
{
    
    int stock;
    double price;



}

 