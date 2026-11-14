#include <iostream>

bool processTransaction(int &stockQuantity, int quantityChange, bool isSale);
double calculatePrice(int quantity, double unitPrice, bool isVIP);

void sell(int &quantity, double &profit, double price, int quantityToBuy);
void stock(int &quantity, int quantityChange);

int main()
{
    int quantity = 0;
    double profit = 0.0;

    int quantityChange;
    double price;
    bool isSale;
    
    std::cin>>quantityChange;
    std::cin>>price;
    std::cin>>isSale;
    if(isSale)
    {
        stock(quantity, quantityChange);
    }
    else
    {
        sell(quantity, profit, price, quantityChange);
    }

    for(int i=0; i<2; i++)
    {
        std::cin>>quantityChange;
        std::cin>>isSale;
        if(isSale)
        {
            stock(quantity, quantityChange);
        }
        else
        {
            sell(quantity, profit, price, quantityChange);
        }
    }


    std::cin>>quantityChange;
    sell(quantity, profit, price, quantityChange);
    sell(quantity, profit, price, quantityChange);

    std::cout<<profit;

    // Не разбирам какви трябва да са входните данни.
    
    return 0;
}

bool processTransaction(int &stockQuantity, int quantityChange, bool isSale)
{
    if(isSale && stockQuantity >= quantityChange)
    {
        stockQuantity -= quantityChange;
        return true;
    }
    else if(!isSale)
    {
        stockQuantity += quantityChange;
        return true;
    }
    return false;
}

double calculatePrice(int quantity, double unitPrice, bool isVIP)
{
    double discount = 1;
    discount -= isVIP ? 0.15: 0;
    discount -= quantity > 10 ? 0.05: 0;

    return quantity * unitPrice * discount;
}

void sell(int &quantity, double &profit, double price, int quantityToBuy)
{
    bool isVIP;
    std::cin>>isVIP;

    if(processTransaction(quantity, quantityToBuy, true))
    {
        profit += calculatePrice(quantityToBuy, price, isVIP);
    }
}

void stock(int &quantity, int quantityChange)
{
    processTransaction(quantity, quantityChange, false);
}