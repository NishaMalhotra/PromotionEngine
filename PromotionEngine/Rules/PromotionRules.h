#pragma once
#include<iostream>
#include<Cart.h>
using namespace std;
class PromotionRules
{
    public:
        PromotionRules();
        string ruleName(); //{// get { return ToString(); }}
        virtual bool IsApplicable(Cart cart) = 0;
        virtual void Execute(Cart cart) = 0;
        static bool IsEmptyCart(Cart cart);
        /*{
            //return 0;//(cart == NULL) || cart.Items == NULL || cart.Items.Count == 0;
        };*/
};

