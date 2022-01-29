#pragma once
#include<iostream>
#include<List>
using namespace std;
class TotalFixedPrice:public PromotionRules
{
    public:
        TotalFixedPrice();
        TotalFixedPrice(List<string> skus, int fixedPrice);
        List<string> SKUs();
        void Execute(Cart cart);
        bool IsApplicable(Cart cart);
        string ToString();
};

