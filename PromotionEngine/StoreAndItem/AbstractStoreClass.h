#include<iostream>
#include<Store.h>
using namespace std;
class AbstractStoreClass
{
  public:
    Store AddSKUitem(SKUitem item);
    Store AddPromotions(List<PromotionRule> promotions);
    Store AddPromotion(PromotionRule promotion);
    Store AddPromotion(string promotion);
    Store AddItemToCart(string itemSKU);
    void DeletePromotion(string promotion);
    Store EmptyCart();
    Store Checkout();
    void DeleteItemFromCart(string sku);
    float GetCartTotal();
    List<SKUitem> GetSKUitems();
    void UpdateSKUitemUnitPrice(string sku, float price);
    void DeleteSKUitem(string sku);
    List<PromotionRule> GetPromotions();
    List<SKUitem> GetAllItems();
    SKUitem GetItem(string sku);
    Cart GetCart();
};
