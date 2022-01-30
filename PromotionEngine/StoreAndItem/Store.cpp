#include<Store.h>
Store::Store(){
    Cart cart = new Cart();
    list<PromotionRules> Promotions;
    list<SKUItem> Items;
}
Store Store::AddSKUitem(SKUitem item)
{
    if(item != NULL)
        Items.push_back(item);
    return this;
}

Store Store::AddPromotions(List<PromotionRules> promotions)
{
    if(promotions!=NULL && promotions.size() > 0)
        Promotions.push_back(promotions);
    return this;
}
Store Store::AddPromotion(PromotionRule promotion)
{
    if ( promotion != null ) Promotions.Add(promotion);
    return this;
}

Store Store::AddPromotion(string promotion)
{
    if (Regex.IsMatch(promotion, @"^\d"))
    {
        AddPromotion(promotion.ToNitemForFixedPricePromotion());
    }
    else
    {
        AddPromotion(promotion.ToCombinedItemFixedPricePromotion());
    }
    return this;
}

Store Store::DeletePromotion(string promotion)
{
    auto promotionIndex = Promotions.
    
    std::list<PromotionRules>::iterator it;
    it = std::find(Promotions.begin(), Promotions.end(), promotion);
    
    if(it == Promotions.end())
        throw std::invalid_argument("Promotion not found!");
    Promotions.erase(promotionIndex);
}

Store Store::AddItemToCart(string itemSKU)
{
    if (!IsValidSKU(itemSKU))
        throw std::invalid_argument("SKU not found!");
    if(itemSKU!= NULL)
    {
        std::list<SKUItem>::iterator it;
        it = std::find (Items.begin(), Items.end(), itemSKU);
        cart.AddItem(*it);
    }
    return this;
}

Store Store::EmptyCart()
{
    Cart = new Cart();
    return this;
}

Store Store::Checkout()
{
    //Promotions.ForEach(p => { if (p.IsApplicable(Cart)) p.Execute(Cart); });
    return this;
}

List<SKUitem> GetSKUitems()
{
    return Items;
}
void Store::UpdateSKUitemUnitPrice(string sku, float price)
{
    if (!IsValidSKU(sku)) 
        throw std::invalid_argument("SKU not found!!!");

    for(item:Items)
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


List<PromotionRule> GetPromotions()
{
    return Promotions;
}

List<SKUitem> GetAllItems()
{
    return Items;
}
SKUitem Store::GetItem(string sku)
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
    Cart.RemoveItem(sku);
}
        
float Store::GetCartTotal()
{
    return Cart.TotalPrice;
}

Cart Store::GetCart()
{
    return Cart;
}

bool Store::IsValidSKU(string sku)
{
    return Items.Any(i => sku.Equals(i.ID));
}
