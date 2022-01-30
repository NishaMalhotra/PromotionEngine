#pragma once
#include<iostream>
using namespace std;
class BuyNForFixedPrice:public PromotionRules
{
    private:
        string SKU;
        int NumberOfItems;
        int FixedPrice;
    public:
        BuyNForFixedPrice();
        BuyNForFixedPrice(string sku, int numberOfItems, int fixedPrice);
        string SKU();
        int NumberOfItems();
        int FixedPrice();
        void Execute(Cart cart);
        bool IsApplicable(Cart cart);
        string ToString();
};

