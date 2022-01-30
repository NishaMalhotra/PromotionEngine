#pragma once
#include<iostream>
#include<List>
using namespace std;
class TotalFixedPrice:public PromotionRules
{
    private:
        List<string> SKUs;
        int FixedPrice;
    public:
        TotalFixedPrice();
        TotalFixedPrice(List<string> skus, int fixedPrice);
        void Execute(Cart cart);
        bool IsApplicable(Cart cart);
        string ToString();
};

