#include<iostream>
using namespace std;
class PromotionRules
{
    public:
        PromotionRules();
        string ruleName { get { return ToString(); }}
        virtual bool IsApplicable(Cart cart) = 0;
        virtual void Execute(Cart cart) = 0;
        static bool IsEmptyCart(Cart cart)
        {
            return (cart == null) || cart.Items == null || cart.Items.Count == 0;
        }
};
