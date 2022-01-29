#pragma once
#include<iostream>
#include<list>
#include<SKUItem.h>
#include<Cart.h>
#include<PromotionRules.h>

using namespace std;
class Store//:public AbstractStoreClass
{
  public:
    Store();
    list<PromotionRules> Promotions();
    list<SKUItem> Items();
    Store AddSKUitem(SKUItem item);
    Store AddPromotions(list<PromotionRules> promotions);
    Store AddPromotion(PromotionRules promotion);
    Store AddPromotion(string promotion);
    void DeletePromotion(string promotion);
    Store AddItemToCart(string itemSKU);
    Store EmptyCart();
    Store Checkout();
    list<SKUItem> GetSKUitems();
    void UpdateSKUitemUnitPrice(string sku, float price);
    void DeleteSKUitem(string sku);
    list<PromotionRules> GetPromotions();
    list<SKUItem> GetAllItems();
    SKUItem GetItem(string sku);
    void DeleteItemFromCart(string sku);
    float GetCartTotal();
    Cart GetCart();
    bool IsValidSKU(string sku);
};
