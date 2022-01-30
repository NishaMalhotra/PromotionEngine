#include<BuyNForFixedPrice.h>
BuyNForFixedPrice::BuyNForFixedPrice()
{
    
}
BuyNForFixedPrice::BuyNForFixedPrice(string sku, int numberOfItems, int fixedPrice)
{
    if(sku == NULL)
        throw std::invalid_argument("Invalid or missing SKU!");
    if (numberOfItems <= 0) 
        throw std::invalid_argument("Invalid number of items in promotion rule! It must be grater than zero!");
    if (fixedPrice <= 0) 
        throw std::invalid_argument("Invalid number for fixed price in promotion rule! It must be grater than zero!");
            
    SKU = sku;
    NumberOfItems = numberOfItems;
    FixedPrice = fixedPrice;
}

void BuyNForFixedPrice::Execute(Cart cart)
{
    float discountItemPrice = FixedPrice / NumberOfItems;
    float residue = 0.0;

    while (IsApplicable(cart))
    {
        residue = FixedPrice - NumberOfItems * discountItemPrice;
        foreach (var item in cart.Items.Where(i => !i.PromotionApplied && SKU.Equals(i.Item.ID)).Take(NumberOfItems))
        {
            item.FinalPrice = discountItemPrice + residue;
            item.PromotionApplied = true;
            residue = 0f;
        }
    }
}

bool BuyNForFixedPrice::IsApplicable(Cart cart)
{
    //return !IsEmptyCart(cart) &&
    return !IsEmptyCart(cart) &&
        cart.Items
        .Where(i => !i.PromotionApplied && SKU.Equals(i.Item.ID))
        .Count() >= NumberOfItems;
}

string BuyNForFixedPrice::ToString()
{
    string str = NumberOfItems + "of" + SKU + "for" + FixedPrice;
    return str;
}
