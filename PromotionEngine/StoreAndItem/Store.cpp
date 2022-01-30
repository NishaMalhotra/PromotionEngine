#include<Store.h>
#include<stdexcept>
using namespace std;
Store::Store()
{
    Cart *cart = new Cart();
    list<PromotionRules*> Promotions;
    list<SKUItem> Items;
}
Store Store::AddSKUitem(SKUItem item)
{
//    if(item !=NULL)
        Items.push_back(item);
    return *this;
}

Store Store::AddPromotions(list<PromotionRules*> promotions)
{
    if(promotions.size() > 0)
        Promotions.insert(Promotions.end(),promotions.begin(),promotions.end());
    return *this;
}
Store Store::AddPromotion(PromotionRules* promotion)
{
    if ( promotion )
        Promotions.push_back(promotion);
    return *this;
}

Store Store::AddPromotion(string promotion)
{
    if (true)//write proper regex
    {
        AddPromotion(promotion.BuyNForFixedPrice());
    }
    else
    {
        AddPromotion(promotion.TotalFixedPrice());
    }
    return *this;
}

Store Store::DeletePromotion(string promotion)
{
    std::list<PromotionRules>::iterator it;
    it = std::find(Promotions.begin(), Promotions.end(), promotion);

    if(it == Promotions.end())
        throw std::invalid_argument("Promotion not found!");
    Promotions.erase(*it);
}

Store Store::AddItemToCart(string itemSKU)
{
    if (!IsValidSKU(itemSKU))
        throw std::invalid_argument("SKU not found!");
    if(itemSKU!= NULL)
    {
        std::list<SKUItem>::iterator it;
        it = std::find(Items.begin(), Items.end(), itemSKU);
        cart.AddItem(*it);
    }
    return *this;
}

Store Store::EmptyCart()
{
    cart = new Cart();
    return *this;
}

Store Store::Checkout()
{
    //Promotions.ForEach(p => { if (p.IsApplicable(Cart)) p.Execute(Cart); });
    return *this;
}

list<SKUItem> Store::GetSKUitems()
{
    return Items;
}
void Store::UpdateSKUitemUnitPrice(string sku, float price)
{
    if (!IsValidSKU(sku))
        throw std::invalid_argument("SKU not found!!!");

    for(SKUItem *item:Items)
    {
        if(sku.compare(item.ID))
        {
            item.UpdateUnitPrice(price);
        }
    }
}

void Store::DeleteSKUitem(string sku)
{
    if (!IsValidSKU(sku))
        throw std::invalid_argument("SKU not found!!!");

    std::list<SKUItem>::iterator it;
    it = std::find(Items.begin(), Items.end(), sku);

    Items.erase(it);
}


list<PromotionRules> Store::GetPromotions()
{
    return Promotions;
}

list<SKUItem> Store::GetAllItems()
{
    return Items;
}
SKUItem Store::GetItem(string sku)
{
    if (!IsValidSKU(sku))
        throw std::invalid_argument("SKU not found!!!");

    std::list<PromotionRules>::iterator it;
    it = std::find(Items.begin(), Items.end(), sku);
    return *it;
}

void Store::DeleteItemFromCart(string sku)
{
    if (!IsValidSKU(sku))
        throw std::invalid_argument("SKU not found!!!");
    cart.RemoveItem(sku);
}

double Store::GetCartTotal()
{
    return cart.TotalPrice;
}

Cart Store::GetCart()
{
    return cart;
}

bool Store::IsValidSKU(string sku)
{
//    return (Items.Any(i => sku.Equals(i.ID)));
      return true;
}
