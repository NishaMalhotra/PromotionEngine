#include<Cart.h>
#include<SKUItem.h>
#include<string>
Cart::Cart()
{
    //list<CartItem> Items;
}
double Cart::TotalPrice()
{
    double total_price;
    for(auto i:Items)
        total_price+=i.FinalPrice;
    return total_price;
}
bool Cart::IsValidSKU(string sku)
{
    return Items.Any(i => sku.Equals(i.Item.ID));
}


void Cart::AddItems(SKUitem item, int numberOfItems)
{
    for (int i = 0; i < numberOfItems; i++)
    {
        CartItem c = new CartItem(item,item.UnitPrice,false)
        Items.push_back(c);
        //Items.Add(new CartItem { Item = item, FinalPrice = item.UnitPrice, PromotionApplied = false });
    }
}

void Cart::AddItem(SKUitem item)
{
    CartItem c = new CartItem(item,item.UnitPrice,false)
    Items.push_back(c);
    //Items.Add(new CartItem { Item = item, FinalPrice = item.UnitPrice, PromotionApplied = false });
}

void Cart::RemoveItem(string skuItemId)
{
    if (!IsValidSKU(skuItemId))
        throw std::invalid_argument("Item not found on cart!");

    for(auto item:Items)
    {
        if(item.ID == skuItemId)
            Items.erase(skuItemId);
    }
    //Items.Remove(Items.FirstOrDefault(t => skuItemId.Equals(t.Item.ID)));
}
