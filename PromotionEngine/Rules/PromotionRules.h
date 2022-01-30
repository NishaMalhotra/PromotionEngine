#pragma once
#include<iostream>
#include<Cart.h>
using namespace std;
class PromotionRules
{
    public:
        PromotionRules();
        string ruleName(); //{// get { return ToString(); }}
        virtual bool IsApplicable(Cart* cart) = 0;
        virtual void Execute(Cart* cart) = 0;
        static bool IsEmptyCart(Cart* cart);
        {
            return (cart == nullptr) || cart.Items == NULL || cart.Items.size() == 0;
        };
};

