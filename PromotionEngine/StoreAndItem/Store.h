#include<iostream>
#include<list>
using namespace std;
class Store:public AbstractStoreClass
{
  public:
    Store();
    Cart Cart();
    list<PromotionRules> Promotions();
    list<SKUitem> Items();
    Store AddSKUitem(SKUitem item);
    Store AddPromotions(List<PromotionRule> promotions);
    Store AddPromotion(PromotionRule promotion);
    Store AddPromotion(string promotion);
    void DeletePromotion(string promotion);
    Store AddItemToCart(string itemSKU);
    Store EmptyCart();
    Store Checkout();
    List<SKUitem> GetSKUitems();
    void UpdateSKUitemUnitPrice(string sku, float price);
    void DeleteSKUitem(string sku);
    List<PromotionRule> GetPromotions();
    list<SKUitem> GetAllItems();
    SKUitem GetItem(string sku);
    void DeleteItemFromCart(string sku);
    float GetCartTotal();
    Cart GetCart();
    bool IsValidSKU(string sku);
};
