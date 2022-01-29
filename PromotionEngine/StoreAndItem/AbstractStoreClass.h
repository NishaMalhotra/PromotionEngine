#pragma once
#include<iostream>
#include<Store.h>
#include<SKUItem.h>
#include<Cart.h>
#include<PromotionRules.h>
using namespace std;
class AbstractStoreClass
{
  public:
    Store AddSKUItem(SKUItem item);
    Store AddPromotions(list<PromotionRules> promotions);
  //  Store AddPromotions(PromotionRules promotion);
    Store AddPromotions(string promotion);
    Store AddItemToCart(string itemSKU);
    void DeletePromotion(string promotion);
    Store EmptyCart();
    Store Checkout();
    void DeleteItemFromCart(string sku);
    float GetCartTotal();
    list<SKUItem> GetSKUitems();
    void UpdateSKUitemUnitPrice(string sku, float price);
    void DeleteSKUitem(string sku);
    list<PromotionRules> GetPromotions();
    list<SKUItem> GetAllItems();
    SKUItem GetItem(string sku);
    Cart GetCart();
};

